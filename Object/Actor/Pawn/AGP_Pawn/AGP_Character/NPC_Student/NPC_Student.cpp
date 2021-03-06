// All the original content belonged to the US Army

#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Character/NPC_Student/NPC_Student.h"

ANPC_Student::ANPC_Student()
{
	bStaticSkinsAndMeshes  = true;
	bCleanUp               = false;
	Skins                  = {
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_Characters/Inf/Soldier_PANTS_Forest_BDU_Clean_Mat.Soldier_PANTS_Forest_BDU_Clean_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_Characters/Inf/Soldier_SHIRT_Forest_BDU_Clean_Mat.Soldier_SHIRT_Forest_BDU_Clean_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_Characters/Inf/Soldier_HAND_Inf_Afr_Mat.Soldier_HAND_Inf_Afr_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_Characters/Inf/Soldier_FACE_AfrA_Mat.Soldier_FACE_AfrA_Mat'"), NULL, LOAD_None, NULL)
	};
}


bool ANPC_Student::IsFriend(APawn* Other)
{
	return true;
}

