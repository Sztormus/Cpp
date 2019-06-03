#pragma once
#include <wx/wx.h>
//#include <wx/dcbuffer.h>
//#include <wx/colordlg.h>
#include <wx/statline.h>

class MainFrame : public wxFrame
{
public:
	MainFrame();
	~MainFrame();

protected:
	void setUpUi();
	void bindEvents();

	/* events */
	void onExit(wxCommandEvent& event);
	virtual void WxPanel_Repaint(wxUpdateUIEvent& event) { event.Skip(); }

	/* binded events IDs */
	enum
	{
		ID_WXBUTTON_MOVE_LEFT_ARM = 1001,
	};

	wxPanel* m_pnlSkeleton;
	wxSlider* m_sldRotationX;
	wxSlider* m_sldRotationY;
	wxSlider* m_sldRotationZ;
	wxSlider* m_sldHeadX;
	wxSlider* m_sldHeadY;
	wxChoice* m_chShoulder;
	wxSlider* m_sldShoulderX;
	wxSlider* m_sldShoulderY;
	wxSlider* m_sldBellyX;
	wxSlider* m_sldBellyY;
	wxChoice* m_chHip;
	wxSlider* m_sldHipX;
	wxSlider* m_sldHipY;
	wxChoice* m_chForearm;
	wxSlider* m_sldForearmX;
	wxSlider* m_sldForearmY;
	wxChoice* m_chHand;
	wxSlider* m_sldHandX;
	wxSlider* m_sldHandY;
	wxChoice* m_chThigh;
	wxSlider* m_sldThighX;
	wxSlider* m_sldThighY;
	wxChoice* m_chCalf;
	wxSlider* m_sldCalfX;
	wxSlider* m_sldCalfY;
	wxMenuBar* m_menuBar;
	wxMenu* m_menuProject;
	wxMenu* m_menuAnimation;
	wxMenu* m_menuHelp;
};
