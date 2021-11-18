// All the original content belonged to the US Army


#include "AA29/Object/CameraEffect/CamEffect_BlurOut/CamEffect_BlurOut.h"

UCamEffect_BlurOut::UCamEffect_BlurOut()
{
	WhenToPostRender = ECameraEffect_PipelineLocation::CEPL_AfterHUD;
	FinalEffect = true;
}

//native Function BeginBlur(float Duration, int MaxBlurPixels, PlayerController PC);
void UCamEffect_BlurOut::BeginBlur(float aDuration, int32 MaxBlurPixels, APlayerController* PC)
{
	//Some code from Native   /ELiZ
}

//native Function EndBlur(PlayerController PC);
void UCamEffect_BlurOut::EndBlur(APlayerController* PC)
{
	//Some code from Native   /ELiZ
}



