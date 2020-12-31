#include "AddConnection.h"
#include "../ApplicationManager.h"

AddConnection::AddConnection(ApplicationManager* pApp):Action(pApp)
{
}

AddConnection::~AddConnection(void)
{
}

void AddConnection::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMsg("Wire two components: Click on the source pin");
	pIn->GetPointClicked(sCx, sCy);
	pOut->ClearStatusBar();

	pOut->PrintMsg("Wire two components: Click on the destination pin");
	pIn->GetPointClicked(dCx, dCy);
	pOut->ClearStatusBar();

	// Waiting for the Select Action to be implemented

}


void AddConnection::Execute()
{
	//Get Center points of source and destination pins
	ReadActionParameters();

	// Waiting for the Select Action to be implemented
	//TODO: get a pointer to the source and destination pins


	// Connection* pA = new Connection(GInfo, SrcPin, DstPin);
	// pManager->AddComponent(pA);
}

void AddConnection::Undo()
{
}

void AddConnection::Redo()
{
}
