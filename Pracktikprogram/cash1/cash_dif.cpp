#include <iostream>
#include <string>
#include <exception>

template <typename T>
class item{
	public:

	 	item* next_ptr;
		item* back_ptr;
		T data;
		unsigned int read;
};

template <typename T>
int check_size(item<T>* arr_obj_list)
{
	int i = 0; 
	item<T>* chaeck = arr_obj_list[i].next_ptr;

	while(chaeck != nullptr)
	{
		++i;
		item<T>* chaeck = arr_obj_list[i].next_ptr;
	}

	return i;
}

template <typename T>
void connect_fun(int size_arr, item<T>* arr_obj_list)
{
	for(int i = 0; i < size_arr; ++i)
	{
		if(i == 0)
		{
			arr_obj_list[i].next_ptr = &arr_obj_list[i+1]; 
			arr_obj_list[i].back_ptr = nullptr;
		} 
		else if(i == size_arr - 1)
		{
			arr_obj_list[i].next_ptr = nullptr;
			arr_obj_list[i].back_ptr = &arr_obj_list[i-1];
		}
		else
		{
			arr_obj_list[i].next_ptr = &arr_obj_list[i+1];
			arr_obj_list[i].back_ptr = &arr_obj_list[i-1];
		}
	}
}

template <typename T>
void change(item*<T> arr_obj_list, unsigned int& max, unsigned int& min)
{
	item<T> tet;
	tet.next_ptr = arr_obj_list[max].next_ptr;
	tet.back_ptr = arr_obj_list[max].back_ptr;
	tet.data = arr_obj_list[max].data;
	tet.read = arr_obj_list[max].read;

	arr_obj_list[max].next_ptr = arr_obj_list[min].next_ptr;
	arr_obj_list[max].back_ptr = arr_obj_list[min].back_ptr;
	arr_obj_list[max].data = arr_obj_list[min].data;
	arr_obj_list[max].read = arr_obj_list[min].read;

	arr_obj_list[min].next_ptr = tet.next_ptr;
	arr_obj_list[min].back_ptr = tet.back_ptr;
	arr_obj_list[min].data = tet.data;
	arr_obj_list[min].read = tet.read;
}

template <typename T>
void sort(item<T>* arr_obj_list, int left, int right)
{
	int l_hold = left;
	int r_hold = right;
	int pivot = arr_obj_list[left].read;

	while (left < right) {

		while ((arr_obj_list[right].read <= pivot) && (left < right)) right--;

		if (left != right)
		{
			change(arr_obj_list[right].read, arr_obj_list[left].read);
			left++;
		}

		while ((arr_obj_list[left].read) && (left < right)) left++;

		if (left != right)
		{
			change(arr_obj_list[left].read, arr_obj_list[right].read);
			right--;
		}
	}

	read[left] = pivot;
	if (l_hold < right) sort(item<T>* arr_obj_list,l_hold, right - 1);
	if (r_hold > right) sort(item<T>* arr_obj_list,right + 1, r_hold);

}

template <typename T>
void get_item(int& position,item*<T> arr_obj_list)
{
	arr_obj_list[position].read += 1;
	std::cout << '\t' << arr_obj_list[position - 1].data << " number of requests: " << arr_obj_list[position - 1].read << '\n';

	sort(arr_obj_list, 0 , check_size(arr_obj_list));
	connect_fun(check_size(arr_obj_list),arr_obj_list);
}


template <typename T>
void all_list(item<T>* arr_obj_list)
{
	int i = check_size(arr_obj_list); 

	for(int k = 0; k <= i; k++)
	{
		std::cout << "#" << k << '\t' << arr_obj_list[k].data << " " << " number of requests: " << arr_obj_list[k].read << '\n';
	}
}

template <typename T>
void filling_arr(int& size, item<T>* arr_obj_list)
{
	for(int i = 0; i < size; ++i)
	{
		std::cin >> arr_obj_list[i].data;

		arr_obj_list[i].read = 0;
	}

	connect_fun(size, arr_obj_list);
}

int main()
{
	int size_arr = 8;

	item<std::string>* arr_obj_list = new item<std::string>[size_arr];
	filling_arr(size_arr, arr_obj_list);

	get_item(3, arr_obj_list);
	get_item(5, arr_obj_list);
	get_item(5, arr_obj_list);
	get_item(5, arr_obj_list);

	all_list(arr_obj_list);

}

