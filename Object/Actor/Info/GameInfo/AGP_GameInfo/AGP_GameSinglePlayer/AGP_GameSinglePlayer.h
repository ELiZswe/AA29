// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Info/GameInfo/AGP_GameInfo/AGP_GameInfo.h"
#include "AGP_GameSinglePlayer.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AAGP_GameSinglePlayer : public AAGP_GameInfo
{
	GENERATED_BODY()
public:
	AAGP_GameSinglePlayer();


	UPROPERTY()					bool bEntryLevelinitialized;				//var bool bEntryLevelinitialized;

	void PreBeginPlay();
	void PostBeginPlay();
	void StartMatch();
	void Timer();
	void SetupAI();
	void GetDefaultTeamClass();

};
