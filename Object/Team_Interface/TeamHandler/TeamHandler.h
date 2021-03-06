// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Team_Interface/Team_Interface.h"
#include "TeamHandler.generated.h"

class AMentalModel;

class AAGP_Pawn;
UCLASS()
class UTeamHandler : public UTeam_Interface
{
	GENERATED_BODY()
public:
	UTeamHandler();

	UPROPERTY()			AMentalModel*	_teamMentalModel;		//var AGP.MentalModel _teamMentalModel;
	UPROPERTY()			bool			bTeamReady;				//var bool bTeamReady;

	AMentalModel* getMentalModel();
	int32 getTeamSize();
	void printTeam();
	bool replaceSubordinate(AAGP_Pawn* old_sub, AAGP_Pawn* new_sub);
	void addPawn(AAGP_Pawn* Add);
	bool replaceLeader(AAGP_Pawn* Leader, AAGP_Pawn* Replace);
	void Init();
	void initLeader(AAGP_Pawn* Leader);
	float Range(float val1, float val2);
};
