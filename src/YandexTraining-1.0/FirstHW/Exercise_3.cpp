#include <iostream>
#include <algorithm>
#include <vector>

int main()
{
	std::vector<std::string> adressBook(4);
	for (int i = 0; i < 4; i++)
	{
		std::cin >> adressBook[i];
		adressBook[i].erase(std::remove(adressBook[i].begin(), adressBook[i].end()
				, '-'), adressBook[i].end());
		adressBook[i].erase(std::remove(adressBook[i].begin(), adressBook[i].end()
				, '('), adressBook[i].end());
				adressBook[i].erase(std::remove(adressBook[i].begin(), adressBook[i].end()
				, ')'), adressBook[i].end());

		if (adressBook[i].size() == 7)
		{
			adressBook[i] = "495" + adressBook[i];
		}
		
		if (adressBook[i][0] == '8')
		{
			adressBook[i].erase(0, 1);
		}
		else if (adressBook[i][0] == '+')
		{
			adressBook[i].erase(0, 2);
		}
	}

	for (int i = 1; i < (int) adressBook.size(); i++)
	{
		if (adressBook[0] == adressBook[i])
		{
			std::cout << "YES" << std::endl;
		}
		else
		{
			std::cout << "NO" << std::endl;
		}
	}
	
	return 0;
}