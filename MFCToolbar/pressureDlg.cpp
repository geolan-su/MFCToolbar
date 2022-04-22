// pressureDlg.cpp : implementation file
//

#include "pch.h"
#include "MFCToolbar.h"
#include "afxdialogex.h"
#include "pressureDlg.h"


// pressureDlg dialog

IMPLEMENT_DYNAMIC(pressureDlg, CDialogEx)

pressureDlg::pressureDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_Pressure_Box, pParent)
{

}

pressureDlg::~pressureDlg()
{
}

void pressureDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}



// pressureDlg message handlers


void pressureDlg::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	CDialogEx::OnOK();
}

BEGIN_MESSAGE_MAP(pressureDlg, CDialogEx)
	ON_EN_CHANGE(IDC_EDIT1, &pressureDlg::OnEnChangeEdit1)
END_MESSAGE_MAP()


void pressureDlg::OnEnChangeEdit1()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}
