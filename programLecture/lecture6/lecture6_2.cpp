#include <iostream>
#include <string>

namespace tachki{
	template <typename T>
	class allpointer
	{
	    private:
		        T* glavptr;

	    public:
				allpointer(T *nptr): glavptr(nptr)
				{
				}

				~allpointer()
				{
					delete glavptr;
				}

				T* operator->()
				{
					return glavptr;
				}

				T& operator*()
				{
					return *glavptr;
				}
	};
}

class dorogocar
{
	private:
	    int price;
	    std::string name_car;

	public:
		dorogocar(std::string new_name_car, int new_price): name_car(new_name_car), price(new_price)
		{
		}

		
		void stack_car()
		{
			if (price >= 30000)
			{
			    std::cout << name_car << ' ' << price << ' ' << "dorogo";  
			}
			else
			{
				std::cout << name_car << ' ' << price << ' ' << "nedorogo";
			} 

		}
};

using namespace tachki;
int main()
{
	allpointer<dorogocar> ptr(new dorogocar("merin",46000));

	ptr->stack_car();
	return 0;
}