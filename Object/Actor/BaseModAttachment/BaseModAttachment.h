// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BaseModAttachment.generated.h"

class USkeletalMesh;
class ABaseWeaponMod;
class ABaseMuzzleFlashEmitter;

UCLASS()
class AA29_API ABaseModAttachment : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABaseModAttachment();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY()			bool						bSpinnyActive;				//var bool bSpinnyActive;
	UPROPERTY()			USkeletalMesh*				SpinnyMesh;					//var StaticMesh SpinnyMesh;
	UPROPERTY()			USkeletalMesh*				WeaponMesh;					//var Mesh WeaponMesh;
	UPROPERTY()			USkeletalMesh*				SpinnyWeaponMesh;			//var Mesh SpinnyWeaponMesh;
	UPROPERTY()			ABaseMuzzleFlashEmitter*	SuppressorMuzzleFlash;		//var AGP_Effects.BaseMuzzleFlashEmitter SuppressorMuzzleFlash;
	UPROPERTY()			ABaseMuzzleFlashEmitter*	cSuppressorMuzzleFlash;		//var class<AGP_Effects.BaseMuzzleFlashEmitter> cSuppressorMuzzleFlash;
	UPROPERTY()			int32						ModSlot;					//var int ModSlot;
	UPROPERTY()			ABaseWeaponMod*				WeaponMod;					//var class<BaseWeaponMod> WeaponMod;
	UPROPERTY()			ABaseModAttachment*			NextModAttachment;			//var BaseModAttachment NextModAttachment;

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
