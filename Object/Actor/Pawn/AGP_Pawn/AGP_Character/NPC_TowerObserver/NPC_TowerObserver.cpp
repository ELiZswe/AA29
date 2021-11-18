// All the original content belonged to the US Army


#include "NPC_TowerObserver.h"

ANPC_TowerObserver::ANPC_TowerObserver()
{
	bStaticSkinsAndMeshes   = true;
	bCleanUp                = false;
	CustomMesh                    = LoadObject<USkeletalMesh>(NULL, TEXT("/Game/AmericasArmy/Animations/A_AA2_CharactersCiv/SoldierM_Infantry_ClassB.SoldierM_Infantry_ClassB"), NULL, LOAD_None, NULL);
	Skins                   = {
		Cast<UMaterialInstance>(StaticLoadObject(UMaterialInstance::StaticClass(), NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_Characters/Inf/Soldier_PANTS_Forest_BDU_Clean_Mat.Soldier_PANTS_Forest_BDU_Clean_Mat'"))),
		Cast<UMaterialInstance>(StaticLoadObject(UMaterialInstance::StaticClass(), NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_Characters/Inf/Soldier_SHIRT_Forest_BDU_Clean_Mat.Soldier_SHIRT_Forest_BDU_Clean_Mat'"))),
		Cast<UMaterialInstance>(StaticLoadObject(UMaterialInstance::StaticClass(), NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_Characters/Inf/Soldier_HAND_Inf_Afr_Mat.Soldier_HAND_Inf_Afr_Mat'"))),
		Cast<UMaterialInstance>(StaticLoadObject(UMaterialInstance::StaticClass(), NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_Characters/Inf/Soldier_FACE_AfrA_Mat.Soldier_FACE_AfrA_Mat'")))
	};
	LoadMesh();
}


void ANPC_TowerObserver::PossessedBy(AController* C)
{

}
void ANPC_TowerObserver::BeginPlay()
{

}