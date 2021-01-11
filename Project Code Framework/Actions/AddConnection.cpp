#include "AddConnection.h"
#include "../ApplicationManager.h"

AddConnection::AddConnection(ApplicationManager* pApp):Action(pApp)
{
	SrcCmpt = NULL;
	DstCmpt = NULL;
	DstPin = 0;
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
	SrcCmpt = pManager->GetClickedComponent(sCx, sCy);
	while (SrcCmpt == NULL ) {
		pOut->PrintMsg("Couldn't connect a component, try again!");
		pIn->GetPointClicked(sCx, sCy);
		SrcCmpt = pManager->GetClickedComponent(sCx, sCy);
	}


	pOut->PrintMsg("Wire two components: Click on the destination pin");
	pIn->GetPointClicked(dCx, dCy);
	DstCmpt = pManager->GetClickedComponent(dCx, dCy);
	while (DstCmpt == NULL || !DstCmpt->Connect(1)) {
		pOut->PrintMsg("Couldn't find a component, try again!");
		pIn->GetPointClicked(sCx, sCy);
		DstCmpt = pManager->GetClickedComponent(dCx, dCy);
	}
	pOut->ClearStatusBar();

}


void AddConnection::Execute()
{
	//Get Center points of source and destination pins
	ReadActionParameters();

	GraphicsInfo GInfo; //Gfx info to be used to construct the Inverter gate

	GInfo.x1 = sCx;
	GInfo.y1 = sCy;
	GInfo.x2 = dCx;
	GInfo.y2 = dCy;
	
	Connection* pA = new Connection(GInfo, SrcCmpt,DstCmpt, DstPin);
	pManager->AddComponent(pA);
}

void AddConnection::Undo()
{
}

void AddConnection::Redo()
{
}
