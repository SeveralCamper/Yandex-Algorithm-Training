#include <bits/stdc++.h>

/* Сложность алгоритма - порядок количетсва действий, которые выполняет алгоритм. Есть вычислительная сложность, которая отслеживает
количество затраченного времени работы алгоритма и пространственная сложность, отображающая колиство затраченной памяти. 
В основном, сложность алгоритмов будет расчитываться с помщью Big O - это нотация, используемая для описания времени выполнения
алгоритма в зависимости от размера входных данных по верхней границе, то есть по наихудшему случаю.

Примеры нотаций Big O
O(1): Константная сложность. Время выполнения алгоритма не зависит от размера входных данных. Например, доступ к элементу массива по индексу.

O(log n): Логарифмическая сложность. Время выполнения алгоритма растет медленно с увеличением размера входных данных.
Например, бинарный поиск в отсортированном массиве.

O(n): Линейная сложность. Время выполнения алгоритма пропорционально размеру входных данных. Например, просмотр всех элементов в массиве.

O(n log n): Линейно-логарифмическая сложность. Время выполнения алгоритма растет быстрее, чем линейное, но медленнее, чем квадратичное.
Например, сортировка слиянием (merge sort).

O(n^2): Квадратичная сложность. Время выполнения алгоритма зависит от квадрата размера входных данных. Например, сортировка пузырьком (bubble sort).

O(2^n): Экспоненциальная сложность. Классический пример этой сложности рекурсивное вычисление чисел Фибоначи.

O(n!): Факториальная сложность. Время выполнения алгоритма растет факториально от размера входных данных.
Этот тип сложности встречается, например, при переборе всех возможных комбинаций элементов,
что делает его чрезвычайно неэффективным и нежелательным для больших значений n. */

/* Задача №1. Дана строка в UTF-8 кодировке. Найти самый часто встречающий в ней символ, если их несколько вывести любой */

void FirstTaskFirstDecision() // не эффективный варинат решения - перебор каждого элемента, а затем подсчет количества таких же элементов вторым проходом: O(n^2)
{
	std::string str;
	std::cin >> str;
	int res = 0;
	for (int i = 0; i < str.length(); i++)
	{
		int new_res = 0;
		for (int j = 0; j < str.length(); j++)
		{
			if (str[i] == str[j])
			{
				new_res++;
			}
		}
		if (new_res > res)
		{
			res = new_res;
		}
	}
	std::cout << res << std::endl;
}

void FirstTaskSecondDecision() // чуть более эффективный варинат решения - через set выделим уникальные символы в строке и посчитаем количство повторений для каждого: O(n * k), где k - уникальные символы
{
	std::string str;
	std::cin >> str;

	std::set<char> set;

	for (int i = 0; i < str.length(); i++)
	{
		set.insert(str[i]);
	}

	int res = 0;
	for (char c : set)
	{
		int new_res = 0;
		for (int j = 0; j < str.length(); j++)
		{
			if (c == str[j])
			{
				new_res++;
			}
		}

		if (new_res > res)
		{
			res = new_res;
		}
	}

	std::cout << res << std::endl;
}

void FirstTaskThirdDecision() // эффективный варинат решения - через unordered_map выделим уникальные символы в строке и посчитаем количство повторений для каждого: O(n + k), где k - уникальные символы
{
	std::string str;
	std::cin >> str;

	std::unordered_map<char, short> map;

	for (int i = 0; i < str.length(); i++)
	{
		if (map.find(str[i]) == map.end())
		{
			map[str[i]] = 0;
		}
		map[str[i]]++;
	}

	int res = 0;
	for (auto item : map)
	{
		if (item.second > res)
		{
			res = item.second;
		}
	}

	std::cout << res << std::endl;
}

/* Особые случаи. Случай в програаме, который стоит обработать, чтобы не получить ошибку. Иногда, такая обработка может быть избыточна, в
виду нюансов реализации кода, как из стандартной бибилотеки, так и собственного. Поэтому всегда нужно проверять необходимость доп. валидации. */

/* Задача №2. Сумма последовательности. На вход передается строка, в которой определена последовательность цифр("10 20 30"). Нужно вывести
сумму последовательности. */

void SecondTaskFirstDecision()
{
	std::string str;
	std::getline(std::cin, str);

	/*
	Здесь можно было бы обработать краевую ситуацию с пустой строкой и вывести ответ 0, но это избыточно
	*/

	std::istringstream iss(str);
	std::vector<short> vec;

	int num;
    while (iss >> num) {
        vec.push_back(num);
    }

	int res = 0;
	for (auto item : vec)
	{
		res += item;
	}

	std::cout << res << std::endl;
}

/* Задача №3. Максимум последовательности. На вход передается строка, в которой определена последовательность цифр("10 20 30"). Нужно вывести
максимум последовательности. При этом здесь нужно отдельно обработать случай пустой последовательности, т.к. отсутствие элементов последовательности,
не говорит о том, что ее максимум = 0. */

void TrhirdTaskFirstDecision()
{
	std::string str;
	std::getline(std::cin, str);

	// Здесь обработка пустой строки не избыточна
	if (str.empty())
	{
		std::cout << "inf" << std::endl;
		return;
	}

	std::istringstream iss(str);
	std::vector<short> vec;

	int num;
    while (iss >> num) {
        vec.push_back(num);
    }

	int res = 0;
	for (auto item : vec)
	{
		if (item > item)
		{
			res = item;
		}
	}

	std::cout << res << std::endl;
}

/* Тестирование. Что нужно тестировать?
1) Тесты из условия (если есть)
2) Общие случаи
3) Особые случаи 

Советы по составлению тестов: 
1) Если есть примеры - реши их руками и сверь ответ. Если не совпадает, то либо правильных ответом м.б. несколько, либо ты неправильно понял задачу
2) Сначала составь несколько примеров и реши задачу руками, чтобы лучше понять услвовие и чтобы потом было с чем сравнивать
3) Проверь последовательность из одного элемента и пустую последовательность
4) "Краевые эффекты" - проверь, что программа работает корректно в начале и конце последовательности, сделай тесты, чтобы ответ находился на первом
и на последнем месте в последовательности
5) Составь покрытие всех ветвлений, так, чтобы был тест, который входил в каждый if и else
6) Подбери тесты чтобы не было ни одного входа в цикл
7) Один тест - одна возможная ошибка*/

int main()
{
	FirstTaskFirstDecision();  // O(n^2)
	FirstTaskSecondDecision(); // O(n * k)
	FirstTaskThirdDecision();  // O(n + k)

	SecondTaskFirstDecision(); // O(n)

	TrhirdTaskFirstDecision(); // O(n)
	
	return 0;
}