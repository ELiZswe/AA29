// All the original content belonged to the US Army

#include "AA29/Object/Actor/BaseModAttachment/AttachMod_PBS4_Suppressor/AttachMod_PBS4_Suppressor.h"
#include "AA29/Object/Actor/Emitter/BaseMuzzleFlashEmitter/SuppressorMuzzleFlash/SuppressorMuzzleFlash.h"

AAttachMod_PBS4_Suppressor::AAttachMod_PBS4_Suppressor()
{
	//cSuppressorMuzzleFlash = ASuppressorMuzzleFlash::StaticClass();
	DrawType = EDrawType::DT_Mesh;
	Mesh = LoadObject<USkeletalMesh>(NULL, TEXT("SkeletalMesh'/Game/AmericasArmy/Animations/A_AA2_ModsOpfor/pbs4_suppressor_3p.pbs4_suppressor_3p'"), NULL, LOAD_None, NULL);
}
