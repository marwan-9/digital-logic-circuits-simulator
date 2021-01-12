#include "Buffer.h"

Buffer::Buffer(const GraphicsInfo& r_GfxInfo, int r_FanOut) :Gate(1, r_FanOut)
{
	m_GfxInfo.x1 = r_GfxInfo.x1;
	m_GfxInfo.y1 = r_GfxInfo.y1;
	m_GfxInfo.x2 = r_GfxInfo.x2;
	m_GfxInfo.y2 = r_GfxInfo.y2;
}


void Buffer::Operate()
{
	//caclulate the output status as the Buffering the ONLY ONE input pins
	m_OutputPin.setStatus(m_InputPins[0].getStatus());
}


// Function Draw
// Draws Buffer gate
void Buffer::Draw(Output* pOut)
{
	//Call output class and pass gate drawing info to it.
	pOut->DrawBuff(m_GfxInfo);
}

//returns status of output pin
int Buffer::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}


//returns status of Inputpin #n
int Buffer::GetInputPinStatus(int n)
{
	return m_InputPins[n - 1].getStatus();	//n starts from 1 but array index starts from 0.
}

//Set status of an input pin ot HIGH or LOW
void Buffer::setInputPinStatus(int n, STATUS s)
{
	m_InputPins[n - 1].setStatus(s);
}

Component* Buffer::Copy()
{
	GraphicsInfo temp;
	temp.x1 = temp.x2 = temp.y1 = temp.y2 = 0;
	Component* Copied = new Buffer(temp, BUFF_FANOUT);
	return Copied;
}

void Buffer::Save(std::ofstream& stream)
{
	stream << ComponentType::COMP_BUFFER << " " << this->GetID() << " " << this->GetLabel()
		<< " " << m_GfxInfo.x1 << " " << m_GfxInfo.y1 << std::endl;
}

