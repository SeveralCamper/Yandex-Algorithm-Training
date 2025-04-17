#include <iostream>

int main()
{
	int firstSideLength, secondSideLength, thirdSideLength;
	std::cin >> firstSideLength >> secondSideLength >> thirdSideLength;

	if (((firstSideLength < (secondSideLength + thirdSideLength))
			&& secondSideLength < (firstSideLength + thirdSideLength)
			&& thirdSideLength < (firstSideLength + secondSideLength))
			|| (firstSideLength == secondSideLength && secondSideLength == thirdSideLength))
	{
		std::cout << "YES" << std::endl;
	}
	else
	{
		std::cout << "NO" << std::endl;
	}

	return 0;
}