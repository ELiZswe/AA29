// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIStyles/AAGUIStyles/STY_AAScoreboardUnitText/STY_AAScoreboardUnitText.h"

USTY_AAScoreboardUnitText::USTY_AAScoreboardUnitText()
{
	KeyName = "ScoreboardUnitText";
	FontNames[0] = "AAFontMidGame";
	FontNames[1] = "AAFontMidGame";
	FontNames[2] = "AAFontMidGame";
	FontNames[3] = "AAFontMidGame";
	FontNames[4] = "AAFontMidGame";
	FontColors[1] = FColor(229, 248, 251, 255);
	FontColors[2] = FColor(229, 248, 251, 255);
	FontColors[3] = FColor(229, 248, 251, 255);
	FontColors[4] = FColor(160, 160, 160, 255);
	Images[0] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/field_translucent_Mat.field_translucent_Mat'"), NULL, LOAD_None, NULL);
	Images[1] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/field_translucent_Mat.field_translucent_Mat'"), NULL, LOAD_None, NULL);
	Images[2] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/field_translucent_Mat.field_translucent_Mat'"), NULL, LOAD_None, NULL);
	Images[3] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/field_translucent_Mat.field_translucent_Mat'"), NULL, LOAD_None, NULL);
	Images[4] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/field_translucent_Mat.field_translucent_Mat'"), NULL, LOAD_None, NULL);
	BorderOffsets[0] = 3;
	BorderOffsets[1] = 10;
	BorderOffsets[2] = 3;
	BorderOffsets[3] = 12;
}
