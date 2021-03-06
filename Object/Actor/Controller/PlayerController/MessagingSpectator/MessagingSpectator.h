// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MessagingSpectator.generated.h"

UCLASS()
class AMessagingSpectator : public APlayerController
{
	GENERATED_BODY()
public:
	AMessagingSpectator();
	
	void PostBeginPlay();
	void InitPlayerReplicationInfo();
};
