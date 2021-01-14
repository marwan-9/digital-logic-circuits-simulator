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
	pManager->DeselectExcept();
	UI.AppMode = SIMULATION;
	pOut->ClearWindow();
	pOut->CreateSimulationToolBar();
	pOut->CreateStatusBar();


	
}

void SwitchToSim::ReadActionParameters()
{

}

void SwitchToSim::Undo()
{}

void SwitchToSim::Redo()
{}

