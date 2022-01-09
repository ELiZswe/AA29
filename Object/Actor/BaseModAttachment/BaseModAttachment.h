// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AA29/MyEnums.h"
#include "BaseModAttachment.generated.h"

class USkeletalMesh;
class ABaseWeaponMod;
class ABaseMuzzleFlashEmitter;

UCLASS()
class ABaseModAttachment : public AActor
{
	GENERATED_BODY()
	
public:	
	
	ABaseModAttachment();

protected:
	
	virtual void BeginPlay() override;

public:	
	
	virtual void Tick(float DeltaTime) override;

	UPROPERTY()			bool						bSpinnyActive;				//var bool bSpinnyActive;
	UPROPERTY()			UStaticMesh*				SpinnyMesh;					//var StaticMesh SpinnyMesh;
	UPROPERTY()			USkeletalMesh*				WeaponMesh;					//var Mesh WeaponMesh;
	UPROPERTY()			USkeletalMesh*				SpinnyWeaponMesh;			//var Mesh SpinnyWeaponMesh;
	UPROPERTY()			ABaseMuzzleFlashEmitter*	SuppressorMuzzleFlash;		//var AGP_Effects.BaseMuzzleFlashEmitter SuppressorMuzzleFlash;
	UPROPERTY()			ABaseMuzzleFlashEmitter*	cSuppressorMuzzleFlash;		//var class<AGP_Effects.BaseMuzzleFlashEmitter> cSuppressorMuzzleFlash;
	UPROPERTY()			int32						ModSlot;					//var int ModSlot;
	UPROPERTY()			ABaseWeaponMod*				WeaponMod;					//var class<BaseWeaponMod> WeaponMod;
	UPROPERTY()			ABaseModAttachment*			NextModAttachment;			//var BaseModAttachment NextModAttachment;

	//My Custom
	UPROPERTY()			USkeletalMesh*				Mesh;
	UPROPERTY()			EDrawType					DrawType;

	void PostNetBeginPlay();
	void GetWeaponMod();
	FName GetAttachBone(int32 Slot);
	void NotifyAttachmentAnimation(uint8 AnimState);
	void Destroyed();
	ABaseModAttachment* GetEnemyClass();
	void NotifyAttachMod();
	void NotifyDetachMod();
	void SetFriendlyMesh(bool bFriendly);
	void SetDefaultMesh();
	bool IsSuppressor();
	bool IsSuppressed();
	ABaseMuzzleFlashEmitter* GetSuppressorMuzzleFlash();
};
