// All the original content belonged to the US Army


#include "NPC_TowerObserverFemale.h"

ANPC_TowerObserverFemale::ANPC_TowerObserverFemale()
{
	bStaticSkinsAndMeshes	= true;
	bCleanUp				= false;
	CustomMesh				= LoadObject<USkeletalMesh>(NULL, TEXT("/Game/AmericasArmy/Animations/A_AA2_CharactersCiv/SoldierM_Infantry_ClassB.SoldierM_Infantry_ClassB"), NULL, LOAD_None, NULL);
	Skins					= {
		Cast<UMaterialInstance>(StaticLoadObject(UMaterialInstance::StaticClass(), NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_Characters/Inf/Soldier_PANTS_Forest_BDU_Clean_Mat.Soldier_PANTS_Forest_BDU_Clean_Mat'"))),
		Cast<UMaterialInstance>(StaticLoadObject(UMaterialInstance::StaticClass(), NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_Characters/Inf/Soldier_SHIRT_Forest_BDU_Clean_Mat.Soldier_SHIRT_Forest_BDU_Clean_Mat'"))),
		Cast<UMaterialInstance>(StaticLoadObject(UMaterialInstance::StaticClass(), NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_Characters/Inf/Soldier_HAND_Inf_Afr_Mat.Soldier_HAND_Inf_Afr_Mat'"))),
		Cast<UMaterialInstance>(StaticLoadObject(UMaterialInstance::StaticClass(), NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_Characters/Inf/SoldierF_FACE_AFR_studentA_Mat.SoldierF_FACE_AFR_studentA_Mat'")))
	};
	LoadMesh();
}


void ANPC_TowerObserverFemale::PossessedBy(AController* C)
{

}
void ANPC_TowerObserverFemale::BeginPlay()
{

}