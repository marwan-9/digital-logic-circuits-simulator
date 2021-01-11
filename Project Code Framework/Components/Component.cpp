#include "Component.h"

Component::Component(const GraphicsInfo &r_GfxInfo)
{
	m_GfxInfo = r_GfxInfo;	
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

Component::Component()
{
	IfSelected=false;
}

Component::~Component()
{}

void Component::drawname(Output* pOut, int Cx, int Cy, const char* cpText) {

	pOut->Printstringg(Cx, Cy, cpText);

}