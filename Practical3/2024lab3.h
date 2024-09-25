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

}