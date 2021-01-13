#pragma once
#include "ApplicationManager.h"
#include "simulation.h"
#include "Components/LED.h"
#include "Components/Switch.h"

//#include <string>
simulation::simulation(ApplicationManager* pApp) : Action(pApp)
{
	//point = NULL;
}
void simulation::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	
	
	//Print Action Message
	pOut->PrintMsg("Click to select a switch");

	//Wait for User Input
	pIn->GetPointClicked(Cx, Cy);

	//Clear Status Bar
	pOut->ClearStatusBar();
}
//Execute action
void simulation::Execute()
{

	//ReadActionParameters(); // i think it must be in while or put getposition
	//int compcount = pManager->GetCompCount(); SEPNEEE 
	int c = 1; 
	int numofin = 0; 
	int numofop = 0;
	//int max = 20; //test
	     // 		Component** comp = pManager->getcomplist(); was HERE
	while (true) { 
		Input* pIn = pManager->GetInput();//remove
		Output* pOut = pManager->GetOutput();
		
		Component** comp = pManager->getcomplist();
		int compcount = pManager->GetCompCount();
		//pManager->GetSelected
		ReadActionParameters(); // i think it must be in while or put getposition
		
		//pIn->GetSrting(pOut, "enter loop ", " ");            // TEST
		//numofop = 0;  blash comented                 //msh mota2kd en mafrod ttdaf hena
		for (int i = 0; i < compcount; i++) 
		{
			numofin=comp[i]->GetNumOfInputs();
			c = 1;
			Switch* switchh = dynamic_cast<Switch*>(comp[i]);
			if (switchh) 
			{
						if (comp[i]->GetOutPinStatus() != HIGH && switchh->GetOutPinStatus() != LOW)
						{  
							//pIn->GetSrting(pOut, "enter cheak ", " ");     // TEST
							string msg1 = " ASSIGN SWITCH ";
							string msg2 = "HIGH OR LOW : ";
							string name = switchh->getlabel();
							string msg = msg1 + name + msg2;
							string str = pIn->GetSrting(pOut, msg, "");
							pOut->ClearStatusBar();

								if (str == "HIGH") {
									//switchh->setoutputpenstatus(HIGH);
								//	pIn->GetSrting(pOut, "high bro ", "");     // TEST
									comp[i]->GetOutputPin()->setStatus(STATUS::HIGH);
								}
								else if (str == "LOW") {
									comp[i]->GetOutputPin()->setStatus(STATUS::LOW);
								//	pIn->GetSrting(pOut, "low bro ", " ");     // TEST

									//switchh->setoutputpenstatus(LOW);
								}
								switchh->DrawStatus(pOut);
						}
				//numofop++;
			}
			if (!switchh) 
			{
				//pIn->GetSrting(pOut, "not switch ", " ");     // TEST
				for (int a = 1; a <= numofin; a++) 
				{
	                                          //pOut->ClearStatusBar();  //pIn->GetSrting(pOut, "enter cheak ", " ");
					if (comp[i]->GetInputPinStatus(a) == UNASSIGNED) {
						c = 0;
						break;
					}
				}
			}
			if (c) 
			{
				Switch* switchh = dynamic_cast<Switch*>(comp[i]);
				LED* led = dynamic_cast<LED*>(comp[i]);
					if (led) 
					{
						
						//pIn->GetSrting(pOut, "entered LED high wl a la ", " ");         //TEST
						if (led->GetInputPinStatus() == HIGH) 
						{
							Output* pOut = pManager->GetOutput();
							//pOut->PrintMsg("highhhhh");
							pOut->DrawLED(led->GetGraphics(), true);
							//pIn->GetSrting(pOut, "LED IS high ", " ");          //TEST
							//continue;
						}
					}
					if (!switchh && !led) 
					{
						comp[i]->Operate();
					}
					//pOut->ClearStatusBar();
					//pIn->GetSrting(pOut, "enter operate ", " ");
			}
		}					
		numofop++;  //pIn->GetSrting(pOut, "OPERATE ++ ", " ");
			if (numofop  == compcount) 
			{
				pIn->GetSrting(pOut, "EXIT WHILE ", " ");
				break;

			}
	}
/*
	ReadActionParameters();
	Component* pc = pManager->GetClickedComponent(Cx, Cy);
	if (pc == NULL || !dynamic_cast<Switch *>(pc))
		return;
	if (pc->GetOutputPin()->getStatus() == STATUS::HIGH)
		pc->GetOutputPin()->setStatus(STATUS::LOW);
	else
		pc->GetOutputPin()->setStatus(STATUS::HIGH);
	pManager->OperateAll();
	pManager->UpdateInterface();
*/
}

//To undo this action 
void simulation::Undo()
{

}

//To redo this action 
void simulation::Redo()
{

}

simulation :: ~simulation()
{

}

/*ReadActionParameters();
if (point != NULL) {
	if (pManager->GetSelected() == NULL)
	{
		pManager->SetSelected(point);
		point->SetIfSelected(true);
	}
	else
	{
		// point->SetIfSelected(false);
		pManager->SetSelected(NULL);
		Component** comp = pManager->getcomplist();
for (int i = 0; i < compcount; i++) {
	if (comp[i]->GetOutPinStatus()!=UNASSIGNED) {
		numofin=comp[i]->GetNumOfInputs();
		for (int a = 1; a < numofin;a++) {
			if (comp[i]->GetInputPinStatus(a) == UNASSIGNED)
				break;

				Switch* switchh = dynamic_cast<Switch*>(comp[i]);
				if (switch) {
					continue;
				}
		}
		*/
		/*if (switchh) {
							numofop++;
							continue; //do not operate skip switch
						}*/