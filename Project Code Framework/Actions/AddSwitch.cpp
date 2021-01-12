#include "AddSwitch.h"
#include "..\ApplicationManager.h"

AddSwitch::AddSwitch(ApplicationManager* pApp):Action(pApp)
{
}

AddSwitch::~AddSwitch(void)
{
}

void AddSwitch::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("A switch Component: Click to add the switch");

	//Wait for User Input
	pIn->GetPointClicked(Cx, Cy);
	//check if within drawing area
	while (!(Cy > UI.ToolBarHeight + UI.GateBarHeight + UI.AND2_Width / 2 && Cy < (UI.height - UI.StatusBarHeight) - UI.AND2_Width / 2))
	{
		pOut->PrintMsg("You are not allowed to print your label outside the drawing area, choose your place again...");
		pIn->GetPointClicked(Cx, Cy);
	}

	//Clear Status Bar
	pOut->ClearStatusBar();
}

void AddSwitch::Execute()
{
	//Get Center point of the Gate
	ReadActionParameters();

	//Calculate the rectangle Corners
	int Len = UI.Switch_Width;
	int Wdth = UI.Switch_Height;

	GraphicsInfo GInfo; //Gfx info to be used to construct the AND2 gate

	GInfo.x1 = Cx - Len / 2;
	GInfo.x2 = Cx + Len / 2;
	GInfo.y1 = Cy - Wdth / 2;
	GInfo.y2 = Cy + Wdth / 2;
	Switch* pA = new Switch(GInfo, Switch_FANOUT);
	pManager->AddComponent(pA);
}

void AddSwitch::Undo()
{
}

void AddSwitch::Redo()
{
}
