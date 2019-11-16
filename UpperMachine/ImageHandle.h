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
	void outPutGrayData(CImage& dstImg);		//�����Ҷ�ͼ����
	void outPutRGB565Data(CImage& dstImg);		//����RGB565����
};

