
// 上位机开发View.cpp: C上位机开发View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "上位机开发.h"
#endif

#include "上位机开发Doc.h"
#include "上位机开发View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C上位机开发View

IMPLEMENT_DYNCREATE(C上位机开发View, CView)

BEGIN_MESSAGE_MAP(C上位机开发View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &C上位机开发View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// C上位机开发View 构造/析构

C上位机开发View::C上位机开发View() noexcept
{
	// TODO: 在此处添加构造代码

}

C上位机开发View::~C上位机开发View()
{
}

BOOL C上位机开发View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// C上位机开发View 绘图

void C上位机开发View::OnDraw(CDC* /*pDC*/)
{
	C上位机开发Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// C上位机开发View 打印


void C上位机开发View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL C上位机开发View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void C上位机开发View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void C上位机开发View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}

void C上位机开发View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void C上位机开发View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// C上位机开发View 诊断

#ifdef _DEBUG
void C上位机开发View::AssertValid() const
{
	CView::AssertValid();
}

void C上位机开发View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C上位机开发Doc* C上位机开发View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C上位机开发Doc)));
	return (C上位机开发Doc*)m_pDocument;
}
#endif //_DEBUG


// C上位机开发View 消息处理程序
