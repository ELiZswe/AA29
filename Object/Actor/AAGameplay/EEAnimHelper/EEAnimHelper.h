// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/AAGameplay/AAGameplay.h"
#include "EEAnimHelper.generated.h"

class ANPC_EEGuard;

UCLASS()
class AA29_API AEEAnimHelper : public AAAGameplay
{
	GENERATED_BODY()
public:
	AEEAnimHelper();
	UPROPERTY()								ANPC_EEGuard* Host;				//var NPC_EEGuard Host;
	UPROPERTY()								bool bTurning;					//var bool bTurning;
	UPROPERTY()								bool bAgitated;					//var bool bAgitated;

	void SetAnimHost(ANPC_EEGuard* AnimHost);
	FAnimInfo2 GetAnimInfo(int32 Channel);
	void BeginPlay();
	bool IsTurning();
	void PlayTurning();
	void BeginAnims();
};
