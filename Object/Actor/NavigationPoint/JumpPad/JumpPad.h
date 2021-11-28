// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/NavigationPoint/NavigationPoint.h"
#include "JumpPad.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AJumpPad : public ANavigationPoint
{
	GENERATED_BODY()
public:
	AJumpPad();

	UPROPERTY(EditAnywhere)										USoundBase* JumpSound;								//var() Sound JumpSound;
	UPROPERTY(EditAnywhere)										float JumpZModifier;								//var() float JumpZModifier;
	UPROPERTY()													AActor* JumpTarget;									//var Actor JumpTarget;
	UPROPERTY()													FVector BACKUP_JumpVelocity;						//var Object.Vector BACKUP_JumpVelocity;
	UPROPERTY()													FVector JumpVelocity;								//var Object.Vector JumpVelocity;
};
