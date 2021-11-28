#ifndef BMP_ANALYS_H
#define BMP_ANALYS_H

static unsigned short read_u16(FILE* fp);
static unsigned int   read_u32(FILE* fp);
static int            read_s32(FILE* fp);

struct BITMAPFILEHEADER;
struct BITMAPINFOHEADER;
struct RGBQUAD;

uint32_t sizearrH(std::string namefile);
uint32_t sizearrW(std::string namefile);
uint32_t** parsbmp(std::string namefile);

#include "bmp_analys.cpp"
#endif