#include "AddConnection.h"
#include "../ApplicationManager.h"

AddConnection::AddConnection(ApplicationManager* pApp):Action(pApp)
{
	SrcPin = NULL;
	DstPin = NULL;
	SrcCmpnt = NULL;
	DstCmpnt = NULL;
	PinNumber = 0;
}

AddConnection::~AddConnection(void)
{
}

void AddConnection::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	if (pManager->GetCompCount() < 2) {
		pOut->PrintMsg("too few components to be wired.");
		return;
	}


	do {
		pOut->PrintMsg("Wire two components: Click on the source pin");
		pIn->GetPointClicked(sCx, sCy);
		SrcCmpnt = pManager->GetClickedComponent(sCx, sCy);
	} while (SrcCmpnt == NULL);

	SrcPin = SrcCmpnt->GetOutputPin();

	
	do {
		pOut->PrintMsg("Wire two components: Click on the destination pin");
		pIn->GetPointClicked(dCx, dCy);
		DstCmpnt = pManager->GetClickedComponent(dCx, dCy);
	} while (DstCmpnt == NULL);

	PinNumber = DstCmpnt->GetPinNumber();
	DstPin = DstCmpnt->GetInputPins(PinNumber);
	
	pOut->ClearStatusBar();

}


void AddConnection::Execute()
{
	//Get Center points of source and destination pins
	ReadActionParameters();

	Output* pOut = pManager->GetOutput();
	
	GraphicsInfo GInfo; 

	GInfo.x1 = sCx;
	GInfo.y1 = sCy;
	GInfo.x2 = dCx;
	GInfo.y2 = dCy;


	Connection* pA = new Connection(GInfo, SrcPin, DstPin, SrcCmpnt, DstCmpnt, PinNumber);
	if (pA->CanConnect())
		pManager->AddComponent(pA);
	else
	{
		delete pA;
		pOut->PrintMsg("Couldn't Connect these two components");
	}
		
}

void AddConnection::Undo()
{
}

void AddConnection::Redo()
{
}
