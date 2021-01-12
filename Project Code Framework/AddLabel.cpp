#pragma once //delete
#include "AddLabel.h"
#include "ApplicationManager.h"
#include "Components\Gate.h"

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
	Output* pOut = pManager->GetOutput();
	Component* Clicked_one = pManager->GetClickedComponent(Cx, Cy); //Returns the clicked component
	               
	if (Clicked_one != NULL)
	{
		corner1 = Clicked_one->getcorners().x1;  //Upper Left Corner of the clicked component
		corner2 = Clicked_one->getcorners().y1;
		
		
		if (Clicked_one->GetLabel() == "") {            //ADD NOT EDIT
			Output* pOut = pManager->GetOutput();
			Input* pIn = pManager->GetInput();

			string str2 = "Enter Label to the Component : ";
			Clicked_one->SetLabel(pIn->GetSrting(pOut, str2, "") );

			//string label = Clicked_one->getlabel();
			//const char* cpText = label.c_str();
			//pOut->Printstringg(corner1 - 5, corner2 + 50, Clicked_one->getlabel());
			//pOut->Printstringg(corner1 - 5, corner2 + 50, cpText);
			//pManager->UpdateInterface();
			pOut->ClearStatusBar();
		}


		else {                                         //EDIT NOT ADD
			
			Output* pOut = pManager->GetOutput();
			Input* pIn = pManager->GetInput();
			string str2 = "Edit Label of the Component : ";
			
			Clicked_one->SetLabel(pIn->GetSrting(pOut, str2, ""));
			//string label = Clicked_one->getlabel();
			//const char* cpText = label.c_str();
			//pOut->cleartext(corner1 - 5, corner2 + 50, corner1 + 300, corner2 + 75)
			//pOut->Printstringg(corner1 - 5, corner2 + 50, Clicked_one->getlabel());
			//pOut->ClearDrawingArea();
			
			pOut->ClearStatusBar();
			//pManager->UpdateInterface();
		}

	}
	//pManager->UpdateInterface();
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