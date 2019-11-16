#pragma once


// MyTextView 视图

class MyTextView : public CEditView
{
	DECLARE_DYNCREATE(MyTextView)

protected:
	MyTextView();           // 动态创建所使用的受保护的构造函数
	virtual ~MyTextView();

public:
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	DECLARE_MESSAGE_MAP()
};


