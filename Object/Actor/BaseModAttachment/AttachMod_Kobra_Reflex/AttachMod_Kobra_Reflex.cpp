// All the original content belonged to the US Army

#include "AA29/Object/Actor/BaseModAttachment/AttachMod_Kobra_Reflex/AttachMod_Kobra_Reflex.h"

AAttachMod_Kobra_Reflex::AAttachMod_Kobra_Reflex()
{
	DrawType = EDrawType::DT_Mesh;
	Mesh = LoadObject<USkeletalMesh>(NULL, TEXT("SkeletalMesh'/Game/AmericasArmy/Animations/A_AA2_ModsOpfor/kobra_3p.kobra_3p'"), NULL, LOAD_None, NULL);
}
