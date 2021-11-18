// All the original content belonged to the US Army


#include "Attch_BDUCap_med.h"

AAttch_BDUCap_med::AAttch_BDUCap_med()
{
	StaticMesh = LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AA2_Attachments/us-soldier/m-sgt_bdu_cap.m-sgt_bdu_cap"), NULL, LOAD_None, NULL);
	Skins = {
		Cast<UMaterialInstance>(StaticLoadObject(UMaterialInstance::StaticClass(), NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_Attachments/us-soldier/Bdu_Cap_Insinia_Mat.Bdu_Cap_Insinia_Mat'")))
	};
}