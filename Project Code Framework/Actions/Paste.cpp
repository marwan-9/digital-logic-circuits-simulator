#include "Copy.h"
#include "Paste.h"
#include "..\Components\AND2.h"
#include "..\ApplicationManager.h"
#include "..\Components\AND3.h"
#include "..\Components\Buffer.h"
#include "..\Components\Connection.h"
#include "..\Components\OR2.h"
#include "..\Components\NAND2.h"
#include "..\Components\NOR3.h"
#include "..\Components\Inverter.h"
#include "..\Components\SWITCH.h"
#include "..\Components\XOR2.h"
#include "AddANDgate2.h"
#include "AddANDgate3.h"
#include "AddBuffergate.h"
#include "AddNANDgate2.h"
#include "AddNORgate3.h"
#include "AddInvertergate.h"
#include "AddORgate2.h"
#include "AddSwitch.h"
#include "AddXOR2gate.h"


Paste::Paste(ApplicationManager* pActionpp) :Action(pActionpp)
{
}

Paste::~Paste(void)
{
}

void Paste::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("Click to Paste a component");

	//Wait for User Input
	pIn->GetPointClicked(Cx, Cy);

	//Clear Status Bar
	pOut->ClearStatusBar();

}

void Paste::Execute()
{

	//Get Center point of the Gate
	ReadActionParameters();
	ToPaste = pManager->getCopied();
	if (ToPaste == NULL)
		return;
	pManager->AddComponent(ToPaste);
	ToPaste->SetGraphics(Cx, Cy);
	//If Cut not copy (Elimanating Clipboard)
	if (!pManager->getcpyStatus())
	{
		ToPaste = NULL;
		pManager->setCopied(NULL);
		return;
	}
	//If Copy not Cut (Maintaing Clipboard)
	ToPaste = ToPaste->Copy();   //Creating a new instance from the copied item
	pManager->setCopied(ToPaste);
	ToPaste->SetLabel(pManager->getCopied()->GetLabel());
	
	//TODO :Paste Label

}

void Paste::Undo()
{}

void Paste::Redo()
{}