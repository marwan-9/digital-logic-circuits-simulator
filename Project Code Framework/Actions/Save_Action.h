#pragma once
#include "Action.h"
#include <string>

using namespace std;

class Save_Action :
    public Action
{
private:
	string file_name;
public:
	Save_Action(ApplicationManager* pApp);
	virtual ~Save_Action(void);

	virtual void ReadActionParameters();
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();

};

