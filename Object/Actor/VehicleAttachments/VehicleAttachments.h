// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "VehicleAttachments.generated.h"

UCLASS()
class AVehicleAttachments : public AActor
{
	GENERATED_BODY()
	
public:	
	
	AVehicleAttachments();

protected:
	
	virtual void BeginPlay() override;

public:	
	
	virtual void Tick(float DeltaTime) override;

};
