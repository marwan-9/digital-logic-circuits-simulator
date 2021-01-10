#pragma once
#include "Action.h"

class Load :
	public Action
{

public:
	Load(ApplicationManager* pApp);
	virtual ~Load(void);
	//Reads parameters required for action to execute
	virtual void ReadActionParameters();

	//Execute action (code depends on action type)
	virtual void Execute();

	//To undo this action (code depends on action type)
	virtual void Undo();

	//To redo this action (code depends on action type)
	virtual void Redo();

};

