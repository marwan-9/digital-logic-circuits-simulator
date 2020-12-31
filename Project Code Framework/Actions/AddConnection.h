#pragma once
#include "Action.h"
#include "../Components/Connection.h"

class AddConnection :
    public Action
{
private:
	// Center points of the source and destination pins
	int sCx, sCy, dCx, dCy;
public:
	AddConnection(ApplicationManager* pApp);
	virtual ~AddConnection(void);

	virtual void ReadActionParameters();

	//Execute action (code depends on action type)
	virtual void Execute();

	//To undo this action (code depends on action type)
	virtual void Undo();

	//To redo this action (code depends on action type)
	virtual void Redo();
};

