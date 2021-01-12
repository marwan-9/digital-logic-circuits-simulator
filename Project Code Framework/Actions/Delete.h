#ifndef DELETE_H
#define DELETE_H

#include "Action.h"

#include "..\\ApplicationManager.h"

class Delete : public Action
{
private:
	int Cx, Cy;//Center point of the gate
	Component* ToDel;
	Component* Dell;

public:
	Delete(ApplicationManager* pApp);

	void ReadActionParameters();
	void Execute();
	void Undo();
	void Redo();
};
#endif
