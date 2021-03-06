// All the original content belonged to the US Army

#include "AA29/Object/Actor/BaseModAttachment/AttachMod_SPR_Suppressor/AttachMod_SPR_Suppressor.h"
#include "AA29/Object/Actor/Emitter/BaseMuzzleFlashEmitter/SuppressorMuzzleFlash/SuppressorMuzzleFlash.h"

AAttachMod_SPR_Suppressor::AAttachMod_SPR_Suppressor()
{
	//cSuppressorMuzzleFlash = ASuppressorMuzzleFlash::StaticClass();
	DrawType = EDrawType::DT_Mesh;
	Mesh = LoadObject<USkeletalMesh>(NULL, TEXT("SkeletalMesh'/Game/AmericasArmy/Animations/A_AA2_ModsUS/spr_suppressor_3p.spr_suppressor_3p'"), NULL, LOAD_None, NULL);
}
