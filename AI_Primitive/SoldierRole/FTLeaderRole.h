// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/AI_Primitive/SoldierRole/SoldierRole.h"
#include "FTLeaderRole.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AFTLeaderRole : public ASoldierRole
{
	GENERATED_BODY()
public:
		AFTLeaderRole();

		void GetDestination(AAGP_Pawn* Leader);
		void spawnNewRole();
		void spawnSubordinateRole();
		void getUnitSize();
		void getUnitLeader();
		virtual ESoldierRole getRole() override;
		void GetTeamClass();

};
