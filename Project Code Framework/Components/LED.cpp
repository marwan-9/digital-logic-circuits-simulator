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

