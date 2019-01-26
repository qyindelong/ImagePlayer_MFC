
// ImagePlayer_MFCDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "ImagePlayer_MFC.h"
#include "ImagePlayer_MFCDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CImagePlayer_MFCDlg 对话框
CImagePlayer_MFCDlg::CImagePlayer_MFCDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CImagePlayer_MFCDlg::IDD, pParent)
	, m_hDC(nullptr)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CImagePlayer_MFCDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CImagePlayer_MFCDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_NCHITTEST()
	ON_WM_ERASEBKGND()
	ON_WM_DESTROY()
	ON_WM_SIZE()
END_MESSAGE_MAP()


// CImagePlayer_MFCDlg 消息处理程序

BOOL CImagePlayer_MFCDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标


	wchar_t modulePath[MAX_PATH];
	::GetModuleFileName(nullptr, modulePath, MAX_PATH);
	::PathRemoveFileSpec(modulePath);
	wchar_t iniPath[MAX_PATH];
	::wcsncpy_s(iniPath, modulePath, _TRUNCATE);
	::wcscat_s(iniPath, L"\\config.ini");

	//::

	::GetPrivateProfileString(L"Config", L"image_path", L"", m_imagePath, MAX_PATH, iniPath);
	OutputDebugString(m_imagePath);
	// TODO: 在此添加额外的初始化代码
	m_hDC = ::GetDC(GetSafeHwnd());

	wchar_t imgPath[MAX_PATH];
	::wcsncpy_s(imgPath, modulePath, _TRUNCATE);
	::wcscat_s(imgPath, L"\\1.jpg");
	if (m_img.Load(imgPath) != S_OK){
		OutputDebugStringA("load image failed\n");
	}

	::SetWindowPos(GetSafeHwnd(), HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE|SWP_SHOWWINDOW|SWP_NOSIZE);
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CImagePlayer_MFCDlg::OnPaint()
{

// 	if (IsIconic())
// 	{
// 		CPaintDC dc(this); // 用于绘制的设备上下文
// 
// 		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);
// 
// 		// 使图标在工作区矩形中居中
// 		int cxIcon = GetSystemMetrics(SM_CXICON);
// 		int cyIcon = GetSystemMetrics(SM_CYICON);
// 		CRect rect;
// 		GetClientRect(&rect);
// 		int x = (rect.Width() - cxIcon + 1) / 2;
// 		int y = (rect.Height() - cyIcon + 1) / 2;
// 
// 		// 绘制图标
// 		dc.DrawIcon(x, y, m_hIcon);
// 	}
// 	else
// 	{
// 		CDialogEx::OnPaint();
// 	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CImagePlayer_MFCDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

LRESULT CImagePlayer_MFCDlg::OnNcHitTest(CPoint point)
{	
	CRect rect;
	::GetWindowRect(GetSafeHwnd(), &rect);
	CRect rectBR(rect.right - 5, rect.bottom - 5, rect.right, rect.bottom);
	if (rectBR.PtInRect(point)){
		return HTBOTTOMRIGHT;
	}
	return HTCAPTION;
}


BOOL CImagePlayer_MFCDlg::OnEraseBkgnd(CDC* pDC)
{
	if (m_hDC != nullptr && m_img.IsNull() != TRUE){
		CRect rect;
		::GetClientRect(GetSafeHwnd(), &rect);

		FillRect(m_hDC, rect, CBrush(RGB(255, 255, 255)));

		CRect drawRect(0, 0, 0, 0);
		if (m_img.GetWidth() * rect.Height() > m_img.GetHeight() * rect.Width())
		{
			drawRect.right = rect.right;
			drawRect.bottom = m_img.GetHeight() * rect.Width() / m_img.GetWidth();
		}
		else
		{
			drawRect.bottom = rect.bottom;
			drawRect.right = m_img.GetWidth() * rect.Height() / m_img.GetHeight();
		}



		m_img.Draw(m_hDC, drawRect);
	}
	return TRUE;
}

void CImagePlayer_MFCDlg::OnDestroy()
{
	CDialogEx::OnDestroy();

	// TODO: 在此处添加消息处理程序代码
	::ReleaseDC(GetSafeHwnd(), m_hDC);
	m_hDC = nullptr;
}


void CImagePlayer_MFCDlg::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);

	// TODO:  在此处添加消息处理程序代码
	UpdateWindow();
}
