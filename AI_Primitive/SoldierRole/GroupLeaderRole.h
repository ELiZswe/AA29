// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/AI_Primitive/SoldierRole/SoldierRole.h"
#include "GroupLeaderRole.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AGroupLeaderRole : public ASoldierRole
{
	GENERATED_BODY()
public:
	AGroupLeaderRole();

	void spawnNewRole();
	void spawnSubordinateRole();
	void getUnitSize();
	void getUnitLeader();
	virtual ESoldierRole getRole() override;
	virtual bool squadBasedRole() override;
};
