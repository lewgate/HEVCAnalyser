#ifndef YUVPARASETDLG_H
#define YUVPARASETDLG_H
#include <wx/dialog.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/button.h>
#include <wx/combobox.h>

class YUVParaSetDlg : public wxDialog
{
	public:
		YUVParaSetDlg(wxWindow *parent);

		void OnButton(wxCommandEvent& event);
		void OnClose(wxCloseEvent& event);
	private:
		DECLARE_EVENT_TABLE()
	private:
			wxStaticText *m_stFormat,
						 *m_stBitDepth,
						 *m_stHeight,
						 *m_stWidth;
			wxTextCtrl *m_TCHeight,
					   *m_TCWidth,
					   *m_TCBitDepth;
			wxButton *m_btOK,
					 *m_btCancel;
			wxComboBox *m_CBFormat;
			long m_height,
				 m_width,
				 m_formartID,
				 m_bitdepth;
	public:
			long GetHeight();
			long GetWidth();
			long GetBitDepth();
};
#endif
