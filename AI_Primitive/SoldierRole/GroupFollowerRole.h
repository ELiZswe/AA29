// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/AI_Primitive/SoldierRole/SoldierRole.h"
#include "GroupFollowerRole.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AGroupFollowerRole : public ASoldierRole
{
	GENERATED_BODY()
public:
	AGroupFollowerRole();

	void spawnNewRole();
	int32 getUnitSize();
	void getUnitLeader();
	virtual ESoldierRole getRole() override;
	virtual bool squadBasedRole() override;


};
