// All the original content belonged to the US Army

#include "AA29/Object/Actor/BaseModAttachment/AttachMod_BS1_Gren/AttachMod_BS1_Gren.h"

AAttachMod_BS1_Gren::AAttachMod_BS1_Gren()
{
	WeaponMesh = LoadObject<USkeletalMesh>(NULL, TEXT("SkeletalMesh'/Game/AmericasArmy/Animations/A_AA2_Weapons3P/aks74u_bs1_3P.aks74u_bs1_3P'"), NULL, LOAD_None, NULL);
	DrawType = EDrawType::DT_None;
}
