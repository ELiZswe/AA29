// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/NavigationPoint/SmallNavigationPoint/SmallNavigationPoint.h"
#include "AGPVehicleStart.generated.h"

class AVehicle;

UCLASS()
class AAGPVehicleStart : public ASmallNavigationPoint
{
	GENERATED_BODY()
public:
	AAGPVehicleStart();

	UPROPERTY()											bool		bEnabled;						//var bool bEnabled;
	UPROPERTY(EditAnywhere)								int32		VehicleNumber;					//var() int32 VehicleNumber;
	UPROPERTY(EditAnywhere, Category = "VehicleClass")	AVehicle*	VehicleSpawnClass;				//var(VehicleClass) class<Vehicle> VehicleSpawnClass;

	void Reset();
	void CreateVehicle();
};
