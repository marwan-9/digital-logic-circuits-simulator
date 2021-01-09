#include "Component.h"

Component::Component(const GraphicsInfo &r_GfxInfo)
{
	m_GfxInfo = r_GfxInfo;	
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

