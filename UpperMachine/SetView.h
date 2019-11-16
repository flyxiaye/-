#pragma once


// SetView 视图

class SetView : public CFormView
{
	DECLARE_DYNCREATE(SetView)

protected:
	SetView();           // 动态创建所使用的受保护的构造函数
	virtual ~SetView();
public:
	enum { IDD = IDD_SETTING };
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
private:
	CListBox m_listBox;
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnLbnSelchangeList1();
};


