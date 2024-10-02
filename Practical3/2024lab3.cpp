#include "2024lab3.h"
// add your tests here.
int main()
{
	
	//char code[1000] = "int main() \n{ \n int var1=10;\n int var2 =10;\n if(var1<10) \n {\n int var3=20;\n} \n}\ n";
	char code[1000] = "int main()\n{ \n int numElephants = 10; \n int var2 = 10; \n	if (var2 < 10)\n{\nint var3 = 20; \n while(var3 < 21) \n {\n int var6 = 10; \n var3++; \n}\n int var7 = 5; \n int var8 = 16;\n}\n while (var2 < 0)\n { \n if (var2 == 10) \n { \n int var4; \n } \n	int num = 10; \n } \n int var5 = 10; \n }";
	char variables[1000]="";
	
	//FindAllVariables(variables, code);
	FindAllVariablesInScope(variables, code, 10);
	std::cout << variables << "\n";
	std::cin.get();

}