// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AA29/AA29.h"
#include "AA29/Pickup/Pickup.h"
#include "GrenadeHelper.generated.h"


UCLASS()
class AA29_API AGrenadeHelper : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGrenadeHelper();

	UPROPERTY()				bool								bHasNotDamagedDeco;		//var bool bHasNotDamagedDeco;
	UPROPERTY()				TArray<FTestOffset>					ActorOffsets;			//var array<TestOffset> ActorOffsets;
	UPROPERTY()				TArray<FName>						PawnBones;				//var array<name> PawnBones;



	void GrenadeEffects(AActor* Grenade, FVector ExplosionLocation, float fDamageRadius, float fKillRadius, float fEffectDuration, float fMaxAudIntensity, float fMaxVisIntensity);
	void GrenHurtRadius(AActor* Grenade, FVector ExplosionLocation, float DamageRadius, float KillRadius, float DamageAmount, UDamageType* ExplosionDamageType, UDamageType* FragDamageType, float Momentum, TArray<AActor> DamageClassList, AController* KillerController);
	void CheckMinDistance(FVector v1, FVector v2, float& MinDistance);
	bool ExposureTrace(AActor* Victim, AActor* Grenade, FVector Start, FVector End);
	float GetExposureTrace(AActor* Victim, AActor* Grenade, FVector ExplosionLoc, float& MinDistance);
	float GetExposureBBoxTrace(AActor* Victim, AActor* Grenade, FVector ExplosionLoc, float& MinDistance);
	FVector GetOffset(FTestOffset Off, FVector Location, FVector H, FVector V);
	float GetExposureCylinderTrace(AActor* Victim, AActor* Grenade, FVector ExplosionLoc, float& MinDistance);
	float GetExposureBoneTrace(APawn* Victim, AActor* Grenade, FVector ExplosionLoc);
	void TurnPickupsOn();
	void TurnPickupsOff();


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
