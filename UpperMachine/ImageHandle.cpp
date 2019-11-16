#include "pch.h"
#include "ImageHandle.h"


ImageHandle::ImageHandle(CImage& img)
{
	name = TEXT("DLLExperience.dll");
	//name = TEXT("get_eage_canny_.dll");
	width = img.GetWidth();
	height = img.GetHeight();
	bit = img.GetBPP();
	int size = width * height * bit / 8;
	pData = new unsigned char[size];
	BYTE* p = NULL;
	if (img.GetPitch() < 0)
		p = (BYTE*)img.GetBits() + (img.GetPitch() * (img.GetHeight() - 1));
	else p = (BYTE*)img.GetBits();
	memcpy_s(pData, size, p, size);
}

ImageHandle::~ImageHandle()
{
	delete[] pData;
}

void ImageHandle::Handle()
{
	HINSTANCE hInst;
	hInst = LoadLibrary(name);
	typedef void(*Sub)(unsigned char*);//函数指针
	Sub funHandle = (Sub)GetProcAddress(hInst, "ImageHandle");//从dll中加载函数出来

	funHandle(pData);//运行函数

	FreeLibrary(hInst);       //LoadLibrary后要记得FreeLibrary
}

void ImageHandle::outPutGrayData(CImage& dstImg)
{
	dstImg.Create(width, height, 24);

	BYTE* pImg = NULL;
	if (dstImg.GetPitch() < 0)
		pImg = (BYTE*)dstImg.GetBits() + (dstImg.GetPitch() * (dstImg.GetHeight() - 1));
	else pImg = (BYTE*)dstImg.GetBits();
	for (int i = 0; i < 188 * 120; i++)
	{

		*(pImg + i * 3) = *(pData + i);
		*(pImg + i * 3 + 1) = *(pData + i);
		*(pImg + i * 3 + 2) = *(pData + i);
		if (*(pData + i) == 128)
		{
			*(pImg + i * 3) = 0;
			*(pImg + i * 3 + 1) = 0;
			*(pImg + i * 3 + 2) = 255;
		}
		else if (*(pData + i) == 100)
		{
			*(pImg + i * 3) = 0;
			*(pImg + i * 3 + 1) = 255;
			*(pImg + i * 3 + 2) = 0;
		}
		else if (*(pData + i) == 254)
		{
			*(pImg + i * 3) = 255;
			*(pImg + i * 3 + 1) = 0;
			*(pImg + i * 3 + 2) = 0;
		}
	}
}



