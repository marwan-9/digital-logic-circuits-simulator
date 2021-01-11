#pragma once //delete
#include "AddLabel.h"
#include "ApplicationManager.h"
#include "Components\Gate.h"
/*
#include "Copy.h"
#include "..\Components\AND2.h"
#include "..\ApplicationManager.h"
#include "..\Components\AND3.h"
#include "..\Components\Buffer.h"
#include "..\Components\Connection.h"
#include "..\Components\OR2.h"
#include "..\Components\NAND2.h"
#include "..\Components\NOR3.h"
#include "..\Components\Inverter.h"
#include "..\Components\Switch.h"
#include "..\Components\XOR2.h"
*/
//Not all are included
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
	pOut->PrintMsg("please select the componenet to be labeled ");

	//Wait for User Input
	pIn->GetPointClicked(Cx, Cy); //here
	//pOut->ClearStatusBar();//here
}

void AddLabel::Execute()
{
	ReadActionParameters();
	Selected = pManager->GetClickedComponent(Cx,Cy);
	if (Selected!=NULL)
	{
		Output* pOut = pManager->GetOutput();
		Input* pIn = pManager->GetInput();
		
		string str2 = "enter label to the component : ";
		
		Selected->setlabel(pIn->GetSrting(pOut, str2, ""));
		//pOut->ClearDrawingArea();
		pManager->UpdateInterface(Cx,Cy);

		/* 
		string label = Selected->getlabel();
		const char* cpText= label.c_str(); 
		pManager->UpdateInterface();
	
		pOut->Printstringg(Cx-7, Cy-15, cpText); */
		pOut->ClearStatusBar();
		//	strcpy(cpText, str2.c_str()); 
	}
}

void AddLabel::Undo()
{}

void AddLabel::Redo()
{}
////////////////
/*
* 
* 
* 
* ReadActionParameters();
	Selected = pManager->GetSelectedCx,Cy);
	if (Selected!=NULL)
	{
		Output* pOut = pManager->GetOutput();
		Input* pIn = pManager->GetInput();
		string str2 = "enter label to the component : ";
		Selected->setlabel(pIn->GetSrting(pOut, str2, ""));
		pOut->ClearStatusBar();
	}
}

////////////////
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

*/
/* AddLabel::~AddLabel(void)
{
}
void AddLabel::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("please select the componenet to be labeled ");

	//Wait for User Input
	pIn->GetPointClicked(Cx, Cy); //here
	//pOut->ClearStatusBar();//here
}

void AddLabel::Execute()
{

	ReadActionParameters();
	Selected = pManager->GetClickedComponent(Cx,Cy);
	if (Selected!=NULL)
	{
		Output* pOut = pManager->GetOutput();
		Input* pIn = pManager->GetInput();
		string str2 = "enter label to the component : ";
		Selected->setlabel(pIn->GetSrting(pOut, str2, ""));
		pOut->Printstringg(Cx, Cy, str2);
		pOut->ClearStatusBar();
	}
}*/