#include "Output.h"

Input::Input(window* pW)
{
	pWind = pW; //point to the passed window
}


void Input::GetPointClicked(int &x, int &y)
{
	pWind->WaitMouseClick(x, y);	//Wait for mouse click
}

string Input::GetSrting(Output *pOut)
{
	///TODO: Implement this Function
	//Read a complete string from the user until the user presses "ENTER".
	//If the user presses "ESCAPE". This function should return an empty string.
	//"BACKSPACE" should be also supported
	//User should see what he is typing at the status bar

	return NULL;
}


// Reads the user's selection and determine the desired action 
ActionType Input::GetUserAction() const {

	int x, y;
	pWind->WaitMouseClick(x, y);	//Get the coordinates of the user click

	// User clicks on the drawing area
	// + GateBarHeight (optional)
	if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight) {
		if (UI.AppMode == MODE::DESIGN) {
			///////////////////////////////////////////To-Do ADD GATES/////////////////////////////////////////////////////////////////////////////////////
		}}

	int clickedItemOrder = x / UI.MenuItemWidth;
	if (UI.AppMode == MODE::DESIGN) {

		// [1] if User clicks on the tool bar
		if (y >= 0 && y < UI.ToolBarHeight) {
			switch (clickedItemOrder) {
				case DsgnMenuItem::ITM_SIM_CIRCUIT: return SIM_MODE;
				case DsgnMenuItem::ITM_WIRE: return ADD_CONNECTION;
				case DsgnMenuItem::ITM_ADD_LABEL: return ADD_Label;
				case DsgnMenuItem::ITM_LOAD: return LOAD;
				case DsgnMenuItem::ITM_SAVE: return SAVE;
				case DsgnMenuItem::ITM_DEL: return DEL;
				case DsgnMenuItem::ITM_COPY: return COPY;
				case DsgnMenuItem::ITM_CUT: return CUT;
				case DsgnMenuItem::ITM_PASTE: return PASTE;
					/* To be added later
					case DsgnMenuItem::ITM_UNDO: return UNDO;
					case DsgnMenuItem::ITM_REDO: return REDO;
					case DsgnMenuItem::ITM_PLAY: return SIMULATION_MODE;
					*/
				case DsgnMenuItem::ITM_EXIT: return EXIT;
				default: return DSN_TOOL; //tool_bar
			}
		}

		//[2] User clicks on the Gates Bar
		if (y >= UI.ToolBarHeight && y < UI.ToolBarHeight + UI.GateBarHeight) {
			clickedItemOrder = (x / UI.ToolItemWidth) + 10;
			switch (clickedItemOrder) {
				case DsgnMenuItem::ITM_SWITCH: return ADD_Switch;
				case DsgnMenuItem::ITM_LED: return ADD_LED;
				case DsgnMenuItem::ITM_BUFF: return ADD_Buff;
				case DsgnMenuItem::ITM_INV: return ADD_INV;
				case DsgnMenuItem::ITM_AND2: return ADD_AND_GATE_2;
				case DsgnMenuItem::ITM_OR2: return ADD_OR_GATE_2;
				case DsgnMenuItem::ITM_NAND2: return ADD_NAND_GATE_2;
				case DsgnMenuItem::ITM_NOR2: return ADD_NOR_GATE_2;
				case DsgnMenuItem::ITM_XOR2: return ADD_XOR_GATE_2;
				case DsgnMenuItem::ITM_XNOR2: return ADD_XNOR_GATE_2;
				case DsgnMenuItem::ITM_AND3: return ADD_AND_GATE_3;
				case DsgnMenuItem::ITM_NOR3: return ADD_NOR_GATE_3;
				case DsgnMenuItem::ITM_XOR3: return ADD_XOR_GATE_3;
				default:
					return GATE_TOOL;
			}
		}


		//[3] User clicks on the drawing area
		if (y >= UI.ToolBarHeight + UI.GateBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return SELECT;	//user want to select/unselect a component
		}

		//[4] User clicks on the status bar
		return STATUS_BAR;
	}

	else // Application is in Simulation mode
	{
		
		// [1] if User clicks on the tool bar
		if (y >= 0 && y < UI.ToolBarHeight) {
			switch (clickedItemOrder) {
				case SimMenuItem::ITM_DES: return DSN_MODE;
				case SimMenuItem::ITM_TRUTH: return Create_TruthTable;
				case SimMenuItem::ITM_PROBE: return Probe;
				default: return SIM_TOOL; //tool_bar
			}
		}

		//[2] User clicks on the drawing area
		if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return SELECT;	//user want to select/unselect a component
		}

		//[3] User clicks on the status bar
		return STATUS_BAR;

	}	
}


Input::~Input()
{
}
