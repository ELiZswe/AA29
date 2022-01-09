// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BassLaserAttachment.generated.h"

UCLASS()
class ABassLaserAttachment : public AActor
{
	GENERATED_BODY()
	
public:	
	
	ABassLaserAttachment();

	FVector GetTipLocation();

protected:
	
	virtual void BeginPlay() override;

public:	
	
	virtual void Tick(float DeltaTime) override;

};
