// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIStyles/AAGUIStyles/STY_AAImageBorder/STY_AAImageBorder.h"

USTY_AAImageBorder::USTY_AAImageBorder()
{
	KeyName = "ImageBorder";
	ImgColors = {
		FColor(212, 212, 212, 255),
		FColor(40, 186, 220, 255),
		FColor(155, 252, 185, 255),
		FColor(212, 212, 212, 255),
		FColor(212, 212, 212, 255)
	};
	Images = {
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/Engine/MenuWhite_Mat.MenuWhite_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/Engine/MenuWhite_Mat.MenuWhite_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/Engine/MenuWhite_Mat.MenuWhite_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/Engine/MenuWhite_Mat.MenuWhite_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/Engine/MenuWhite_Mat.MenuWhite_Mat'"), NULL, LOAD_None, NULL)
	};
	ImgStyle = {
		EImgStyle::ISTY_Scaled,
		EImgStyle::ISTY_Scaled,
		EImgStyle::ISTY_Scaled,
		EImgStyle::ISTY_Scaled,
		EImgStyle::ISTY_Scaled
	};
	BorderOffsets = {
		2,
		2,
		2,
		2
	};
}
