#include "YUVParaSetDlg.h"
#include <wx/sizer.h>
#include <wx/valtext.h>
#include <wx/string.h>

BEGIN_EVENT_TABLE(YUVParaSetDlg, wxDialog)
	EVT_BUTTON(wxID_ANY, YUVParaSetDlg::OnButton)
END_EVENT_TABLE()


YUVParaSetDlg::YUVParaSetDlg(wxWindow *parent)
			  : wxDialog(parent, wxID_ANY, wxString(_T("YUV parameters setting")))
{
	m_height = 480;
	m_width = 832;
	m_bitdepth = 8;

	m_stFormat = new wxStaticText(this, wxID_ANY, _T("format"));
	wxString strarray[2]={_T("YUV420"), _T("YUV422")};
	m_CBFormat = new wxComboBox(this, wxID_ANY, );
	wxBoxSizer *sizerFormat = new wxBoxSizer(wxHORIZONTAL);
	sizerFormat->Add(m_stFormat, 0, wxALIGN_CENTER_VERTICAL, 5);
	sizerFormat->Add(m_CBFormat, 0, wxALIGN_CENTER_VERTICAL, 5);

	wxTextValidator textfilter(wxFILTER_NUMERIC);
	m_stHeight = new wxStaticText(this, wxID_ANY, _T("height"));
	m_TCHeight = new wxTextCtrl(this, wxID_ANY, wxString::Format(_T("%d"), m_height), wxDefaultPosition, wxDefaultSize, 0, textfilter);
	wxBoxSizer *sizerHeight = new wxBoxSizer(wxHORIZONTAL);
	sizerHeight->Add(m_stHeight, 0, wxALIGN_CENTER_VERTICAL, 5);
	sizerHeight->Add(m_TCHeight, 0, wxALIGN_CENTER_VERTICAL, 5);

	m_stWidth = new wxStaticText(this, wxID_ANY, _T("width"));
	m_TCWidth = new wxTextCtrl(this, wxID_ANY, wxString::Format(_T("%d"), m_width), wxDefaultPosition, wxDefaultSize, 0, textfilter);
	wxBoxSizer *sizerWidth = new wxBoxSizer(wxHORIZONTAL);
	sizerWidth->Add(m_stWidth, 0, wxALIGN_CENTER_VERTICAL, 5);
	sizerWidth->Add(m_TCWidth, 0, wxALIGN_CENTER_VERTICAL, 5);

	m_stBitDepth = new wxStaticText(this, wxID_ANY, _T("bit depth"));
	m_TCBitDepth = new wxTextCtrl(this, wxID_ANY, wxString::Format(_T("%d"), m_bitdepth), wxDefaultPosition, wxDefaultSize, 0, textfilter);
	wxBoxSizer *sizerBitDepth = new wxBoxSizer(wxHORIZONTAL);
	sizerBitDepth->Add(m_stBitDepth, 0, wxALIGN_CENTER_VERTICAL, 5);
	sizerBitDepth->Add(m_TCBitDepth, 0, wxALIGN_CENTER_VERTICAL, 5);

	m_btOK = new wxButton(this, wxID_ANY, _T("OK"));
	m_btCancel = new wxButton(this, wxID_ANY, _T("Cancel"));
	wxBoxSizer *sizerBt = new wxBoxSizer(wxHORIZONTAL);
	sizerBt->Add(m_btOK, 0, wxALIGN_CENTER_VERTICAL, 5);
	sizerBt->Add(m_btCancel, 0,	wxALIGN_CENTER_VERTICAL, 5);

	wxBoxSizer *sizerTop = new wxBoxSizer(wxVERTICAL);
	sizerTop->Add(sizerFormat, 0, wxALIGN_CENTER_HORIZONTAL, 5);
	sizerTop->Add(sizerHeight, 0, wxALIGN_CENTER_HORIZONTAL, 5);
	sizerTop->Add(sizerWidth, 0, wxALIGN_CENTER_HORIZONTAL, 5);
	sizerTop->Add(sizerBitDepth, 0, wxALIGN_CENTER_HORIZONTAL, 5);
	sizerTop->Add(sizerBt, 0, wxALIGN_CENTER_VERTICAL, 5);

	SetSizer(sizerTop);
    sizerTop->SetSizeHints(this);
	sizerTop->Fit(this);

	ShowModal();

}
void YUVParaSetDlg::OnButton(wxCommandEvent& event)
{
	if(event.GetEventObject() == m_btOK)
	{
		if(!m_TCHeight->IsEmpty())
		{
			wxString heightstr = m_TCHeight->GetValue();
			heightstr.ToLong(&m_height, 10);
		}
		if(!m_TCWidth->IsEmpty())
		{
			wxString widthstr = m_TCWidth->GetValue();
			widthstr.ToLong(&m_width, 10);
		}
		if(!m_TCBitDepth->IsEmpty())
		{
			wxString bitdepthstr = m_TCBitDepth->GetValue();
			bitdepthstr.ToLong(&m_bitdepth, 10);
		}
	}
	EndModal(0);
}
long YUVParaSetDlg::GetHeight()
{
	return m_height;
}
long YUVParaSetDlg::GetWidth()
{
	return m_width;
}
long YUVParaSetDlg::GetBitDepth()
{
	return m_bitdepth;
}
