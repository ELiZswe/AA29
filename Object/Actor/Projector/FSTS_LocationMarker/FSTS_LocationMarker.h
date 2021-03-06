// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Projector/Projector.h"
#include "FSTS_LocationMarker.generated.h"

UCLASS()
class AFSTS_LocationMarker : public AProjector
{
	GENERATED_BODY()
public:
	AFSTS_LocationMarker();

	UPROPERTY()			bool		bMarkerActive;		//var bool bMarkerActive;
	UPROPERTY()			FVector		MarkOffset;			//var Vector MarkOffset;

	void PostBeginPlay();
	bool IsMarkerActive();
	void ActivateMarker();
	void DeactivateMarker();
	bool SetMarkingLocation(FVector NewLocation, FVector AdditionalMarkOffset);
};
