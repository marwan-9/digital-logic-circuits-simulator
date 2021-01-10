#include "LED.h"
LED::LED(const GraphicsInfo& r_GfxInfo):Component(r_GfxInfo)
{
	m_InputPin.setComponent(this);
	IfSelected = false;
}

void LED::Operate()
{

}

void LED::Draw(Output* pOut)
{

	if(m_InputPin.getStatus()==HIGH)
		pOut->DrawLED(m_GfxInfo, IfSelected); //when on
	else 
		pOut->DrawLED(m_GfxInfo, IfSelected); //when off
	
	
}
void LED::DrawFrame(Output* pOut)
{
	pOut->DrawSquare(m_GfxInfo);
}
int LED::GetOutPinStatus()	
{
	return -1;
}

int LED::GetInputPinStatus(int n=1)	
{
	return m_InputPin.getStatus();
}

void LED::setInputPinStatus(int n, STATUS s)
{
	IfSelected = false;
	m_InputPin.setStatus(s);
}

Component* LED::Copy()
{
	return nullptr;
}

void LED::Save(std::ofstream& stream, int ID)
{
	stream << ComponentType::COMP_LED << " " << ID << " " << this->GetLabel()
		<< " " << m_GfxInfo.x1 << " " << m_GfxInfo.x2 << " " << m_GfxInfo.y1 << " " << m_GfxInfo.y2 << std::endl;
}

