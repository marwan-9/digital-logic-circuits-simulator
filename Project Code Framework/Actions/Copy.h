#ifndef _COPY_H
#define _COPY_H
#include "Action.h"
#include "..\Components\Gate.h"


class Copy :public Action
{
private:

	int Cx, Cy;//Center point of the gate
	Component* Copied;
	Component* ToCopy;
public:
	Copy(ApplicationManager* pApp);
	~Copy(void);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();


};

#endif
