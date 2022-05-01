
// MFCApplication1Dlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "MFCApplication1.h"
#include "MFCApplication1Dlg.h"
#include "afxdialogex.h"
#include "stdlib.h"
#include <iostream>
#include <cstring>


#ifdef _DEBUG
#define new DEBUG_NEW
#endif

using namespace std;


// CMFCApplication1Dlg dialog



CMFCApplication1Dlg::CMFCApplication1Dlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_MFCAPPLICATION1_DIALOG, pParent)
	, E1(_T(""))
	, E2(_T(""))
	, E3(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	
}

void CMFCApplication1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, E1);
	DDX_Text(pDX, IDC_EDIT2, E2);
	SetWindowTextW(L"CompressionStringVarApp");
	DDX_Text(pDX, IDC_EDIT3, E3);
}

BEGIN_MESSAGE_MAP(CMFCApplication1Dlg, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCApplication1Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFCApplication1Dlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// CMFCApplication1Dlg message handlers

BOOL CMFCApplication1Dlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMFCApplication1Dlg::OnPaint()
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
		CDialog::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMFCApplication1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCApplication1Dlg::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here

	input = "";
	ms = "";
	t = "";
	UpdateData(true);
		input = E1;
	UpdateData(false);
	counter = 1;
	for (int i = 0; i < input.GetLength(); i++)
	{
		if (input[i] == input[i + 1]) { counter++; }
		else {
			t.Format(L"%d", counter);
			ms += input[i];
			if(counter>1)ms += t;
			counter = 1;
		}
	}


	UpdateData(true);
	E2 = ms;
	UpdateData(false);

}


void CMFCApplication1Dlg::OnBnClickedButton2()
{
	// TODO: Add your control notification handler code here
	ms = "";
	t = "";

	UpdateData(true);
	input = E1;
	UpdateData(false);

	for (int i = 0; i < input.GetLength(); i++)
	{

		if (!(48 <= (int)input[i] && (int)input[i] <= 57)) { t += input[i]; fg1 = true; }
		if (48 <= (int)input[i] && (int)input[i] <= 57) { counter_string += input[i]; }
		if (fg1 == true && !(48 <= (int)input[i + 1] && (int)input[i + 1] <= 57)) {
			if (counter_string.GetLength() > 0)counter = _ttoi(counter_string);
			for (int j = 0; j < counter; j++)
			{
				ms+= t;
			}
			fg1 = false;
			counter_string = "";
			t = "";
			counter = 1;
		}

	}


	UpdateData(true);
	E3 = ms;
	UpdateData(false);

}
