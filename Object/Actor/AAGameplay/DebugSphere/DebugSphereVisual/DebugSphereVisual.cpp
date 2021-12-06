// All the original content belonged to the US Army


#include "AA29/Object/Actor/AAGameplay/DebugSphere/DebugSphereVisual/DebugSphereVisual.h"

ADebugSphereVisual::ADebugSphereVisual()
{
	YawRate = -4096;
	//textSphere = FinalBlend'T_AA2_MISC.misc.Misc_Grid_BlueF';
}

void ADebugSphereVisual::PostBeginPlay()
{
	UE_LOG(LogTemp, Log, TEXT("DebugSphereVisual PostBeginPlay() entered"));
	//Log("Texture for vision sphere: " $ textSphere);
	//Skins[0] = textSphere;
}