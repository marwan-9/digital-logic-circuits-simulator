#include "Switch.h"

Switch::Switch(const GraphicsInfo& r_GfxInfo, int r_FanOut):m_OutputPin(r_FanOut), Component(r_GfxInfo)
{
}

void Switch::Operate()
{

}

void Switch::Draw(Output* pOut)
{
	pOut->DrawSwitch(m_GfxInfo);
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