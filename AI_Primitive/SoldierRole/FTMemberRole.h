// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/AI_Primitive/SoldierRole/SoldierRole.h"
#include "FTMemberRole.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AFTMemberRole : public ASoldierRole
{
	GENERATED_BODY()
public:
	AFTMemberRole();

	void GetDestination(AAGP_Pawn* Leader);
	void spawnNewRole();
	int32 getUnitSize();
	void getUnitLeader();
	virtual ESoldierRole getRole() override;
	void GetTeamClass();

};
