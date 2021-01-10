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
	Output *pOut = pManager->GetOutput();
	Input * pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("label");

	//Wait for User Input
	pIn->GetPointClicked(Cx, Cy);

	//edit label when label is bresed and and is selected
	string str2 = "Add component (AND) new label hii : "; //ahmed
	pIn->GetSrting(pOut, str2, "");   //ahmed 

	//Clear Status Bar
	pOut->ClearStatusBar();

}

void AddLabel::Execute()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	ReadActionParameters();

	//Calculate the rectangle Corners
	int Len = UI.AddLabel_Width;
	int Wdth = UI.AddLabel_Height;

	GraphicsInfo GInfo; //Gfx info to be used to construct the AND2 gate

	GInfo.x1 = Cx - Len / 2;
	GInfo.x2 = Cx + Len / 2;
	GInfo.y1 = Cy - Wdth / 2;
	GInfo.y2 = Cy + Wdth / 2;
	//AddLabel* pA = new AddLabel(GInfo, NAND2_FANOUT);
	//pManager->AddComponent(pA);
	
		//edit label when label is bresed and and is selected
	//string str2 = "Add component (AND) new label hii : "; //ahmed
	//pIn->GetSrting(pOut, str2, "");   //ahmed 
}

void AddLabel::Undo()
{}

void AddLabel::Redo()
{}

