// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/AI_Primitive/SoldierRole/SoldierRole.h"
#include "GroupFollowerRole.generated.h"

class AAGP_Pawn;
class ASoldierRole;
UCLASS()
class AGroupFollowerRole : public ASoldierRole
{
	GENERATED_BODY()
public:
	AGroupFollowerRole();

	ASoldierRole* spawnNewRole();
	int32 getUnitSize();
	AAGP_Pawn* getUnitLeader();
	ESoldierRole getRole();
	bool squadBasedRole();
};
