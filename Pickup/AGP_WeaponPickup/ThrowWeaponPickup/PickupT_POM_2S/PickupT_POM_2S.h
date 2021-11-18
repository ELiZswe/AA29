// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Pickup/AGP_WeaponPickup/ThrowWeaponPickup/ThrowWeaponPickup.h"
#include "PickupT_POM_2S.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API APickupT_POM_2S : public AThrowWeaponPickup
{
	GENERATED_BODY()
public:
	APickupT_POM_2S();

	
	UPROPERTY()		float  TriggerCheckRate;				//var float TriggerCheckRate;
	UPROPERTY()		float  PopTime;							//var float PopTime;
	UPROPERTY()		float  PopupSoundRadius;				//var float PopupSoundRadius;
	UPROPERTY()		float  ArmedSoundRadius;				//var float ArmedSoundRadius;
	UPROPERTY()		float  PopupVelocity;					//var float PopupVelocity;
	UPROPERTY()		float  TriggerRadius;					//var float TriggerRadius;
	UPROPERTY()		FVector  SavedLandedVector;				//var FVector SavedLandedVector;
	UPROPERTY()		USoundBase*  PopUpSound;				//var Sound PopUpSound;
	UPROPERTY()		USoundBase*  ArmedSound;				//var Sound ArmedSound;
	UPROPERTY()		bool  bTriggerProcessed;				//var bool bTriggerProcessed;
	UPROPERTY()		bool  bArmedEffectsProcessed;			//var bool bArmedEffectsProcessed;
	UPROPERTY()		bool  bTriggered;						//var bool bTriggered;
	UPROPERTY()		bool  bArmed;							//var bool bArmed;

	void PostBeginPlay();
	void Tick(float DeltaTime);
	void ClientPopUp();
	void ClientArmedEffects();
	void Landed(FVector HitNormal);
	void ShouldTrigger(AActor* Other);
	//void TakeDamage (int Damage, Pawn instigatedBy, FVector HitLocation, FVector Momentum, class<DamageType>  DamageType, optional Actor.BoneInfo Bone, optional Controller KillerController, optional Actor ResponsibleActor, optional Material HitMaterial);
	void Timer();
	void PopUp();

};
