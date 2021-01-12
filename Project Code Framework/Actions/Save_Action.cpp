#include "Save_Action.h"
#include "../ApplicationManager.h"
#include <string>
#include <fstream>
#include <iostream>

Save_Action::Save_Action(ApplicationManager* pApp): Action(pApp)
{
}

Save_Action::~Save_Action(void)
{
}

void Save_Action::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("Saving the circuit");

	file_name = pIn->GetSrting(pOut, "Enter the name of the file: ");

	//Clear Status Bar
	pOut->ClearStatusBar();
}

void Save_Action::Execute()
{
	// Get a pointer to the output interface to print an error message, if the file didn't open
	Output* pOut = pManager->GetOutput();

	ReadActionParameters();
	ofstream write("SavedFiles//" + file_name+".txt");
	if (write.is_open()) {
		pManager->Save(write);
		write.close();
	}
	else
		pOut->PrintMsg("Couldn't save the file");
}

void Save_Action::Undo()
{
}

void Save_Action::Redo()
{
}
