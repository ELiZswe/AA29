// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/AI_Primitive/SoldierRole/SoldierRole.h"
#include "SquadLeaderRole.generated.h"

class AAGP_Pawn;
class ASoldierRole;
UCLASS()
class ASquadLeaderRole : public ASoldierRole
{
	GENERATED_BODY()
public:
	ASquadLeaderRole();

	FVector GetDestination(AAGP_Pawn* Leader);
	ASoldierRole* spawnNewRole();
	ASoldierRole* spawnSubordinateRole();
	AAGP_Pawn* getUnitLeader();
	ESoldierRole getRole();
	AActor* GetTeamClass();
};
