#include "XOR3.h"


#include <iostream>
using namespace std;
XOR3::XOR3(const GraphicsInfo &r_GfxInfo, int r_FanOut):Gate(3, r_FanOut)
{
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
}


void XOR3::Operate()
{
	//caclulate the output status as the ANDing of the two input pins

	if (m_InputPins[0].getStatus()==LOW && m_InputPins[1].getStatus()==LOW && m_InputPins[2].getStatus()==LOW)
		m_OutputPin.setStatus(LOW);
	else if (m_InputPins[0].getStatus()==LOW && m_InputPins[1].getStatus()==LOW && m_InputPins[2].getStatus()==HIGH)
		m_OutputPin.setStatus(HIGH);
	else if (m_InputPins[0].getStatus()==LOW && m_InputPins[1].getStatus()==HIGH && m_InputPins[2].getStatus()==LOW)
		m_OutputPin.setStatus(HIGH);
	else if (m_InputPins[0].getStatus()==LOW && m_InputPins[1].getStatus()==HIGH && m_InputPins[2].getStatus()==HIGH)
		m_OutputPin.setStatus(LOW);
	else if (m_InputPins[0].getStatus()==HIGH && m_InputPins[1].getStatus()==LOW && m_InputPins[2].getStatus()==LOW)
		m_OutputPin.setStatus(HIGH);
	else if (m_InputPins[0].getStatus()==HIGH && m_InputPins[1].getStatus()==LOW && m_InputPins[2].getStatus()==HIGH)
		m_OutputPin.setStatus(LOW);
	else if (m_InputPins[0].getStatus()==HIGH && m_InputPins[1].getStatus()==HIGH && m_InputPins[2].getStatus()==LOW)
		m_OutputPin.setStatus(LOW);
	else
		m_OutputPin.setStatus(HIGH);
}


// Function Draw
// Draws 2-input AND gate
void XOR3::Draw(Output* pOut)
{
	//Call output class and pass gate drawing info to it.
	pOut->DrawXOR3(m_GfxInfo, IfSelected);
}

//returns status of outputpin
int XOR3::GetOutPinStatus()	
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
int XOR3::GetInputPinStatus(int n)	
{
	return m_InputPins[n-1].getStatus();	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void XOR3::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n-1].setStatus(s);
}

void XOR3::Save(std::ofstream& stream, int ID)
{
	stream << ComponentType::XOR3 << " " << ID << " " << this->GetLabel()
		<< " " << m_GfxInfo.x1 << " " << m_GfxInfo.x2 << " " << m_GfxInfo.y1 << " " << m_GfxInfo.y2 << std::endl;
}
