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

	window* CreateWind(int wd, int h, int x, int y) const; //Creates user interface window

	
	// Draws 2-input AND gate
	void DrawAND2(GraphicsInfo r_GfxInfo, bool selected = false) const;

	///TODO: Make similar functions for drawing all other gates, switch, and LED, .. etc
	/* 
	ahmed
	ADD_Buff,			//Add 1-input Buffer gate
	ADD_INV,			//Add 1-input Inverter gate
	ADD_AND_GATE_2,		//Add 2-input AND gate
	ADD_OR_GATE_2,		//Add 2-input OR gate
	ADD_NAND_GATE_2,	//Add 2-input NAND gate
	ADD_NOR_GATE_2,		//Add 2-input NOR gate
	ADD_XOR_GATE_2,		//Add 2-input XOR gate
	ADD_XNOR_GATE_2,	//Add 2-input XNOR gate
	ADD_AND_GATE_3,		//Add 3-input AND gate
	ADD_NOR_GATE_3,		//Add 3-input NOR gate
	ADD_XOR_GATE_3,		//Add 3-input XOR gate
	ADD_Switch,			//Add Switch
	ADD_LED,			//Add LED
	ADD_CONNECTION,		//Add Wire Connection 
	*/
		void DrawNAND3(GraphicsInfo r_GfxInfo, bool selected = false) const;
		void DrawOR2(GraphicsInfo r_GfxInfo, bool selected = false) const;
		void DrawOR3(GraphicsInfo r_GfxInfo, bool selected = false) const;
		void DrawNAND(GraphicsInfo r_GfxInfo, bool selected = false) const;
		void DrawNOR(GraphicsInfo r_GfxInfo, bool selected = false) const;
		void DrawXOR(GraphicsInfo r_GfxInfo, bool selected = false) const;
		void DrawXNOR(GraphicsInfo r_GfxInfo, bool selected = false) const;
		void DrawNOR3(GraphicsInfo r_GfxInfo, bool selected = false) const;
		void DrawXOR3(GraphicsInfo r_GfxInfo, bool selected = false) const;
		void DrawBuff(GraphicsInfo r_GfxInfo, bool selected = false) const;
		void DrawINV(GraphicsInfo r_GfxInfo, bool selected = false) const;
		void DrawSwitch(GraphicsInfo r_GfxInfo, bool selected = false) const;
		void DrawLED(GraphicsInfo r_GfxInfo, bool selected = false) const;


	// Draws Connection
	void DrawConnection(GraphicsInfo r_GfxInfo, bool selected = false) const;
	
	void PrintMsg(string msg) const;	//Print a message on Status bar


	~Output();
};
