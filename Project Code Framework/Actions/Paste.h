#ifndef _PASTE_H
#define _PASTE_H
#include "Action.h"

#include "..\Components\Gate.h"
class Paste :public Action
{
private:

	int Cx, Cy;//Center point of the gate
	Component* ToPaste;
	Component* Pasted;

public:
	Paste(ApplicationManager* pApp);
	~Paste(void);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();
	void setCopied(Component*);

};

#endif

