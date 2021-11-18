// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/AAGameplay/AAGameplay.h"
#include "EEAnimHelper.generated.h"

class ANPC_EEGuard;

UCLASS()
class AA29_API AEEAnimHelper : public AAAGameplay
{
	GENERATED_BODY()
public:
	AEEAnimHelper();
	UPROPERTY()								ANPC_EEGuard* PlayerAudibility;				//var NPC_EEGuard Host;
	UPROPERTY()								bool bTurning;								//var bool bTurning;
	UPROPERTY()								bool bAgitated;								//var bool bAgitated;
};
