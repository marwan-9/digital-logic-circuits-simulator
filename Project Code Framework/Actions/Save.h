#pragma once
#include "Action.h"

class Save :
    public Action
{

public:
	Save(ApplicationManager* pApp);
	virtual ~Save(void);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();

	//Execute action (code depends on action type)
	virtual void Execute();

	//To undo this action (code depends on action type)
	virtual void Undo();

	//To redo this action (code depends on action type)
	virtual void Redo();

};

