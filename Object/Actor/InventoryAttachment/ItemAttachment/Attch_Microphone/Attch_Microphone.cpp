// All the original content belonged to the US Army

#include "AA29/Object/Actor/InventoryAttachment/ItemAttachment/Attch_Microphone/Attch_Microphone.h"

AAttch_Microphone::AAttch_Microphone()
{
	AttachBone  = "RHandObject";
	StaticMesh  = LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AA2_Attachments/Misc/ath2_misc_microphone.ath2_misc_microphone"), NULL, LOAD_None, NULL);
	DrawScale   = 0.75;
}
