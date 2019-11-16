// MyTextView.cpp: 实现文件
//

#include "pch.h"
#include "UpperMachine.h"
#include "MyTextView.h"


// MyTextView

IMPLEMENT_DYNCREATE(MyTextView, CEditView)

MyTextView::MyTextView()
{

}

MyTextView::~MyTextView()
{
}

BEGIN_MESSAGE_MAP(MyTextView, CEditView)
END_MESSAGE_MAP()


// MyTextView 诊断

#ifdef _DEBUG
void MyTextView::AssertValid() const
{
	CEditView::AssertValid();
}

#ifndef _WIN32_WCE
void MyTextView::Dump(CDumpContext& dc) const
{
	CEditView::Dump(dc);
}
#endif
#endif //_DEBUG


// MyTextView 消息处理程序
