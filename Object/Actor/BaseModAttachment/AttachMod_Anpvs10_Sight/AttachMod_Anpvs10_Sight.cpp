// All the original content belonged to the US Army

#include "AA29/Object/Actor/BaseModAttachment/AttachMod_Anpvs10_Sight/AttachMod_Anpvs10_Sight.h"

AAttachMod_Anpvs10_Sight::AAttachMod_Anpvs10_Sight()
{
	DrawType = EDrawType::DT_Mesh;
	Mesh = LoadObject<USkeletalMesh>(NULL, TEXT("SkeletalMesh'/Game/AmericasArmy/Animations/A_AA2_ModsUS/anpvs10.anpvs10'"), NULL, LOAD_None, NULL);
}
