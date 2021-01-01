#ifndef _NAND2_H
#define _NAND2_H

/*
  Class AND2
  -----------
  represent the 2-input AND gate
*/

#include "Gate.h"

class NAND2 :public Gate
{
public:
	NAND2(const GraphicsInfo& r_GfxInfo, int r_FanOut);
	virtual void Operate();	//Calculates the output of the AND gate
	virtual void Draw(Output* pOut);	//Draws 2-input gate

	virtual int GetOutPinStatus();	//returns status of outputpin if LED, return -1
	virtual int GetInputPinStatus(int n);	//returns status of Inputpin # n if SWITCH, return -1

	virtual void setInputPinStatus(int n, STATUS s);	//set status of Inputpin # n, to be used by connection class.


};

#endif