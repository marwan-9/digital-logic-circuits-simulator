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
	//Get a Pointer to the Input

	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();	
	//pOut->PrintMsg(" simulatioon ");

	//pOut->ClearStatusBar();

	//pOut->CreateSimulationToolBar();
	//pOut->PrintMsg(" simulatioon22 ");
	//Wait for User Input
	//pIn->GetPosition(x, y);

	//Clear Status Bar
	//pOut->ClearStatusBar();
}
//Execute action
void simulation::Execute()
{
	ReadActionParameters(); // i think it must be in while or put getposition
	int compcount = pManager->GetCompCount(); 
	int c = 1; int numofin = 0; int numofop = 0; //ahmed
	Component** comp = pManager->getcomplist(); //was in loop
	while (true) { 
		ReadActionParameters(); // i think it must be in while or put getposition
		Input* pIn = pManager->GetInput();//remove
		Output* pOut = pManager->GetOutput();
		//pIn->GetSrting(pOut, "enter loop ", " ");
		numofop = 0;//msh mota2kd en mafrod ttdaf hena
		for (int i = 0; i < compcount; i++) {
			numofin=comp[i]->GetNumOfInputs();
			int c = 1;

			Switch* switchh = dynamic_cast<Switch*>(comp[i]);
			if (switchh) {
				if (comp[i]->GetOutPinStatus() != HIGH && switchh->GetOutPinStatus() != LOW)
				{
					//pIn->GetSrting(pOut, "enter cheak ", " ");
					string msg1 = " ASSIGN SWITCH ";
					string msg2 = "HIGH OR LOW : ";
					string name = switchh->getlabel();
					string msg = msg1 + name + msg2;
					string str = pIn->GetSrting(pOut, msg, " ");
					if (str == "HIGH") {
						//switchh->setoutputpenstatus(HIGH);
						comp[i]->GetOutputPin()->setStatus(HIGH);
					}

					else if (str == "LOW") {
						comp[i]->GetOutputPin()->setStatus(LOW);
						//switchh->setoutputpenstatus(LOW);
					}
				}
			}
			if (!switchh) {
				for (int a = 1; a <= numofin; a++) {
					//pOut->ClearStatusBar();
					//pIn->GetSrting(pOut, "enter cheak ", " ");
					if (comp[i]->GetInputPinStatus(a) == UNASSIGNED) {
						c = 0;
						break;
					}
				}
			}
			if (c) {
				Switch* switchh = dynamic_cast<Switch*>(comp[i]);
				LED* led = dynamic_cast<LED*>(comp[i]);
				if (led) {
					numofop++;
					//pIn->GetSrting(pOut, "entered high wl a la ", " ");
					if (led->GetInputPinStatus() == HIGH) {
						Output* pOut = pManager->GetOutput();
						//pOut->PrintMsg("highhhhh");
						pOut->DrawLED(led->Getinfo(pOut), true);
						//pIn->GetSrting(pOut, "entered high ", " ");
						//continue;
					}
					}
				if (!switchh && !led) {
					comp[i]->Operate();
				}
				//pOut->ClearStatusBar();
				//pIn->GetSrting(pOut, "enter operate ", " ");
				numofop++;
				}
		}
		if (numofop == compcount) {
			break;
		}
	}
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