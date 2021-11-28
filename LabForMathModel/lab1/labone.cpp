#include <iostream>
#include <cmath>
#include <fstream>
#include <string>

const double h = 0.05;
const double start = 0;
const double end = 1;
unsigned int kolvo;

double fxy(double y, double x)
{
	return h*((x/(exp(x*x)) - (2*y*x)));	
}


void zapisfail(std::string namefile, double* x, double* y)
{
	std::ofstream input(namefile, std::ios::app);

	if(input.is_open())
	{
		for(unsigned int count = 0; count <= kolvo; ++count)
		{
			input << x[count] << " " << y[count] << '\n';
		}
	}
	input.close();
}

void Ailer()
{

	double* x = new double[kolvo];
	double* y = new double[kolvo];

	x[0] = 0;
	y[0] = 1;

	double x_start = 0;
	for(unsigned int count = 1; count <= kolvo; count++)
	{

		x_start += h;
		x[count] = x_start;

		y[count] = y[count - 1] + fxy(y[count - 1], x[count]);

	}

	zapisfail("Ailer.txt",x,y);

	delete[] x;
	delete[] y;

}

void Runge()
{ 
    
    double* x = new double[kolvo];
	double* y = new double[kolvo];

	x[0] = 0;
	y[0] = 1;

	double x_start = 0;
	double k1,k2,k3,k4;
	for(unsigned int count = 1; count <= kolvo; count++)
	{
		k1 = fxy(y[count - 1], x[count - 1]);
		k2 = fxy(y[count - 1] + (0.5*k1), x[count - 1] + (0.5*h));
		k3 = fxy(y[count - 1] + (0.5*k2), x[count - 1] + (0.5*h));
		k4 = fxy(y[count - 1] + k3, x[count - 1] + h);

		y[count] = y[count - 1] + (k1 + 2*k2 + 2*k3 + k4)/6;

		x_start += h;
		x[count] = x_start;
	}

	zapisfail("Runge.txt",x,y);

	delete[] x;
	delete[] y;

}


int main()
{

	kolvo = static_cast<int>((end - start) / h);
    Ailer();
    Runge();

    return 0;
} 