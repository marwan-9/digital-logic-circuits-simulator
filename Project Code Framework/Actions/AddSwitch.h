#pragma once

#include "Action.h"
#include "../Components/Switch.h"

class AddSwitch :
    public Action
{
private:
	//Parameters for rectangular area to be occupied by the component
	int Cx, Cy;	//Center point of the component
	int x1, y1, x2, y2;	//Two corners of the rectangluar area
public:
	AddSwitch(ApplicationManager* pApp);
	virtual ~AddSwitch(void);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();


};

