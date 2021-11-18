// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/InventoryAttachment/WeaponAttachment/BaseWeaponAttachment/BaseWeaponAttachment.h"
#include "AA29/Inventory/Weapon/AGP_Weapon/FixedWeapon/FixedWeapon.h"
#include "FixedWeaponAttachment.generated.h"


class AAGP_Pawn;

UCLASS()
class AA29_API AFixedWeaponAttachment : public ABaseWeaponAttachment
{
	GENERATED_BODY()
public:
	AFixedWeaponAttachment();

	UPROPERTY()															bool bInterpolateRotation;							//var bool bInterpolateRotation;
	UPROPERTY()															bool bMeshVerified;									//var bool bMeshVerified;
	UPROPERTY()															bool bDisabled;										//var bool bDisabled;
	UPROPERTY()															float InterpolatedYaw;								//var float InterpolatedYaw;
	UPROPERTY()															float InterpolatedPitch;							//var float InterpolatedPitch;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)							float fRotationMultiplier;							//var() float fRotationMultiplier;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "EnemyMesh")	uint8 FriendlyTeam;									//var(EnemyMesh) byte FriendlyTeam;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "EnemyMesh")	bool bUseEnemyMesh;									//var(EnemyMesh) bool bUseEnemyMesh;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "EnemyMesh")	FName EnemyTurretTag;								//var(EnemyMesh) name EnemyTurretTag;
	UPROPERTY()															bool bTimerDoVerify;								//var bool bTimerDoVerify;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)							uint8 UseTeam;										//var() byte UseTeam;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)							TSubclassOf<class UaDamageType> KillPawnDamageType;	//var() class<DamageType> KillPawnDamageType;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)							bool bDisableWhenTriggered;							//var() bool bDisableWhenTriggered;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)							bool bKillPawnWhenTriggered;						//var() bool bKillPawnWhenTriggered;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)							bool bHidePawnWhenUsed;								//var() bool bHidePawnWhenUsed;
	UPROPERTY()															AActor* AssociatedActor;							//var Actor AssociatedActor;
	UPROPERTY()															AFixedWeaponAttachment* EnemyTurret;				//var FixedWeaponAttachment EnemyTurret;
	UPROPERTY()															USoundBase* sRotateStop;							//var Sound sRotateStop;
	UPROPERTY()															USoundBase* sRotateLoop;							//var Sound sRotateLoop;
	UPROPERTY()															USoundBase* sRotateStart;							//var Sound sRotateStart;
	UPROPERTY()															USoundBase* next_sound;								//var Sound next_sound;
	UPROPERTY()															float last_move_time;								//var float last_move_time;
	UPROPERTY()															bool bEndRotateSound;								//var bool bEndRotateSound;
	UPROPERTY()															FRotator TurretRotation;							//var Object.Rotator TurretRotation;
	UPROPERTY()															AFixedWeapon* FWeapon;								//var FixedWeapon FWeapon;
	UPROPERTY()															TSubclassOf<class AFixedWeapon> FixedWeaponClass;	//var class<FixedWeapon> FixedWeaponClass;


	void PostBeginPlay();
	void MatchStarting();
	void LinkTurrets();
	AFixedWeaponAttachment* GetEnemyTurret();
	void ManTurret(APawn* p);
	void AbandonWeapon();
	void BeginPlay();
	void AnimEnd(int32 Channel);
	void ThirdPersonEffects();
	void UpdateTurretRotation(FRotator NewRotation);
	void ServerSetTurretValues(int32 new_pitch, int32 new_yaw);
	FRotator GetTurretRotation();
	void SetTurretRotation(FRotator NewRotation);
	void moveTurret();
	void Timer();
	void GetSource();
	void GetAngleDelta(int curr, int Old, float DeltaTime);
	void InterpolateAngle(float Interp, int32 Target, float Delta, int32 Mid);
	void InterpolateRotation(float DeltaTime);
	void SetPitchYaw(float NewPitch, float NewYaw);
	void ClientsVerifyMesh(float fAgain);
	void Tick(float DeltaTime);
	void PostNetBeginPlay();
	void VerifyMesh();
	void Trigger(AActor* Other, APawn* EventInstigator);
	float GetRotationMultiplier();
	void CanManTurret(AAGP_Pawn* p, FString Reason);


};
