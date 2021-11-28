// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Info/GameInfo/AGP_GameInfo/AGP_GameInfo.h"
#include "FSTS_GameSinglePlayer.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AFSTS_GameSinglePlayer : public AAGP_GameInfo
{
	GENERATED_BODY()
public:
	AFSTS_GameSinglePlayer();


	void GetDefaultTeamClass();
	void GetDefaultPlayerClass(AController* C);

};
