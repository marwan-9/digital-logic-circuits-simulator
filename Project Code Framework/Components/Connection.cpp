#include "Connection.h"

Connection::Connection(const GraphicsInfo& r_GfxInfo, Component* pS, Component* pD, int Pin):Component(r_GfxInfo)
{
	SrcCmpnt = pS;
	DstCmpnt = pD;
	DstPin = pD->GetPinNumber();
}
void Connection::setSourcePin(Component* r_SrcCmpnt)
{
	SrcCmpnt = r_SrcCmpnt;
}

void Connection::setDestPin(Component* r_DstCmpnt)
{
	DstCmpnt = r_DstCmpnt;
}

Component* Connection::getSourcePin()
{
	return SrcCmpnt;
}



Component* Connection::getDestPin()
{	return DstCmpnt;	}


void Connection::Operate()
{
	//Status of connection destination pin = status of connection source pin
	// DstPin->setStatus((STATUS)SrcPin->getStatus());
	DstCmpnt->setInputPinStatus(DstPin, (STATUS)SrcCmpnt->GetOutPinStatus());
}

void Connection::Draw(Output* pOut)
{
	pOut->DrawConnection(m_GfxInfo);
}

void Connection::DrawFrame(Output* pOut)
{
}

int Connection::GetOutPinStatus()	//returns status of outputpin if LED, return -1
{
	return DstCmpnt->GetInputPinStatus(DstPin);
}


int Connection::GetInputPinStatus(int n)	//returns status of Inputpin # n if SWITCH, return -1
{
	return SrcCmpnt->GetOutPinStatus();	//n is ignored as connection has only one input pin (src pin)	
}

void Connection::setInputPinStatus(int n, STATUS s)
{
	SrcCmpnt->setInputPinStatus(n, s);
}

Component* Connection::Copy()
{
	return NULL;
}