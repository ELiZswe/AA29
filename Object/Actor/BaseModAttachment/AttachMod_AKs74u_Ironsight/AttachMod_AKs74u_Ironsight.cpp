// All the original content belonged to the US Army

#include "AA29/Object/Actor/BaseModAttachment/AttachMod_AKs74u_Ironsight/AttachMod_AKs74u_Ironsight.h"

AAttachMod_AKs74u_Ironsight::AAttachMod_AKs74u_Ironsight()
{
	DrawType = EDrawType::DT_Mesh;
	Mesh = LoadObject<USkeletalMesh>(NULL, TEXT("SkeletalMesh'/Game/AmericasArmy/Animations/A_AA2_ModsOpfor/aks74u_ironsight_3p.aks74u_ironsight_3p'"), NULL, LOAD_None, NULL);
}
