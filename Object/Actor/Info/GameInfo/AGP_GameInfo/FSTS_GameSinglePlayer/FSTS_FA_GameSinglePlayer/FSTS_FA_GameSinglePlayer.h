// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Info/GameInfo/AGP_GameInfo/FSTS_GameSinglePlayer/FSTS_GameSinglePlayer.h"
#include "FSTS_FA_GameSinglePlayer.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AFSTS_FA_GameSinglePlayer : public AFSTS_GameSinglePlayer
{
	GENERATED_BODY()
public:
	AFSTS_FA_GameSinglePlayer();

	void GetDefaultTeamClass();
	void GetDefaultPlayerClass(AController* C);
};
