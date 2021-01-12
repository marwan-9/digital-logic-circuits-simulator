#ifndef _COMPONENT_H
#define _COMPONENT_H

#include "..\Defs.h"
#include "..\GUI\Output.h"
#include <fstream>

#include "InputPin.h"
#include "OutputPin.h"


//Base class for classes Gate, Switch, and LED.
class Component
{
private:
	string m_Label;
protected:
	GraphicsInfo m_GfxInfo;	// The parameters required to draw a component
	int m_ID;					// unique ID for each component
	bool IfSelected;        // if component is selected or not
public:
	Component(const GraphicsInfo &r_GfxInfo);
	virtual void Operate() = 0;	//Calculates the output according to the inputs
	virtual void Draw(Output* pOut) = 0;	//for each component to Draw itself
	virtual void DrawFrame(Output* pOut) = 0;
	
	virtual bool Inside(int x, int y);

	virtual int GetOutPinStatus()=0;	//returns status of outputpin if LED, return -1
	virtual int GetInputPinStatus(int n)=0;	//returns status of Inputpin # n if SWITCH, return -1

	virtual void setInputPinStatus(int n, STATUS s)=0;	//set status of Inputpin # n, to be used by connection class.
	virtual void SetGraphics(int x, int y, bool type = false);
	// Set Graphics using one Corner Only
	void SetGraphicsCorner(int x, int y);
	GraphicsInfo GetGraphics();
	//JUST COPYING LITERALLY
	virtual Component* Copy() = 0;  

	void SetIfSelected(bool q);
	bool GetIfSelected();


	// Each Component should save and load itself in this format
	// Comp_1_Type Comp_ID Label Component_Graphics_info
	virtual void Save(std::ofstream&) = 0;
	virtual void Load(std::ifstream&) = 0;

	string GetLabel();
	void SetLabel(string);
	void SetID(int r_ID);
	int GetID();
	
	virtual OutputPin* GetOutputPin();
	virtual InputPin* GetInputPins(int index);

	// Checks if there are available Input Pins to be connected or not, if yes it returns the number of the available pin, otherwise it returns -1
	virtual int GetPinNumber();

	Component();	
	
	//Destructor must be virtual
	virtual ~Component();
};

#endif
