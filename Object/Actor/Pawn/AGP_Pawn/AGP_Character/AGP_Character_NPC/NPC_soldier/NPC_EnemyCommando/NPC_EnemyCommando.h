// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Character/AGP_Character_NPC/NPC_soldier/NPC_soldier.h"
#include "NPC_EnemyCommando.generated.h"

UCLASS()
class ANPC_EnemyCommando : public ANPC_soldier
{
	GENERATED_BODY()
public:
	ANPC_EnemyCommando();

	void BeginPlay();
	void LoadSkinsAndMeshes();
	void SetSkinsAndMeshes();
	void AnimateWalking();
	bool IsFriend(APawn* Other);
};
