#pragma once
#include "Action.h"
#include "../Components/Connection.h"

class AddConnection :
    public Action
{
private:
	Component* SrcCmpt;
	Component* DstCmpt;
	OutputPin* SrcPin;	//The Source pin of this connection (an output pin of certain Component)
	InputPin* DstPin;	//The Destination pin of this connection (an input pin of certain Component)
	int		PinNumber;		//The Input pin to which this connection is linked
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

