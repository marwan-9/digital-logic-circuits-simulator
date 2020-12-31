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

}


void AddConnection::Execute()
{
	//Get Center points of source and destination pins
	ReadActionParameters();

	/* 
	//Calculate the rectangle Corners
	int Len = UI.AND2_Width;
	int Wdth = UI.AND2_Height;

	GraphicsInfo GInfo; //Gfx info to be used to construct the AND2 gate

	GInfo.x1 = Cx - Len / 2;
	GInfo.x2 = Cx + Len / 2;
	GInfo.y1 = Cy - Wdth / 2;
	GInfo.y2 = Cy + Wdth / 2;
	*/

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
