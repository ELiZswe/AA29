// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/BaseWeaponMod/BaseWeaponMod.h"
#include "AA29/AA29.h"
#include "BaseWeaponMod_AuxWeapon.generated.h"

class USkeletalMesh;
class AAGP_Weapon;

UCLASS()
class ABaseWeaponMod_AuxWeapon : public ABaseWeaponMod
{
	GENERATED_BODY()
public:
	ABaseWeaponMod_AuxWeapon();
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		USoundBase* AltReloadSound;							//var Sound AltReloadSound;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		USoundBase* AuxOutdoorSingleFire;					//var Sound AuxOutdoorSingleFire;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		USoundBase* AuxSingleFire;							//var Sound AuxSingleFire;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		FBoneOffset AuxMuzzleFlashOffset;					//var Object.BoneOffset AuxMuzzleFlashOffset;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		TSubclassOf<class AAA2_Emitter> AuxMuzzleFlash;		//var class<Emitter> AuxMuzzleFlash;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		int32 NumAuxRound;									//var int NumAuxRound;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		TSubclassOf<class ABaseAmmoRound> AuxARound;		//var class<BaseAmmoRound> AuxARound;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		int32 AuxAmmoCount;									//var int AuxAmmoCount;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		TSubclassOf<class AAmmunition> AuxAmmo;				//var class<Ammunition> AuxAmmo;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		USkeletalMesh* AuxWeaponMesh;						//var Mesh AuxWeaponMesh;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		USkeletalMesh* NewWeaponMesh;						//var Mesh NewWeaponMesh;

	virtual bool MutuallyExclusive(ABaseWeaponMod* OtherMod) override;
	virtual void ModifyWeapon() override;
	void SetupAuxWeapon();
};
