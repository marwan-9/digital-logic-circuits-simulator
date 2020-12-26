#ifndef _GATE_H
#define _GATE_H

/*
  Class Gate
  -----------
  - Base class for all types of gates
  - Each gate has n inputs pins and one output pin
*/


#include "InputPin.h"
#include "OutputPin.h"
#include "Component.h"

#pragma once
#include "Component.h"
#include "inputpin.h"
#include "outputpin.h"
 
 
class Gate : public Component
{
protected:
	InputPin* m_InputPins;	//Array of input pins of the Gate
	OutputPin m_OutputPin;	//The Gate output pin
	int m_Inputs;		//No. of input pins of that Gate.
public:
 
	//Gate(Output* pOut, const GraphicsInfo& gfxInfo);
	Gate(int r_Inputs, int r_FanOut);
 
	void SetGraphicsInfo(Output* pOut, const GraphicsInfo& gfxInfo);
 
	virtual int GetInputPinIndex(int x, int y);
 
	virtual void GetInputPinCoordinates(int& x, int& y, int n);
 
	virtual void GetOutputPinCoordinates(int& x, int& y);
 
	virtual Pin* GetInputPin(int n) = 0;
 
	virtual Pin* GetOutputPin() = 0;
 
	virtual Component* GetNextComponent(int index) = 0;
 
	virtual int GetConnectedCount() = 0;
 
	virtual ~Gate();
};
#endif
