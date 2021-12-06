// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Volume/PhysicsVolume/AA2_PhysicsVolume.h"
#include "PressureVolume.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API APressureVolume : public AAA2_PhysicsVolume
{
	GENERATED_BODY()
public:
	APressureVolume();

	UPROPERTY()						bool bScreamed;						//var bool bScreamed;
	UPROPERTY()						bool bTriggered;		        	//var bool bTriggered;
	UPROPERTY()						float TimePassed;		        	//var float TimePassed;
	UPROPERTY()						float DieDrawScale;		        	//var float DieDrawScale;
	UPROPERTY()						float DieFOV;						//var float DieFOV;
	UPROPERTY(EditAnywhere)			FVector EndFlashFog;		       	//var() FVector EndFlashFog;
	UPROPERTY(EditAnywhere)			float EndFlashScale;		       	//var() float EndFlashScale;
	UPROPERTY(EditAnywhere)			FVector StartFlashFog;		       	//var() FVector StartFlashFog;
	UPROPERTY(EditAnywhere)			float StartFlashScale;		       	//var() float StartFlashScale;
	UPROPERTY(EditAnywhere)			float KillTime;						//var() float KillTime;

	void Trigger(AActor* Other, APawn* EventInstigator);
	void Tick(float DeltaTime);
	void MakeNormal(APawn* p);
	void PawnLeavingVolume(APawn* Other);
};
