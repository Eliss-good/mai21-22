#include <iostream>

template <typename T, std::size_t tmx, std::size_t tmy>  	
class Image {
	
	T* img;
	size_t mx;
	size_t my;

	public:

		~Image();
		Image(const Image& v);
		Image();
		int get(unsigned int x,unsigned int y);
		void set(unsigned int x,unsigned int y,unsigned int color);
		void see();

		Image& operator = (const Image& v)
		{
			this->mx = v.mx;
			this->my = v.my;

			if(this->img != nullptr)
			{
				delete[] this->img;
			}

			this->img = new T[v.mx*v.my];

			for(int i = 0; i < v.mx*v.my; i++)
			{
				this->img[i] = v.img[i];
			}

			return *this;
		
		}

		friend bool operator == (Image& imgfist, Image& imgsecond);
};

template <typename T, std::size_t tmx, std::size_t tmy> 
Image<T,tmx,tmy>::Image()
{
    mx = tmx;
    my = tmy;
	img = new T[mx*my]();
}

template <typename T, std::size_t tmx, std::size_t tmy> 
Image<T,tmx,tmy>::Image(const Image<T,tmx,tmy>& v)
{
	img =  new T[tmx*tmy];
			
	for(unsigned int i = 0; i < tmx*tmy; ++i)
	{
	    img[i] = v.img[i];
	}
} 

template <typename T, std::size_t tmx, std::size_t tmy> 
Image<T,tmx,tmy>::~Image()
{
	delete[] img;
}

template <typename T, std::size_t tmx, std::size_t tmy> 
void Image<T,tmx,tmy>::see()
{
	for(unsigned int i = 0; i < tmx*tmy; ++i)
	{
		std::cin >> img[i];
	}
}

template <typename T, std::size_t tmx, std::size_t tmy> 
int Image<T,tmx,tmy>::get(unsigned int x,unsigned int y) 
{
	if(x >= 0 && x < tmx && y >= 0 && y < tmy)
	{
		return img[y*tmy+x];
	}
}

template <typename T, std::size_t tmx, std::size_t tmy> 
void Image<T,tmx,tmy>::set(unsigned int x,unsigned int y,unsigned int color) 
{
    if(x >= 0 && x < tmx && y >= 0 && y < tmy)
	{
		img[y*tmy+x] = color;
	}
}	

template <typename T, std::size_t tmx, std::size_t tmy> 
bool operator == (Image<T,tmx,tmy>& imgfirst, Image<T,tmx,tmy>& imgsecond)
{
    return (imgfirst.tmx == imgsecond.tmx && imgfirst.tmy == imgsecond.tmy);
}



int main(){
	Image<int,8,8> img1;
    Image<int,8,8> img2;
    if (img1 == img2)
        std::cout << "The Images have the same format" << '\n';
    
    img1.set(4, 4, 245);
    img2.set(3, 3, 124);

    img1.get(4, 4);
    img2.get(3, 3);

    img1.see();
    std::cout << std::endl;
    img2.see();

}