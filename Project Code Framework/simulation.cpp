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