#include "ApplicationManager.h"
#include "Actions\AddANDgate2.h"
#include "Actions/AddORgate2.h"
#include "Actions/AddSwitch.h"
#include "Actions/AddLED.h"
#include "Actions/AddInverterGate.h"
#include "Actions/AddBufferGate.h"
#include "Actions/AddXOR2Gate.h"
#include "Actions/AddANDgate3.h"
#include "Actions/AddNANDgate2.h"
#include "Actions/AddNORgate3.h"
#include "Actions/AddNORgate2.h"
#include "Actions/AddXORgate3.h"
#include "Actions/AddXNORgate2.h"
#include "Actions\Select.h"

ApplicationManager::ApplicationManager()
{
	CompCount = 0;

	for(int i=0; i<MaxCompCount; i++)
		CompList[i] = NULL;

	//Creates the Input / Output Objects & Initialize the GUI
	OutputInterface = new Output();
	InputInterface = OutputInterface->CreateInput();
}
////////////////////////////////////////////////////////////////////
void ApplicationManager::AddComponent(Component* pComp)
{
	CompList[CompCount++] = pComp;		
}
////////////////////////////////////////////////////////////////////

ActionType ApplicationManager::GetUserAction()
{
	//Call input to get what action is reuired from the user
	return InputInterface->GetUserAction(); 	
}
////////////////////////////////////////////////////////////////////

void ApplicationManager::ExecuteAction(ActionType ActType)
{
	Action* pAct = NULL;
	switch (ActType)
	{
		case ADD_AND_GATE_2:
			pAct= new AddANDgate2(this);
			break;
		case ADD_OR_GATE_2:
			pAct = new AddORgate2(this);
			break;
		case ADD_NAND_GATE_2:
			pAct = new AddNANDgate2(this);
			break;
		case ADD_NOR_GATE_2:
			pAct = new AddNORgate2(this);
			break;
		case ADD_XOR_GATE_2:
			pAct = new AddXOR2Gate(this);
			break;
		case ADD_XNOR_GATE_2:
			pAct = new AddXNORgate2(this);
			break;
		case ADD_AND_GATE_3:
			pAct = new AddANDgate3(this);
			break;
		case ADD_NOR_GATE_3:
			pAct = new AddNORgate3(this);
			break;
		case ADD_XOR_GATE_3:
			pAct = new AddXORgate3(this);
			break;
		case ADD_Switch:
			pAct = new AddSwitch(this);
			break;
		case ADD_LED:
			pAct= new AddLED(this);
			break;
		case ADD_Buff:
			pAct = new AddBufferGate(this);
			break;
		case ADD_INV:
			pAct = new AddInverterGate(this);
			break;
		case ADD_CONNECTION:
			//TODO: Create Action here
			break;
		case ADD_Label:
			//TODO: Create Action here
			break;
		case EDIT_Label:
			//TODO: Create Action here
			break;
		case Create_TruthTable:
			//TODO: Create Action here
			break;
		case Change_Switch:
			//TODO: Create Action here
			break;
		case Probe:
			//TODO: Create Action here
		case SELECT:
			pAct = new Select(this);
			break;
		case DEL:
			//TODO: Create Action here
			break;
		case MOVE:
			//TODO: Create Action here
			break;
		case COPY:
			//TODO
		case CUT:
			//TODO: Create Action here
			break;
		case PASTE:
			//TODO: Create Action here
			break;
		case SAVE:
			//TODO: Create Action here
			break;
		case LOAD:
			//TODO: Create Action here
			break;
		case UNDO:
			//TODO: Create Action here
			break;
		case REDO:
			//TODO: Create Action here
			break;
		case DSN_MODE:
			//TODO: Create Action here
			break;
		case SIM_MODE:
			//TODO: Create Action here
			break;
		case HOVER:
			//TODO: Create Action here
			break;
		case STATUS_BAR:
			//TODO: Create Action here
			break;
		case DSN_TOOL:
			//TODO: Create Action here
			break;
		case GATE_TOOL:
			//TODO: Create Action here
			break;
		case SIM_TOOL:
			//TODO: Create Action here
			break;
		
	

		case EXIT:
			///TODO: create ExitAction here
			break;
	}
	if(pAct)
	{
		pAct->Execute();
		delete pAct;
		pAct = NULL;
	}
}
////////////////////////////////////////////////////////////////////

void ApplicationManager::UpdateInterface()
{
		for(int i=0; i<CompCount; i++)
			CompList[i]->Draw(OutputInterface);

}
////////////////////////////////////////////////////////////////////
void ApplicationManager::SetSelected(Component* sel)
{
	selected = sel;
}
////////////////////////////////////////////////////////////////////
Input* ApplicationManager::GetInput()
{
	return InputInterface;
}

////////////////////////////////////////////////////////////////////
Output* ApplicationManager::GetOutput()
{
	return OutputInterface;
}
///////////////////////////////////////////////////////////////////
Component* ApplicationManager::GetSelected()
{
	return selected;
}

////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////
Component* ApplicationManager::GetClickedComponent(int x, int y)
{
	for (int i = 0; i < CompCount; i++)
		if (CompList[i]->Inside(x, y))
			return CompList[i];
	return NULL;
}

ApplicationManager::~ApplicationManager()
{
	for(int i=0; i<CompCount; i++)
		delete CompList[i];
	delete OutputInterface;
	delete InputInterface;
	
}
