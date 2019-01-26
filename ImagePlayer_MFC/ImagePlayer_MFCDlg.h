
// ImagePlayer_MFCDlg.h : 头文件
//

#pragma once
#include <atlimage.h>

// CImagePlayer_MFCDlg 对话框
class CImagePlayer_MFCDlg : public CDialogEx
{
// 构造
public:
	CImagePlayer_MFCDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_IMAGEPLAYER_MFC_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg LRESULT OnNcHitTest(CPoint point);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);

	wchar_t	m_imagePath[MAX_PATH];
	CImage	m_img;
	HDC		m_hDC;
	afx_msg void OnDestroy();
	afx_msg void OnSize(UINT nType, int cx, int cy);
};
