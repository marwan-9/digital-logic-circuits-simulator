#include "Select.h"
#include "..\ApplicationManager.h"

Select::Select(ApplicationManager* pApp): Action(pApp)
{
	point = NULL;
}
void Select::ReadActionParameters()
{
	if (pManager->GetSelected() == NULL)
	{
		//Get a Pointer to the Input
		Input* pIn = pManager->GetInput();

		//Wait for User Input
		pIn->GetPosition(x, y);

		point = pManager->GetClickedComponent(x, y);
	}
	else
		point = pManager->GetSelected();

}

//Execute action
void Select::Execute()
{
	ReadActionParameters();
	if (point != NULL)
	if (pManager->GetSelected() == NULL)
	{
		pManager->SetSelected(point);
		point->SetIfSelected(true);
	}
	else
	{
		pManager->SetSelected(NULL);
		point->SetIfSelected(false);
	}
}

//To undo this action 
void Select::Undo()
{

}

//To redo this action 
void Select::Redo()
{

}

Select :: ~Select()
{

}