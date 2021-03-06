// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIStyles/STY_ListSelection/STY_ListSelection.h"
#include "AA29/Object/Interactions/Interaction/BaseGUIController/GUIController/GUIController.h"

USTY_ListSelection::USTY_ListSelection()
{
	KeyName = "ListSelection";
	FontNames[10] = "UT2HeaderFont";
	FontNames[11] = "UT2HeaderFont";
	FontNames[12] = "UT2HeaderFont";
	FontNames[13] = "UT2HeaderFont";
	FontNames[14] = "UT2HeaderFont";
	FontColors[0] = FColor(128, 64, 64, 255);
	FontColors[1] = FColor(128, 64, 64, 255);
	FontColors[2] = FColor(128, 64, 64, 255);
	FontColors[3] = FColor(128, 64, 64, 255);
	FontColors[4] = FColor(128, 64, 64, 255);
}

void USTY_ListSelection::Initialize()
{
	int32 i = 0;
	Super::Initialize();
	for (i = 0; i < 5; i++)
	{
		Images[i] = Controller->DefaultPens[0];
	}
}
