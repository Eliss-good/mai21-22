#include <iostream>
#include <cmath>

template <typename T>
class ArrgayCS{

private:

	int size_array;
	T *glav_array;

	bool getparametr(int pozishon);

public:

	ArrayCS(int size);
	ArrayCS(const ArrayCS& second_array);
	~ArrayCS();

	void see_array();
	void setparametr(int number, int pozishon);
	void pushend_sdvig(int number);
	void sum_subt(const ArrayCS& first_array);
	void vector_operation(const ArrayCS& first_array);
	void pushend(int number);
	void getparametr(int pozishon);


};

template <typename T>
bool ArrayCS<T>::getparametr(int pozishon){

    if(pozishon <= size_array && pozishon > 0){ 
    	return false;
    } else {  
    	return true;
    }

}

template <typename T>
ArrayCS<T>::ArrayCS(int size) : size_array(size)
{
          
    glav_array = new T [size_array];
    if(size_array == 0) throw std::bad_alloc();

    for(int i = 0; i < size; ++i) glav_array[i] = i;

}

template <typename T>
ArrayCS<T>::ArrayCS(const ArrayCS<T>& first_array): size_array(first_array.size_array), glav_array(nullptr)

{     
    glav_array = new T [size_array];
    if(size_array == 0) throw std::bad_alloc();

    for(int i = 0; i < size_array; ++i)
    {
    	glav_array[i] = first_array.glav_array[i];
    }
}

template <typename T>
ArrayCS<T>::~ArrayCS()
{

	delete[] glav_array;

}

template <typename T>
void ArrayCS<T>::see_array()
{

	for(int i = 0; i < size_array; ++i) 
	{
		std::cout << glav_array[i] << ' ';
	}

	std::cout << std::endl;

}

template <typename T>
void ArrayCS<T>::setparametr(int number, int pozishon)
{

    if (number <= -100 && number >= 100) throw std::invalid_argument("dulo");
    
    if(getparametr(pozishon)) throw std::out_of_range("Chicha");

    glav_array[pozishon] = number;

}

template <typename T>
void ArrayCS<T>::getterwindow(int pozishon)
{
	if(getparametr(pozishon)) std::cout << '\n' << "You number" << glav_array[pozishon] << '\n';
}

template <typename T>
void ArrayCS<T>::pushend_sdvig(int number)
{
 	if (number >= 100 || number <= -100)
    {
		throw std::invalid_argument("THE_SCATEMAN_WORLD");
    }

    setparametr(number, size_array);

    for(int i = 1; i < size_array; ++i)
    { 
    	glav_array[i - 1] = glav_array[i];
    }

    glav_array[size_array - 1] = number;
        
}

template <typename T>
void ArrayCS<T>::pushend(int number)
{   
    if (number >= 100 || number <= -100)
    {
		throw std::invalid_argument("THE_SCATEMAN_WORLD");
    }

	if(number <= 100 && number >= -100){
	    int* next_array = new T[size_array + 1];

        for(int i = 0; i < size_array; ++i) next_array[i] = glav_array[i];

        next_array[size_array] = number;
        ++size_array;

        delete[] glav_array;
        glav_array = next_array;

        size_array++;
    }
      
}


template <typename T>
void ArrayCS<T>::sum_subt(const ArrayCS<T>& first_array)
{

    	int sumone = 0;
    	int sumtwo = 0;

    	for(int i = 0; i < size_array; i++)
    	{
    		sumone += glav_array[i];
    	}

    	for(int i = 0; i < first_array.size_array; ++i)
    	{
    		sumtwo += first_array.glav_array[i];
    	}

    	std::cout << "Summ: " << sumone + sumtwo << '\n' << "Subt: " << sumone - sumtwo << std::endl;

}

template <typename T>
void ArrayCS<T>::vector_operation(const ArrayCS<T>& first_array)
{
	int distance = 0;

	for(int i = 0; i < size_array; i++)
	{
		distance += ((glav_array[i] - first_array.glav_array[i]) * (glav_array[i] - first_array.glav_array[i]));
	}

	std::cout << '\n' <<"distance different vectors line" << size_array << " = " << sqrt(distance) << std::endl;
}

int main()
{
	ArrayCS<int> test(3);

	ArrayCS<int> test1 = test;

	kest1mvector_operationgtestf;
	t`est1.sum_subt(test);

	return 0;
}
