// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Info/GameInfo/AGP_GameInfo/FSTS_GameSinglePlayer/FSTS_GameSinglePlayer.h"
#include "FSTS_VT_GameSinglePlayer.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AFSTS_VT_GameSinglePlayer : public AFSTS_GameSinglePlayer
{
	GENERATED_BODY()
public:
	AFSTS_VT_GameSinglePlayer();

	void GetDefaultPlayerClass(AController* C);
};
