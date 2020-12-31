#include "AddXOR2Gate.h"
#include "..\ApplicationManager.h"

AddXOR2Gate::AddXOR2Gate(ApplicationManager* pApp) :Action(pApp)
{
}

AddXOR2Gate::~AddXOR2Gate(void)
{
}

void AddXOR2Gate::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("XOR2 Gate: Click to add the gate");

	//Wait for User Input
	pIn->GetPointClicked(Cx, Cy);

	//Clear Status Bar
	pOut->ClearStatusBar();

}

void AddXOR2Gate::Execute()
{
	//Get Center point of the Gate
	ReadActionParameters();

	//Calculate the rectangle Corners
	int Len = UI.AND2_Width;
	int Wdth = UI.AND2_Height;

	GraphicsInfo GInfo; //Gfx info to be used to construct the XOR2 gate

	GInfo.x1 = Cx - Len / 2;
	GInfo.x2 = Cx + Len / 2;
	GInfo.y1 = Cy - Wdth / 2;
	GInfo.y2 = Cy + Wdth / 2;
	XOR2* pA = new XOR2(GInfo, XOR2_FANOUT);
	pManager->AddComponent(pA);
}

void AddXOR2Gate::Undo()
{}

void AddXOR2Gate::Redo()
{}

