#include "Component.h"

Component::Component(const GraphicsInfo &r_GfxInfo)
{
	m_GfxInfo = r_GfxInfo;	
}

void Component::SetGraphics(int x, int y, bool type)    //zy ma bn3ml add kda
{
	int Len = UI.AND2_Width;
	int Wdth = UI.AND2_Height;
	GraphicsInfo GInfo; //Gfx info to be used to construct the AND2 gate

	GInfo.x1 = x - Len / 2;
	GInfo.x2 = x + Len / 2;
	GInfo.y1 = y - Wdth / 2;
	GInfo.y2 = y + Wdth / 2;
	m_GfxInfo = GInfo;
}

Component::Component()
{}

Component::~Component()
{}

