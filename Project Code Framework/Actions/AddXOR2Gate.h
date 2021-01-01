#ifndef _ADD_XOR2_GATE_H
#define _ADD_XOR2_GATE_H  XOR2

#include "action.h"
#include "..\Components\XOR2.h"

class AddXOR2Gate : public Action
{
private:
	//Parameters for rectangular area to be occupied by the gate
	int Cx, Cy;	//Center point of the gate
	int x1, y1, x2, y2;	//Two corners of the rectangluar area
public:
	AddXOR2Gate(ApplicationManager* pApp);
	virtual ~AddXOR2Gate(void);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();


};

#endif