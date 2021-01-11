#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H

#include "Defs.h"
#include "GUI\Output.h"
#include "GUI\Input.h"
#include "Actions\Action.h"
#include "Components\Component.h"

//Main class that manages everything in the application.
class ApplicationManager
{

	enum { MaxCompCount = 200 };	//Max no of Components	

private:
	int CompCount;		//Actual number of Components
	Component* CompList[MaxCompCount];	//List of all Components (Array of pointers)
	Component* selected=NULL; //poiter to selected component
	Output* OutputInterface; //pointer to the Output Clase Interface
	Input* InputInterface; //pointer to the Input Clase Interface

	Component* CopiedItem; //A pointer to the Copied Item
	bool CutOrCopy;  //true->Copy // false->Cut


public:	
	ApplicationManager(); //constructor

	//Reads the required action from the user and returns the corresponding action type
	ActionType GetUserAction();

	//Creates an action and executes it
	void ExecuteAction(ActionType);
	
	void UpdateInterface();	//Redraws all the drawing window
	void UpdateL_Interface();

	//Gets a pointer to Input / Output Object
	Output* GetOutput();
	Input* GetInput();

	//Adds a new component to the list of components
	void AddComponent(Component* pComp);

	////////////////////////////////////////////////////////////////////////
	void setCopied(Component* Cop);
	Component* getCopied();
	void DeleteCopy();
	Component* getCompList();
	bool getcpyStatus();
	void setcpyStatus(bool set);
	void deleteGate(Component* ToDelete);
	////////////////////////////////////////////////////////////////////////
	void SetSelected(Component*); //set selected pointer

	Component* GetSelected();  //return selected pointer

	Component* GetClickedComponent(int x, int y); //returns selected component

	//string givelabel(); //ahmed
	Component** getcomplist(); //ahmed
	int GetCompCount(); //ahmed
	//void settlabel();//ahmed
	//destructor
	~ApplicationManager();
};

#endif
