#include <iostream>
#include "strutil.h"

/* Написать функцию для определяет наличие строки a в строке str
int strConteins(char *a, char* str)
Возвращает -1, если не содержит
Позицию начала, если содержит */

int main(){

	char str1[100], str2[100];

	std::cin >> str1 >> str2;
	std::cout << strConteins(str1,str2);

	return 0;
}
