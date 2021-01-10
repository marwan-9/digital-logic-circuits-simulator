#ifndef _CUT_H
#define _CUT_H
#include "Action.h"
#include "..\Components\Gate.h"
#include "Paste.h"

class Cut :public Action
{
private:

	int Cx, Cy;//Center point of the gate
	Component* ToCut;
	Component* Cutt;
public:
	Cut(ApplicationManager* pApp);
	~Cut(void);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();
	Component* getCopied();
	void setCut(Component*);
};

#endif
