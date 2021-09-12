#include <iostream>

/*class FooString {
   char* buf;
public:
   FooString(char* tbuf);
   ~FooString();
   void show (); 

bool compare(char* str);              // Вариант 3 - true – если строки равны

Для метода по варианту написать модульный тесты, проверяющие его работу*/

class FooString {

   char* buf;

public:

   FooString(char* tbuf);
   ~FooString();
   void show ();
   bool compare(char* str);

};


FooString::FooString(char* tbuf){

   this -> buf = tbuf;

}

FooString::~FooString()
{
   //в данной реализации динамического выделения памяти внутри класса нет, поэтому в деструкторе нет необходимости
}

void FooString::show(){

	int i = 0;
   while(buf[i] != '\0'){

      std::cout << buf[i];
      ++i;
   }

}

bool FooString::compare(char* str){

   int i = 0;

   while(buf[i] != '\0' || str[i] != '\0'){
      
      if(buf[i] != str[i]){
         return false;
      }

      ++i;
   }
   return true;
}


void testCompare(){

   FooString f1('Moskow');

   if(f1.compare('Moskow0')) {
      std::cout << "vse kruto";
   }
   else {
      std::cout << "ne kroto"; 
   }

}


int main(){

   char test[100],test1[100];
   std::cin >> test >> test1;

   FooString fs1(test);

   std::cout << fs1.compare(test1); 

	return 0;
}