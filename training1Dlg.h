
// training1Dlg.h : header file
//

#pragma once


// Ctraining1Dlg dialog
class Ctraining1Dlg : public CDialogEx
{
// Construction
public:
	Ctraining1Dlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TRAINING1_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CComboBox ctrloperation;
	int input1;
	int input2;
	afx_msg void OnBnClickedButton1calculate();
	afx_msg void OnCbnSelchangeCombooperation();
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	CString m_strSymbol;
	CString total;
	CString initial;
	CString result;
	double output;
};
