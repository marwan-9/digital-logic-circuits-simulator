#include "Inverter.h"

Inverter::Inverter(const GraphicsInfo &r_GfxInfo, int r_FanOut):Gate(2, r_FanOut)
{
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
}


void Inverter::Operate()
{
	//caclulate the output status as the Inverting of the ONLY ONE input pins
	m_OutputPin.setStatus(!(m_InputPins[0].getStatus()));
}


// Function Draw
// Draws Inverter gate
void Inverter::Draw(Output* pOut)
{
	//Call output class and pass gate drawing info to it.
	pOut->DrawINV(m_GfxInfo);
}

//returns status of output pin
int Inverter::GetOutPinStatus()	
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
int Inverter::GetInputPinStatus(int n)	
{
	return m_InputPins[n-1].getStatus();	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void Inverter::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n-1].setStatus(s);
}
