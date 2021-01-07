#include "AddLabel.h"
#include "ApplicationManager.h"
AddLabel::AddLabel(ApplicationManager* pApp) :Action(pApp)
{
}

AddLabel::~AddLabel(void)
{
}

void AddLabel::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("label");

	//Wait for User Input
	pIn->GetPointClicked(Cx, Cy);

	//edit label when label is bresed and and is selected
	string str2 = "Add component (AND) new label : "; //ahmed
	pIn->GetSrting(pOut, str2, "");   //ahmed 

	//Clear Status Bar
	pOut->ClearStatusBar();

}

void AddLabel::Execute()
{


	
}

void AddLabel::Undo()
{}

void AddLabel::Redo()
{}

