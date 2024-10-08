#pragma once
#include <iostream>

bool isLeapYear(int year)
{
	if (year % 4 == 0)
		return true;
	else if (year % 100 == 0)
	{
		if (year % 400 == 0)
		{
			return true;
		}
	}
	else return false;
}

int Reversed(int testNumber)
{
	return 0;
}
bool isAPalindrome(int testNumber)
{
	int number = testNumber;
	int half = number / 2;
	int count = 0;
	int reverse = 0;
	int digit;
	while (number > 0)
	{
		number /= 10;
		count++;
	}
	number = testNumber;
	for (int i = 0; i < count; i++)
	{
		digit = number % 10;
		reverse = (reverse * 10) + digit;
		number = number / 10;
	}
	if (testNumber == reverse)
		return true;
	else
		return false;
}
bool isAPrimeNumber(int numbertoTest)
{
	int number = numbertoTest;
	int half = number / 2;
	for (int i = 2; i < numbertoTest / 2 + 1; i++)
	{
		if (numbertoTest % i == 0)
		{
			break;
			return false;
		}
	}
	return true;
}
int input5CharsConvertToInt()
{
	int returnInt = 0;
	char inputChar;
	for (int i = 0; i < 5; i++)
	{
		std::cin >> inputChar;
		if (isdigit(inputChar))
		{
			returnInt = (returnInt * 10) + (inputChar - '0');
		}
		else {
			returnInt = 0;
			break;
		}
		//check if its a digit.
		//do something

	}
	return returnInt;
}
int convertBinarytoDecimal(int binaryNumber)
{
	int number = binaryNumber;
	int count = 0;
	int result = 0;
	while (number > 0)
	{
		result += (number % 10) * pow(2, count);
		number /= 10;
		count++;
	}
	return result;
}
void drawRightAngledTriangle()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < i + 1; j++)
		{
				std::cout << "A ";
		}
		std::cout << "\n";
	}
}
void drawIsocelesTriangle()
{
	for (int i = 0; i < 8; i++)
	{
		if(i < 4)
		{
			for (int j = 0; j < i + 1; j++)
			{
				std::cout << "A ";
			}
		}
		else
		{
			for (int j = 8; j > i + 1; j--)
			{
				std::cout << "A ";
			}
		}
		std::cout << "\n";
	}
}
void drawIsocelesTriangle2()
{

}

int find(int size, int arr[], int toFind)
{
	for (int i = 0; i < size; i++)
	{
		if (arr[i] == toFind)
		{
			return i;
		}
	}
	return -1;
}
int find2ndLargest(int size, int arr[])
{
	int largest = -1;
	int secondLargest = -1;
	for (int i = 0; i < size; i++)
	{
		if (i == 0)
			largest = arr[i];
		if (arr[i] > largest)
		{
			secondLargest = largest;
			largest = arr[i];
		}
	}
	if (secondLargest > -1)
	{
		return secondLargest;
	}
	return -1;
}
void copyArraytoArray(int size, int arr1[], int arr2[])
{
	for (int i = 0; i < size; i++)
	{
		arr2[i] = arr1[i];
	}
}
bool insertElement(int& size, int& count, int arr[], int elementToInsert, int insertIndex)
{
	if (count >= size)
	{
		std::cout << "Array is full\n";
		return false;
	}
	if (insertIndex <= count)
	{
		int savedValue1 = -1;
		int savedValue2 = -1;
		bool reached = false;
		for (int i = 0; i < count; i++)
		{
			if (reached)
			{
				if (savedValue2 == -1)
				{
					savedValue2 = arr[i];
					arr[i] = savedValue1;
					savedValue1 = -1;
				}
				else if (savedValue1 == -1)
				{
					savedValue1 = arr[i];
					arr[i] = savedValue2;
					savedValue2 = -1;
				}
			}
			if (i == insertIndex)
			{
				reached = true;
				savedValue1 = arr[i];
				arr[i] = elementToInsert;
				count++;
			}
		}
	}
	else {
		std::cout << "Index out of active array area\n";
		return false;
	}

	return true;
}
bool deleteElement(int& size, int& count, int arr[], int deleteIndex)
{
	if (count == 0)
	{
		std::cout << "Array is empty\n";
		return false;
	}
	if (deleteIndex <= count)
	{
		int savedValue1 = -1;
		int savedValue2 = -1;
		bool reached = false;
		for (int i = 0; i < count; i++)
		{
			if (reached)
			{
				arr[i] = arr[i + 1];
			}
			if (i == deleteIndex)
			{
				reached = true;
				arr[i] = arr[i+1];
			}
		}
		count--;
	}
	else {
		std::cout << "Index out of active array area\n";
		return false;
	}


	return true;
}
int frequencyCount(int size, int arr[], int value)
{
	int count = 0;
	for (int i = 0; i < size; i++)
	{
		if (arr[i] == value)
			count++;
	}

	return count;
}
int countDuplicates(int size, int arr[])
{
	int dupeArray[]{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
	int dupeArraySize = 0;
	int dupeCount = 0;
	bool foundMatch = false;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < dupeArraySize; j++)
		{
			if (arr[i] == dupeArray[j])
			{
				dupeCount++;
				foundMatch = true;
			}
		}
		if (i == 0)
		{
			dupeArray[dupeArraySize] = arr[i];
			dupeArraySize++;
		}
		else if (foundMatch) {
			foundMatch = false;
		}
		else {
			dupeArray[dupeArraySize] = arr[i];
			dupeArraySize++;
		}

	}
	return dupeCount;
}
void reverse(int size, int arr[])
{
	for (int i = size - 1; i > 0; i--)
	{
		std::cout << arr[i] << " ";
	}
}
int rotateLeft(int size, int arr[])
{
	int savedValue = -1;
	for (int i = 0; i < size; i++)
	{
		if (i == 0)
		{
			savedValue = arr[i];
		}
		if (i == size - 1)
		{
			arr[i] = savedValue;
		}
		else
		{
			arr[i] = arr[i + 1];
		}
	}
	return -1;
}
bool twoMovies(int flightLength, int movieLengths[], int size)
{
	for (int firstMovie = 0; firstMovie < size; firstMovie++)
	{
		for (int secondMovie = 0; secondMovie < size; secondMovie++)
		{
			if (firstMovie != secondMovie)
			{
				if ((movieLengths[firstMovie] +
					movieLengths[secondMovie]) == flightLength)
					return true;
			}
		}
	}
	return false;
}
int wordCounter(int size, char characters[])
{
	bool isWord = false;
	int wordCounter = 0;
	for (int i = 0; i < size; i++)
	{
		if ((characters[i] >= 65 && characters[i] <= 90) ||
			(characters[i] >= 97 && characters[i] <= 122))
		{
			if (!isWord)
			{
				isWord = true;
				wordCounter++;
			}
		}
		else
			if (isWord)
				isWord = false;
	}
	return wordCounter;
}

void extraTriangle()
{
	std::cout << "\n\nBONUS QUESTION:\n";
	for (int i = -4; i < 4; i++)
	{
		for (int j = abs(i) % 5; j < 4; j++)
		{
			std::cout << "A ";
		}

		std::cout << "\n";
	}
}