/////////////////////////////////////////////////////////////////////////////
// Name:        life.h
// Purpose:     The game of Life, created by J. H. Conway
// Author:      Guillermo Rodriguez Garcia, <guille@iies.es>
// Modified by:
// Created:     Jan/2000
// Copyright:   (c) 2000, Guillermo Rodriguez Garcia
// Licence:     wxWindows licence
/////////////////////////////////////////////////////////////////////////////

#ifndef _LIFE_APP_H_
#define _LIFE_APP_H_

#include "wx/wx.h"
#include "wx/sizer.h"

// #include "game.h"


// --------------------------------------------------------------------------
// BasicDrawPane
// --------------------------------------------------------------------------

class BasicDrawPane : public wxPanel
{
 
public:
    BasicDrawPane(wxWindow* parent);
 
    void paintEvent(wxPaintEvent & evt);
    void paintNow();
 
    void render(wxDC& dc);

    int cellsize;
    long m_tailleX;
    long m_tailleY;

 
    DECLARE_EVENT_TABLE()
};


// --------------------------------------------------------------------------
// LifeFrame
// --------------------------------------------------------------------------

class LifeFrame : public wxFrame
{
public:
    // ctor and dtor
    LifeFrame();
    virtual ~LifeFrame();

    // member functions
    void UpdateInfoText();
    void UpdateUI();

    BasicDrawPane *drawPane;

private:
    // any class wishing to process wxWidgets events must use this macro
    wxDECLARE_EVENT_TABLE();

    // event handlers
    void OnMenu(wxCommandEvent& event);
    void OnOpen(wxCommandEvent& event);
    void OnSamples(wxCommandEvent& event);
    void OnNavigate(wxCommandEvent& event);
    void OnZoom(wxCommandEvent& event);
    void OnSlider(wxScrollEvent& event);
    void OnTimer(wxTimerEvent& event);
    void OnClose(wxCloseEvent& event);
    void OnNewGame(wxCommandEvent& WXUNUSED(event));

    // event handler helpers
   /* void OnStart();
    void OnStop();
    void OnStep();*/

   // Life           *m_life;

    wxStaticText   *m_text;
    wxTimer        *m_timer;
    bool            m_running;
    bool            m_topspeed;
    long            m_interval;
    long            m_tics;

};



// --------------------------------------------------------------------------
// LifeApp
// --------------------------------------------------------------------------

class LifeApp : public wxApp
{
public:
    virtual bool OnInit();
    wxFrame *frame;
    BasicDrawPane *drawPane;
};

#endif  // _LIFE_APP_H_




