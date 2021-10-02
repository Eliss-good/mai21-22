#include <iostream>

class Image {
	
	int* img;
	int mx,
	int my;

	public:

		Image(int tmx, int tmy):mx(tmx),my(tmy)
		{
			img = new int[mx*my]();
		}

		Image(const Image& v) : mx(v.mx), my(v.my) img(nullptr)
		{
			img =  new int[mx*my];
			
			for(int i = 0; i < mx*my; ++i)
			{
				img[i] = v.img[i];
			}
		} 

		Image& operator = (const Image& v)
		{
			this->mx = v.mx;
			this->my = v.my;

			if(this->img != nullptr)
			{
				delete[] this->img;
			}

			this->img = new int[v.mx*v.my];

			for(int i = 0; i < v.mx*v.my; i++)
			{
				this->img[i] = v.img[i];
			}

			return *this;
		
		}

		vitual ~Image()
		{
			delete[] img;
		}

		int get(int x,int y);
		void set(int x,int y,int color);
		void see(const Image& v);

		friend bool operator == (Image &arrInt, Image &arrInt2);
};

void Image::see(const Image& v)
{
	for(int i = 0; i < v.mx * v.my; ++i)
	{
		std::cin >> v.img[i];
	}
}

int Image::get(int x,int y) 
{
	if(x >= 0 && x < mx && y >= 0 && y < my)
	{
		return img[y*my+x];
	}
}

void Image::set(int x,int y,int color) 
{
    if(x >= 0 && x < mx && y >= 0 && y < my)
	{
		img[y*my+x] = color;
	}
}

bool operator == (Image& arrInt, Image& arrInt2)
{
    return (arrInt.mx == arrInt2.mx && arrInt.my == arrInt2.my);
}



int main(){
	Image img1(8, 8);
    Image img2(8, 8);
    if (img1 == img2)
        std::cout << "The Images have the same format" << endl;
    
    img1.set(4, 4, 245);
    img2.set(3, 3, 124);

    img1.get(4, 4);
    img2.get(3, 3);

    img1.see();
    std::cout << std::endl;
    img2.see();

}