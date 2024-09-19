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
	return -1;
}
int find2ndLargest(int size, int arr[])
{
	return -1;
}
void copyArraytoArray(int size, int arr1[], int arr2[])
{
	return;
}
bool insertElement(int& size, int& count, int arr[], int elementToInsert, int insertIndex)
{

	return false;
}
bool deleteElement(int& size, int& count, int arr[], int deleteIndex)
{

	return true;
}
int frequencyCount(int size, int arr[], int value)
{

	return 0;
}
int countDuplicates(int size, int arr[])
{

	return 0;
}
void reverse(int size, int arr[])
{
	return;
}
int rotateLeft(int size, int arr[])
{
	return -1;
}
bool twoMovies(int flightLength, int movieLengths[], int size)
{
	return false;
}
int wordCounter(int size, char characters[])
{
	return 0;
}