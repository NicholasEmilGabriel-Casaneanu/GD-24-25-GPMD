#include "2024lab3.h"
// add your tests here.
int main()
{
	
	//char code[1000] = "int main() \n{ \n int var1=10;\n int var2 =10;\n if(var1<10) \n {\n int var3=20;\n} \n}\ n";
	char code[1000] = "int main()\n{ \n int numElephants = 10; \n int var2 = 10; \nif (var2 < 10)\n	{\n	int var3 = 20; \n	while(var3 < 21) \n		{\n		int var6 = 10; \n		var3++; \n		}\n	int var7 = 5; \n	int var8 = 16;\n	}\n while (var2 < 0)\n	{ \n	if (var2 == 10) \n		{ \n		int var4; \n		} \n	int num = 10; \n	} \n int var5 = 10; \n}";
	
	std::cout << code << "\n";

	//FindAllVariables(variables, code);
	for (int i = 0; i < 9; i++)
	{
		char variables[1000] = "";
		if(i==0)
		{
			std::cout << "\nline 3:\n";
			FindAllVariablesInScope(variables, code, 3);
			std::cout << variables << "\n";
		}
		if(i == 1)
		{
			std::cout << "\nline 4:\n";
			FindAllVariablesInScope(variables, code, 4);
			std::cout << variables << "\n";
		}
		if (i == 2)
		{
			std::cout << "\nline 7:\n";
			FindAllVariablesInScope(variables, code, 7);
			std::cout << variables << "\n";
		}
		if (i == 3)
		{
			std::cout << "\nline 10:\n";
			FindAllVariablesInScope(variables, code, 10);
			std::cout << variables << "\n";
		}
		if (i == 4)
		{
			std::cout << "\nline 13:\n";
			FindAllVariablesInScope(variables, code, 13);
			std::cout << variables << "\n";
		}
		if (i == 5)
		{
			std::cout << "\nline 14:\n";
			FindAllVariablesInScope(variables, code, 14);
			std::cout << variables << "\n";
		}
		if (i == 6)
		{
			std::cout << "\nline 20:\n";
			FindAllVariablesInScope(variables, code, 20);
			std::cout << variables << "\n";
		}
		if (i == 7)
		{
			std::cout << "\nline 22:\n";
			FindAllVariablesInScope(variables, code, 22);
			std::cout << variables << "\n";
		}
		if (i == 8)
		{
			std::cout << "\nline 24:\n";
			FindAllVariablesInScope(variables, code, 24);
			std::cout << variables << "\n";
		}
	}
	std::cin.get();

}