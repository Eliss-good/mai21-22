#include <iostream>
#include <algorithm>
#include <vector>
#include <exception>

void seeVector(std::vector<int>& glavV,const int& sizeV,int index)
{
	std::cout << glavV[index] << ' ';
	++index;
	if (index == sizeV)
	{
		throw std::bad_alloc(); 
	}	
	return seeVector(glavV, sizeV, index);
}

int main()
{
	unsigned int size;
	std::cin >> size;
    
    int n = 0;
    try
    {
	    std::vector<int> glav(size);
	    std::generate(glav.begin(),glav.end(),[&n] {return ++n;});

	    seeVector(glav,size, 0);

    }
    catch(std::exception &exception)
    {
    	std::cout << '\n' << "You see full array";
    }

    return 0;
}