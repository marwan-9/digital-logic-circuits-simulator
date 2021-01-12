#ifndef _SwitchToSim_H
#define _SwitchToSimu_H

#include "action.h"


class SwitchToSim : public Action
{

public:
	SwitchToSim(ApplicationManager* pApp);
	virtual ~SwitchToSim();


	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void ReadActionParameters();
	virtual void Undo();
	virtual void Redo();


};

#endif