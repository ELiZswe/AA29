// All the original content belonged to the US Army

#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Character/AGP_Character_NPC/NPC_AirborneInstructor/NPC_AirborneInstructor.h"

ANPC_AirborneInstructor::ANPC_AirborneInstructor()
{
	bStaticSkinsAndMeshes	= true;
	bCleanUp				= false;
	CustomMesh				= LoadObject<USkeletalMesh>(NULL, TEXT("SkeletalMesh'/Game/AmericasArmy/Animations/A_AA2_CharactersCiv/SoldierM_Infantry_ClassB.SoldierM_Infantry_ClassB'"), NULL, LOAD_None, NULL);
	Skins					= {
		Cast<UMaterialInstance>(StaticLoadObject(UMaterialInstance::StaticClass(), NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_Characters/Inf/Soldier_PANTS_Forest_BDU_Clean_Mat.Soldier_PANTS_Forest_BDU_Clean_Mat'"))),
		Cast<UMaterialInstance>(StaticLoadObject(UMaterialInstance::StaticClass(), NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_Characters/Instructor/Instructor_SHIRT_Airborne_Mat.Instructor_SHIRT_Airborne_Mat'"))),
		Cast<UMaterialInstance>(StaticLoadObject(UMaterialInstance::StaticClass(), NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_Characters/Inf/Soldier_HAND_Inf_Cauc_Mat.Soldier_HAND_Inf_Cauc_Mat'"))),
		Cast<UMaterialInstance>(StaticLoadObject(UMaterialInstance::StaticClass(), NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_Characters/Inf/Soldier_FACE_CaucB_Mat.Soldier_FACE_CaucB_Mat'")))
	};
	LoadMesh();
}

bool ANPC_AirborneInstructor::IsFriend(APawn* Other)
{
	return true;
}

void ANPC_AirborneInstructor::PostBeginPlay()
{
	Super::PostBeginPlay();
	AddDefaultInventory();
	LoadSkinsAndMeshes();
}
