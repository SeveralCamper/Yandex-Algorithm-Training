#include <iostream>

int main()
{
	int tRoom, tCond;
	std::string mode;
	std::cin >> tRoom >> tCond >> mode;

	if (mode == "heat")
	{
		std::cout << (tRoom < tCond ? tCond : tRoom) << std::endl;
	}
	else if (mode == "freeze")
	{
		std::cout << (tRoom < tCond ? tRoom : tCond) << std::endl;
	}
	else if (mode == "auto")
	{
		std::cout << tCond << std::endl;
	}
	else if (mode == "fan")
	{
		std::cout << tRoom << std::endl;
	}

	return 0;
}