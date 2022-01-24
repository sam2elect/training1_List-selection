
// training1Dlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "training1.h"
#include "training1Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// Ctraining1Dlg dialog



Ctraining1Dlg::Ctraining1Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_TRAINING1_DIALOG, pParent)
	, input1(0)
	, input2(0)
	, m_strSymbol(_T(""))
	, total(_T(""))
	, initial(_T(""))
	, result(_T(""))
	, output(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void Ctraining1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO_operation, ctrloperation);
	DDX_Text(pDX, IDC_EDIT1_input1, input1);
	DDX_Text(pDX, IDC_EDIT1_input2, input2);
	DDX_Text(pDX, IDC_STATIC_SYMBOL, m_strSymbol);
	DDX_Text(pDX, IDC_STATICtotal, total);
	DDX_Text(pDX, IDC_STATICiniial, initial);
	DDX_Text(pDX, IDC_STATICresult, result);
	DDX_Text(pDX, IDC_EDIT1_output, output);
}

BEGIN_MESSAGE_MAP(Ctraining1Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1_calculate, &Ctraining1Dlg::OnBnClickedButton1calculate)
	ON_CBN_SELCHANGE(IDC_COMBO_operation, &Ctraining1Dlg::OnCbnSelchangeCombooperation)
	ON_BN_CLICKED(IDOK, &Ctraining1Dlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &Ctraining1Dlg::OnBnClickedCancel)
END_MESSAGE_MAP()


// Ctraining1Dlg message handlers

BOOL Ctraining1Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void Ctraining1Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void Ctraining1Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR Ctraining1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void Ctraining1Dlg::OnBnClickedButton1calculate()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	int select = ctrloperation.GetCurSel();
	if (select == 0)
	{
		output = input1 * input2;
	}
	else if (select == 1)
	{
		output = (input1 * input2)/2;
	}
	else if (select == 2)
	{
		output = (input1 / input2)*100;
	}
	else if (select == 3)
	{
		output = (input1 / input2) * 100;
	}
	else if (select == 4)
	{
		output = (input1 / input2) * 100;
	}
	else if (select == 5)
	{
		output = input1 / input2;
	}
	else if (select == 6)
	{
		output = input1 / input2;
	}
	else if (select == 7)
	{
		output = input1 / input2;
	}
	else if (select == 8)
	{
		output = input1 / input2;
	}
	UpdateData(FALSE);
}


void Ctraining1Dlg::OnCbnSelchangeCombooperation()
{
	// TODO: Add your control notification handler code here
	int select = ctrloperation.GetCurSel();
	if (select == 0)
	{
		m_strSymbol = "Rectangle";
			total = "Length";
			initial = "Breadth";
			result = "Area";
	}
	else if (select == 1)
	{
		m_strSymbol = "Triangle";
		total = "Base";
		initial = "height";
		result = "Area";
	}
	else if (select == 2)
	{
		m_strSymbol = "CovidVirus";
		total = "Total patients";
		initial = "patients_Dead";
		result = "Mortality_rate";
	}
	else if (select == 3)
	{
		m_strSymbol = "HivVirus";
		total = "Total patients";
		initial = "patients_Dead";
		result = "Mortality_rate";
	}
	else if (select == 4)
	{
		m_strSymbol = "BirdFlue";
		total = "Total patients";
		initial = "patients_Dead";
		result = "Mortality_rate";
	}
	else if (select == 5)
	{
		m_strSymbol = "InternalCombustineEngine ";
		total = "Engine_Output";
		initial = "Engine_input";
		result = "Efficiency";
	}
	else if (select == 6)
	{
		m_strSymbol = "ExternalCombustineEngine ";
		total = "Engine_Output";
		initial = "Engine_Input";
		result = "Efficiency";
	}
	else if (select == 7)
	{
		m_strSymbol = "PetrolEngine ";
		total = "Engine_Output";
		initial = "Engine_Input";
		result = "Efficiency";
	}
	else if (select == 8)
	{
		m_strSymbol = "SteamEngine ";
		total = "Engine_Output";
		initial = "Engine_Input";
		result = "Efficiency";
	}
	UpdateData(FALSE);
}




void Ctraining1Dlg::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	CDialogEx::OnOK();
}


void Ctraining1Dlg::OnBnClickedCancel()
{
	// TODO: Add your control notification handler code here
	CDialogEx::OnCancel();
}
