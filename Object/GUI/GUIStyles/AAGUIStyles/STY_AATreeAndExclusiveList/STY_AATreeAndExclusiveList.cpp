// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIStyles/AAGUIStyles/STY_AATreeAndExclusiveList/STY_AATreeAndExclusiveList.h"

USTY_AATreeAndExclusiveList::USTY_AATreeAndExclusiveList()
{
	KeyName = "TreeAndExclusiveList";
	FontNames[0] = "AAFontServerList";
	FontNames[1] = "AAFontServerList";
	FontNames[2] = "AAFontServerList";
	FontNames[3] = "AAFontServerList";
	FontNames[4] = "AAFontServerList";
	FontColors[0] = FColor(156, 201, 168, 255);
	FontColors[2] = FColor(229, 248, 251, 255);
	FontColors[3] = FColor(229, 248, 251, 255);
	FontColors[4] = FColor(160, 160, 160, 255);
	Images[0] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/field_translucent_Mat.field_translucent_Mat'"), NULL, LOAD_None, NULL);
	Images[1] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/field_translucent_Mat.field_translucent_Mat'"), NULL, LOAD_None, NULL);
	Images[2] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/field_translucent_Mat.field_translucent_Mat'"), NULL, LOAD_None, NULL);
	Images[3] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/field_translucent_Mat.field_translucent_Mat'"), NULL, LOAD_None, NULL);
	Images[4] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/field_translucent_Mat.field_translucent_Mat'"), NULL, LOAD_None, NULL);

}
