// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Projector/Projector.h"
#include "BaseContactProjector.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API ABaseContactProjector : public AProjector
{
	GENERATED_BODY()
public:
	ABaseContactProjector();

	UPROPERTY(EditAnywhere)		bool		bRandomRoll;						//var() bool bRandomRoll;
	UPROPERTY(EditAnywhere)		bool		bRandomScale;						//var() bool bRandomScale;
private:
	UPROPERTY()					bool		bBodyPanelProjector;				//var bool bBodyPanelProjector;
	UPROPERTY()					FVector		OwnerLoc;							//var Vector OwnerLoc;
	UPROPERTY()					FRotator	OwnerRot;							//var Rotator OwnerRot;

public:
	/*
	void PostBeginPlay();
	void UpdateProjector();
	void Tick(float DeltaTime);
	int32 GetYoungestUID();
	void NotifyRenderInfoExpired();
	void Reset();
	*/
};
