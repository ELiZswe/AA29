// All the original content belonged to the US Army

#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Character/AGP_Character_NPC/NPC_soldier/NPC_ISoldier/NPC_ISoldierNCO/NPC_ISoldierNCO.h"

ANPC_ISoldierNCO::ANPC_ISoldierNCO()
{
	CustomMesh = LoadObject<USkeletalMesh>(NULL, TEXT("/Game/AmericasArmy/Animations/A_AA2_CharactersOpfor/EnemyCommando.EnemyCommando"), NULL, LOAD_None, NULL);
	LoadMesh();
}
