// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIStyles/AAGUIStyles/STY_AAImageBorder/STY_AAImageBorder.h"

USTY_AAImageBorder::USTY_AAImageBorder()
{
	KeyName = "ImageBorder";
	ImgColors[0] = FColor(212, 212, 212, 255);
	ImgColors[1] = FColor(40, 186, 220, 255);
	ImgColors[2] = FColor(155, 252, 185, 255);
	ImgColors[3] = FColor(212, 212, 212, 255);
	ImgColors[4] = FColor(212, 212, 212, 255);
	Images[0] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/Engine/MenuWhite_Mat.MenuWhite_Mat'"), NULL, LOAD_None, NULL);
	Images[1] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/Engine/MenuWhite_Mat.MenuWhite_Mat'"), NULL, LOAD_None, NULL);
	Images[2] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/Engine/MenuWhite_Mat.MenuWhite_Mat'"), NULL, LOAD_None, NULL);
	Images[3] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/Engine/MenuWhite_Mat.MenuWhite_Mat'"), NULL, LOAD_None, NULL);
	Images[4] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/Engine/MenuWhite_Mat.MenuWhite_Mat'"), NULL, LOAD_None, NULL);
	ImgStyle[0] = EImgStyle::ISTY_Scaled;
	ImgStyle[1] = EImgStyle::ISTY_Scaled;
	ImgStyle[2] = EImgStyle::ISTY_Scaled;
	ImgStyle[3] = EImgStyle::ISTY_Scaled;
	ImgStyle[4] = EImgStyle::ISTY_Scaled;
	BorderOffsets[0] = 2;
	BorderOffsets[1] = 2;
	BorderOffsets[2] = 2;
	BorderOffsets[3] = 2;
}
