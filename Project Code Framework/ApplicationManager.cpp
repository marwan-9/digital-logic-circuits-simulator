#include "ApplicationManager.h"
#include "Actions\AddANDgate2.h"
#include "Actions/AddORgate2.h"
#include "Actions/AddSwitch.h"
#include "AddANDgate3.h"
#include "AddNANDgate2.h"
#include "AddNORgate3.h"

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
			//TODO: Create Action here
			break;
		case ADD_XOR_GATE_2:
			//TODO: Create Action here
			break;
		case ADD_XNOR_GATE_2:
			//TODO: Create Action here
			break;
		case ADD_AND_GATE_3:
			pAct = new AddANDgate3(this);
			break;
		case ADD_NOR_GATE_3:
			pAct = new AddNORgate3(this);
			break;
		case ADD_XOR_GATE_3:
			//TODO: Create Action here
			break;
		case ADD_Switch:
			pAct = new AddSwitch(this);
			break;
		case ADD_LED:
			//TODO: Create Action here
		case ADD_Buff:
			//TODO: Create Action here
			break;
		case ADD_INV:
			//TODO: Create Action here
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
			//TODO: Create Action here
			break;
		case DEL:
			//TODO: Create Action here
			break;
		case MOVE:
			//TODO: Create Action here
			break;
		case COPY:
			//TODO: Create Action here
			break;
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
Input* ApplicationManager::GetInput()
{
	return InputInterface;
}

////////////////////////////////////////////////////////////////////
Output* ApplicationManager::GetOutput()
{
	return OutputInterface;
}

////////////////////////////////////////////////////////////////////

ApplicationManager::~ApplicationManager()
{
	for(int i=0; i<CompCount; i++)
		delete CompList[i];
	delete OutputInterface;
	delete InputInterface;
	
}