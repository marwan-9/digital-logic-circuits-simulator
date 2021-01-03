#include "XNOR2.h"

/* Constructor */
XNOR2::XNOR2(const GraphicsInfo& r_GfxInfo, int r_FanOut) :Gate(2, r_FanOut) {
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
}


/* Calculates the output of the XNOR gate */
void XNOR2::Operate() {
	//caclulate the output status as the XNORing of the two input pins
	bool out = 0;
	for (int i = 0; i < m_Inputs; i++) {
		out = out ^ (m_InputPins[i].getStatus() == STATUS::HIGH ? 1 : 0);
	}

	m_OutputPin.setStatus(out ? STATUS::LOW : STATUS::HIGH);
}

// Draws 2-input XNOR gate
void XNOR2::Draw(Output* pOut) {
	
		pOut->DrawXNOR2(m_GfxInfo);
}

//returns status of outputpin
int XNOR2::GetOutPinStatus()	
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
int XNOR2::GetInputPinStatus(int n)	
{
	return m_InputPins[n-1].getStatus();	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void XNOR2::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n-1].setStatus(s);
}
