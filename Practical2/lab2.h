#include <iostream>
// dont use cout in any of the functions apart from PrintArray();
int ReplaceWithMinusOne(int array[4][6])
{
	bool deleting{ false };
	int deletingNumber{ 0 };
	int score{ 0 };
	for (int i = 0; i < 4; i++)
	{
		for (int j = 2; j < 6; j++)
		{
			if (deleting)
			{
				if (array[i][j] == deletingNumber)
				{
					score += deletingNumber;
					array[i][j] = -1;
				}
				else
				{
					deletingNumber = 0;
					deleting = false;
				}
			}
			if(!deleting)
			{
				if (array[i][j - 2] == array[i][j - 1] && array[i][j - 1] == array[i][j] && array[i][j] != 0 && array[i][j] != -1)
				{
					deletingNumber = array[i][j];
					deleting = true;
					array[i][j - 2] = -1;
					array[i][j - 1] = -1;
					array[i][j] = -1;
					score += deletingNumber * 3;
				}
			}
		}
	}
	return score;
}
void FallDownAndReplace(int array[4][6])
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 6; j++)
		{
		}
	}
}
void PrintArray(int array[4][6])
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			if(array[i][j] != 0)
				std::cout << array[i][j] << "     ";
			else
				std::cout <<  "      ";
		}
		std::cout << " \n";
	}
}
