// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/SVehicleFactory/SVehicleFactory.h"
#include "KVehicleFactory.generated.h"

class AKVehicle;

UCLASS()
class AKVehicleFactory : public ASVehicleFactory
{
	GENERATED_BODY()
public:
	AKVehicleFactory();

	UPROPERTY(EditAnywhere)			AKVehicle*		KVehicleClass;		//var() class<KVehicle> KVehicleClass;

	void Trigger(AActor* Other, APawn* EventInstigator);
};
