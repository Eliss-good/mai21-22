#include <iostream>
#include <string>
#include <fstream>
#include <exception>

template <typename T, int tsize>
class spisok
{
private:
	size_t allsize;

	T** next_ptr;
	T** back_ptr;
	T* data;
	int* read;

	void change(int& max, int& min);
	void sort(int left, int right);

public:
	spisok();
	~spisok();

	void get(int place);
	void del(int place);
	void get_all_spisok();
	void insertdata(int size);
};

template <typename T, int tsize>
spisok<T, tsize>::spisok()
{
	allsize = tsize;

	if (allsize <= 0) throw std::bad_alloc();
	data = new T[allsize];

	next_ptr = new T * [allsize];
	back_ptr = new T * [allsize];
	read = new int[allsize];

	for (int i = 0; i < allsize; ++i)
	{
		if (i == 0)
		{
			next_ptr[i] = &data[i + 1];
			back_ptr[i] = nullptr;
		}
		else if (i == allsize - 1)
		{
			next_ptr[i] = nullptr;
			back_ptr[i] = &data[i - 1];
		}
		else
		{
			next_ptr[i] = &data[i + 1];
			back_ptr[i] = &data[i - 1];
		}


		read[i] = -1;
	}
}

template <typename T, int tsize>
spisok<T, tsize>::~spisok()
{
	delete[] next_ptr;
	delete[] back_ptr;

	delete[] data;
	delete[] read;
}

template <typename T, int tsize>
void spisok<T, tsize>::change(int& max, int& min)
{
	min = min + max;
	max = min - max;
	min = min - max;

	T prob = data[max];
	data[max] = data[min];
	data[min] = prob;
}

template <typename T, int tsize>
void spisok<T, tsize>::sort(int left, int right)
{
	int l_hold = left;
	int r_hold = right;
	int pivot = read[left];

	while (left < right) {

		while ((read[right] <= pivot) && (left < right)) right--;

		if (left != right)
		{
			change(read[right], read[left]);
			left++;
		}

		while ((read[left] >= pivot) && (left < right)) left++;

		if (left != right)
		{
			change(read[left], read[right]);
			right--;
		}
	}

	read[left] = pivot;
	if (l_hold < right) sort(l_hold, right - 1);
	if (r_hold > right) sort(right + 1, r_hold);

}

template <typename T, int tsize>
void spisok<T, tsize>::get(int n_place)
{
	if (n_place <= 0) throw std::bad_alloc();

	std::cout << '\t' << data[n_place - 1] << " number of requests: " << read[n_place - 1] << '\n';

	read[n_place - 1]++;

	int left = 0;
	int right = allsize - 1;
	sort(left, allsize);
}

template <typename T, int tsize>
void spisok<T, tsize>::get_all_spisok()
{

	for (unsigned int i = 0; i < allsize; i++)
	{
		if (read[i] != -1)
		{
			std::cout << std::string(60, '-') << '\n';
			std::cout << "?" << i + 1 << '\t' << data[i] << " " << " number of requests: " << read[i] << '\n';
		}
	}
}

template <typename T, int tsize>
void spisok<T, tsize>::insertdata(int size)
{
	if (allsize < size) throw std::bad_alloc();

	for (int i = 0; i < allsize; ++i)
	{
		if (read[i] == -1 && size != 0)
		{
			std::cout << '\t' << i + 1 << ' ';
			std::cin >> data[i];

			std::cout << '\n';
			++read[i];

			--size;
		}

	}
}

template <typename T, int tsize>
void spisok<T, tsize>::del(int place)
{
	if (place >= 0 && allsize < place) throw std::bad_alloc();

	T** new_nextptr = new T * [allsize - 1];
	T** new_backptr = new T * [allsize - 1];

	T* new_data = new T[allsize - 1];
	int* new_read = new int[allsize - 1];

	int j = 0;
	for (int i = 0; i < allsize; ++i)
	{
		if (i + 1 != place)
		{
			new_nextptr[j] = next_ptr[i];
			new_backptr[j] = back_ptr[i];

			new_data[j] = data[i];
			new_read[j] = read[i];

			j++;
		}

	}

	allsize--;
	delete[] next_ptr;
	delete[] back_ptr;

	delete[] data;
	delete[] read;

	next_ptr = new_nextptr;
	back_ptr = new_backptr;

	data = new_data;
	read = new_read;
}


template <typename T, int tsize>
void fun_commands(std::string& n_command, spisok<T, tsize>& nf)
{
	if (n_command == "del")
	{
		int place;

		std::cout << "Enter the position ";
		std::cin >> place;
		nf.del(place);
	}
	else if (n_command == "get")
	{
		int place;

		std::cout << "Enter the position ";
		std::cin >> place;
		nf.get(place);
	}
	else if (n_command == "getall")
	{
		nf.get_all_spisok();
	}
	else if (n_command == "insertdata")
	{
		std::cout << "\thow many values will you enter?";

		int size;
		std::cin >> size;
		std::cout << '\n';

		nf.insertdata(size);

	}
	else if (n_command == "exit")
	{
		exit(0);
	}
}

int main()
{
	spisok<int, 8> hf;

	while (true)
	{
		std::cout << '\n' << "E/G" << "   INSERTDATA | GET | GETALL | DEL | EXIT" << std::endl;
		std::string command;
		std::cin >> command;

		fun_commands(command, hf);
	}

	return 0;
}