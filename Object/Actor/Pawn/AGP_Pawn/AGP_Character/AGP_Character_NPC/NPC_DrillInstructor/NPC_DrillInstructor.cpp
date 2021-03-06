// All the original content belonged to the US Army

#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Character/AGP_Character_NPC/NPC_DrillInstructor/NPC_DrillInstructor.h"

ANPC_DrillInstructor::ANPC_DrillInstructor()
{
	bStaticSkinsAndMeshes	= true;
	bCleanUp				= false;
	Skins = {
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_Characters/Instructor/Instructor_PANTS_Forest_Mat.Instructor_PANTS_Forest_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_Characters/Instructor/Instructor_SHIRT_Forest_Drill_Mat.Instructor_SHIRT_Forest_Drill_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_Characters/Instructor/Instructor_HAND_Inf_Cauc_Mat.Instructor_HAND_Inf_Cauc_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_Characters/Instructor/Instructor_FACE_Drill_Instructor_Mat.Instructor_FACE_Drill_Instructor_Mat'"), NULL, LOAD_None, NULL)
	};
}

bool ANPC_DrillInstructor::IsFriend(APawn* Other)
{
	return true;
}
