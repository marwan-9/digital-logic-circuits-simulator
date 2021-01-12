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
	pOut->ClearWindow();
	pOut->CreateDesignToolBar();
	
}

void SwitchToDsg::ReadActionParameters()
{

}

void SwitchToDsg::Undo()
{}

void SwitchToDsg::Redo()
{}