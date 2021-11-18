// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Pawn/AA2_Pawn.h"
#include "Scout.generated.h"

UCLASS()
class AA29_API AScout : public AAA2_Pawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AScout();


	UPROPERTY()							float MaxLandingVelocity;								//var const float MaxLandingVelocity;
	
	void PreBeginPlay();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
