#include "SwitchToDsg.h"
#include "..\ApplicationManager.h"

SwitchToDsg::SwitchToDsg(ApplicationManager* pApp) :Action(pApp)
{
}

SwitchToDsg::~SwitchToDsg()
{
}


void SwitchToDsg::Execute()
{

	Output* pOut = pManager->GetOutput();


	
	pManager->DeselectExcept();
	UI.AppMode = DESIGN;
	pOut->ClearWindow();
	pOut->CreateDesignToolBar();
	pOut->CreateStatusBar();
	
}

void SwitchToDsg::ReadActionParameters()
{

}

void SwitchToDsg::Undo()
{}

void SwitchToDsg::Redo()
{}