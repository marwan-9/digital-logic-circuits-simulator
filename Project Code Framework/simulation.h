#pragma once
//#include "Action.h"
#include "Actions/Action.h"
#include "Components\Component.h"
//#include ""
class simulation : public Action
{
private:
	int Cx, Cy;
	//Component* point;
public:
	simulation(ApplicationManager* pApp);
	virtual void ReadActionParameters();

	//Execute action (code depends on action type)
	virtual void Execute();

	//To undo this action (code depends on action type)
	virtual void Undo();

	//To redo this action (code depends on action type)
	virtual void Redo();

	~simulation();
};

