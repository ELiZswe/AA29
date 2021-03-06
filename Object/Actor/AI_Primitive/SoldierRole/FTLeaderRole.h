// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/AI_Primitive/SoldierRole/SoldierRole.h"
#include "FTLeaderRole.generated.h"

class AAGP_Pawn;
class ASoldierRole;
UCLASS()
class AFTLeaderRole : public ASoldierRole
{
	GENERATED_BODY()
public:
	AFTLeaderRole();

	FVector GetDestination(AAGP_Pawn* Leader);
	ASoldierRole* spawnNewRole();
	ASoldierRole* spawnSubordinateRole();
	int32 getUnitSize();
	AAGP_Pawn* getUnitLeader();
	ESoldierRole getRole();
	AActor* GetTeamClass();
};
