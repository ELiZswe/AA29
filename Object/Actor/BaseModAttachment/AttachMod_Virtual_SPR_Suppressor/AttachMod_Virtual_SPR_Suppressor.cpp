// All the original content belonged to the US Army

#include "AA29/Object/Actor/BaseModAttachment/AttachMod_Virtual_SPR_Suppressor/AttachMod_Virtual_SPR_Suppressor.h"
#include "AA29/Object/Actor/Emitter/BaseMuzzleFlashEmitter/SuppressorMuzzleFlash/SuppressorMuzzleFlash.h"

AAttachMod_Virtual_SPR_Suppressor::AAttachMod_Virtual_SPR_Suppressor()
{
	//cSuppressorMuzzleFlash = ASuppressorMuzzleFlash::StaticClass()
	DrawType = EDrawType::DT_None;
}
