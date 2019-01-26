
// ImagePlayer_MFCDlg.h : ͷ�ļ�
//

#pragma once
#include <atlimage.h>

// CImagePlayer_MFCDlg �Ի���
class CImagePlayer_MFCDlg : public CDialogEx
{
// ����
public:
	CImagePlayer_MFCDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_IMAGEPLAYER_MFC_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
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
