#ifndef SELECT_H
#define SELECT_H

#include "Action.h"
#include "..\\Components\\Gate.h"
#include "..\\GUI\Input.h"
#include "..\\ApplicationManager.h"

class Select : public Action
{
private:
	int x, y;
	Component* target;
public:
	Select(ApplicationManager* pApp);
	
	void ReadActionParameters();
	void Execute(); 
	void Undo(); 
	void Redo();
	~Select();
};

#endif
