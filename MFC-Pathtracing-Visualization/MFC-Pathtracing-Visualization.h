
// MFC-Pathtracing-Visualization.h: Hauptheaderdatei für die PROJECT_NAME-Anwendung
//

#pragma once

#ifndef __AFXWIN_H__
	#error "'pch.h' vor dieser Datei für PCH einschließen"
#endif

#include "resource.h"		// Hauptsymbole


// CMFCPathtracingVisualizationApp:
// Siehe MFC-Pathtracing-Visualization.cpp für die Implementierung dieser Klasse
//

class CMFCPathtracingVisualizationApp : public CWinApp
{
public:
	CMFCPathtracingVisualizationApp();

// Überschreibungen
public:
	virtual BOOL InitInstance();

// Implementierung

	DECLARE_MESSAGE_MAP()
};

extern CMFCPathtracingVisualizationApp theApp;
