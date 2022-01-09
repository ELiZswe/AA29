// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIStyles/AAGUIStyles/STY_AAGUITreeListItem/STY_AAGUITreeListItem.h"

USTY_AAGUITreeListItem::USTY_AAGUITreeListItem()
{
	KeyName = "AAGUITreeListItem";
	FontColors[0] = FColor(156, 201, 168, 255);
	FontColors[3] = FColor(156, 201, 168, 255);
	FontColors[4] = FColor(156, 201, 168, 255);
	ImgColors = {
		FColor(127, 127, 127, 127),
		FColor(127, 127, 127, 127),
		FColor(127, 127, 127, 127),
		FColor(127, 127, 127, 127),
		FColor(127, 127, 127, 127)
	};
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
