
// MFCToolbarView.cpp : implementation of the CMFCToolbarView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "MFCToolbar.h"
#endif
#include "pressureDlg.h"
#include "MFCToolbarDoc.h"
#include "MFCToolbarView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCToolbarView

IMPLEMENT_DYNCREATE(CMFCToolbarView, CView)

BEGIN_MESSAGE_MAP(CMFCToolbarView, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_BUTTON_CIRCLE, &CMFCToolbarView::OnButtonCircle)
	ON_COMMAND(ID_BUTTON_EMPTY, &CMFCToolbarView::OnButtonEmpty)
	ON_COMMAND(ID_BUTTON_LINE, &CMFCToolbarView::OnButtonLine)
	ON_COMMAND(ID_BUTTON_RECTANGLE, &CMFCToolbarView::OnButtonRectangle)
	ON_COMMAND(ID_BUTTON_ZOOM, &CMFCToolbarView::OnButtonZoom)
	ON_UPDATE_COMMAND_UI(ID_BUTTON_CIRCLE, &CMFCToolbarView::OnUpdateButtonCircle)
	ON_UPDATE_COMMAND_UI(ID_BUTTON_EMPTY, &CMFCToolbarView::OnUpdateButtonEmpty)
	ON_UPDATE_COMMAND_UI(ID_BUTTON_LINE, &CMFCToolbarView::OnUpdateButtonLine)
	ON_UPDATE_COMMAND_UI(ID_BUTTON_RECTANGLE, &CMFCToolbarView::OnUpdateButtonRectangle)
	ON_UPDATE_COMMAND_UI(ID_BUTTON_ZOOM, &CMFCToolbarView::OnUpdateButtonZoom)
	ON_COMMAND(ID_TOOLS_PRESSUREVALUES, &CMFCToolbarView::OnToolsPressurevalues)
END_MESSAGE_MAP()

// CMFCToolbarView construction/destruction

CMFCToolbarView::CMFCToolbarView() noexcept
{
	// TODO: add construction code here

}

CMFCToolbarView::~CMFCToolbarView()
{
}

BOOL CMFCToolbarView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CMFCToolbarView drawing

//draw selected shape
void CMFCToolbarView::OnDraw(CDC* pDC)
{
	CMFCToolbarDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
	CRect WinRect;
	GetClientRect(&WinRect);
	CRect BMPRect;
	//GetBitmapDrawSize(&BMPRect);
	CPen pen;
	pen.CreatePen(PS_SOLID, 10, RGB(222, 150, 0));
	//chose pen
	auto oldPen = pDC->SelectObject(pen);

	//draw bigger if magnify
	const int topLeftXY = m_zoomIn ? 50 : 100;
	const int bottomRightXY = m_zoomIn ? 600 : 200;

	//draw selected shape
	switch (m_shapeToDraw) {
	case DrawShape::Circle:
		pDC->Ellipse(CRect{ topLeftXY, topLeftXY, bottomRightXY, bottomRightXY });
		break;
	case DrawShape::Rect:
		pDC->Rectangle((CRect{ topLeftXY, topLeftXY, bottomRightXY, bottomRightXY }));
		break;
	case DrawShape::Line:
	{
		pDC->MoveTo({ topLeftXY,topLeftXY });
		pDC->LineTo({ bottomRightXY,bottomRightXY });
	}
	break;
	}
}

void CMFCToolbarView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFCToolbarView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFCToolbarView diagnostics

#ifdef _DEBUG
void CMFCToolbarView::AssertValid() const
{
	CView::AssertValid();
}

void CMFCToolbarView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCToolbarDoc* CMFCToolbarView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCToolbarDoc)));
	return (CMFCToolbarDoc*)m_pDocument;
}
#endif //_DEBUG


// CMFCToolbarView message handlers


void CMFCToolbarView::OnButtonCircle()
{
	// TODO: Add your command handler code here
	//change selected shape
	m_shapeToDraw = DrawShape::Circle;
	//redraw window
	Invalidate();
	UpdateWindow();
}


void CMFCToolbarView::OnButtonEmpty()
{
	// TODO: Add your command handler code here
	//change selected shape
	m_shapeToDraw = DrawShape::None;
	//redraw window
	Invalidate();
	UpdateWindow();
}


void CMFCToolbarView::OnButtonLine()
{
	// TODO: Add your command handler code here
	//change selected shape
	m_shapeToDraw = DrawShape::Line;
	//redraw window
	Invalidate();
	UpdateWindow();
}


void CMFCToolbarView::OnButtonRectangle()
{
	// TODO: Add your command handler code here
	//change selected shape
	m_shapeToDraw = DrawShape::Rect;
	//redraw window
	Invalidate();
	UpdateWindow();

}


void CMFCToolbarView::OnButtonZoom()
{
	// TODO: Add your command handler code here
	m_zoomIn = !m_zoomIn;
	Invalidate();
	UpdateWindow();
}


void CMFCToolbarView::OnUpdateButtonCircle(CCmdUI* pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable(m_shapeToDraw != DrawShape::Circle);
}


void CMFCToolbarView::OnUpdateButtonEmpty(CCmdUI* pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable(m_shapeToDraw != DrawShape::None);
}


void CMFCToolbarView::OnUpdateButtonLine(CCmdUI* pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable(m_shapeToDraw != DrawShape::Line);
}


void CMFCToolbarView::OnUpdateButtonRectangle(CCmdUI* pCmdUI)
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable(m_shapeToDraw != DrawShape::Rect);
}


void CMFCToolbarView::OnUpdateButtonZoom(CCmdUI* pCmdUI)
{
	// TODO: Add your command update UI handler code here
}


void CMFCToolbarView::OnToolsPressurevalues()
{
	// TODO: Add your command handler code here
	pressureDlg pDlg;
	pDlg.DoModal();
}
