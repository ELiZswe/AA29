// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/BaseWeaponMod/BaseWeaponMod.h"
#include "AA29/AA29.h"
#include "BaseWeaponMod_AuxWeapon.generated.h"

class USkeletalMesh;
class AAGP_Weapon;

class ABaseWeaponMod;
UCLASS()
class ABaseWeaponMod_AuxWeapon : public ABaseWeaponMod
{
	GENERATED_BODY()
public:
	ABaseWeaponMod_AuxWeapon();
	
	UPROPERTY(EditAnywhere)		USoundBase* AltReloadSound;							//var Sound AltReloadSound;
	UPROPERTY(EditAnywhere)		USoundBase* AuxOutdoorSingleFire;					//var Sound AuxOutdoorSingleFire;
	UPROPERTY(EditAnywhere)		USoundBase* AuxSingleFire;							//var Sound AuxSingleFire;
	UPROPERTY(EditAnywhere)		FBoneOffset AuxMuzzleFlashOffset;					//var Object.BoneOffset AuxMuzzleFlashOffset;
	UPROPERTY(EditAnywhere)		TSubclassOf<class AAA2_Emitter> AuxMuzzleFlash;		//var class<Emitter> AuxMuzzleFlash;
	UPROPERTY(EditAnywhere)		int32 NumAuxRound;									//var int NumAuxRound;
	UPROPERTY(EditAnywhere)		TSubclassOf<class ABaseAmmoRound> AuxARound;		//var class<BaseAmmoRound> AuxARound;
	UPROPERTY(EditAnywhere)		int32 AuxAmmoCount;									//var int AuxAmmoCount;
	UPROPERTY(EditAnywhere)		TSubclassOf<class AAmmunition> AuxAmmo;				//var class<Ammunition> AuxAmmo;
	UPROPERTY(EditAnywhere)		USkeletalMesh* AuxWeaponMesh;						//var Mesh AuxWeaponMesh;
	UPROPERTY(EditAnywhere)		USkeletalMesh* NewWeaponMesh;						//var Mesh NewWeaponMesh;

	virtual bool MutuallyExclusive(ABaseWeaponMod* OtherMod) override;
	virtual void ModifyWeapon() override;
	void SetupAuxWeapon();
};
