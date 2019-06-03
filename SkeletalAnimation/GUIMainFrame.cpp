#include "GUIMainFrame.h"

GUIMainFrame::GUIMainFrame(): MainFrame()
{
}

GUIMainFrame::~GUIMainFrame()
{}

void GUIMainFrame::WxPanel_Repaint(wxUpdateUIEvent& event)
{
	DrawSkeleton();
}

void GUIMainFrame::Normalization(Vector4& vector)
{
	vector.data[0] /= vector.data[3];
	vector.data[1] /= vector.data[3];
	vector.data[2] /= vector.data[3];
}

void GUIMainFrame::Projection(Matrix4& matrix)
{
	Matrix4 View;
	View.data[0][0] = 1.0;
	View.data[1][1] = 1.0;
	View.data[3][2] = 1.0 / 2.0;

	Matrix4 Panel_Size;
	wxSize panelSize = m_pnlSkeleton->GetSize();
	Panel_Size.data[0][0] = panelSize.GetWidth() / 2.0;
	Panel_Size.data[0][3] = Panel_Size.data[0][0];
	Panel_Size.data[1][1] = -panelSize.GetHeight() / 2.0;
	Panel_Size.data[1][3] = -Panel_Size.data[1][1];

	matrix = Panel_Size * View;
}

void GUIMainFrame::Transformation(Matrix4& matrix)
{
	double alpha;

	Matrix4 RotateX;
	alpha = m_sldRotationX->GetValue() * acos(-1) / 180;
	RotateX.data[0][0] = 1.0;
	RotateX.data[1][1] = cos(alpha);
	RotateX.data[1][2] = sin(alpha);
	RotateX.data[2][1] = -sin(alpha);
	RotateX.data[2][2] = cos(alpha);

	Matrix4 RotateY;
	alpha = m_sldRotationY->GetValue() * acos(-1) / 180;
	RotateY.data[0][0] = cos(alpha);
	RotateY.data[0][2] = -sin(alpha);
	RotateY.data[1][1] = 1.0;
	RotateY.data[2][0] = sin(alpha);
	RotateY.data[2][2] = cos(alpha);

	Matrix4 RotateZ;
	alpha = m_sldRotationZ->GetValue() * acos(-1) / 180;
	RotateZ.data[0][0] = cos(alpha);
	RotateZ.data[0][1] = sin(alpha);
	RotateZ.data[1][0] = -sin(alpha);
	RotateZ.data[1][1] = cos(alpha);
	RotateZ.data[2][2] = 1.0;

	matrix = RotateX * RotateY * RotateZ;
}

void GUIMainFrame::DrawSkeleton()
{
	wxClientDC dc(m_pnlSkeleton);
	wxBufferedDC buffer(&dc);
	buffer.SetBackground(*wxWHITE_BRUSH);
	buffer.Clear();
	buffer.SetPen(wxPen(wxColor(0, 0, 0)));

	wxSize size = m_pnlSkeleton->GetSize();

	Segment position[15][12];

	for (int i = 0; i < 12; ++i)
	{
		position[0][i] = skeleton.head->lines[i];
		position[1][i] = skeleton.left_shoulder->lines[i];
		position[2][i] = skeleton.right_shoulder->lines[i];
		position[3][i] = skeleton.left_forearm->lines[i];
		position[4][i] = skeleton.right_forearm->lines[i];
		position[5][i] = skeleton.left_arm->lines[i];
		position[6][i] = skeleton.right_arm->lines[i];
		position[7][i] = skeleton.chest->lines[i];
		position[8][i] = skeleton.stomach->lines[i];
		position[9][i] = skeleton.left_hip->lines[i];
		position[10][i] = skeleton.right_hip->lines[i];
		position[11][i] = skeleton.left_thigh->lines[i];
		position[12][i] = skeleton.right_thigh->lines[i];
		position[13][i] = skeleton.left_calf->lines[i];
		position[14][i] = skeleton.right_calf->lines[i];
	}

	Matrix4 projection;
	Matrix4 transformation;
	Projection(projection);
	Transformation(transformation);

	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 12; j++)
		{
			Vector4 Point1, Point2;
			Point1.Set(position[i][j].begin->x, position[i][j].begin->y, position[i][j].begin->z);
			Point2.Set(position[i][j].end->x, position[i][j].end->y, position[i][j].end->z);
			Point1 = transformation * Point1;
			Point2 = transformation * Point2;
			Normalization(Point1);
			Normalization(Point2);
			if (Point1.GetZ() > -2.0 && Point2.GetZ() <= -2.0 || Point2.GetZ() > -2.0 && Point1.GetZ() <= -2.0)
			{
				Vector4 Temp_Point1 = Point2.GetZ() <= 2.0 ? Point2 : Point1;
				Vector4 Temp_Point2 = Point2.GetZ() <= -2.0 ? Point1 : Point2;
				double ratio = fabs((-2.0 - Temp_Point1.data[2]) / (Temp_Point2.data[2] - Temp_Point1.data[2]));
				Temp_Point1.data[0] = (Temp_Point2.data[0] - Temp_Point1.data[0]) * ratio + Temp_Point1.data[0];
				Temp_Point1.data[1] = (Temp_Point2.data[1] - Temp_Point1.data[1]) * ratio + Temp_Point1.data[1];
				Temp_Point1.data[2] = -2.0;
				Point1 = projection * Temp_Point1;
				Point2 = projection * Temp_Point2;
				Normalization(Point1);
				Normalization(Point2);
			}
			else if (Point1.GetZ() <= -2 && Point2.GetZ() <= -2)
				continue;
			else
			{
				Point1 = projection * Point1;
				Point2 = projection * Point2;
				Normalization(Point1);
				Normalization(Point2);
			}

			buffer.DrawLine(Point1.GetX(), Point1.GetY(), Point2.GetX(), Point2.GetY());
		}
	}
}