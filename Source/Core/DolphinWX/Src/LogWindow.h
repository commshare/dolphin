// Copyright (C) 2003-2008 Dolphin Project.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, version 2.0.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License 2.0 for more details.

// A copy of the GPL 2.0 should have been included with the program.
// If not, see http://www.gnu.org/licenses/

// Official SVN repository and contact information can be found at
// http://code.google.com/p/dolphin-emu/

#ifndef LOGWINDOW_H_
#define LOGWINDOW_H_
#include "Main.h" // for wxGetApp
#include "LogManager.h"
#include "IniFile.h"
#include <queue>

enum
{
    IDM_LOG,
    IDM_CLEARLOG,
    IDM_LOGCHECKS,
    IDM_OPTIONS,
    IDM_TOGGLEALL,
    IDM_WRITEFILE,
    IDM_WRITECONSOLE,
	IDTM_UPDATELOG,
	IDM_VERBOSITY,
    IDM_SUBMITCMD
};

class wxTextCtrl;
class wxCheckListBox;
class wxString;

class CLogWindow : public wxDialog,Listener
{
public:
	CLogWindow(wxWindow* parent);
	~CLogWindow();
	void NotifyUpdate();

	void SaveSettings();
	void LoadSettings();
	void Log(LogTypes::LOG_LEVELS, const char *text);

private:
	wxTextCtrl* m_log, * m_cmdline;
	bool m_writeFile, m_writeConsole;
	wxCheckBox* m_writeFileCB, * m_writeConsoleCB;
	wxTimer *m_logTimer;
	wxCheckListBox* m_checks;
	wxRadioBox *m_verbosity;
	FileLogListener *m_fileLog;
	ConsoleListener *m_console;
	LogManager *m_logManager;
	std::queue<std::pair<u8, wxString> > msgQueue;

	DECLARE_EVENT_TABLE()

	void CreateGUIControls();
	void OnSubmit(wxCommandEvent& event);
	void OnOptionsCheck(wxCommandEvent& event);
	void OnLogCheck(wxCommandEvent& event);
	void OnClear(wxCommandEvent& event);
	void OnToggleAll(wxCommandEvent& event);
	void OnLogTimer(wxTimerEvent& WXUNUSED(event));

	void UpdateChecks();
	void UpdateLog();

};

#endif /*LOGWINDOW_H_*/
