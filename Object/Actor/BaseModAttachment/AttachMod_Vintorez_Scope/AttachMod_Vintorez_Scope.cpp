// All the original content belonged to the US Army

#include "AA29/Object/Actor/BaseModAttachment/AttachMod_Vintorez_Scope/AttachMod_Vintorez_Scope.h"

AAttachMod_Vintorez_Scope::AAttachMod_Vintorez_Scope()
{
	DrawType = EDrawType::DT_Mesh;
	Mesh = LoadObject<USkeletalMesh>(NULL, TEXT("SkeletalMesh'/Game/AmericasArmy/Animations/A_AA2_ModsOpfor/PSO_3p.PSO_3p'"), NULL, LOAD_None, NULL);
}
