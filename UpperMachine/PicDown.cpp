// PicDown.cpp: 实现文件
//

#include "pch.h"
#include "UpperMachine.h"
#include "PicDown.h"
#include "UpperMachineDoc.h"


// PicDown

IMPLEMENT_DYNCREATE(PicDown, CFormView)

PicDown::PicDown():CFormView(IDD)
{

}

PicDown::~PicDown()
{
}

BEGIN_MESSAGE_MAP(PicDown, CFormView)
END_MESSAGE_MAP()


// PicDown 绘图

void PicDown::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO:  在此添加绘制代码
	//CUpperMachineDoc* pDoc = (CUpperMachineDoc*)GetDocument();
	//CString imgPath = pDoc->imagePath;
	//if (!imgPath.IsEmpty())
	//{
	//	CRect rect;
	//	m_picDown.GetClientRect(&rect);	//获取控件区域对象
	//	CImage image;
	//	image.Load(imgPath);
	//	pDC = m_picDown.GetWindowDC();
	//	//显示全部
	//	CRect rc;
	//	CWnd* pWnd = GetDlgItem(IDC_PICDOWN);
	//	pWnd->GetClientRect(&rc);
	//	image.Draw(pDC->m_hDC, rc);
	//	ReleaseDC(pDC);
	//}
}


// PicDown 诊断

#ifdef _DEBUG
void PicDown::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void PicDown::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// PicDown 消息处理程序


void PicDown::DoDataExchange(CDataExchange* pDX)
{
	// TODO: 在此添加专用代码和/或调用基类

	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICDOWN, m_picDown);
}


void PicDown::OnUpdate(CView* /*pSender*/, LPARAM /*lHint*/, CObject* /*pHint*/)
{
	// TODO: 在此添加专用代码和/或调用基类
	CUpperMachineDoc* pDoc = (CUpperMachineDoc*)GetDocument();
	CString imgPath = pDoc->imagePath;
	CImage& img = pDoc->resImg;
	if (!img.IsNull())
	{
		CRect rect;
		m_picDown.GetClientRect(&rect);	//获取控件区域对象
		CDC* pDC = m_picDown.GetWindowDC();
		//显示全部
		CRect rc;
		CWnd* pWnd = GetDlgItem(IDC_PICDOWN);
		pWnd->GetClientRect(&rc);
		img.Draw(pDC->m_hDC, rc);
		ReleaseDC(pDC);
	}
}
