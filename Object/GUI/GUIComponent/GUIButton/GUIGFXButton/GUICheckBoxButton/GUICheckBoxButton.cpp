// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIGFXButton/GUICheckBoxButton/GUICheckBoxButton.h"
#include "AA29/Object/GUI/GUIComponent/GUIComponent.h"
#include "AA29/Object/Interactions/Interaction/BaseGUIController/GUIController/GUIController.h"

UGUICheckBoxButton::UGUICheckBoxButton()
{
	CheckedOverlay.SetNum(10);
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
	int32 i = 0;
	Super::InitComponent(MyController, MyOwner);
	for (i = 0; i < 10; i++)
	{
		if (CheckedOverlay[i] == nullptr)
		{
			CheckedOverlay[i] = Graphic;
		}
	}
}
