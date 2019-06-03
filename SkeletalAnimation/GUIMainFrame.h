#pragma once
#include "MainFrame.h"
#include "Skeleton.h"
#include "Vecmath.h"
#include <wx/dcbuffer.h>

class GUIMainFrame : public MainFrame
{
public:
	GUIMainFrame();
	~GUIMainFrame();

	void Normalization(Vector4& vector);
	void Projection(Matrix4& matrix);
	void Transformation(Matrix4& matrix);
	void DrawSkeleton();

private:
	void WxPanel_Repaint(wxUpdateUIEvent& event);

	Skeleton skeleton;
};
