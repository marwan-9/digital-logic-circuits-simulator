#include "Cut.h"
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
#include "..\Components\SWITCH.h"
#include "..\Components\XOR2.h"


Cut::Cut(ApplicationManager* pApp) :Action(pApp)
{
}

Cut::~Cut(void)
{
	delete ToCut;
}

void Cut::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("Click to Cut a component");

	//Wait for User Input
	pIn->GetPointClicked(Cx, Cy);

	//Clear Status Bar
	pOut->ClearStatusBar();

}

void Cut::Execute()
{
	ReadActionParameters();
	Output* pOut = pManager->GetOutput();
	ToCut = pManager->GetClickedComponent(Cx,Cy);
	//Handeling the cases of cutting nothing
	if (ToCut == NULL) return;
	if (Cutt == NULL) return;

	if (pManager->getCopied() != NULL)
	{
		pManager->DeleteCopy();
	}
	if (Cutt != NULL && pManager->getCopied() == NULL)
	{

		Cutt = ToCut->Copy();
		Cutt->setlabel(ToCut->getlabel());
		//TODO: Copy Labell
	}
	//Cutt = ToCut->Copy();
	//Cutt->setlabel(Cutt->getlabel());

	pManager->setCopied(Cutt);
	//TODO: Would Cut reps a problem when gates is connected ?
	pManager->deleteGate(ToCut);


	pManager->setcpyStatus(false);  //Means Cut
	pOut->ClearDrawingArea();
}

void Cut::Undo()
{
}

void Cut::Redo()
{
}