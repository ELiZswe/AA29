// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Pickup/AGP_WeaponPickup/ThrowWeaponPickup/ThrowWeaponPickup.h"
#include "PickupT_DoorBreacher_Demo.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API APickupT_DoorBreacher_Demo : public AThrowWeaponPickup
{
	GENERATED_BODY()
public:
		APickupT_DoorBreacher_Demo();

		UPROPERTY()		AEmitter* DoorBreachedEmitter;							//var class<> DoorBreachedEmitter;

		void SetDoorBreacherEmitter(AEmitter* EM);
		void DoBreacherEffects();
		void NotifyDoorBreacherExploded();
		void FindOtherDoorBreachers();
		void ProcessBlewUp();

};
