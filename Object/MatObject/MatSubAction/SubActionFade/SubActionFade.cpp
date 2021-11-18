// All the original content belonged to the US Army


#include "AA29/Object/MatObject/MatSubAction/SubActionFade/SubActionFade.h"

USubActionFade::USubActionFade()
{
	bFadeOut = true;
		

		Icon = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/Engine/SubActionFade.SubActionFade'"), NULL, LOAD_None, NULL);
		Desc = "Fade";
}