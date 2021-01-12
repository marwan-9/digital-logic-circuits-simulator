#include "Gate.h"

//Gate Constructor
//Parameters:
//r_Inputs: no. of gate's input pins
//r_FanOut: Fan out of the gate's output pin
Gate::Gate(int r_Inputs, int r_FanOut):m_OutputPin(r_FanOut)
{
	//Allocate number of input pins (equals r_Inputs)
	m_InputPins = new InputPin[r_Inputs];
	m_Inputs = r_Inputs;	//set no. of inputs of that gate
	
	//Associate all input pins to this gate
	for(int i=0; i<m_Inputs; i++)
		m_InputPins[i].setComponent(this);
}

void Gate::DrawFrame(Output* pOut)
{
	pOut->DrawSquare(m_GfxInfo);
}

OutputPin* Gate::GetOutputPin()
{
	return &m_OutputPin;
}

InputPin* Gate::GetInputPins(int i)
{
	if (i != -1)
		return &m_InputPins[i];
	return NULL;
}
int Gate::GetNumOfInputs() {
	return m_Inputs;
}
int Gate::GetPinNumber()
{
	for (int i = 0; i < m_Inputs; i++) {
		if (m_InputPins[i].getStatus() == STATUS::UNASSIGNED) {
			return i;
		}
	}
	return -1;
}

void Gate::Load(std::ifstream& stream)
{
	int ID;
	string Label;
	int x, y;
	stream >> ID >> Label >> x >> y;
	this->SetID(ID);
	this->SetLabel(Label);
	this->SetGraphicsCorner(x, y);
}