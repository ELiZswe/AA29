// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Team_Interface/Team_Interface.h"
#include "TeamHandler.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UTeamHandler : public UTeam_Interface
{
	GENERATED_BODY()
public:
	UTeamHandler();


	//UPROPERTY()								AMentalModel _teamMentalModel;									//var AGP.MentalModel _teamMentalModel;
	UPROPERTY()									bool bTeamReady;												//var bool bTeamReady;



	virtual void getMentalModel();
	virtual void getTeamSize();
	virtual void printTeam() override;
	virtual void replaceSubordinate(AAGP_Pawn* old_sub, AAGP_Pawn* new_sub) override;
	virtual void addPawn(AAGP_Pawn* Add);
	virtual void replaceLeader(AAGP_Pawn* Leader, AAGP_Pawn* Replace);
	virtual void Init();
	virtual void initLeader(AAGP_Pawn* Leader);
	virtual void Range(float val1, float val2);




};
