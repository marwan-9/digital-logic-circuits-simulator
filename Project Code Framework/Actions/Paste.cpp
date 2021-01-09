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
	//if (!CheckCoordinates(Cx, Cy)) return;
	ToPaste = pManager->getCopied();
	if (ToPaste == NULL)
		return;

	ToPaste->SetGraphics(Cx, Cy);
	pManager->AddComponent(ToPaste);
	Pasted = ToPaste;
	if (!pManager->getcpyStatus())
	{
		ToPaste = NULL;
		pManager->setCopied(NULL);
		return;
	}
	ToPaste = ToPaste->Copy();
	pManager->setCopied(ToPaste);
	//TODO :Paste Label

	void setCopied(Component * Copied);
}

void Paste::Undo()
{}

void Paste::Redo()
{}