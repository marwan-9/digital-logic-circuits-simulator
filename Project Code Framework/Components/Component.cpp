#include "Component.h"

Component::Component(const GraphicsInfo &r_GfxInfo)
{
	m_GfxInfo = r_GfxInfo;
	m_Label = "DefaultLabel";
	m_ID = 0;
}
void Component::setlabel(string str) {
	m_Label = str;
	//m_Label= pIn->GetSrting(pOut, str2, "");	
}
string Component::getlabel() {
	return m_Label;
}
//int Component::GetNumOfInputs() = 0;//add me ahmed here

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
void Component::SetGraphicsCorner(int x, int y)
{
	int Len = UI.AND2_Width;
	int Wdth = UI.AND2_Height;
	GraphicsInfo GInfo; //Gfx info to be used to construct the AND2 gate

	GInfo.x1 = x;
	GInfo.x2 = x + Len;
	GInfo.y1 = y;
	GInfo.y2 = y + Wdth;
	m_GfxInfo = GInfo;
}
GraphicsInfo Component::GetGraphics()
{
	return m_GfxInfo;
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


string Component::GetLabel()
{
	return m_Label;
}

void Component::SetLabel(string r_Label)
{
	m_Label = r_Label;
}

void Component::SetID(int r_ID)
{
	m_ID = r_ID;
}

int Component::GetID()
{
	return m_ID;
}
OutputPin* Component::GetOutputPin()
{
	return nullptr;
}

InputPin* Component::GetInputPins(int i)
{
	return nullptr;
}

int Component::GetPinNumber()
{
	return -1;
}

const GraphicsInfo Component::getGraphicsInfo()
{
	return m_GfxInfo;
}

COMPS Component::getcomptype() const
{
	return COMPS::ITM_GEN;
}
Component::Component()
{
	IfSelected=false;
	m_Label = "DefaultLabel";
	m_ID = 0;
}

Component::~Component()
{}

