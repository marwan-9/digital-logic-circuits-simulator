#include "Inverter.h"

Inverter::Inverter(const GraphicsInfo &r_GfxInfo, int r_FanOut):Gate(1, r_FanOut)
{
	m_GfxInfo = r_GfxInfo;
}


void Inverter::Operate()
{
	//caclulate the output status as the Inverting of the ONLY ONE input pins
	int output = m_InputPins[0].getStatus();
	if (output) {
		m_OutputPin.setStatus(LOW);
	}
	m_OutputPin.setStatus(HIGH);
}


// Function Draw
// Draws Inverter gate
void Inverter::Draw(Output* pOut)
{
	//Call output class and pass gate drawing info to it.
	pOut->DrawINV(m_GfxInfo);
	pOut->Printstringg(m_GfxInfo.x1 - 5, m_GfxInfo.y1 + 50, getlabel());
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

Component* Inverter::Copy()
{
	GraphicsInfo temp;
	temp.x1 = temp.x2 = temp.y1 = temp.y2 = 0;
	Component* Copied = new Inverter(temp, INV_FANOUT);
	return Copied;
}

void Inverter::Save(std::ofstream& stream)
{
	stream << ComponentType::COMP_INVERTER << " " << this->GetID() << " " << this->GetLabel()
		<< " " << m_GfxInfo.x1 << " " << m_GfxInfo.y1  << std::endl;
}
