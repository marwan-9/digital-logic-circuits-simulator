#include "GUI\Input.h"
#include "GUI\Output.h"

//This is a test code to test the Input and Output classes

int main()
{
	int x,y;

	//Create Input and Output objects to test
	Output *pOut = new Output();;
	Input *pIn = pOut->CreateInput();

	//Starting the test
	pOut->PrintMsg("This demo is to test input and output classes, Click anywhere to start the test");
	pIn->GetPointClicked(x,y);	//Wait for any click


	///////////////////////////////////////////////////////////////////////////////////
	// TEST 1:	Create The FULL Tool bar, the drawing area and the status bar	
	//			This has already been done through the constrcutor of class Output
	///////////////////////////////////////////////////////////////////////////////////

	pOut->PrintMsg("TEST1: Drawing Tool bar and Status bar, Click anywhere to continue");
	pIn->GetPointClicked(x,y);	//Wait for any click

	
	///////////////////////////////////////////////////////////////////////////////////
	// TEST 2:	Drawing all the Components with all possible states: Normal, highlighted
	//			
	///////////////////////////////////////////////////////////////////////////////////
	
	pOut->PrintMsg("TEST2: Now we will show that Output class can draw any Component in any state, Click anywhere to continue");
	pIn->GetPointClicked(x,y);	//Wait for any click

	GraphicsInfo GfxInfo;  //to be used with draw function of the class Ouput

	/// 2.1- AND2 Gate test
	pOut->PrintMsg("Drawing 2-input AND gate, Normal and Highlighted,  Click to continue");
	
	//Drawing Normal AND2 gate
	GfxInfo.x1 = 150;	GfxInfo.y1 = 300;
	pOut->DrawAND2(GfxInfo);

	//Drawing Highlighted AND2 gate
	GfxInfo.x1 = 150;	GfxInfo.y1 = 400;
	pOut->DrawAND2(GfxInfo, true);

	pIn->GetPointClicked(x,y);	//Wait for any click
	pOut->ClearDrawingArea();
	
	/// 2.2- NAND2 Gate test
	pOut->PrintMsg("Drawing 2-input NAND gate, Normal and Highlighted,  Click to continue");

	///TODO: Add code to draw 2-input NAND gate, Normal and Highlighted
	//Drawing Normal NAND2 gate

	GfxInfo.x1 = 150;	GfxInfo.y1 = 300;
	pOut->DrawNAND(GfxInfo);

	//Drawing Highlighted NAND2 gate
	GfxInfo.x1 = 150;	GfxInfo.y1 = 400;
	pOut->DrawNAND(GfxInfo, true);

	pIn->GetPointClicked(x,y);	//Wait for any click
	pOut->ClearDrawingArea();

	/// 2.3- OR2 and NOR2 Gates test
	pOut->PrintMsg("Drawing 2-input OR and NOR gates, Normal and Highlighted,  Click to continue");
	///TODO: Add code to draw 2-input OR and NOR gates, Normal and Highlighted for each
	//Drawing Normal OR2 gate

	GfxInfo.x1 = 150;	GfxInfo.y1 = 300;
	pOut->DrawOR2(GfxInfo);

	//Drawing Highlighted OR2 gate
	GfxInfo.x1 = 150;	GfxInfo.y1 = 400;
	pOut->DrawOR2(GfxInfo, true);

	// Drawing Normal NOR2 gate

	GfxInfo.x1 = 250;	GfxInfo.y1 = 300;
	pOut->DrawNOR(GfxInfo);

	//Drawing Highlighted NOR2 gate
	GfxInfo.x1 = 250;	GfxInfo.y1 = 400;
	pOut->DrawNOR(GfxInfo, true);

	pIn->GetPointClicked(x,y);	//Wait for any click
	pOut->ClearDrawingArea();

	/// 2.4- XOR2 and XNOR2 Gates test
	pOut->PrintMsg("Drawing 2-input XOR and XNOR gates, Normal and Highlighted,  Click to continue");
	///TODO: Add code to draw 2-input XOR and XNOR gates, Normal and Highlighted for each

	//Drawing Normal XOR2 gate

	GfxInfo.x1 = 150;	GfxInfo.y1 = 300;
	pOut->DrawXOR(GfxInfo);

	//Drawing Highlighted XOR2 gate
	GfxInfo.x1 = 150;	GfxInfo.y1 = 400;
	pOut->DrawXOR(GfxInfo, true);

	//Drawing Normal XNOR2 gate

	GfxInfo.x1 = 250;	GfxInfo.y1 = 300;
	pOut->DrawXNOR(GfxInfo);

	//Drawing Highlighted XNOR2 gate
	GfxInfo.x1 = 250;	GfxInfo.y1 = 400;
	pOut->DrawXNOR(GfxInfo, true);

	pIn->GetPointClicked(x,y);	//Wait for any click
	pOut->ClearDrawingArea();

	/// 2.5- Buffer and Inverter Gates test
	pOut->PrintMsg("Drawing Buffer and Inverter Gates, Normal and Highlighted,  Click to continue");
	///TODO: Add code to draw Buffer and Inverter Gates, Normal and Highlighted for each
	//Drawing Normal Buffer gate

	GfxInfo.x1 = 150;	GfxInfo.y1 = 300;
	pOut->DrawBuff(GfxInfo);

	//Drawing Highlighted Buffer gate
	GfxInfo.x1 = 150;	GfxInfo.y1 = 400;
	pOut->DrawBuff(GfxInfo, true);

	//Drawing Normal Inverter gate

	GfxInfo.x1 = 250;	GfxInfo.y1 = 300;
	pOut->DrawINV(GfxInfo);

	//Drawing Highlighted Inverter gate
	GfxInfo.x1 = 250;	GfxInfo.y1 = 400;
	pOut->DrawINV(GfxInfo, true);


	pIn->GetPointClicked(x,y);	//Wait for any click
	pOut->ClearDrawingArea();


	/// 2.6- AND3, NOR3, and XOR3 Gates test
	pOut->PrintMsg("Drawing 3-input AND, NOR, XOR Gates, Normal and Highlighted,  Click to continue");
	///TODO: Add code to draw 3-input AND, NOR, and XOR Gates, Normal and Highlighted for each
	
	                                          ////3INPUT AND///
	//Drawing Normal 3-AND gate
	GfxInfo.x1 = 150;	GfxInfo.y1 = 300;
	pOut->DrawAND3(GfxInfo);

	//Drawing Highlighted 3-AND gate
	GfxInfo.x1 = 150;	GfxInfo.y1 = 400;
	pOut->DrawAND3(GfxInfo, true);

	                                           ////3INPUT NOR///
	//Drawing Normal 3-NOR gate

	GfxInfo.x1 = 250;	GfxInfo.y1 = 300;
	pOut->DrawNOR3(GfxInfo);

	//Drawing Highlighted 3-NOR gate
	GfxInfo.x1 = 250;	GfxInfo.y1 = 400;
	pOut->DrawNOR3(GfxInfo, true);
	
	                                           ///3INPUT XOR///
	//Drawing Normal 3-XOR gate

	GfxInfo.x1 = 350;	GfxInfo.y1 = 300;
	pOut->DrawXOR3(GfxInfo);

	//Drawing Highlighted 3-XOR gate
	GfxInfo.x1 = 350;	GfxInfo.y1 = 400;
	pOut->DrawXOR3(GfxInfo, true);

	pIn->GetPointClicked(x, y);	//Wait for any click
	pOut->ClearDrawingArea();


	/// 2.7- Switch and LED test
	pOut->PrintMsg("Drawing Switch and LED, Normal and Highlighted,  Click to continue");
	///TODO: Add code to draw Switch and LED, Normal and Highlighted for each

										       	 ////Switch///
	//Drawing Normal 3-AND gate
	GfxInfo.x1 = 150;	GfxInfo.y1 = 300;
	pOut->DrawSwitch(GfxInfo);

	//Drawing Highlighted 3-AND gate
	GfxInfo.x1 = 150;	GfxInfo.y1 = 400;
	pOut->DrawSwitch(GfxInfo, true);

	                                              ////LED///
//Drawing Normal 3-NOR gate

	GfxInfo.x1 = 250;	GfxInfo.y1 = 300;
	pOut->DrawLED(GfxInfo);

	//Drawing Highlighted 3-NOR gate
	GfxInfo.x1 = 250;	GfxInfo.y1 = 400;
	pOut->DrawLED(GfxInfo, true);


	pIn->GetPointClicked(x,y);	//Wait for any click
	pOut->ClearDrawingArea();


	/// 2.8- Connections
	pOut->PrintMsg("Drawing connections, Normal, Highlighted, straight, and broken,  Click to continue");
	///TODO: Add code to draw connections, Normal, Highlighted, straight, and broken (all combinations) 

	//STRAIGHT CONNECTION//

	//Drawing Normal connection
	GfxInfo.x1 = 150;	GfxInfo.y1 = 300;
	pOut->DrawConnection(GfxInfo);

	//Drawing Highlighted connection
	GfxInfo.x1 = 150;	GfxInfo.y1 = 400;
	pOut->DrawConnection(GfxInfo, true);

	// BROKEN CONNECTION//
	/*
	//Drawing Normal connection
		GfxInfo.x1 = 150;	GfxInfo.y1 = 300;
	pOut->DrawConnectionbrk(GfxInfo);

	//Drawing Highlighted connection
	GfxInfo.x1 = 150;	GfxInfo.y1 = 400;
	pOut->DrawConnectionbrk(GfxInfo, true);
	*/

	pIn->GetPointClicked(x,y);	//Wait for any click
	pOut->ClearDrawingArea();




	///////////////////////////////////////////////////////////////////////////////////
	// TEST 3: Read strings from the user
	///////////////////////////////////////////////////////////////////////////////////
	pOut->PrintMsg("TEST3: Now Time to test class Input, Click anywhere to continue");
	pIn->GetPointClicked(x,y);	//Wait for any click
	
	pOut->PrintMsg("Testing Input ability to read strings");

	///TODO: Add code here to 
	// 1- Read a string from the user on the status bar and print it inside the drawing area


	pIn->GetPointClicked(x,y);	//Wait for any click
	pOut->ClearDrawingArea();

	///////////////////////////////////////////////////////////////////////////////////
	// TEST 4: Check for the user action
	///////////////////////////////////////////////////////////////////////////////////
	pOut->PrintMsg("TEST4: Testing Input ability to detect User Action, click anywhere");

	ActionType ActType;
	
	///TODO:  You must add a case for each action
	//Add cases for the missing actions below
	do
	{
		ActType = pIn->GetUserAction();

		switch (ActType)
		{
		case ADD_Buff:
				pOut->PrintMsg("Action: add a buffer gate , Click anywhere");
				break;

		case ADD_INV:
				pOut->PrintMsg("Action: add an inverter gate , Click anywhere");
				break;

		case ADD_AND_GATE_2:
				pOut->PrintMsg("Action: add 2-input AND gate , Click anywhere");
				break;

		case ADD_NAND_GATE_2:
				pOut->PrintMsg("Action: add 2-input NAND gate , Click anywhere");
				break;

		case ADD_OR_GATE_2:
				pOut->PrintMsg("Action: add 2-input OR gate , Click anywhere");
				break;

		case ADD_NOR_GATE_2:
				pOut->PrintMsg("Action: add 2-input NOR gate , Click anywhere");
				break;

		case ADD_XOR_GATE_2:
				pOut->PrintMsg("Action: add 2-input XOR gate , Click anywhere");
				break;

		case ADD_XNOR_GATE_2:
				pOut->PrintMsg("Action: add 2-input XNOR gate , Click anywhere");
				break;

		case SELECT:
				pOut->PrintMsg("Action: a click on the Drawing area, Click anywhere");
				break;
			
		case STATUS_BAR:
				pOut->PrintMsg("Action: a click on the Status Bar, Click anywhere");
				break;
 
		case DSN_TOOL:
				pOut->PrintMsg("Action: a click on empty area in the Design Tool Bar, Click anywhere");
				break;

		case SIM_MODE:
				pOut->PrintMsg("Action: Switch to Simulation Mode, creating simualtion tool bar");
				pOut->CreateSimulationToolBar();
				break;

		case DSN_MODE:
				pOut->PrintMsg("Action: Switch to Design Mode, creating Design tool bar");
				pOut->CreateDesignToolBar();
				break;


		case EXIT:				
				break;
		}
	}while(ActType != EXIT);


	/// Exiting
	pOut->PrintMsg("Action: EXIT, test is finished, click anywhere to exit");
	pIn->GetPointClicked(x,y);

	
	delete pIn;
	delete pOut;	
	return 0;
}


