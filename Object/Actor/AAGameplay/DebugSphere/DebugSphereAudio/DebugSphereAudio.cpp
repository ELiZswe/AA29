// All the original content belonged to the US Army


#include "AA29/Object/Actor/AAGameplay/DebugSphere/DebugSphereAudio/DebugSphereAudio.h"

ADebugSphereAudio::ADebugSphereAudio()
{
	YawRate = 4096;
	//textSphere = FinalBlend'T_AA2_MISC.misc.Misc_Grid_GreenF':
	//StaticMesh = StaticMesh'M_AA2_NPCDebugTools.DebugTools.VisionCone';
	//RelativeRotation = (Pitch = 0, Yaw = 16384, Roll = 49152);
}

void ADebugSphereAudio::PostBeginPlay()
{
	UE_LOG(LogTemp, Log, TEXT("DebugSphereAudio PostBeginPlay() entered"));
	//Log("Texture for audio sphere: " $ textSphere);
	//Skins[0] = textSphere;
	//RotationRate.Yaw = YawRate;
}
