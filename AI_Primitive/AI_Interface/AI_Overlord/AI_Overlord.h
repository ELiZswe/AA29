// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/AI_Primitive/AI_Interface/AI_Interface.h"
#include "AA29/MyStructs.h"
#include "AI_Overlord.generated.h"

/**
 * 
 */
//class ATeamHandler;

UCLASS()
class AA29_API AAI_Overlord : public AAI_Interface
{
	GENERATED_BODY()
public:
	AAI_Overlord();


	//UPROPERTY()																			ATeamHandler* BottomTeam;						//var TeamHandler BottomTeam;
	//UPROPERTY()																			ATeamHandler* TopTeam;						//var TeamHandler TopTeam;


	void GetTeam(ETeam Team);
	void createTeam(ETeam Team);
	void getOrCreateTeam(ETeam Team);
	void Init();

};
