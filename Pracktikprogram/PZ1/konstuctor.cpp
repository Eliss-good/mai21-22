#include <iostream>

class ArrayCS{

private:

	int size_array;
	int *glav_array;

	bool getparametr(int pozishon);

public:

	ArrayCS(int size);
	ArrayCS(const ArrayCS& second_array);
	~ArrayCS();

	void see_array();
	void setparametr(int number, int pozishon);
	void pushend(int number);
	void sum_subt(ArrayCS& first_array);
};

bool ArrayCS::getparametr(int pozishon){

    if(pozishon <= size_array && pozishon > 0){ 
    	return true;
    } else {  
    	return false;
    }

    }

ArrayCS::ArrayCS(int size) : size_array(size)

{
    glav_array = new int [size];

    for(int i = 0; i < size; ++i) glav_array[i] = i;

}

ArrayCS::ArrayCS(const ArrayCS& first_array): size_array(first_array.size_array), glav_array(nullptr)

{
    glav_array = new int [size_array];

    for(int i = 0; i < size_array; ++i)
    {
    	glav_array[i] = first_array.glav_array[i];
    }
}


ArrayCS::~ArrayCS()
    {

		delete[] glav_array;

	}

void ArrayCS::see_array()
	{

		for(int i = 0; i < size_array; ++i) 
		{
			std::cout << glav_array[i] << ' ';
		}

		std::cout << std::endl;

	}

void ArrayCS::setparametr(int number, int pozishon)
    {

    	if (number >= -100 && number <= 100 && getparametr(pozishon)) 
    		{
    			glav_array[pozishon] = number;
    		}

    }

void ArrayCS::pushend(int number)
    {

    	setparametr(number, size_array);

    	for(int i = 1; i < size_array; ++i)
    	{ 
    		glav_array[i - 1] = glav_array[i];
    	}

    	glav_array[size_array - 1] = number;
        
    }

void ArrayCS::sum_subt(ArrayCS& first_array)
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





int main()
{
	ArrayCS test(7);
	test.see_array();
	test.pushend(4);

	ArrayCS test1 = test;
	test1.see_array();

	test.sum_subt(test1);

	return 0;
}