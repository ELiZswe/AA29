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
	// Sets default values for this actor's properties
	AFSTS_FA_MedicalPickups();

	void DisablePickup();
	void ActivatePickup();
	void Reset();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
