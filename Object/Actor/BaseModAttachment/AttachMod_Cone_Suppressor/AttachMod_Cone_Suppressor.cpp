// All the original content belonged to the US Army

#include "AA29/Object/Actor/BaseModAttachment/AttachMod_Cone_Suppressor/AttachMod_Cone_Suppressor.h"

AAttachMod_Cone_Suppressor::AAttachMod_Cone_Suppressor()
{
	DrawType = EDrawType::DT_Mesh;
	Mesh = LoadObject<USkeletalMesh>(NULL, TEXT("SkeletalMesh'/Game/AmericasArmy/Animations/A_AA2_ModsOpfor/cone_flash_suppressor_3p.cone_flash_suppressor_3p'"), NULL, LOAD_None, NULL);
}
