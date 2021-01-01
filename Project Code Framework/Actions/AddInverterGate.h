#ifndef _ADD_INVERTER_GATE_H
#define _ADD_INVERTER_GATE_H

#include "action.h"
#include "..\Components\Inverter.h"

class AddInverterGate : public Action
{
private:
	//Parameters for rectangular area to be occupied by the gate
	int Cx, Cy;	//Center point of the gate
	int x1, y1, x2, y2;	//Two corners of the rectangluar area
public:
	AddInverterGate(ApplicationManager* pApp);
	virtual ~AddInverterGate(void);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();


};

#endif