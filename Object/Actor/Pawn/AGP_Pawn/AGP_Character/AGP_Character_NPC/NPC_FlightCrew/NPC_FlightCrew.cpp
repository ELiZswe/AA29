// All the original content belonged to the US Army


#include "NPC_FlightCrew.h"

ANPC_FlightCrew::ANPC_FlightCrew()
{
	bStaticSkinsAndMeshes	= true;
	bCleanUp				= false;
	CustomMesh				= LoadObject<USkeletalMesh>(NULL, TEXT("/Game/AmericasArmy/Animations/A_AA2_CharactersCiv/CivilianM.CivilianM"), NULL, LOAD_None, NULL);
	Skins					= {
								Cast<UMaterialInstance>(StaticLoadObject(UMaterialInstance::StaticClass(), NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_Characters/FlightCrew/FlightCrew_PANTS_Chute_Mat.FlightCrew_PANTS_Chute_Mat'"))),
								Cast<UMaterialInstance>(StaticLoadObject(UMaterialInstance::StaticClass(), NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_Characters/FlightCrew/FlightCrew_SHIRT_Chute_Mat.FlightCrew_SHIRT_Chute_Mat'"))),
								Cast<UMaterialInstance>(StaticLoadObject(UMaterialInstance::StaticClass(), NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_Characters/Inf/Soldier_HAND_Inf_Latin_Mat.Soldier_HAND_Inf_Latin_Mat'"))),
								Cast<UMaterialInstance>(StaticLoadObject(UMaterialInstance::StaticClass(), NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_Characters/Inf/Soldier_FACE_LatinA_Mat.Soldier_FACE_LatinA_Mat'")))
							};
	LoadMesh();
}