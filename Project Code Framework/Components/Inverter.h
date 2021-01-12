#ifndef _Inverter_H
#define _Inverter_H

/*
  Class Inverter
  -----------
  represent the Inverter gate
*/

#include "Gate.h"

class Inverter:public Gate
{
public:
	Inverter(const GraphicsInfo& r_GfxInfo, int r_FanOut);
	virtual void Operate();	//Calculates the output of the Inverter gate
	virtual void Draw(Output* pOut);	//Draws Inverter gate

	virtual int GetOutPinStatus();	//returns status of outputpin if LED, return -1
	virtual int GetInputPinStatus(int n);	//returns status of Inputpin # n if SWITCH, return -1

	virtual void setInputPinStatus(int n, STATUS s);	//set status of Inputpin # n, to be used by connection class.
	virtual Component* Copy();

};

#endif