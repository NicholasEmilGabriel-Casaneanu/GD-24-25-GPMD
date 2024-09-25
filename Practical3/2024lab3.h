#pragma once
#include <iostream>

void FindAllVariables(char variables[1000], char code[1000])
{
	bool  recording = false;
	bool check = false;
	int checkCount = 0;
	int variablesCounter = 0;

	for (int i = 0; i < 1000; i++)
	{
		while (!check && recording)
		{
			if (code[checkCount] == 32)
			{
				check = true;
			}
			else if (code[checkCount] == 40)
			{
				check = true;
				recording = false;
				i = checkCount;
			}
			checkCount++;
		}
		if (recording && !(
			(code[i] < 97 || code[i] > 90) && (code[i] < 48 || code[i] > 57) && (code[i] < 97 || code[i] > 122)
			))
		{
			variables[variablesCounter] = code[i];
			variablesCounter++;
		}
		else if (recording && 
					( 
						(code[i] < 97 || code[i] > 90) && (code[i] < 48 || code[i] > 57) && (code[i] < 97 || code[i] > 122)
					)
				)
		{
			variables[variablesCounter] = 44;
			variablesCounter++;
			recording = false;
			check = false;
		}
		if ((code[i] == 116 && code[i - 1] == 110 && code[i - 2] == 105) ||
			(code[i] == 114 && code[i - 1] == 97 && code[i - 2] == 104 && code[i-3] == 99))
		{
			recording = true;
			i++;
			checkCount = i + 1;
		}
	}
}
void FindAllVariablesInScope(char variables[1000], char code[1000], int lineNumber)
{
	int codeIndex = 0;
	int variablesCounter = 0;
	int currentLine = 1;

	bool done = false;
	bool reachedScope = false;
	bool recording = false;
	int openedBlocks = 0;

	int scope = 0;
	int destScope = 0;
	int closeCounter = 0;

	while (!done)
	{
		if (!reachedScope)
		{
			if (code[codeIndex] == '{')
			{
				destScope++;
			}
			if (code[codeIndex] == '}')
			{
				destScope--;
				closeCounter++;
			}

			if (codeIndex > 0 && code[codeIndex] == '\n')
			{
				currentLine++;
			}
			if (currentLine == lineNumber)
			{
				reachedScope = true;
				codeIndex = 0;
				currentLine = 1;
			}
		}
		else
		{
			if (code[codeIndex] == 123)
				scope++;
			if (code[codeIndex] == 125)
			{
				if (scope > 0)
				{
					scope--;
					closeCounter--;
				}
				else
				{
					done = true;
					break;
				}
			}
			if (recording && 
				!(
					(code[codeIndex] < 97 || code[codeIndex] > 90) && (code[codeIndex] < 48 || code[codeIndex] > 57) && (code[codeIndex] < 97 || code[codeIndex] > 122) && (code[codeIndex] < 64)
				))
			{
				variables[variablesCounter] = code[codeIndex];
				variablesCounter++;
			}
			else if (recording &&
				
						(
							(code[codeIndex] < 97 || code[codeIndex] > 90) && (code[codeIndex] < 48 || code[codeIndex] > 57) && (code[codeIndex] < 97 || code[codeIndex] > 122)
						)
					)
			{
				variables[variablesCounter] = 44;
				variablesCounter++;
				recording = false;
			}
			if (((code[codeIndex] == 116 && code[codeIndex - 1] == 110 && code[codeIndex - 2] == 105) ||
				(code[codeIndex] == 114 && code[codeIndex - 1] == 97 && code[codeIndex - 2] == 104 && code[codeIndex - 3] == 99)) &&
				(scope == 1 || (scope > 1 && closeCounter == 0)))
			{
				recording = true;
				codeIndex++;
			}
			if (codeIndex > 0 && code[codeIndex] == '\n')
			{
				currentLine++;
			}
			if (currentLine > lineNumber)
			{
				done = true;
			}

		}
		if (codeIndex < 1000)
			codeIndex++;
		else
			done = true;
	}
}