// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Pawn/Vehicle/Vehicle.h"
#include "KVehicle.generated.h"

UCLASS()
class AA29_API AKVehicle : public AVehicle
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AKVehicle();

	UPROPERTY()								bool bHistoryWarmup;								//var bool bHistoryWarmup;
	UPROPERTY()								int32 NextHistorySlot;								//var int NextHistorySlot;
	UPROPERTY()								FVector CameraHistory;								//var Object.Vector CameraHistory;
	UPROPERTY()								bool bVehicleIsAltFiring;							//var bool bVehicleIsAltFiring;
	UPROPERTY()								bool bVehicleIsFiring;								//var bool bVehicleIsFiring;
	UPROPERTY(EditAnywhere)					bool bAutoDrive;									//var() bool bAutoDrive;
	UPROPERTY(EditAnywhere)					AActor* DestroyEffectClass;							//var() class<Actor> DestroyEffectClass;

	void GraphData(FString DataName, float DataValue);
	//void TakeDamage(int32 Damage, APawn instigatedBy, FVector HitLocation, FVector Momentum, UaDamageType* DamageType, FBoneInfo Bone, AController* KillerController, AActor* ResponsibleActor, UMaterialInstance* HitMaterial);
	void VehicleStateReceived();
	void KVehicleUpdateParams();
	bool TryToDrive(APawn* p);
	void ClientKDriverEnter(APlayerController* PC);
	void KDriverEnter(APawn* p);
	void ClientKDriverLeave(APlayerController* PC);
	bool KDriverLeave(bool bForceLeave);
	bool SpecialCalcView(AActor*& ViewActor, FVector& CameraLocation, FRotator& CameraRotation);
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
