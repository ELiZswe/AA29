// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIStyles/AAGUIStyles/STY_AAGUITreeSeparatorListItem/STY_AAGUITreeSeparatorListItem.h"

USTY_AAGUITreeSeparatorListItem::USTY_AAGUITreeSeparatorListItem()
{
	KeyName = "AAGUITreeSeparatorListItem";
	FontColors[0] = FColor(255, 255, 255, 255);
	FontColors[1] = FColor(255, 255, 255, 255);
	FontColors[2] = FColor(255, 255, 255, 255);
	FontColors[3] = FColor(255, 255, 255, 255);
	FontColors[4] = FColor(255, 255, 255, 255);
	ImgColors[4] = FColor(255, 255, 255, 255);
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
