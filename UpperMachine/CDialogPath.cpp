// CDialogPath.cpp: 实现文件
//

#include "pch.h"
#include "UpperMachine.h"
#include "CDialogPath.h"
#include "afxdialogex.h"

#include "UpperMachineDoc.h"
// CDialogPath 对话框

IMPLEMENT_DYNAMIC(CDialogPath, CDialogEx)

CDialogPath::CDialogPath(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_PATH, pParent)
	, m_path(_T(""))
{

}

CDialogPath::~CDialogPath()
{
}

void CDialogPath::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_path);
}


BEGIN_MESSAGE_MAP(CDialogPath, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON3, &CDialogPath::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON1, &CDialogPath::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON4, &CDialogPath::OnBnClickedButton4)
END_MESSAGE_MAP()


void CDialogPath::setPath(CString path)
{
	m_path = path;
	//UpdateData(FALSE);
}

CString CDialogPath::getPath()
{
	return m_path;
}

// CDialogPath 消息处理程序



void CDialogPath::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	//确认路径
	UpdateData(TRUE);
	OnOK();
}


void CDialogPath::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	OnCancel();
}


void CDialogPath::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码
	//选择路径
	BROWSEINFO bi;
	ZeroMemory(&bi, sizeof(BROWSEINFO));
	bi.hwndOwner = m_hWnd;
	bi.ulFlags = BIF_RETURNONLYFSDIRS;
	LPITEMIDLIST pidl = SHBrowseForFolder(&bi);
	BOOL bRet = FALSE;
	TCHAR szFolder[MAX_PATH * 2];
	szFolder[0] = _T('/0');
	if (pidl)
	{
		if (SHGetPathFromIDList(pidl, szFolder))
			bRet = TRUE;
		IMalloc* pMalloc = NULL;
		if (SUCCEEDED(SHGetMalloc(&pMalloc)) && pMalloc)
		{
			pMalloc->Free(pidl);
			pMalloc->Release();
		}
		m_path = szFolder;//选择的文件夹路径 
	}
	UpdateData(FALSE);
}
