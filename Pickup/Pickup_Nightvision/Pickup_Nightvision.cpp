// All the original content belonged to the US Army


#include "Pickup_Nightvision.h"
APickup_Nightvision::APickup_Nightvision()
{
	DrawType    = EDrawType::DT_StaticMesh;
	VisibleStaticMesh->SetStaticMesh(LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AA2_Attachments/us-soldier/m-nvg_dwn.m-nvg_dwn"), NULL, LOAD_None, NULL));
}
