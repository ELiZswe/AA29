// All the original content belonged to the US Army

#include "AA29/Object/Actor/BaseModAttachment/AttachMod_Compact_AimPoint/AttachMod_Compact_AimPoint.h"

AAttachMod_Compact_AimPoint::AAttachMod_Compact_AimPoint()
{
	DrawType = EDrawType::DT_Mesh;
	Mesh = LoadObject<USkeletalMesh>(NULL, TEXT("SkeletalMesh'/Game/AmericasArmy/Animations/A_AA2_ModsOpfor/compact_3p.compact_3p'"), NULL, LOAD_None, NULL);
}
