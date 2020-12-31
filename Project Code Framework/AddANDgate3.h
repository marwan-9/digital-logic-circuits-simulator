#ifndef _ADD_AND3_GATE_H
#define _ADD_AND3_GATE_H

//#include "action.h"
#include"Actions/Action.h"
//#include "..\Components\AND2.h"
#include "AND3.h"

class AddANDgate3 : public Action
{
private:
	//Parameters for rectangular area to be occupied by the gate
	int Cx, Cy;	//Center point of the gate
	int x1, y1, x2, y2;	//Two corners of the rectangluar area
public:
	AddANDgate3(ApplicationManager* pApp);
	virtual ~AddANDgate3(void);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();


};

#endif
