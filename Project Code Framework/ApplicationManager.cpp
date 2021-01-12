#include "ApplicationManager.h"
//#include "ApplicationManager.h"
#include "Actions\AddANDgate2.h"
#include "Actions/AddORgate2.h"
#include "Actions/AddSwitch.h"
#include "Actions/AddInverterGate.h"
#include "Actions/AddBufferGate.h"
#include "Actions/AddXOR2Gate.h"
#include "Actions/AddANDgate3.h"
#include "Actions/AddNANDgate2.h"
#include "Actions/AddNORgate3.h"
#include "Actions\Paste.h"
#include "Actions\copy.h"
#include "Actions\cut.h"
#include "AddLabel.h"
#include "Actions/Select.h"
#include "Actions/AddLED.h"
#include "Actions/AddXNORgate2.h"
#include "Actions/AddXORgate3.h"
#include "Actions/AddNOR2.h"
#include "Actions/Save_Action.h"
#include "Actions/Load_Action.h"
#include "Actions/AddConnection.h"
#include "simulation.h"
#include "Actions/Delete.h"
#include "Components/AND2.h"
#include "Components/AND3.h"
#include "Components/Buffer.h"
#include "Components/Inverter.h"
#include "Components/LED.h"
#include "Components/NAND2.h"
#include "Components/NOR3.h"
#include "Components/OR2.h"
#include "Components/Switch.h"
#include "Components/XNOR2.h"
#include "Components/XOR2.h"
#include "Components/XOR3.h"
#include "Components/NOR2.h"
//
#include <string>



ApplicationManager::ApplicationManager()
{
	CompCount = 0;


	for(int i=0; i<MaxCompCount; i++)
		CompList[i] = NULL;

	//Creates the Input / Output Objects & Initialize the GUI
	OutputInterface = new Output();
	InputInterface = OutputInterface->CreateInput();
	CopiedItem = NULL;

}
////////////////////////////////////////////////////////////////////
void ApplicationManager::AddComponent(Component* pComp, bool loaded)
{
	if (!loaded) {
		pComp->SetID(CompCount);
		CompList[CompCount++] = pComp;
	}
	else {
		CompList[pComp->GetID()] = pComp;
		CompCount++;
	}
			
}
int ApplicationManager::GetCompCount()
{
	return CompCount;
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
			pAct = new AddNOR2(this);
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
			pAct = new AddLED(this);
			break;
		case ADD_Buff:
			pAct = new AddBufferGate(this);
			break;
		case ADD_INV:
			pAct = new AddInverterGate(this);
			break;
		case ADD_CONNECTION:
			pAct = new AddConnection(this);
			break;
		case ADD_Label:
			pAct = new AddLabel(this);
			break;
		//case EDIT_Label:
			//TODO: Create Action here
			//break;
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
			pAct = new Delete(this);
			break;
		case MOVE:
			//TODO: Create Action here
			break;
		case COPY:
			pAct = new Copy(this);
			break;
		case CUT:
			pAct = new Cut(this);
			break;
		case PASTE:
			pAct = new Paste(this);
			break;
		case SAVE:
			pAct = new Save_Action(this);
			break;
		case LOAD:
			pAct = new Load_Action(this);
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
			pAct = new simulation(this); //edit me
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
	OutputInterface->ClearDrawingArea();
	for(int i=0; i<CompCount; i++)
		CompList[i]->Draw(OutputInterface);
}
////////////////
//void ApplicationManager::UpdateL_Interface(int &Cx,int &Cy)
//{
	/*OutputInterface->ClearDrawingArea();
	for (int i = 0; i < CompCount; i++) {
		CompList[i]->Draw(OutputInterface);
		////
		int Cx, Cy;
		string label = CompList[i]->getlabel();
		const char* cpText = label.c_str();
		InputInterface->GetPosition(Cx, Cy);
		OutputInterface->Printstringg(Cx - 1, Cy - 1, cpText);
		////
		*/
	//}
//}


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
void ApplicationManager::setCopied(Component* Cop)
{
	CopiedItem = Cop;

}
Component* ApplicationManager::getCopied()
{
	return CopiedItem;
}

void ApplicationManager::DeleteCopy()
{
	delete CopiedItem;
	CopiedItem = NULL;
}

Component* ApplicationManager::getCompList()
{
	return CompList[0];
}
Component** ApplicationManager::getcomplist()	
{ //ahmed	
	return CompList;	
}

bool ApplicationManager::getcpyStatus() {
	return CutOrCopy;
}

void ApplicationManager::setcpyStatus(bool set) {
	CutOrCopy=set;
}

