#pragma once


// PicUp 视图

class PicUp : public CFormView
{
	DECLARE_DYNCREATE(PicUp)

protected:
	PicUp();           // 动态创建所使用的受保护的构造函数
	virtual ~PicUp();
public:
	enum { IDD = IDD_PICUP };
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
	CStatic m_picUp;
	virtual void OnUpdate(CView* /*pSender*/, LPARAM /*lHint*/, CObject* /*pHint*/);
//	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
//	afx_msg void OnSize(UINT nType, int cx, int cy);
//	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnSize(UINT nType, int cx, int cy);
};


