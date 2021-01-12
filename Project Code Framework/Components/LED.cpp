#include "LED.h"
LED::LED(const GraphicsInfo& r_GfxInfo):Component(r_GfxInfo)
{
	m_InputPin.setComponent(this);
	IfSelected = false;
}

void LED::Operate()
{
	m_InputPin.setStatus(m_InputPin.getStatus());

}

int LED::GetNumOfInputs() {
	return 1; //check this ahmed
}

void LED::Draw(Output* pOut)
{

	if (m_InputPin.getStatus() == HIGH) {
		pOut->DrawLED(m_GfxInfo, IfSelected); //when on
		pOut->Printstringg(m_GfxInfo.x1 - 5, m_GfxInfo.y1 + 50, GetLabel());
	}
	else 
		pOut->DrawLED(m_GfxInfo, IfSelected); //when off
	  pOut->Printstringg(m_GfxInfo.x1 - 5, m_GfxInfo.y1 + 60, GetLabel());
}


void LED::DrawFrame(Output* pOut)
{
	pOut->DrawSquare(m_GfxInfo);
	pOut->Printstringg(m_GfxInfo.x1 - 5, m_GfxInfo.y1 + 50, GetLabel());
}
int LED::GetOutPinStatus()	
{
	return -1;
}

int LED::GetInputPinStatus(int n)	
{
	return m_InputPin.getStatus();
}

void LED::setInputPinStatus(int n, STATUS s)
{
	IfSelected = false;
	m_InputPin.setStatus(s);
}



void LED::Save(std::ofstream& stream)
{
	stream << ComponentType::COMP_LED << " " << this->GetID() << " " << this->GetLabel()
		<< " " << m_GfxInfo.x1 << " "  << m_GfxInfo.y1 << std::endl;
}

void LED::Load(std::ifstream& stream)
{
	int ID;
	string Label;
	int x, y;
	stream >> ID >> Label >> x >> y;
	this->SetID(ID);
	this->SetLabel(Label);
	this->SetGraphicsCorner(x, y);
}

Component* LED::Copy()
{
	GraphicsInfo temp;
	temp.x1 = temp.x2 = temp.y1 = temp.y2 = 0;
	Component* Copied = new LED(temp);
	return Copied;
}

InputPin* LED::GetInputPins(int index)
{
	return &m_InputPin;
}

