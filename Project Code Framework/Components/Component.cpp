#include "Component.h"

Component::Component(const GraphicsInfo &r_GfxInfo)
{
	m_GfxInfo = r_GfxInfo;	
}
void Component::setlabel(string str) {
	m_Label = str;
	//m_Label= pIn->GetSrting(pOut, str2, "");
}

bool Component::Inside(int x, int y)
{
	if (x >= m_GfxInfo.x1 && x <= m_GfxInfo.x2 && y >= m_GfxInfo.y1 && y <= m_GfxInfo.y2)
		return true;
	else
		return false;
}
void Component::SetIfSelected(bool q)
{
	IfSelected = q;

}
bool Component:: GetIfSelected()
{
	return IfSelected;
}

Component::Component()
{
	IfSelected=false;
}

Component::~Component()
{}

