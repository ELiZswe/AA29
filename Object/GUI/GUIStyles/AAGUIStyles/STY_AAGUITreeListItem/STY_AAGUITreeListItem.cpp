// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIStyles/AAGUIStyles/STY_AAGUITreeListItem/STY_AAGUITreeListItem.h"

USTY_AAGUITreeListItem::USTY_AAGUITreeListItem()
{
	KeyName = "AAGUITreeListItem";
	FontColors[0] = FColor(156, 201, 168, 255);
	FontColors[3] = FColor(156, 201, 168, 255);
	FontColors[4] = FColor(156, 201, 168, 255);
	ImgColors[0] = FColor(127, 127, 127, 127);
	ImgColors[1] = FColor(127, 127, 127, 127);
	ImgColors[2] = FColor(127, 127, 127, 127);
	ImgColors[3] = FColor(127, 127, 127, 127);
	ImgColors[4] = FColor(127, 127, 127, 127);
	RStyles[0] = EMenuRenderStyle::MSTY_Translucent;
	RStyles[1] = EMenuRenderStyle::MSTY_Translucent;
	RStyles[2] = EMenuRenderStyle::MSTY_Translucent;
	RStyles[3] = EMenuRenderStyle::MSTY_Translucent;
	RStyles[4] = EMenuRenderStyle::MSTY_Translucent;
	Images[0] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/field_translucent_Mat.field_translucent_Mat'"), NULL, LOAD_None, NULL);
	Images[1] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/field_translucent_Mat.field_translucent_Mat'"), NULL, LOAD_None, NULL);
	Images[2] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/field_translucent_Mat.field_translucent_Mat'"), NULL, LOAD_None, NULL);
	Images[3] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/field_translucent_Mat.field_translucent_Mat'"), NULL, LOAD_None, NULL);
	Images[4] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/field_translucent_Mat.field_translucent_Mat'"), NULL, LOAD_None, NULL);

}
