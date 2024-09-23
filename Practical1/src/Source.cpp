#include "../include/functions.h"
// Test for Questions 1 to 8
int main()
{
	std::cout << "Leapyear" << std::endl;
	if (!isLeapYear(1700))
	{
		std::cout << "yes" << std::endl;
	}
	else {
		std::cout << "no" << std::endl;
	}
	if (isLeapYear(1600))
	{
		std::cout << "yes" << std::endl;
	}
	else {
		std::cout << "no" << std::endl;
	}
	if (isLeapYear(2016))
	{
		std::cout << "yes" << std::endl;
	}
	else {
		std::cout << "no" << std::endl;
	}
	std::cout << "NumberReversed" << std::endl;
	if (Reversed(123) == 321)
	{
		std::cout << "yes" << std::endl;
	}
	else {
		std::cout << "no" << std::endl;
	}

	if (Reversed(1) == 1)
	{
		std::cout << "yes" << std::endl;
	}
	else {
		std::cout << "no" << std::endl;
	}
	if (Reversed(1234) != 321)
	{
		std::cout << "yes" << std::endl;
	}
	else {
		std::cout << "no" << std::endl;
	}

	std::cout << "Palindrome" << std::endl;
	if (isAPalindrome(1))
	{
		std::cout << "yes" << std::endl;
	}
	else {
		std::cout << "no" << std::endl;
	}
	if (isAPalindrome(121))
	{
		std::cout << "yes" << std::endl;
	}
	else {
		std::cout << "no" << std::endl;
	}
	if (isAPalindrome(1213))
	{
		std::cout << "yes" << std::endl;
	}
	else {
		std::cout << "no" << std::endl;
	}
	if (isAPalindrome(1213121))
	{
		std::cout << "yes" << std::endl;
	}
	else {
		std::cout << "no" << std::endl;
	}
	std::cout << "Prime Number" << std::endl;
	if (isAPrimeNumber(3))
	{
		std::cout << "yes" << std::endl;
	}
	else {
		std::cout << "no" << std::endl;
	}
	if (isAPrimeNumber(2147483647))
	{
		std::cout << "yes" << std::endl;
	}
	else {
		std::cout << "no" << std::endl;
	}
	if (!isAPrimeNumber(4))
	{
		std::cout << "yes" << std::endl;
	}
	else {
		std::cout << "no" << std::endl;
	}
	std::cout << "Binary to Decimal" << std::endl;
	if (convertBinarytoDecimal(110) == 6)
	{
		std::cout << "yes" << std::endl;
	}
	else {
		std::cout << "no" << std::endl;
	}
	if (convertBinarytoDecimal(111) == 7)
	{
		std::cout << "yes" << std::endl;
	}
	else {
		std::cout << "no" << std::endl;
	}
	std::cout << "5 chars to int" << std::endl;
	int convertedInt = input5CharsConvertToInt();
	std::cout << convertedInt << std::endl;

	std::cout << "Triangles" << std::endl;
	drawRightAngledTriangle();
	drawIsocelesTriangle();

	int array1[10] = { 0,1,2,3,4,5,6,7,8,9 };
	int array2[10] = { 0,0,0,0,0,0,0,0,0,0 };

	std::cout << "Find Elem in array" << std::endl;
	std::cout << find(10, array1, 3) << "\n";

	std::cout << "Find Second Largest in array" << std::endl;
	std::cout << find2ndLargest(10, array1) << "\n";
	
	std::cout << "\nArray1: ";
	for (int i = 0; i < sizeof(array1) / sizeof(int); i++)
	{
		std::cout << array1[i] << " ";
	}
	std::cout << "\nArray2: ";
	for (int i = 0; i < sizeof(array1) / sizeof(int); i++)
	{
		std::cout << array2[i] << " ";
	}

	std::cout << "\n\nCopy array1 to array2" << std::endl;
	copyArraytoArray(sizeof(array1) / sizeof(int), array1, array2);

	std::cout << "\nArray1: ";
	for (int i = 0; i < sizeof(array1) / sizeof(int); i++)
	{
		std::cout << array1[i] << " ";
	}
	std::cout << "\nArray2: ";
	for (int i = 0; i < sizeof(array1) / sizeof(int); i++)
	{
		std::cout << array2[i] << " ";
	}

	int newArray[10] = { 2,5,3,6,0,0,0,0,0,0 };
	int newArraycount = 4;
	int newArraySize = 10;

	std::cout << "\nnewArray: ";
	for (int i = 0; i < sizeof(array1) / sizeof(int); i++)
	{
		std::cout << newArray[i] << " ";
	}

	std::cout << "\nInsert Element in newArray" << std::endl;
	insertElement(newArraySize, newArraycount, newArray, 2, 2);
	insertElement(newArraySize, newArraycount, newArray, 2, 2);

	for (int i = 0; i < sizeof(array1) / sizeof(int); i++)
	{
		std::cout << newArray[i] << " ";
	}

	std::cout << "\nnewArray: ";
	for (int i = 0; i < sizeof(array1) / sizeof(int); i++)
	{
		std::cout << newArray[i] << " ";
	}

	std::cout << "\nDelete Element in newArray" << std::endl;
	deleteElement(newArraySize, newArraycount, newArray, 2);

	for (int i = 0; i < sizeof(array1) / sizeof(int); i++)
	{
		std::cout << newArray[i] << " ";
	}

	std::cout << "\nCount frequency of 2 in newArray" << std::endl;
	std::cout<< frequencyCount(newArraySize, newArray, 2) << "\n";

	std::cout << "\nCount dupes in newArray" << std::endl;
	std::cout << countDuplicates(newArraySize, newArray) << "\n";

	std::cout << "\nReverse of newArray" << std::endl;
	reverse(newArraySize, newArray);
	std::cout << "\n";

}