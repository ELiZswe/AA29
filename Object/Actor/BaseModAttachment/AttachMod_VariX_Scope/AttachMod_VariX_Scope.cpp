// All the original content belonged to the US Army

#include "AA29/Object/Actor/BaseModAttachment/AttachMod_VariX_Scope/AttachMod_VariX_Scope.h"

AAttachMod_VariX_Scope::AAttachMod_VariX_Scope()
{
	DrawType = EDrawType::DT_Mesh;
	Mesh = LoadObject<USkeletalMesh>(NULL, TEXT("SkeletalMesh'/Game/AmericasArmy/Animations/A_AA2_ModsUS/vari_x_iii_m3_scope_3p.vari_x_iii_m3_scope_3p'"), NULL, LOAD_None, NULL);
}
