// All the original content belonged to the US Army


#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIGFXButton/GUICheckBoxButton/GUICheckBoxButton.h"

UGUICheckBoxButton::UGUICheckBoxButton()
{
	CheckedOverlay = {
	LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/box_check_selected_Mat.box_check_selected_Mat'"), NULL, LOAD_None, NULL),
	LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/box_check_selected_Mat.box_check_selected_Mat'"), NULL, LOAD_None, NULL),
	LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/box_check_selected_Mat.box_check_selected_Mat'"), NULL, LOAD_None, NULL),
	LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/box_check_selected_Mat.box_check_selected_Mat'"), NULL, LOAD_None, NULL),
	LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/box_check_selected_Mat.box_check_selected_Mat'"), NULL, LOAD_None, NULL)
	};
	Position = EIconPosition::ICP_Scaled;
	bCheckBox = true;
	StyleName = "CheckBox";
	bTabStop = true;
}

void UGUICheckBoxButton::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	/*
	local int i;
	InitComponent(MyController, MyOwner);
	for (i = 0; i < 10; i++)
	{
		if (CheckedOverlay[i] == None)
		{
			CheckedOverlay[i] = Graphic;
		}
	}
	*/
}
