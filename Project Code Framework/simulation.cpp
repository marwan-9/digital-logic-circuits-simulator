#pragma once
#include "ApplicationManager.h"
#include "simulation.h"
//#include <string>
simulation::simulation(ApplicationManager* pApp) : Action(pApp)
{
	point = NULL;
}
void simulation::ReadActionParameters()
{
	//Get a Pointer to the Input

	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();	pOut->PrintMsg(" simulatioon ");

	//pOut->ClearStatusBar();

	//pOut->CreateSimulationToolBar();
	//pOut->PrintMsg(" simulatioon22 ");
	//Wait for User Input
	pIn->GetPosition(x, y);

	//Clear Status Bar
	//pOut->ClearStatusBar();
}
//Execute action
void simulation::Execute()
{
	ReadActionParameters(); // i think it must be in while or put getposition
	int compcount = pManager->GetCompCount(); int c = 1; int numofin = 0; int numofop = 0; //ahmed
	while (true) {
		Input* pIn = pManager->GetInput();//remove
		numofop = 0;//msh mota2kd en mafrod ttdaf hena
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
				numofop++;
				comp[i]->GetOutPinStatus();
			}
	
		}
		if (numofop == compcount)
			break;
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