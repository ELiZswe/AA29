// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/VehicleWeapon/VehicleWeapon.h"
#include "VehicleWeaponFPOverlay.generated.h"

class AVehicleWeapon;
UCLASS()
class AVehicleWeaponFPOverlay : public AVehicleWeapon
{
	GENERATED_BODY()
public:
	AVehicleWeaponFPOverlay();



	UPROPERTY()							FVector						CameraOffset;						//var Object.Vector CameraOffset;
	UPROPERTY()							float						WeaponFOV;							//var float WeaponFOV;
	UPROPERTY()							AVehicleWeapon*				Weapon;								//var VehicleWeapon Weapon;

	void RenderOverlays(UCanvas* C, bool bNoPurposeBool);
	void PostBeginPlay();
	void Destroyed();

};
