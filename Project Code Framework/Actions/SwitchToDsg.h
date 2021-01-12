#ifndef _SwitchToDesign_H
#define _SwitchToDesign_H

#include "action.h"


class SwitchToDsg : public Action
{

public:
	SwitchToDsg(ApplicationManager* pApp);
	virtual ~SwitchToDsg();


	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void ReadActionParameters();
	virtual void Undo();
	virtual void Redo();


};

#endif