#include "Switch.h"
#include <sstream>
#include <iostream>
Switch::Switch(const GraphicsInfo& r_GfxInfo, int r_FanOut):m_OutputPin(r_FanOut), Component(r_GfxInfo)
{
}

void Switch::Operate()
{
	//m_OutputPin.setStatus(UNASSIGNED);
}

void Switch::Draw(Output* pOut)
{

	pOut->DrawSwitch(m_GfxInfo);
	pOut->Printstringg(m_GfxInfo.x1 - 5, m_GfxInfo.y1 + 60, GetLabel()); 



}
void Switch::DrawStatus(Output* pOut) {
	stringstream ss;
	int k=GetOutPinStatus();
	ss<<k;//make me string
	string s;
	ss >> s;
	pOut->Printstringg(m_GfxInfo.x1 - 5, m_GfxInfo.y1 + 50, s );

/*
	if (m_OutputPin.getStatus() == HIGH)
		pOut->DrawSwitch(m_GfxInfo, true); //when on
	else
		pOut->DrawSwitch(m_GfxInfo, false); //when off

	pOut->Printstringg(m_GfxInfo.x1 - 5, m_GfxInfo.y1 + 60, GetLabel());
*/
}

int Switch::GetNumOfInputs() {
	return 0; //check this ahmed
}


void Switch::DrawFrame(Output* pOut)
{
	pOut->DrawSquare(m_GfxInfo);
	
}

int Switch::GetOutPinStatus()       // must be staus not int?
{ 
	//int S = m_OutputPin.getStatus(); // must be staus not int?
	return m_OutputPin.getStatus();
}

int Switch::GetInputPinStatus(int n)
{
	return -1;
}
void Switch::setoutputpenstatus(STATUS s) {
	m_OutputPin.setStatus(s);

}
void Switch::setInputPinStatus(int n, STATUS s)
{

}
Component* Switch::Copy()
{
	GraphicsInfo temp;
	temp.x1 = temp.x2 = temp.y1 = temp.y2 = 0;
	Component* Copied = new Switch(temp, Switch_FANOUT);
	return Copied;
}
string Switch::getlabel() {
	return GetLabel();
}

void Switch::Save(std::ofstream& stream)
{
	stream << ComponentType::COMP_SWITCH << " " << this->GetID() << " " << this->GetLabel()
		<< " " << m_GfxInfo.x1 << " " << m_GfxInfo.y1 << std::endl;
}
void Switch::Load(std::ifstream& stream)
{
	int ID;
	string Label;
	int x, y;
	stream >> ID >> Label >> x >> y;
	this->SetID(ID);
	this->SetLabel(Label);
	this->SetGraphicsCorner(x, y);
}
OutputPin* Switch::GetOutputPin()
{
	return &m_OutputPin;
}
