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
		
		
		if (Clicked_one->GetLabel() == "DefaultLabel") {            //ADD NOT EDIT
			Output* pOut = pManager->GetOutput();
			Input* pIn = pManager->GetInput();

			string str2 = "Enter Label to the Component : ";
			Clicked_one->SetLabel(pIn->GetSrting(pOut, str2, "") );

			pOut->ClearStatusBar();
		}


		else {                                         //EDIT NOT ADD
			
			Output* pOut = pManager->GetOutput();
			Input* pIn = pManager->GetInput();
			string str2 = "Edit Label of the Component : ";
			Clicked_one->SetLabel(pIn->GetSrting(pOut, str2, ""));
			pOut->ClearStatusBar();
		}
	}
}


void AddLabel::Undo()
{}

void AddLabel::Redo()
{}
