// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Pawn/AA2_Pawn.h"
#include "SVehicle.generated.h"

//class ASVehicleWheel;

UCLASS()
class AA29_API ASVehicle : public AAA2_Pawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ASVehicle();

	UPROPERTY(EditAnywhere)						AActor* DestroyEffectClass;							//var() class<Actor> DestroyEffectClass;
	UPROPERTY()									FVector FlipAxis;									//var Object.Vector FlipAxis;
	UPROPERTY()									float FlipTimeLeft;									//var float FlipTimeLeft;
	UPROPERTY()									float FlipScale;									//var float FlipScale;
	UPROPERTY(EditAnywhere)						float FlipTime;										//var() float FlipTime;
	UPROPERTY(EditAnywhere)						float FlipTorque;									//var() float FlipTorque;
	UPROPERTY(EditAnywhere)						float VehicleMass;									//var() float VehicleMass;
	UPROPERTY()									bool bVehicleOnGround;								//var const bool bVehicleOnGround;
	//UPROPERTY(EditAnywhere)						TArray<ASVehicleWheel*> Wheels;						//var() array<SVehicleWheel> Wheels;

	void GraphData(FString DataName, float DataValue);
	void VehicleStateReceived();
	void UpdateVehicle(float DeltaTime);
	void PostNetBeginPlay();
	void JumpOffPawn();
	void SVehicleUpdateParams();
	void Flip(FVector HitNormal, float ForceScale);
	void KApplyForce(FVector &Force, FVector &Torque);
	
	void Destroyed();


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
