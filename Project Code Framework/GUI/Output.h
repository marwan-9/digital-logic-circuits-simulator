#pragma once
#include "..\Defs.h"
#include "Input.h"

class Output	//The application manager should have a pointer to this class
{
private:
	window* pWind;	//Pointer to the Graphics Window
public:
	Output(); // Performs the Window Initialization
	Input* CreateInput() const; //creates a pointer to the Input object
	void ChangeTitle(string Title) const;

	void CreateDesignToolBar() const;	//Tool bar of the design mode
	void CreateSimulationToolBar() const;//Tool bar of the simulation mode
	void CreateStatusBar() const;	//Create Status bar

	void ClearStatusBar() const;		//Clears the status bar
	void ClearDrawingArea() const;	//Clears the drawing area
	void ClearWindow() const;

	window* CreateWind(int wd, int h, int x, int y) const; //Creates user interface window

	void DrawSquare(GraphicsInfo r_GfxInfo) const;
	
	// Draws 2-input AND gate
	void DrawAND2(GraphicsInfo r_GfxInfo, bool selected = false) const;
	void DrawAND3(GraphicsInfo r_GfxInfo, bool selected = false) const;

	///TODO: Make similar functions for drawing all other gates, switch, and LED, .. etc
	
	void DrawNAND2(GraphicsInfo r_GfxInfo, bool selected = false) const;
	void DrawNAND3(GraphicsInfo r_GfxInfo, bool selected = false) const;
	void DrawOR2(GraphicsInfo r_GfxInfo, bool selected = false) const;
	void DrawOR3(GraphicsInfo r_GfxInfo, bool selected = false) const;
	void DrawNOR2(GraphicsInfo r_GfxInfo, bool selected = false) const;
	void DrawNOR3(GraphicsInfo r_GfxInfo, bool selected = false) const;
	void DrawXOR2(GraphicsInfo r_GfxInfo, bool selected = false) const;
	void DrawXOR3(GraphicsInfo r_GfxInfo, bool selected = false) const;
	void DrawXNOR2(GraphicsInfo r_GfxInfo, bool selected = false) const;
	void DrawBuff(GraphicsInfo r_GfxInfo, bool selected = false) const;
	void DrawINV(GraphicsInfo r_GfxInfo, bool selected = false) const;
	void DrawSwitch(GraphicsInfo r_GfxInfo, bool selected = false) const;
	void DrawLED(GraphicsInfo r_GfxInfo, bool selected = false) const;

	// Draws Connection
	void DrawConnection(GraphicsInfo r_GfxInfo, bool selected = false) const;
	void cleartext(int x1, int y1 , int x2, int y2);
	void PrintMsg(string msg) const;	//Print a message on Status bar

	void Printstringg(const int x, const int y, const string cpText);	//Print a message on Status bar
	~Output();
};