void ApplicationManager::deleteGate(Component* ToDelete)
{
	for (int i = 0; i < CompCount; i++)
	{
		if (CompList[i] == ToDelete)
		{
			delete CompList[i];
			CompList[i] = CompList[CompCount - 1];
			CompList[CompCount - 1] = NULL;
			CompCount--;
			return;
		}
	}
}
void ApplicationManager::SetSelected(Component* sel)
{
	selected = sel;
	if (selected != NULL)
		selected->DrawFrame(OutputInterface);
}


Component* ApplicationManager::GetSelected()
{
	if (selected != NULL)
		return selected;
	return NULL;
}


Component* ApplicationManager::GetClickedComponent(int x, int y)
{
	for (int i = 0; i < CompCount; i++) {
		if (CompList[i]->Inside(x, y))
			return CompList[i];
	}
	return NULL;
}
//////////////////////////////////////////////////////////////
int ApplicationManager::WhichComp(COMPS& comptype)
{
	int x = 0, y = 0;
	GetInput()->GetPointClicked(x, y); // To get the x, y coordinates of point clicked
	int target = -1; // The default value
	comptype = COMPS::ITM_GEN; // The default value of the component clicked is COMP_GENERAL
	for (int i = 0; i < CompCount; i++) { // all components to se which component is selected
		// To get a copy from the x1, y1, x2, y2 of each component
		int x1 = CompList[i]->getGraphicsInfo().x1;
		int y1 = CompList[i]->getGraphicsInfo().y1;
		int x2 = CompList[i]->getGraphicsInfo().x2;
		int y2 = CompList[i]->getGraphicsInfo().y2;
		// compare clicked coordinates with coordinates of each component.

		//check if the clicked is a connection
		if (CompList[i]->getcomptype() == COMPS::ITM_CONN)
		{
			GraphicsInfo Area;
			//generate area  and check if the click is inside it
			Area.x1 = x1;
			Area.y1 = y1 - 5;
			Area.x2 = x1 + 20;
			Area.y2 = y1 + 5;
			if (Area.x1 <= x && x <= Area.x2 && Area.y1 <= y && y <= Area.y2) {
				CompList[i]->SetIfSelected(true); // Set the is_select data member to true.
				comptype = CompList[i]->getcomptype();
				target = i;
				break;
			}

			//area 2
			Area.x1 = x1 + 15;
			Area.y1 = y2 - 5;
			Area.x2 = x2;
			Area.y2 = y2 + 5;
			if (Area.x1 <= x && x <= Area.x2 && Area.y1 <= y && y <= Area.y2) {
				CompList[i]->SetIfSelected(true); // Set the is_select data member to true.
				comptype = CompList[i]->getcomptype();
				target = i;
				break;
			}



			if (y1 > y2)
			{
				Area.x1 = x1 + 15;
				Area.y1 = y2 - 5;
				Area.x2 = x1 + 20;
				Area.y2 = y1 + 5;


			}
			else
			{
				Area.x1 = x1 + 15;
				Area.y1 = y1 - 5;
				Area.x2 = x1 + 20;
				Area.y2 = y2 + 5;

			}
			if (Area.x1 <= x && x <= Area.x2 && Area.y1 <= y && y <= Area.y2) {
				CompList[i]->SetIfSelected(true); 
				comptype = CompList[i]->getcomptype();
				target = i;
				break;
			}






		}
		else if (x1 <= x && x <= x2 && y1 <= y && y <= y2) {
			CompList[i]->SetIfSelected(true); 
			comptype = CompList[i]->getcomptype();
			target = i;
			break;
		}
	}



	return target; 
}



void ApplicationManager::Save(std::ofstream& stream)
{
	// Number of Components without the connections
	int ActualCompCount = 0;
	for (int i = 0; i < CompCount; i++) {
		if (!dynamic_cast<Connection*>(CompList[i]))
			ActualCompCount++;
	}
	stream << ActualCompCount << endl;

	for (int i = 0; i < CompCount; i++) {
		if(!dynamic_cast<Connection*>(CompList[i]))
			CompList[i]->Save(stream);
	}

	stream << "Connections" << endl;
	for (int i = 0; i < CompCount; i++) {
		if (dynamic_cast<Connection*>(CompList[i]))
			CompList[i]->Save(stream);
	}
	stream << "-1";
}

