
// MFCToolbarView.h : interface of the CMFCToolbarView class
//

#include <vector>
#pragma once

enum class DrawShape { None, Circle, Rect, Line};

class CMFCToolbarView : public CView
{
protected: // create from serialization only
	CMFCToolbarView() noexcept;
	DECLARE_DYNCREATE(CMFCToolbarView)

// Attributes
public:
	CMFCToolbarDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// Implementation
public:
	virtual ~CMFCToolbarView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
private:
	DrawShape m_shapeToDraw{ DrawShape::None };
	std::vector<CRect> shapes; 
	bool m_zoomIn{ false };

// Generated message map functions
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnButtonCircle();
	afx_msg void OnButtonEmpty();
	afx_msg void OnButtonLine();
	afx_msg void OnButtonRectangle();
	afx_msg void OnButtonZoom();
	afx_msg void OnUpdateButtonCircle(CCmdUI* pCmdUI);
	afx_msg void OnUpdateButtonEmpty(CCmdUI* pCmdUI);
	afx_msg void OnUpdateButtonLine(CCmdUI* pCmdUI);
	afx_msg void OnUpdateButtonRectangle(CCmdUI* pCmdUI);
	afx_msg void OnUpdateButtonZoom(CCmdUI* pCmdUI);
	afx_msg void OnToolsPressurevalues();
};

#ifndef _DEBUG  // debug version in MFCToolbarView.cpp
inline CMFCToolbarDoc* CMFCToolbarView::GetDocument() const
   { return reinterpret_cast<CMFCToolbarDoc*>(m_pDocument); }
#endif

