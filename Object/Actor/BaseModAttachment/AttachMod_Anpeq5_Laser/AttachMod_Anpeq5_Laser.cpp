// All the original content belonged to the US Army

#include "AA29/Object/Actor/BaseModAttachment/AttachMod_Anpeq5_Laser/AttachMod_Anpeq5_Laser.h"

AAttachMod_Anpeq5_Laser::AAttachMod_Anpeq5_Laser()
{
	DrawType = EDrawType::DT_Mesh;
	Mesh = LoadObject<USkeletalMesh>(NULL, TEXT("SkeletalMesh'/Game/AmericasArmy/Animations/A_AA2_ModsUS/anpeq5.anpeq5'"), NULL, LOAD_None, NULL);
}
