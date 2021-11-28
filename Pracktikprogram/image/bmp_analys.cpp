#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string>
#include <cstring>

using namespace std;

struct BITMAPFILEHEADER
{
    unsigned int    bfType;
    unsigned long   bfSize;
    unsigned int    bfReserved1;
    unsigned int    bfReserved2;
    unsigned long   bfOffBits;
};

struct BITMAPINFOHEADER
{
    unsigned int    biSize;
    int             biWidth;
    int             biHeight;
    unsigned short  biPlanes;
    unsigned short  biBitCount;
    unsigned int    biCompression;
    unsigned int    biSizeImage;
    int             biXPelsPerMeter;
    int             biYPelsPerMeter;
    unsigned int    biClrUsed;
    unsigned int    biClrImportant;
};

struct RGBQUAD
{
    int   rgbBlue;
    int   rgbGreen;
    int   rgbRed;
    int   rgbReserved;
};


static unsigned short read_u16(FILE* fp)
{
    unsigned char b0, b1;

    b0 = getc(fp);
    b1 = getc(fp);

    return ((b1 << 8) | b0);
}


static unsigned int read_u32(FILE* fp)
{
    unsigned char b0, b1, b2, b3;

    b0 = getc(fp);
    b1 = getc(fp);
    b2 = getc(fp);
    b3 = getc(fp);

    return ((((((b3 << 8) | b2) << 8) | b1) << 8) | b0);
}


static int read_s32(FILE* fp)
{
    unsigned char b0, b1, b2, b3;

    b0 = getc(fp);
    b1 = getc(fp);
    b2 = getc(fp);
    b3 = getc(fp);

    return (static_cast<int>((((((b3 << 8) | b2) << 8) | b1) << 8) | b0));
}

uint32_t sizearrW(std::string namefile)
{
    char NF[namefile.size()];
    strcpy(NF,namefile.c_str());

    FILE* pFile = fopen(NF, "rb");
    
    BITMAPFILEHEADER header;
    header.bfType = read_u16(pFile);
    header.bfSize = read_u32(pFile);
    header.bfReserved1 = read_u16(pFile);
    header.bfReserved2 = read_u16(pFile);
    header.bfOffBits = read_u32(pFile);

    BITMAPINFOHEADER bmiHeader;

    bmiHeader.biSize = read_u32(pFile);
    bmiHeader.biWidth = read_s32(pFile);
    bmiHeader.biHeight = read_s32(pFile);
    bmiHeader.biPlanes = read_u16(pFile);
    bmiHeader.biBitCount = read_u16(pFile);
    bmiHeader.biCompression = read_u32(pFile);
    bmiHeader.biSizeImage = read_u32(pFile);
    bmiHeader.biXPelsPerMeter = read_s32(pFile);
    bmiHeader.biYPelsPerMeter = read_s32(pFile);
    bmiHeader.biClrUsed = read_u32(pFile);
    bmiHeader.biClrImportant = read_u32(pFile);
   
    return static_cast<uint32_t>(bmiHeader.biWidth);
}

uint32_t sizearrH(std::string namefile)
{
    char NF[namefile.size()];
    strcpy(NF,namefile.c_str());

    FILE* pFile = fopen(NF, "rb");

    BITMAPFILEHEADER header;
    header.bfType = read_u16(pFile);
    header.bfSize = read_u32(pFile);
    header.bfReserved1 = read_u16(pFile);
    header.bfReserved2 = read_u16(pFile);
    header.bfOffBits = read_u32(pFile);

    BITMAPINFOHEADER bmiHeader;

    bmiHeader.biSize = read_u32(pFile);
    bmiHeader.biWidth = read_s32(pFile);
    bmiHeader.biHeight = read_s32(pFile);
    bmiHeader.biPlanes = read_u16(pFile);
    bmiHeader.biBitCount = read_u16(pFile);
    bmiHeader.biCompression = read_u32(pFile);
    bmiHeader.biSizeImage = read_u32(pFile);
    bmiHeader.biXPelsPerMeter = read_s32(pFile);
    bmiHeader.biYPelsPerMeter = read_s32(pFile);
    bmiHeader.biClrUsed = read_u32(pFile);
    bmiHeader.biClrImportant = read_u32(pFile);

    return static_cast<uint32_t>(bmiHeader.biHeight);
}

uint32_t** parsbmp(std::string namefile)
{
    char NF[namefile.size()];
    strcpy(NF,namefile.c_str());

    FILE* pFile = fopen(NF, "rb"); 

    BITMAPFILEHEADER header;

    header.bfType = read_u16(pFile);
    header.bfSize = read_u32(pFile);
    header.bfReserved1 = read_u16(pFile);
    header.bfReserved2 = read_u16(pFile);
    header.bfOffBits = read_u32(pFile);

    BITMAPINFOHEADER bmiHeader;

    bmiHeader.biSize = read_u32(pFile);
    bmiHeader.biWidth = read_s32(pFile);
    bmiHeader.biHeight = read_s32(pFile);
    bmiHeader.biPlanes = read_u16(pFile);
    bmiHeader.biBitCount = read_u16(pFile);
    bmiHeader.biCompression = read_u32(pFile);
    bmiHeader.biSizeImage = read_u32(pFile);
    bmiHeader.biXPelsPerMeter = read_s32(pFile);
    bmiHeader.biYPelsPerMeter = read_s32(pFile);
    bmiHeader.biClrUsed = read_u32(pFile);
    bmiHeader.biClrImportant = read_u32(pFile);

    RGBQUAD** rgb = new RGBQUAD * [bmiHeader.biWidth];
    for (int i = 0; i < bmiHeader.biWidth; i++) {
        rgb[i] = new RGBQUAD[bmiHeader.biHeight];
    }

    uint32_t** colors = new uint32_t * [bmiHeader.biWidth];
    for (int i = 0; i < bmiHeader.biWidth; i++) {
        colors[i] = new uint32_t[bmiHeader.biHeight];
    }

    for (int i = 0; i < bmiHeader.biWidth; i++) {
        for (int j = 0; j < bmiHeader.biHeight; j++) {
            rgb[i][j].rgbBlue = getc(pFile);
            rgb[i][j].rgbGreen = getc(pFile);
            rgb[i][j].rgbRed = getc(pFile);
            colors[i][j] = rgb[i][j].rgbBlue + (rgb[i][j].rgbGreen << 8) + (rgb[i][j].rgbRed << 16);
        }
        getc(pFile);
    }
    fclose(pFile);

    delete[] rgb;

    return colors;
}
