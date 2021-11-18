// All the original content belonged to the US Army


#include "AA29/Object/CameraEffect/CamEffect_FlashBang/CamEffect_FlashBang.h"

UCamEffect_FlashBang::UCamEffect_FlashBang()
{
	WhenToPostRender = ECameraEffect_PipelineLocation::CEPL_AfterHUD;
}
void UCamEffect_FlashBang::StartFlash(float Duration, float Intensity, APlayerController* PC)
{
	//Some code from Native   /ELiZ
}
void UCamEffect_FlashBang::EndFlash(APlayerController* PC)
{
	//Some code from Native   /ELiZ
}

//native Function StartFlash(float Duration, float Intensity, PlayerController PC);
//native Function EndFlash(PlayerController PC);