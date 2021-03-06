// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/AI_Primitive/SoldierRole/SoldierRole.h"
#include "FTMemberRole.generated.h"

class AAGP_Pawn;
class ASoldierRole;
UCLASS()
class AFTMemberRole : public ASoldierRole
{
	GENERATED_BODY()
public:
	AFTMemberRole();

	FVector GetDestination(AAGP_Pawn* Leader);
	ASoldierRole* spawnNewRole();
	int32 getUnitSize();
	AAGP_Pawn* getUnitLeader();
	ESoldierRole getRole();
	AActor* GetTeamClass();
};
