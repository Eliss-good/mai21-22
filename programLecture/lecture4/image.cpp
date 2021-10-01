#include <iostream>

class Image {
	int* img;
	int mx,
	int my;

	public:
		Image(int tmx, int tmy):mx(tmx),my(tmy){
			img = new int[mx*my]();
		}
		Image(const Image& v); // Реализовать
		Image operator = (const Image& v) // Реализовать
		vitual ~Image();// Реализовать
		int get(int x,int y) {return img[y*my+x];} // Добавить обработку ошибок при помощи исключений
		int set(int x,int y,int color) {// Добавить обработку ошибок при помощи исключений
			img[y*my+x]=color;
		}
		friend std::ostream& operator<<(std::ostream& out, const Image &d1); // Реализовать
		friend bool operator ==(Image &arrInt, Image &arrInt2 );
		// Реализовать

int main(){

}