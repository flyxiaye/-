#pragma once


// PicDown 视图

class PicDown : public CFormView
{
	DECLARE_DYNCREATE(PicDown)

protected:
	PicDown();           // 动态创建所使用的受保护的构造函数
	virtual ~PicDown();
public:
	enum { IDD = IDD_PICDOWN };
public:
	virtual void OnDraw(CDC* pDC);      // 重写以绘制该视图
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	DECLARE_MESSAGE_MAP()
	virtual void DoDataExchange(CDataExchange* pDX);
public:
	CStatic m_picDown;
	virtual void OnUpdate(CView* /*pSender*/, LPARAM /*lHint*/, CObject* /*pHint*/);
};


