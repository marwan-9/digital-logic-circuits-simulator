#include "NAND2.h"

NAND2::NAND2(const GraphicsInfo& r_GfxInfo, int r_FanOut) :Gate(2, r_FanOut)
{
	m_GfxInfo = r_GfxInfo;
}


void NAND2::Operate()
{
	//caclulate the output status as the NAND of the two input pins
	int output = m_InputPins[0].getStatus() * m_InputPins[1].getStatus();
	if (output == 0) 
		m_OutputPin.setStatus(HIGH);
	else
		m_OutputPin.setStatus(LOW);
}


// Function Draw
// Draws 2-input NAND gate
void NAND2::Draw(Output* pOut)
{
	//Call output class and pass gate drawing info to it.
	pOut->DrawNAND2(m_GfxInfo);
}

//returns status of outputpin
int NAND2::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
int NAND2::GetInputPinStatus(int n)
{
	return m_InputPins[n - 1].getStatus();	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void NAND2::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n - 1].setStatus(s);
}
