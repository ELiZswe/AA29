// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/MyEnums.h"
#include "AA29/Object/Actor/AI_Primitive/AI_Primitive.h"
//#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Pawn.h"
#include "SoldierRole.generated.h"

//~~~~~ Forward Declarations~~~~~
class AAGP_Pawn;

UCLASS()
class AA29_API ASoldierRole : public AAI_Primitive
{
	GENERATED_BODY()
public:
	ASoldierRole();

	
	UPROPERTY()		FString TeamClassName;					//var string TeamClassName;
	UPROPERTY()		ESoldierRole my_role;					//var ESoldierRole my_role;
	UPROPERTY()		AAGP_Pawn* my_AGP_Pawn;					//var AGP_Pawn my_AGP_Pawn;

	void GetDestination(AAGP_Pawn* Leader);
	void spawnNewRole();
	void spawnSubordinateRole();
	void getUnitSize();
	void getMentalModel();
	void getUnitLeader();
	virtual ESoldierRole getRole();
	virtual bool squadBasedRole();
	void GetTeamClass();


};
