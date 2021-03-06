// All the original content belonged to the US Army

#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Character/AGP_Character_NPC/NPC_FlightCrew/NPC_FlightCrew.h"

ANPC_FlightCrew::ANPC_FlightCrew()
{
	bStaticSkinsAndMeshes	= true;
	bCleanUp				= false;
	CustomMesh = LoadObject<USkeletalMesh>(NULL, TEXT("SkeletalMesh'/Game/AmericasArmy/Animations/A_AA2_CharactersCiv/CivilianM.CivilianM'"), NULL, LOAD_None, NULL);
	Skins = {
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_Characters/FlightCrew/FlightCrew_PANTS_Chute_Mat.FlightCrew_PANTS_Chute_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_Characters/FlightCrew/FlightCrew_SHIRT_Chute_Mat.FlightCrew_SHIRT_Chute_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_Characters/Inf/Soldier_HAND_Inf_Latin_Mat.Soldier_HAND_Inf_Latin_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_Characters/Inf/Soldier_FACE_LatinA_Mat.Soldier_FACE_LatinA_Mat'"), NULL, LOAD_None, NULL)
	};
	LoadMesh();
}

bool ANPC_FlightCrew::IsFriend(APawn* Other)
{
	return true;
}

void ANPC_FlightCrew::PostBeginPlay()
{
	Super::PostBeginPlay();
	AddDefaultInventory();
	LoadSkinsAndMeshes();
}
