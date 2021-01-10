#pragma once
#include "Action.h"
#include <string>
using namespace std;


class Load_Action:
	public Action
{
	string file_name;
public:
	Load_Action(ApplicationManager* pApp);
	virtual ~Load_Action(void);
	//Reads parameters required for action to execute
	virtual void ReadActionParameters();

	//Execute action (code depends on action type)
	virtual void Execute();

	//To undo this action (code depends on action type)
	virtual void Undo();

	//To redo this action (code depends on action type)
	virtual void Redo();

};

