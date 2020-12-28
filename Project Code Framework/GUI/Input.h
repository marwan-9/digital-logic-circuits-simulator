#pragma once
#include "..\Defs.h"
#include "..\CMUgraphicsLib\CMUgraphics.h"
#include "UI_Info.h"
 
class Output;
class Input
{
private:
	int LastX, LastY;		
	window* pWind;			
 
public:
 
	Input(window* pW);
 
//last point clicked
	void GetPointClicked(int& x, int& y) const;
 
//return mouse click cooridinates
	void WaitMouseClick(int& x, int& y);
 
//return mouse state
	buttonstate GetButtonState(const button btMouse, int& x, int& y);
 
//returns key press
	keytype GetKeyPress(char& c);
 
//returns the string entered by the user and reflect it on the status bar
	string GetSrting(Output* pOut, string msg, string str = "") const;
 
//reads the selection do the action */
	ActionType GetUserAction(Output* pOut);
 
	~Input();
};
