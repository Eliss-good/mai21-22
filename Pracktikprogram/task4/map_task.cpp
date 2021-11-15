#include <iostream>
#include <map>
#include <vector>

void result(std::map<std::string, int>& count_words)
{
	std::map <std::string,int> :: iterator it;
	it = count_words.begin();

	while(it != count_words.end())
	{
		std::cout << '\n' << it->first << ' ' << it->second << '\n';
		++it;
	}
}

void find_new_string(std::string sentence, std::map<std::string, int>& count_words)
{
	std::string word;
	std::map<std::string, int> :: iterator it;

	for (unsigned int i = 0; i < sentence.size(); ++i)
	{
		if (sentence[i] != ' ' && sentence[i] != '.' && sentence[i] != ';' && sentence[i] != ':' && sentence[i] != '\0')
		{
			while (sentence[i] != ' ' && sentence[i] != '.' && sentence[i] != ';' && sentence[i] != ':' && sentence[i] != '\0')
			{
				word.push_back(tolower(sentence[i]));
				++i;
			}

			it = count_words.find(word);

			if(it == count_words.end())
			{
				count_words[word] = 1;
			} 
			else
			{
				it->second++; 
			}
		}

		word.clear();
	}
}


int main()
{
	std::map<std::string, int> count_words;
	std::string sentence;

	std::getline(std::cin, sentence);

	find_new_string(sentence, count_words);
	result(count_words);

	return 0;
}