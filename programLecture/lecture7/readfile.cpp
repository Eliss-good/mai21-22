#include <iostream>
#include <exception>
#include <string>
#include <fstream>
#include <cctype>

int size = 2000;

class Hash
{
private:
	std::string* wordlist;
	int** glavar_connect;

	void size_hash_correct(double& k);
	void probverka_size();
	void insert(std::string& n_word);
	void poiskslova(std::string& stroka);

	void status();

public:

	Hash(std::string& namefile);
	~Hash();

};

void Hash::status()
{
	for (int i = 0; i < size; i++)
	{
		if (glavar_connect[i] != nullptr)
		{
			std::cout << wordlist[i] << ": " << *glavar_connect[i] << '\n';
		}
	}
}

void Hash::size_hash_correct(double& k)
{
	int newsize = static_cast<int>(k) * 2;

	int** next_connect = new int* [newsize];
	for (int i = 0; i < size; ++i) glavar_connect[i] = nullptr;

	std::string* next_list = new std::string[newsize];

	for (int i = 0; i < size; ++i)
	{
		if (glavar_connect[i] != nullptr)
		{
			next_connect[i] = glavar_connect[i];
			next_list[i] = wordlist[i];
		}
	}

	size = newsize;

	delete[] glavar_connect;
	delete[] wordlist;

	glavar_connect = next_connect;
	wordlist = next_list;
}

void Hash::probverka_size()
{
	double realsize = 0;
	for (int i = 0; i < size; ++i)
	{
		if (glavar_connect[i] != nullptr)
		{
			++realsize;
		}
	}

	if (realsize / static_cast<double>(size) >= 0.75)
	{
		size_hash_correct(realsize);
	}
}

void Hash::insert(std::string& n_word)
{
	probverka_size();

	int i = 0;
	while (glavar_connect[i] != nullptr)
	{
		if (wordlist[i] == n_word)
		{
			int k = *glavar_connect[i];
			k++;

			*glavar_connect[i] = k;
			return;
		}
		++i;
	}

	wordlist[i] = n_word;
	int* index = new int;

	*index = 1;

	glavar_connect[i] = index;

}

void Hash::poiskslova(std::string& stroka)
{
	std::string word;
	for (unsigned int i = 0; i < stroka.size(); ++i)
	{
		if (stroka[i] != ' ' && stroka[i] != '.' && stroka[i] != ';' && stroka[i] != ':' && stroka[i] != '\0')
		{
			while (stroka[i] != ' ' && stroka[i] != '.' && stroka[i] != ';' && stroka[i] != ':' && stroka[i] != '\0')
			{
				word.push_back(tolower(stroka[i]));
				++i;
			}

			insert(word);
		}

		word.clear();
	}

}

Hash::Hash(std::string& namefile)
{
	wordlist = new std::string[size];
	glavar_connect = new int* [size];

	for (int i = 0; i < size; ++i) glavar_connect[i] = nullptr;

	std::ifstream input(namefile);

	if (input.is_open())
	{
		std::string stroka;

		while (getline(input, stroka))
		{
			poiskslova(stroka);
		}
	}
	input.close();

	status();
}

Hash::~Hash()
{
	delete[] glavar_connect;
	delete[] wordlist;
}

int main()
{
	std::string namefile;
	std::cin >> namefile;

	Hash test(namefile);

	return 0;
}