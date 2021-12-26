// All the original content belonged to the US Army

#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Character/AGP_Character_NPC/NPC_doctor/NPC_doctor.h"

ANPC_doctor::ANPC_doctor()
{
	NPC_DamageOn			= true;
	bStaticSkinsAndMeshes	= true;
	KillHealth				= 100;
	AnimRate				= 1;
	bCleanUp				= false;
	CustomMesh				= LoadObject<USkeletalMesh>(NULL, TEXT("/Game/AmericasArmy/Animations/A_AA2_CharactersUS/SoldierM_Pilot.SoldierM_Pilot"), NULL, LOAD_None, NULL);
	LoadMesh();
}
