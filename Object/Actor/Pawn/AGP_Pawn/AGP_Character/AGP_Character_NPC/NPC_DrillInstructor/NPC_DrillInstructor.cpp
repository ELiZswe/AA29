// All the original content belonged to the US Army


#include "NPC_DrillInstructor.h"

ANPC_DrillInstructor::ANPC_DrillInstructor()
{
	bStaticSkinsAndMeshes	= true;
	bCleanUp				= false;
	Skins					= {
								Cast<UMaterialInstance>(StaticLoadObject(UMaterialInstance::StaticClass(), NULL, TEXT("MaterialInstance'/Game/AmericasArmy/Textures/T_AA2_Characters/Instructor/Instructor_PANTS_Forest_Mat.Instructor_PANTS_Forest_Mat'"))),
								Cast<UMaterialInstance>(StaticLoadObject(UMaterialInstance::StaticClass(), NULL, TEXT("MaterialInstance'/Game/AmericasArmy/Textures/T_AA2_Characters/Instructor/Instructor_SHIRT_Forest_Drill_Mat.Instructor_SHIRT_Forest_Drill_Mat'"))),
								Cast<UMaterialInstance>(StaticLoadObject(UMaterialInstance::StaticClass(), NULL, TEXT("MaterialInstance'/Game/AmericasArmy/Textures/T_AA2_Characters/Instructor/Instructor_HAND_Inf_Cauc_Mat.Instructor_HAND_Inf_Cauc_Mat'"))),
								Cast<UMaterialInstance>(StaticLoadObject(UMaterialInstance::StaticClass(), NULL, TEXT("MaterialInstance'/Game/AmericasArmy/Textures/T_AA2_Characters/Instructor/Instructor_FACE_Drill_Instructor_Mat.Instructor_FACE_Drill_Instructor_Mat'")))
							};
}