#include "Select.h"
#include "..\Components\Component.h"
#include "..\Components\Switch.h"



Select::Select(ApplicationManager* pApp): Action(pApp), x(0), y(0)
{

}

void Select::ReadActionParameters()
{
	pManager->GetInput()->GetPointClicked(x, y); // To get the x, y coordinates of point clicked
}

void Select::Execute()
{
	//ReadActionParameters(); // To get the clicked coordinates

	COMPS comp;
	int target = pManager->WhichComp(comp); // To get the index of the target component.

	
	if (target == -1) // check if the user clicked on a blank space
	{
		pManager->DeselectExcept(); // deselect all
	}
	else
	{
		pManager->DeselectExcept(target); // deselect all except target

		pManager->SelectComponent(target);

		pManager->SetLastSelected(target); // pointer to the last selected comp
		Component* LastSelectedComponent = pManager->GetLastSelected();

		LastSelectedComponent->SetIfSelected(true);

		//GraphicsInfo r_GfxInfo = LastSelectedComponent->getGraphicsInfo();

		switch (comp)
		{
		case COMPS::ITM_GATE:
			break;
		case COMPS::ITM_SWITCH:
		{
			if (UI.AppMode == DESIGN) {

				break;
			}
			

		case COMPS::ITM_LED:
			//pManager->GetOutput()->DrawLED(r_GfxInfo, false, true); // to be done //LED selected Not High//
			break;
		case COMPS::ITM_CONN:
			//pManager->GetOutput()->DrawConnection(r_GfxInfo, true); // Make connetion highlighted
			break;
		default:
			break;
		}
	}
	}
}

void Select::Undo()
{
}

void Select::Redo()
{
}

Select::~Select()
{
}
