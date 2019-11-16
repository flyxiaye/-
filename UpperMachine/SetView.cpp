// SetView.cpp: 实现文件
//

#include "pch.h"
#include "UpperMachine.h"
#include "SetView.h"

#include "FileInfo.h"
#include "UpperMachineDoc.h"
#include "CDialogPath.h"
#include "ImageHandle.h"


// SetView

IMPLEMENT_DYNCREATE(SetView, CFormView)

SetView::SetView() :CFormView(IDD)
{

}

SetView::~SetView()
{
}

BEGIN_MESSAGE_MAP(SetView, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &SetView::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &SetView::OnBnClickedButton2)
	ON_LBN_SELCHANGE(IDC_LIST1, &SetView::OnLbnSelchangeList1)
END_MESSAGE_MAP()


// SetView 绘图

void SetView::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO:  在此添加绘制代码
}


// SetView 诊断

#ifdef _DEBUG
void SetView::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void SetView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// SetView 消息处理程序


void SetView::DoDataExchange(CDataExchange* pDX)
{
	// TODO: 在此添加专用代码和/或调用基类

	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_listBox);
}


void SetView::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	//刷新目录内容
	//读取路径
	CUpperMachineDoc* pDoc = (CUpperMachineDoc*)GetDocument();
	CString path = pDoc->folderPath;
	using std::vector;
	FileInfo fin(path);
	vector<CString> vec;
	fin.searchFile(vec);
	//显示在ListBox中
	m_listBox.ResetContent();
	for (auto it = vec.begin(); it != vec.end(); it++)
		m_listBox.AddString(*it);
}

#define PATH "path.txt"
void SetView::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	CUpperMachineDoc* pDoc = (CUpperMachineDoc*)GetDocument();
	CString m_path = pDoc->folderPath;
	//设置路径
	CDialogPath dlg_path;
	dlg_path.setPath(m_path);
	dlg_path.DoModal();
	m_path = dlg_path.getPath();
	//保存路径
	ofstream fout(PATH, std::ios_base::out);
	if (fout.is_open())
	{
		CStringA tmp;
		tmp = m_path;
		fout << string(tmp.GetBuffer()) << std::endl;
		fout.close();
	}
	pDoc->folderPath = m_path;
}


void SetView::OnLbnSelchangeList1()
{
	// TODO: 在此添加控件通知处理程序代码
	//列表控件选择触发消息
	CUpperMachineDoc* pDoc = (CUpperMachineDoc*)GetDocument();
	CString& imgPath = pDoc->imagePath;
	CString folderPath = pDoc->folderPath;
	CImage& img = pDoc->image;
	CImage& resImg = pDoc->resImg;
	//切换时显示图片
	int idx = m_listBox.GetCurSel();
	CString fileName;
	m_listBox.GetText(idx, fileName);
	if (!fileName.IsEmpty())
	{
		imgPath = folderPath + "\\" + fileName;

		//加载图片
		img.Destroy();
		resImg.Destroy();
		img.Load(imgPath);
		//处理图片
		ImageHandle ig = ImageHandle(img);
		ig.Handle();
		ig.outPutGrayData(resImg);

		pDoc->UpdateAllViews(NULL);
	}
}
