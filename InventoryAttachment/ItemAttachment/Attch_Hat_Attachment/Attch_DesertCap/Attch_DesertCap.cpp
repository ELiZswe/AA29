// All the original content belonged to the US Army


#include "Attch_DesertCap.h"

AAttch_DesertCap::AAttch_DesertCap()
{
	StaticMesh = LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AA2_Attachments/us-soldier/m-bdu_cap.m-bdu_cap"), NULL, LOAD_None, NULL);
	Skins      = {
	                  Cast<UMaterialInstance>(StaticLoadObject(UMaterialInstance::StaticClass(), NULL, TEXT("MaterialInstance'/Game/AmericasArmy/Textures/T_AA2_Attachments/us-soldier/skn-bdu_dsrt_cap_Mat.skn-bdu_dsrt_cap_Mat'")))
            	};
}
