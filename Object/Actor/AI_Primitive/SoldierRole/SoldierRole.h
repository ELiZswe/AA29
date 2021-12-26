// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/MyEnums.h"
#include "AA29/Object/Actor/AI_Primitive/AI_Primitive.h"
#include "SoldierRole.generated.h"

class AAGP_Pawn;
class AMentalModel;

UCLASS()
class ASoldierRole : public AAI_Primitive
{
	GENERATED_BODY()
public:
	ASoldierRole();
	
	UPROPERTY()		FString			TeamClassName;		//var string TeamClassName;
	UPROPERTY()		ESoldierRole	my_role;			//var ESoldierRole my_role;
	UPROPERTY()		AAGP_Pawn*		my_AGP_Pawn;		//var AGP_Pawn my_AGP_Pawn;

	FVector GetDestination(AAGP_Pawn* Leader);
	ASoldierRole* spawnNewRole();
	ASoldierRole* spawnSubordinateRole();
	int32 getUnitSize();
	AMentalModel* getMentalModel();
	AAGP_Pawn* getUnitLeader();
	ESoldierRole getRole();
	bool squadBasedRole();
	AActor* GetTeamClass();
};
