#include "SwitchToSim.h"

//#include "Simulation.h"
#include "..\ApplicationManager.h"

SwitchToSim::SwitchToSim(ApplicationManager* pApp) :Action(pApp)
{
}

SwitchToSim::~SwitchToSim()
{
}


void SwitchToSim::Execute()
{

	Output* pOut = pManager->GetOutput();

	bool valid = true; //pManager->validate();
	if (valid) {
		int num;
		pManager->DeselectExcept();
		UI.AppMode = SIMULATION;
		pOut->ClearWindow();
		pOut->CreateSimulationToolBar();
		// pManager->ExecuteAction(SIMULATE);
	}
	else
		pOut->PrintMsg("Ciruit is not Valid");



	
}

void SwitchToSim::ReadActionParameters()
{

}

void SwitchToSim::Undo()
{}

void SwitchToSim::Redo()
{}

