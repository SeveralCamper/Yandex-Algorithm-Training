#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

// sqrt(ax + b) = c
// О.Д.З: ax + b >= 0, c >= 0
// Преобразовываем уравнение в более удобную форму: ax + b = c^2
// ax = c^2 - b
// x = (c^2 - b) / 2
// подставляем значение x в исходное уравнение: a((c^2-b)/a) + b >= 0 => c^2 >= 0
// если c >= 0, то уравнение имеет едиснтвенное решение: x = (c^2 - b) / a, a != 0
// если c < 0 то уравнение не имеет решений, т.к. sqrt(ax + b) не м.б. отрицательным

// Если a = 0, уравнение примет вид sqrt(b) = c. в таком случае,
// если b >= 0 и с = sqrt(b), то x - любое число(бесконечно много решений)
// если b >= 0 b c != sqrt(b), решений нет
// если b < 0, решений нет

int main() {
	int a, b, c;
	std::cin >> a >> b >> c;

	if (c < 0)
	{
		std::cout << "NO SOLUTION" << std::endl;
	}
	else if (a == 0)
	{
		if (b < 0)
		{
			std::cout << "NO SOLUTION" << std::endl;
		}
		else if (c * c == b)
		{
			std::cout << "MANY SOLUTIONS" << std::endl;
		}
		else
		{
			std::cout << "NO SOLUTION" << std::endl;
		}
	}
	else
	{
		int numerator = c * c - b;
		if (numerator % a != 0)
		{
			std::cout << "NO SOLUTION" << std::endl;
		}
		else
		{
			int x = numerator / a;
			if (a * x + b >= 0 && sqrt(a * x + b) == c)\
			{
				std::cout << x << std::endl;
			} 
			else
			{
				std::cout << "NO SOLUTION" << std::endl;
			}
		}
	}

	return 0;
}