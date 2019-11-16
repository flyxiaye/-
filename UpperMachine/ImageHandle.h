#pragma once
class ImageHandle
{
public:
	CString name; 
	BYTE* pData;
	int width;
	int height;
	int bit;
public:
	ImageHandle() { pData = NULL; }
	ImageHandle(CImage& img);
	~ImageHandle();
	//void getCImage(CImage& img);
	void Handle();
	void outPutGrayData(CImage& dstImg);		//导出灰度图数据
	void outPutRGB565Data(CImage& dstImg);		//导出RGB565数据
};

