// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/BaseWeaponMod/BaseWeaponMod.h"
#include "WeaponMod_Anpeq5_Laser.generated.h"

class USkeletalMesh;

UCLASS()
class AWeaponMod_Anpeq5_Laser : public ABaseWeaponMod
{
	GENERATED_BODY()
public:
	AWeaponMod_Anpeq5_Laser();

	UPROPERTY(EditAnywhere)			USkeletalMesh* NonLaserMesh;				//var Mesh NonLaserMesh;
	UPROPERTY(EditAnywhere)			USkeletalMesh* WithLaserMesh;				//var Mesh WithLaserMesh;
	UPROPERTY(EditAnywhere)			bool bLaserOn;								//var bool bLaserOn;
	//UPROPERTY(EditAnywhere)		ALaserProjector* laser;						//var AGP.LaserProjector laser;


	virtual void Destroyed() override;
	virtual void ModifyWeapon() override;
	virtual void NotifyWeaponZoom(bool bNewZoom) override;
	virtual void Toggle() override;
	void ServerSetLaser(bool new_setting);

};
