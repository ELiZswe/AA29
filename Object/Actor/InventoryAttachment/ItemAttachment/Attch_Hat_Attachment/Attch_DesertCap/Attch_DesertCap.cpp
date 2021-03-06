// All the original content belonged to the US Army

#include "AA29/Object/Actor/InventoryAttachment/ItemAttachment/Attch_Hat_Attachment/Attch_DesertCap/Attch_DesertCap.h"

AAttch_DesertCap::AAttch_DesertCap()
{
	StaticMesh = LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AA2_Attachments/us-soldier/m-bdu_cap.m-bdu_cap"), NULL, LOAD_None, NULL);
	Skins      = {
	                  Cast<UMaterialInstance>(StaticLoadObject(UMaterialInstance::StaticClass(), NULL, TEXT("MaterialInstance'/Game/AmericasArmy/Textures/T_AA2_Attachments/us-soldier/skn-bdu_dsrt_cap_Mat.skn-bdu_dsrt_cap_Mat'")))
            	};
}
