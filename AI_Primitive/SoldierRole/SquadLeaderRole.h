// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/AI_Primitive/SoldierRole/SoldierRole.h"
#include "SquadLeaderRole.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API ASquadLeaderRole : public ASoldierRole
{
	GENERATED_BODY()
public:
	ASquadLeaderRole();

	void GetDestination(AAGP_Pawn* Leader);
	void spawnNewRole();
	void spawnSubordinateRole();
	void getUnitLeader();
	virtual ESoldierRole getRole() override;
	void GetTeamClass();

};