void ApplicationManager::Load(std::ifstream& stream)
{
	ClearApp();
	Component* pC = NULL;
	int m_CompCount;
	int CompType;
	int CompID;
	string CompLabel;
	GraphicsInfo m_GfxInfo;
	stream >> m_CompCount;
	for (int i = 0; i < m_CompCount; i++) {
		stream >> CompType;
		switch (CompType) {
		case COMP_SWITCH:
			pC = new Switch(m_GfxInfo);
			break;
		case COMP_LED:
			pC = new LED(m_GfxInfo);
			break;
		case COMP_BUFFER:
			pC = new Buffer(m_GfxInfo, BUFF_FANOUT);
			break;
		case COMP_INVERTER:
			pC = new Inverter(m_GfxInfo, INV_FANOUT);
			break;
		case COMP_AND2:
			pC = new AND2(m_GfxInfo, AND2_FANOUT);
			break;
		case COMP_AND3:
			pC = new AND3(m_GfxInfo, AND3_FANOUT);
			break;
		case COMP_NAND2:
			pC = new NAND2(m_GfxInfo, NAND2_FANOUT);
			break;
		case COMP_NOR2:
			pC = new NOR2(m_GfxInfo, COMP_FANOUT);
			break;
		case COMP_NOR3:
			pC = new NOR3(m_GfxInfo, NOR3_FANOUT);
			break;
		case COMP_OR2:
			pC = new OR2(m_GfxInfo, OR2_FANOUT);
			break;
		case COMP_XNOR2:
			pC = new XNOR2(m_GfxInfo, COMP_FANOUT);
			break;
		case COMP_XOR2:
			pC = new XOR2(m_GfxInfo, XOR2_FANOUT);
			break;
		case COMP_XOR3:
			pC = new XOR3(m_GfxInfo, XOR2_FANOUT);
			break;
		}
		pC->Load(stream);
		AddComponent(pC, 1);
	}
		 
	int SrcCmpID;
	int DstCmpID;
	Component* SrcCmpnt;
	Component* DstCmpnt;
	string buffer;
	// ignoring the "Connections" line
	stream >> buffer;
	stream >> SrcCmpID >> DstCmpID;
	while (SrcCmpID != -1) {
		SrcCmpnt = GetComponent(SrcCmpID);
		DstCmpnt = GetComponent(DstCmpID);
		pC = new Connection(SrcCmpnt, DstCmpnt);
		if (SrcCmpnt && DstCmpnt) {
			pC->Load(stream);
			AddComponent(pC, 1);
		}
		else {
			string msg = "Loading Connections Failed in " + std::to_string(SrcCmpID);
			OutputInterface->PrintMsg(msg);
			break;
		}
		stream >> SrcCmpID >> DstCmpID;
	}
	UpdateInterface();
}

void ApplicationManager::ClearApp()
{
	CompCount = 0;
	for (int i = 0; i < MaxCompCount; i++)
		CompList[i] = NULL;
	OutputInterface->ClearDrawingArea();
}



Component* ApplicationManager::GetComponent(int ID)
{
	for (int i = 0; i < CompCount; i++) {
		if (CompList[i]->GetID() == ID)
			return CompList[i];
	}
	return NULL;
}


void ApplicationManager::SelectComponent(int target)
{
	CompList[target]->SetIfSelected(true); 
}
Component* ApplicationManager::GetLastSelected()
{
	return lastSelected;
}

void ApplicationManager::SetLastSelected(int target)
{
	if (target == -1)
		lastSelected = nullptr;
	else
		lastSelected = CompList[target];
}

void ApplicationManager::DeselectExcept(int except)
{
	GetOutput()->PrintMsg(""); 
	if (except == -1)
		SetLastSelected(-1); 

	
	for (int i = 0; i < CompCount; i++)
	{
		if (i == except)
			continue;
		else
			CompList[i]->SetIfSelected(false); 
	}
}
//////////////////////////////////////////////////////////////
//Delete

void ApplicationManager::DeleteComp()
{

	if (lastSelected != nullptr)

		for (int i = 0; i < CompCount; i++)
		{


			if (lastSelected == CompList[i]) 
			{
				delete CompList[i]; 
				CompList[i] = CompList[CompCount - 1]; 
				CompList[CompCount - 1] = NULL;
				CompCount--;
				break;
			}
		

		}
}
void ApplicationManager::OperateAll()
{
	
	for (int i = 0; i < CompCount; i++) {
		CompList[i]->Operate();
		LED* Led = dynamic_cast<LED*>(CompList[i]);
		if (Led) {
			if (Led->GetInputPinStatus(1))
				OutputInterface->PrintMsg("Led is HIGH");
			else
				OutputInterface->PrintMsg("Led is LOW");
		}
	}
}
/////////////////////////////////////////////////////////////

ApplicationManager::~ApplicationManager()
{
	for(int i=0; i<CompCount; i++)
		delete CompList[i];
	delete OutputInterface;
	delete InputInterface;
}
