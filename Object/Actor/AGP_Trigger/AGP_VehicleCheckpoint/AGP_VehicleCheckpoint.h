// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/AGP_Trigger/AGP_Trigger.h"
#include "AGP_VehicleCheckpoint.generated.h"

UCLASS()
class AAGP_VehicleCheckpoint : public AAGP_Trigger
{
	GENERATED_BODY()
public:
	AAGP_VehicleCheckpoint();

	UPROPERTY(EditAnywhere)				int32 checkpoint;		//var() int checkpoint;

	void Touch(AActor* Other);
};
