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
	while (number > 0)
	{
		number /= 10;
		count++;
	}
	number = testNumber;
	for (int i = 0; i < count/2; i++)
	{
		if (((number / (10 * i)) % 10) != ((number / (10 * (count - i))) % 10))
		{
			return false;
		}
	}
	return true;
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
		//check if its a digit.
		//do something

	}
	return returnInt;
}
int convertBinarytoDecimal(int binaryNumber)
{
	return 0;
}
void drawRightAngledTriangle()
{

}
void drawIsocelesTriangle()
{

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