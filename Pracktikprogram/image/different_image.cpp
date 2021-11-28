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
			result += ((colors_second[i][j] - colors_first[i][j])*(colors_second[i][j] - colors_first[i][j])); 
		}
	}

	delete[] colors_first;
	delete[] colors_second;

	return sqrt(sqrt(result));
}

int main()
{
	/*
	std::cout << rast("image_exemple/apple_2.bmp", "image_exemple/apple_1.bmp") << std::endl;
	std::cout << rast("image_exemple/apple_3.bmp", "image_exemple/apple_1.bmp") << std::endl;
	std::cout << rast("image_exemple/apple_4.bmp", "image_exemple/apple_1.bmp") << std::endl;
	std::cout << rast("image_exemple/apple_3.bmp", "image_exemple/apple_2.bmp") << std::endl;
	std::cout << rast("image_exemple/apple_4.bmp", "image_exemple/apple_2.bmp") << std::endl;
	std::cout << rast("image_exemple/apple_4.bmp", "image_exemple/apple_3.bmp") << std::endl;
	*/

	std::cout << rast("image_exemple/mog_2.bmp", "image_exemple/mog_1.bmp") << std::endl;
	std::cout << rast("image_exemple/mog_3.bmp", "image_exemple/mog_1.bmp") << std::endl;
	std::cout << rast("image_exemple/mog_4.bmp", "image_exemple/mog_1.bmp") << std::endl;
	std::cout << rast("image_exemple/mog_3.bmp", "image_exemple/mog_2.bmp") << std::endl;
	std::cout << rast("image_exemple/mog_4.bmp", "image_exemple/mog_2.bmp") << std::endl;
	std::cout << rast("image_exemple/mog_4.bmp", "image_exemple/mog_3.bmp") << std::endl;

	return 0;
}