#include "Delete.h"

Delete::Delete(ApplicationManager* pApp) : Action(pApp)
{
}

void Delete::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("Click to Delete a component");

	//Wait for User Input
	pIn->GetPointClicked(Cx, Cy);

	//Clear Status Bar
	pOut->ClearStatusBar();
}

void Delete::Execute()
{
	//pManager->DeleteComp();

	ReadActionParameters();
	Output* pOut = pManager->GetOutput();
	ToDel = pManager->GetClickedComponent(Cx,Cy);
	//Handeling the cases of cutting nothing
	if (ToDel == NULL) return;
	if (Dell == NULL) return;


	//TODO: Would Cut reps a problem when gates is connected ?
	pManager->deleteGate(ToDel);

	pOut->ClearDrawingArea();
}

void Delete::Undo()
{
}

void Delete::Redo()
{
}
