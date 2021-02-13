
// MFC-Pathtracing-VisualizationDlg.h: Headerdatei
//

#pragma once


// CMFCPathtracingVisualizationDlg-Dialogfeld
class CMFCPathtracingVisualizationDlg : public CDialogEx
{
// Konstruktion
public:
	CMFCPathtracingVisualizationDlg(CWnd* pParent = nullptr);	// Standardkonstruktor

// Dialogfelddaten
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCPATHTRACINGVISUALIZATION_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV-Unterstützung


// Implementierung
protected:
	HICON m_hIcon;

	// Generierte Funktionen für die Meldungstabellen
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
};
