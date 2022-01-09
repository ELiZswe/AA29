// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FSTS_FA_MedicalPickups.generated.h"

UCLASS()
class AFSTS_FA_MedicalPickups : public AActor
{
	GENERATED_BODY()
public:	
	
	AFSTS_FA_MedicalPickups();

	void DisablePickup();
	void ActivatePickup();
	void Reset();

protected:
	
	virtual void BeginPlay() override;

public:	
	
	virtual void Tick(float DeltaTime) override;

};
