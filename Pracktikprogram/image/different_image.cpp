#include <iostream>
#include <string>
#include <cmath>
#include <string>

#include "bmp_analys.h"


uint32_t rast(std::string img1, std::string img2)
{
	uint32_t** colors_first = parsbmp(img1);
	uint32_t** colors_second = parsbmp(img2);

	uint32_t sizeW = sizearrW(img1);
	uint32_t sizeH = sizearrH(img1);

	uint32_t result = 0;

	for(uint32_t i = 0; i < sizeW; ++i)
	{
		for(uint32_t j = 0; j < sizeH; ++j)
		{
			result += sqrt((colors_second[i][j] - colors_first[i][j])); 
		}
	}

	delete[] colors_first;
	delete[] colors_second;

	return result;
}

int main()
{
	//int kolvo;
	//std::cin >> kolvo;

	/*while(kolvo > 0)
	{
		std::string img1, img2;
		std::cin >> img1 >> img2;

		std::cout << img1 + img2;

		--kolvo;
	}*/

	uint32_t k = rast("1.bmp", "2.bmp");
	std::cout << k;

	return 0;
}