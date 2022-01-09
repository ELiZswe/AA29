// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIStyles/AAGUIStyles/STY_AAGUITreeSeparatorListItem/STY_AAGUITreeSeparatorListItem.h"

USTY_AAGUITreeSeparatorListItem::USTY_AAGUITreeSeparatorListItem()
{
	KeyName = "AAGUITreeSeparatorListItem";
	FontColors = {
		FColor(255, 255, 255, 255),
		FColor(255, 255, 255, 255),
		FColor(255, 255, 255, 255),
		FColor(255, 255, 255, 255),
		FColor(255, 255, 255, 255)
	};
	ImgColors[4] = FColor(255, 255, 255, 255);
	RStyles = {
		EMenuRenderStyle::MSTY_Translucent,
		EMenuRenderStyle::MSTY_Translucent,
		EMenuRenderStyle::MSTY_Translucent,
		EMenuRenderStyle::MSTY_Translucent,
		EMenuRenderStyle::MSTY_Translucent
	};
	Images = {
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/field_translucent_Mat.field_translucent_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/field_translucent_Mat.field_translucent_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/field_translucent_Mat.field_translucent_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/field_translucent_Mat.field_translucent_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/field_translucent_Mat.field_translucent_Mat'"), NULL, LOAD_None, NULL)
	};
}
