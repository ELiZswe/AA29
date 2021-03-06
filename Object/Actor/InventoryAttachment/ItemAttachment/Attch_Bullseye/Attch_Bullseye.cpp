// All the original content belonged to the US Army

#include "AA29/Object/Actor/InventoryAttachment/ItemAttachment/Attch_Bullseye/Attch_Bullseye.h"
#include "AA29/Object/Actor/Inventory/Inventory.h"

AAttch_Bullseye::AAttch_Bullseye()
{
	AttachBone = "RuckSack";
	DisableOtherAttachment = {
		"Attch_MedicRuck"
		"Attch_RPGBackpack"
		"Attch_FlightCrewPara"
	};
	EnemyStaticMesh = LoadObject<UStaticMesh>(NULL, TEXT("StaticMesh'/Game/AmericasArmy/Meshes/M_AA2_Attachments/us-soldier/Target.Target'"), NULL, LOAD_None, NULL);
	FriendlyStaticMesh = LoadObject<UStaticMesh>(NULL, TEXT("StaticMesh'/Game/AmericasArmy/Meshes/M_AA2_Attachments/us-soldier/Target.Target'"), NULL, LOAD_None, NULL);
	//EnemyAttachmentClass = AAttch_Bullseye::StaticClass();
	StaticMesh = LoadObject<UStaticMesh>(NULL, TEXT("StaticMesh'/Game/AmericasArmy/Meshes/M_AA2_Attachments/us-soldier/Target.Target'"), NULL, LOAD_None, NULL);
}

FName AAttch_Bullseye::GetAttachBoneFor(AInventory* Inv)
{
	return "RuckSack";
}
