// All the original content belonged to the US Army

#include "AA29/Object/Actor/BaseModAttachment/AttachMod_VliFlashLight/AttachMod_VliFlashLight.h"

AAttachMod_VliFlashLight::AAttachMod_VliFlashLight()
{
	DrawType = EDrawType::DT_Mesh;
	Mesh = LoadObject<USkeletalMesh>(NULL, TEXT("SkeletalMesh'/Game/AmericasArmy/Animations/A_AA2_ModsUS/vliflashlight.vliflashlight'"), NULL, LOAD_None, NULL);
}
