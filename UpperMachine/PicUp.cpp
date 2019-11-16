// PicUp.cpp: 实现文件
//

#include "pch.h"
#include "UpperMachine.h"
#include "PicUp.h"

#include "UpperMachineDoc.h"

// PicUp

IMPLEMENT_DYNCREATE(PicUp, CFormView)

PicUp::PicUp() :CFormView(IDD)
{

}

PicUp::~PicUp()
{
}

BEGIN_MESSAGE_MAP(PicUp, CFormView)
//	ON_WM_CREATE()
//	ON_WM_SIZE()
//	ON_WM_TIMER()
ON_WM_SIZE()
END_MESSAGE_MAP()


// PicUp 绘图

void PicUp::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO:  在此添加绘制代码
	//CUpperMachineDoc* pDoc = (CUpperMachineDoc*)GetDocument();
	//CString imgPath = pDoc->imagePath;
	//if (!imgPath.IsEmpty())
	//{
	//	CRect rect;
	//	m_picUp.GetClientRect(&rect);	//获取控件区域对象
	//	CImage image;
	//	image.Load(imgPath);
	//	pDC = m_picUp.GetWindowDC();
	//	//显示全部
	//	CRect rc;
	//	CWnd* pWnd = GetDlgItem(IDC_PICUP);
	//	pWnd->GetClientRect(&rc);
	//	image.Draw(pDC->m_hDC, rc);
	//	ReleaseDC(pDC);
	//}
}


// PicUp 诊断

#ifdef _DEBUG
void PicUp::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void PicUp::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// PicUp 消息处理程序


void PicUp::DoDataExchange(CDataExchange* pDX)
{
	// TODO: 在此添加专用代码和/或调用基类

	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICUP, m_picUp);
}


void PicUp::OnUpdate(CView* /*pSender*/, LPARAM /*lHint*/, CObject* /*pHint*/)
{
	// TODO: 在此添加专用代码和/或调用基类
	CUpperMachineDoc* pDoc = (CUpperMachineDoc*)GetDocument();
	CString imgPath = pDoc->imagePath;
	CImage& img = pDoc->image;
	if (!img.IsNull())
	{
		CRect rect;
		m_picUp.GetClientRect(&rect);	//获取控件区域对象
		CDC* pDC = m_picUp.GetWindowDC();
		//显示全部
		CRect rc;
		CWnd* pWnd = GetDlgItem(IDC_PICUP);
		pWnd->GetClientRect(&rc);
		img.Draw(pDC->m_hDC, rc);
		ReleaseDC(pDC);
	}
}


//int PicUp::OnCreate(LPCREATESTRUCT lpCreateStruct)
//{
//	if (CFormView::OnCreate(lpCreateStruct) == -1)
//		return -1;
//
//	// TODO:  在此添加您专用的创建代码
//	SetTimer(0, 100, NULL);
//	return 0;
//}


//void PicUp::OnSize(UINT nType, int cx, int cy)
//{
//	
//	
//	CFormView::OnSize(nType, cx, cy);
//
//	// TODO: 在此处添加消息处理程序代码
//}


//void PicUp::OnTimer(UINT_PTR nIDEvent)
//{
//	// TODO: 在此添加消息处理程序代码和/或调用默认值
//	Invalidate(FALSE);
//	CFormView::OnTimer(nIDEvent);
//}


void PicUp::OnSize(UINT nType, int cx, int cy)
{
	CFormView::OnSize(nType, cx, cy);
	// TODO: 在此处添加消息处理程序代码
}
