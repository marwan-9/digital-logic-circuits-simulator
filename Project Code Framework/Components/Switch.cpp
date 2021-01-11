#include "Switch.h"

Switch::Switch(const GraphicsInfo& r_GfxInfo, int r_FanOut):m_OutputPin(r_FanOut), Component(r_GfxInfo)
{
}

void Switch::Operate()
{
	m_OutputPin.setStatus(HIGH);
}

void Switch::Draw(Output* pOut)
{
	pOut->DrawSwitch(m_GfxInfo);
}

int Switch::GetNumOfInputs() {
	return 0; //check this ahmed
}

void Switch::DrawFrame(Output* pOut)
{
	pOut->DrawSquare(m_GfxInfo);
}

int Switch::GetOutPinStatus()
{
	return m_OutputPin.getStatus();
}

int Switch::GetInputPinStatus(int n)
{
	return -1;
}

void Switch::setInputPinStatus(int n, STATUS s)
{

}
Component* Switch::Copy()
{
	GraphicsInfo temp;
	temp.x1 = temp.x2 = temp.y1 = temp.y2 = 0;
	Component* Copied = new Switch(temp, Switch_FANOUT);
	return Copied;
}

OutputPin* Switch::GetOutputPin()
{
	return &m_OutputPin;
}
