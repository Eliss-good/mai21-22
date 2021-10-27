#include <iostream>
#include <exception>
#include <string>

const int allsize = 5;

template <typename T, int tsize>
class hef
{
    private:
		T** glavar_connect;
		size_t size_table;

		int fun_hesh(T element);

	public:
		~hef();
		hef();
		void insert(T element);
		void change(int hesh, T n_element);
		void del(int hesh);
		void all_spisok();
};

template <typename T, int tsize>
hef<T,tsize>::hef()
{
	size_table = tsize;
	glavar_connect = new T*[tsize];

	for(int i = 0; i < tsize; ++i) glavar_connect[i] = nullptr;
}

template <typename T, int tsize>
hef<T,tsize>::~hef()
{
	delete[] glavar_connect;
}

template <typename T, int tsize>
int hef<T,tsize>::fun_hesh(T element)
{
	int n_hesh = (static_cast<int>(element) % tsize);
	
	while(true)
	{
		if(tsize > n_hesh){
			if(glavar_connect[n_hesh] == nullptr)
			{
				return n_hesh;
			}
			++n_hesh;
	    }
	    else
	    {
	    	n_hesh = 0;
	    }
	}

}

template <typename T, int tsize>
void hef<T,tsize>::insert(T element)
{
	int hesh = fun_hesh(element);

	T* new_element = new T;
	*new_element = element;

	glavar_connect[hesh] = new_element;

	std::cout << '\n' <<"New elementl have hash ID: " << hesh << std::endl;
}

template <typename T, int tsize>
void hef<T, tsize>::all_spisok()
{

	for(int i = 0; i < tsize; ++i)
	{
		if(glavar_connect[i] != nullptr)
		{
			std::cout << i << " " << *glavar_connect[i] << "| ";
		}
	}

	std::cout << std::endl;

}

template <typename T, int tsize>
void hef<T, tsize>::change(int hesh, T n_element)
{
	if(glavar_connect[hesh] != nullptr)
	{
		*glavar_connect[hesh] = n_element;
    }
    else
    {
    	throw std::bad_alloc();    
    }
}

template <typename T, int tsize>
void hef<T,tsize>::del(int hesh)
{
	if(glavar_connect[hesh] != nullptr && hesh < tsize)
	{
		delete glavar_connect[hesh];
		glavar_connect[hesh] = nullptr;
	}
	else 
	{
		throw std::bad_alloc();
	}
}

int main()
{

	hef<int,allsize> table1;
	table1.insert(200);
	table1.insert(500);
	table1.insert(100);

	table1.all_spisok();

	std::string command;
	while(true)
	{
		std::cin >> command;

		if(command == "dell")
		{
			int index;
			std::cin >> index;

			table1.del(index);
			table1.all_spisok();
		}

		else if(command == "cahnge")
		{
			int index;
			int pi;
			std::cin >> index >> pi;

			table1.change(index, pi);
			table1.all_spisok();
		}

		else if(command == "stop")
		{
			return 0;
		}

	}
}