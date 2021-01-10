#include "Load_Action.h"
#include "../ApplicationManager.h"
#include <fstream>

Load_Action::Load_Action(ApplicationManager* pApp): Action(pApp)
{
}

Load_Action::~Load_Action(void)
{
	file_name = "";
}

void Load_Action::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("Loading a file");

	file_name = pIn->GetSrting(pOut, "Enter the name of the file: ");

	//Clear Status Bar
	pOut->ClearStatusBar();
}

void Load_Action::Execute()
{
	// Get a pointer to the output interface to print an error message, if the file didn't open
	Output* pOut = pManager->GetOutput();

	ReadActionParameters();

	ifstream read("SavedFiles//" + file_name + ".txt");
	if (read.is_open()) {
		pManager->Load(read);
		read.close();
	}
	else
		pOut->PrintMsg("Error loading the file");
}

void Load_Action::Undo()
{
}

void Load_Action::Redo()
{
}
