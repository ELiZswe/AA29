// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIStyles/STY_RoundButton/STY_ArrowLeft/STY_ArrowLeft.h"

USTY_ArrowLeft::USTY_ArrowLeft()
{
	KeyName = "ArrowLeft";
	Images[0] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/InterfaceContent/Menu/ArrowBlueLeft_Mat.ArrowBlueLeft_Mat'"), NULL, LOAD_None, NULL);
	Images[1] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/InterfaceContent/Menu/ArrowBlueLeft_Mat.ArrowBlueLeft_Mat'"), NULL, LOAD_None, NULL);
	Images[2] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/InterfaceContent/Menu/ArrowBlueLeft_Mat.ArrowBlueLeft_Mat'"), NULL, LOAD_None, NULL);
	Images[3] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/InterfaceContent/Menu/ArrowBlueLeft_Mat.ArrowBlueLeft_Mat'"), NULL, LOAD_None, NULL);
	ImgStyle[0] = EImgStyle::ISTY_Scaled;
	ImgStyle[1] = EImgStyle::ISTY_Scaled;
	ImgStyle[2] = EImgStyle::ISTY_Scaled;
	ImgStyle[3] = EImgStyle::ISTY_Scaled;
	ImgStyle[4] = EImgStyle::ISTY_Scaled;
}
