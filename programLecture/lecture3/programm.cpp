#include <iostream>
#include <bitset>
#include <string>
#include <bits/stdc++.h>

/*Написать программу, :
- умеет читать тектосвый файл, который может быть указан ей в качестве аргумента коммандной строки и содержит названия протоколов (одно на строке)
Пример файла:

BinaryProtocol
HexProtocol 
HexProtocol



- Реализует классы Protocol, BinaryProtocol, HexProtocol
- Классы BinaryProtocol, HexProtocol являются наследниками Protocol
- Класс Protocol определяет виртуальный метод void send(char* buf, int len), который ничего не делает
- Классы BinaryProtocol, HexProtocol переопределяют виртуальный метод void send(char* buf, int len)
  - void BinaryProtocol::send(char* buf, int len) - печатает на экран содержимое строки buf в виде бинарного кода (т.е. при помощи "0101 0101 0100 1000")
  - void HexProtocol::send(char* buf, int len)    - печатает на экран содержимое строки buf в виде шестнатеричного кода (т.е. так "0xff 0xff")

Дополнительно:

Вариант 4.
- Создать структуру ConnectionList, содержащую статический массив указателей на класс Protocol и число считанных протоколов,  
функцию для добавления туда классов, соответствующих протоколам, считанным из файла

struct ConnectionList { 
  Protocol* mas[100];
  int count = 0;
};
void addProtocol(ConnectionList*p, Protocol* newProtocol );
- Написать функцию для печати всех животных void sendAll(ConnectionList*p)

*/

int size = 16;

class Protocol{

	public:

  virtual void send(char* buf, int len) = 0;
};

class BinaryProtocol : public Protocol{
	
	public:
		void send(char* buf, int len){
			for (int i = 0; i < len && buf[i] != '\0'; ++i){

				bitset<8> value_bit(buf[i]);
				std::cout << value_bit << ' ';	
		}

};

class HexProtocol : public Protocol{

  public:

    void send(char* buf, int len){

			for(int i = 0; i < len && buf[i] != '\0'; ++i){
				
				std::cout << "0x" << hex << (int)(buf[i] & 0xff) << ' ';

			}

		}

};

void FileRead(char* buf[i]){
	int score = 0;

  std::ifstream input(namefile);

  if (input.is_open() != true) {

    std::cout << "ERROR";
    return;
        
   } else{
          std::string second = "";

          while (getline(input, second)){
          	char stoki[size];

          	std::cout << score;
          	strcpy(stroki, second.c_str());

          	BinaryProtocol bp; 
          	bp.send(FileRead(namefile),size);

          	cout << endl << string(60, '=') << endl;

          	HexProtocol hp;
          	hp.send(FileRead(namefile),size);

          	+score;
          	std::cout << '\n';
          }
        }
} 

int main(){
	
	char namefile[size];
	std::cin >> namefile;

	FileRead(namefile);
	return 0;
}
