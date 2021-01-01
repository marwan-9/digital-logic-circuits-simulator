#include "NOR3.h"

NOR3::NOR3(const GraphicsInfo& r_GfxInfo, int r_FanOut) :Gate(3, r_FanOut)
{
	m_GfxInfo = r_GfxInfo;
}


void NOR3::Operate()
{
	//caclulate the output status as the NOR of the three input pins
	int output = m_InputPins[0].getStatus() + m_InputPins[1].getStatus() + m_InputPins[2].getStatus();
	if (output == 0) 
		m_OutputPin.setStatus(HIGH);
	else
		m_OutputPin.setStatus(LOW);
}


// Function Draw
// Draws 3-input NOR gate
void NOR3::Draw(Output* pOut)
{
	//Call output class and pass gate drawing info to it.
	pOut->DrawNOR3(m_GfxInfo);
}

//returns status of outputpin
int NOR3::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
int NOR3::GetInputPinStatus(int n)
{
	return m_InputPins[n - 1].getStatus();	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void NOR3::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n - 1].setStatus(s);
}
