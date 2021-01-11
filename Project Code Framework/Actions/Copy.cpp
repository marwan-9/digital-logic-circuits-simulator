#include "Copy.h"
#include "..\Components\AND2.h"
#include "..\ApplicationManager.h"
#include "..\Components\AND3.h"
#include "..\Components\Buffer.h"
#include "..\Components\Connection.h"
#include "..\Components\OR2.h"
#include "..\Components\NAND2.h"
#include "..\Components\NOR3.h"
#include "..\Components\Inverter.h"
#include "..\Components\Switch.h"
#include "..\Components\XOR2.h"
//Not all are included

Copy::Copy(ApplicationManager* pApp) :Action(pApp)
{
}

Copy::~Copy(void)
{
}

void Copy::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("Click to Copy a component");

	//Wait for User Input
	pIn->GetPointClicked(Cx, Cy);

	//Clear Status Bar
	pOut->ClearStatusBar();

}

void Copy::Execute()
{
	ReadActionParameters();
	ToCopy = pManager->GetClickedComponent(Cx,Cy); //EL MAFROOD getselected(); !!!!!
	if (ToCopy == NULL) return;
	Copied = NULL;
	
	//lw fee 7aga ma3molaha copy ttms77 mn el memory
	if (pManager->getCopied() != NULL)
	{
		pManager->DeleteCopy();
	}
	
	if (ToCopy != NULL && pManager->getCopied() == NULL)
	{
		
		Copied = ToCopy->Copy();
		
		//TODO: Copy Labell
	}


	pManager->setCopied(Copied);
	pManager->setcpyStatus(true); //COPY NOT CUT

}

void Copy::Undo()
{}

void Copy::Redo()
{}