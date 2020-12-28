#include "Input.h"
#include "Output.h"


Input::Input(window* pW) {
	pWind = pW;
}

// last point clicked
void Input::GetPointClicked(int& x, int& y) const {
	x = LastX;
	y = LastY;
}

// mouse click coordinate
void Input::WaitMouseClick(int& x, int& y) {
	pWind->WaitMouseClick(x, y);
	LastX = x;
	LastY = y;
}

// current state of the mouse buttons and position
buttonstate Input::GetButtonState(const button Mouse, int& x, int& y) {
	return pWind->GetButtonState(Mouse, x, y);;
}

// Returns user key press
keytype Input::GetKeyPress(char& key) {

	return pWind->GetKeyPress(key);
}


// Returns the string entered by the user and reflect it on the status bar
string Input::GetSrting(Output* pOut, string msg, string str) const {
	// ASCII Codes
	const int ESCAPE = 27;
	const int ENTER = 13;
	const int BACKSPACE = 8;

	char c;
	string s = str;

	pWind->FlushKeyQueue();

	do {
		pOut->PrintMsg(msg + " " + s);
		pWind->WaitKeyPress(c);
		
		switch (c) {
		case BACKSPACE:
			if (!s.empty()) s.pop_back();
			break;
		case ESCAPE:
			s.clear();
			break;
		case ENTER:
			// Nothing
			break;
		default:
			s.push_back(c);
			break;
		}

	} while (c != ESCAPE && c != ENTER);

	return s;
}

// Reads the user's selection and determine the desired action 
ActionType Input::GetUserAction(Output* pOut) {
	pWind->FlushMouseQueue();

	int x, y;
	char hotKey;
	keytype keyType;

	LastX = x;
	LastY = y;

	// User clicks on the drawing area
	// + GateBarHeight (optional)
	if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight) {
		if (UI.AppMode == MODE::DESIGN) {
			///////////////////////////////////////////To-Do ADD GATES/////////////////////////////////////////////////////////////////////////////////////
		}}

	pWind->WaitMouseClick(x, y);

	// User clicks on the tool bar
	if (y >= 0 && y < UI.ToolBarHeight) {
		int clickedItemOrder = x / UI.ToolItemWidth;

		if (UI.AppMode == MODE::DESIGN) {
			switch (clickedItemOrder) {
			//  case DsgnMenuItem::ITM_EDIT: return ActionType::EDIT;
			case DsgnMenuItem::ITM_DEL: return ActionType::DEL;
			case DsgnMenuItem::ITM_COPY: return ActionType::COPY;
			case DsgnMenuItem::ITM_CUT: return ActionType::CUT;
			case DsgnMenuItem::ITM_PASTE: return ActionType::PASTE;
			case DsgnMenuItem::ITM_UNDO: return ActionType::UNDO;
			case DsgnMenuItem::ITM_REDO: return ActionType::REDO;
			//  case DsgnMenuItem::ITM_PLAY: return ActionType::SIMULATION_MODE;
			case DsgnMenuItem::ITM_SAVE: return ActionType::SAVE;
			case DsgnMenuItem::ITM_LOAD: return ActionType::LOAD;
			case DsgnMenuItem::ITM_EXIT: return ActionType::EXIT;
			default: return ActionType::STATUS_BAR; //tool_bar
			}
		}
		else {
			switch (clickedItemOrder) {
			//case DsgnMenuItem::ITM_PAUSE: return ActionType::DESIGN_MODE;
			case SimMenuItem::ITM_TRUTH: return ActionType::Create_TruthTable;
			case DsgnMenuItem::ITM_EXIT:	return ActionType::EXIT;
			default: return ActionType::STATUS_BAR; //tool_bar
			}
		}
	}
	// User clicks on gate bar
	else if (y >= UI.ToolBarHeight && y < UI.ToolBarHeight + UI.StatusBarHeight) {
		int clickedItemOrder = x / UI.MenuItemWidth;

		if (UI.AppMode == MODE::DESIGN) {
			switch (clickedItemOrder) {
			case DsgnMenuItem::ITM_SWITCH: return ActionType::ADD_Switch;
			case DsgnMenuItem::ITM_AND2: return ActionType::ADD_AND_GATE_2;
			case DsgnMenuItem::ITM_NAND2: return ActionType::ADD_NAND_GATE_2;
			case DsgnMenuItem::ITM_AND3: return ActionType::ADD_AND_GATE_3;
			case DsgnMenuItem::ITM_BUFF: return ActionType::ADD_Buff;
			case DsgnMenuItem::ITM_INV: return ActionType::ADD_INV;
			case DsgnMenuItem::ITM_OR2: return ActionType::ADD_OR_GATE_2;
			case DsgnMenuItem::ITM_NOR2: return ActionType::ADD_NOR_GATE_2;
			case DsgnMenuItem::ITM_NOR3: return ActionType::ADD_NOR_GATE_3;
			case DsgnMenuItem::ITM_XOR2: return ActionType::ADD_XOR_GATE_2;
			case DsgnMenuItem::ITM_XNOR2: return ActionType::ADD_XNOR_GATE_2;
			case DsgnMenuItem::ITM_XOR3: return ActionType::ADD_XOR_GATE_3;
			case DsgnMenuItem::ITM_WIRE: return ActionType::ADD_CONNECTION;
			case DsgnMenuItem::ITM_LED: return ActionType::ADD_LED;
			//default:return ActionType::GATE_BAR;
			}
		}
		else {
			//Check if there will be a gate bar
			//return ActionType::GATE_BAR;
		}
	}
	// User clicks on status bar
	else {
		return ActionType::STATUS_BAR;
	}		
}


Input::~Input() {

}
	
