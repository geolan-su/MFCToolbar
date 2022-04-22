#pragma once
#include "afxdialogex.h"


// pressureDlg dialog

class pressureDlg : public CDialogEx
{
	DECLARE_DYNAMIC(pressureDlg)

public:
	pressureDlg(CWnd* pParent = nullptr);   // standard constructor
	virtual ~pressureDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_Pressure_Box };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnIpnFieldchangedIpaddress1(NMHDR* pNMHDR, LRESULT* pResult);
	//DECLARE_MESSAGE_MAP()
	afx_msg void OnEnChangeEdit1();
};
