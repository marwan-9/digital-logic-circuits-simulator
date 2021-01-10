#pragma once
#include "ApplicationManager.h"
#include "simulation.h"
simulation::simulation(ApplicationManager* pApp) : Action(pApp)
{
	point = NULL;
}
void simulation::ReadActionParameters()
{
	if (pManager->GetSelected() == NULL)
	{
		//Get a Pointer to the Input
		Input* pIn = pManager->GetInput();

		//Wait for User Input
		pIn->GetPosition(x, y);

		point = pManager->GetClickedComponent(x, y);
	}
	else
		point = pManager->GetSelected();

}

//Execute action
void simulation::Execute()
{
int compcount = pManager->GetCompCount(); int c = 1; int numofin = 0; //ahmed
	while (true) {
		Component** comp = pManager->getcomplist();
		for (int i = 0; i < compcount; i++) {
			numofin=comp[i]->GetNumOfInputs();
			int c = 1;
			for (int a = 1; a <= numofin; a++) {
				if (comp[i]->GetInputPinStatus(a) == UNASSIGNED){
					c = 0; 
					break;
				}
			}
			if (c) {
				comp[i]->Operate();
				comp[i]->GetOutPinStatus();
			}
				
			
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
		}
		*/