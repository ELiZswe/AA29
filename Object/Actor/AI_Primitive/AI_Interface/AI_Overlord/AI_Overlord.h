// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/AI_Primitive/AI_Interface/AI_Interface.h"
#include "AA29/MyEnums.h"
#include "AI_Overlord.generated.h"

class UTeamHandler;

UCLASS()
class AAI_Overlord : public AAI_Interface
{
	GENERATED_BODY()
public:
	AAI_Overlord();

	UPROPERTY()			UTeamHandler* BottomTeam;				//var TeamHandler BottomTeam;
	UPROPERTY()			UTeamHandler* TopTeam;					//var TeamHandler TopTeam;

	UTeamHandler* GetTeam(ETeam Team);
	UTeamHandler* createTeam(ETeam Team);
	UTeamHandler* getOrCreateTeam(ETeam Team);
	void Init();
};
