// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Pawn/Vehicle/Vehicle.h"
#include "VehiclePosition.generated.h"

class AAGP_Vehicle;

/**
 * 
 */
UCLASS(Config = Game)
class AA29_API AVehiclePosition : public AVehicle
{
	GENERATED_BODY()
public:
	AVehiclePosition();

	//const FilterFrames = 5;


	UPROPERTY()						FRotator					OldVehicleBaseRotation;					//var Object.Rotator OldVehicleBaseRotation;
	UPROPERTY()						FRotator					OldCameraRotation;						//var Object.Rotator OldCameraRotation;
	UPROPERTY()						int32						PositionsIndex;							//var int PositionsIndex;
	UPROPERTY()						bool						bClientInitComplete;					//var bool bClientInitComplete;
	UPROPERTY()						UMaterialInstance*			CrosshairTexture;						//var config Texture CrosshairTexture;
	UPROPERTY(config)				float						CrosshairY;								//var config float CrosshairY;
	UPROPERTY(config)				float						CrosshairX;								//var config float CrosshairX;
	UPROPERTY(config)				FColor						CrossHairColor;							//var config Object.Color CrossHairColor;
	UPROPERTY(EditAnywhere)			FName						CameraBone;								//var() name CameraBone;
	UPROPERTY()						bool						bHasAltFire;							//var bool bHasAltFire;
	UPROPERTY()						bool						bHasOwnHealth;							//var bool bHasOwnHealth;
	UPROPERTY()						FString						DebugInfo;								//var string DebugInfo;
	UPROPERTY()						float						PitchAccel;								//var float PitchAccel;
	UPROPERTY()						float						YawAccel;								//var float YawAccel;
	UPROPERTY()						bool						bHistoryWarmup;							//var bool bHistoryWarmup;
	UPROPERTY()						int32						NextHistorySlot;						//var int NextHistorySlot;
	UPROPERTY()						FVector						CameraHistory;							//var Object.Vector CameraHistory;
	UPROPERTY(EditAnywhere)			AActor*						DestroyEffectClass;						//var() class<Actor> DestroyEffectClass;
	UPROPERTY()						AAGP_Vehicle*				VehicleBase;							//var AGP_Vehicle VehicleBase;
	UPROPERTY()						bool						bDrawGunOverlay;						//var bool bDrawGunOverlay;
	//UPROPERTY()						AVehicleWeaponFPOverlay*	GunOverlay;							//var VehicleWeaponFPOverlay GunOverlay;
	//UPROPERTY()						AVehicleWeaponFPOverlay*	GunOverlayClass;					//var class<VehicleWeaponFPOverlay> GunOverlayClass;
	//UPROPERTY()						AVehicleWeapon*				GunClass;							//var class<VehicleWeapon> GunClass;
	//UPROPERTY()						AVehicleWeapon*				Gun;								//var VehicleWeapon Gun;
	UPROPERTY(EditAnywhere)			FRotator					GunnerRot;								//var() Object.Rotator GunnerRot;
	UPROPERTY(EditAnywhere)			FVector						GunnerPos;								//var() Object.Vector GunnerPos;

	void CreateVRI();
	int32 GetVehicleNumber();
	int32 GetVehiclePositionIndex(AVehicle* VehiclePosition);
	void AttachFlag(AActor* FlagActor);
	void GetMoveTargetFor(APawn* p);
	bool HasWeapon();
	void GetAimTarget();
	bool CanAttack(AActor* Other);
	bool TooCloseToAttack(AActor* Other);
	void ChooseFireAt(AActor* A);
	int32 RefireRate();
	bool IsFiring();
	bool NeedToTurn(FVector targ);
	bool FireOnRelease();
	bool IndependentVehicle();
	void ToggleZoom();
	//void DisplayDebug(UCanvas* Canvas, float &YL, float &YPos);
	void PostBeginPlay();
	void PostNetBeginPlay();
	bool IsReplicationComplete();
	void TeamChanged();
	AAGP_Vehicle* GetVehicleBase();
	void AttachToVehicle(AAGP_Vehicle* VehiclePawn, FName WeaponBone);
	FVector RotatorAlign(FRotator A, FRotator B);
	void SpecialCalcFirstPersonView(APlayerController* PC, AActor*& ViewActor, FVector& CameraLocation, FRotator& CameraRotation);
	void GetCameraLocationStart();
	void Destroyed();
	void EncroachedBy(AActor* Other);
	void BaseChange();
	void NPC_Fire(float F, APawn* Enemy);
	void SetInstantFire(bool bInstant);
	void Fire(float F);
	void AltFire(float F);
	void ClientVehicleCeaseFire(bool bWasAltFire);
	void VehicleCeaseFire(bool bWasAltFire);
	bool TryToDrive(APawn* p);
	void KDriverEnter(APawn* p);
	bool KDriverLeave(bool bForceLeave);
	void DriverDied();
	void ClientKDriverEnter(APlayerController* PC);
	void ClientKDriverLeave(APlayerController* PC);
	void SpawnFPVehicleWeaponOverlay(APlayerController* PC);
	void DrivingStatusChanged();
	bool PlaceExitingDriver();
	void GetDriverAttachmentBone(AActor*& AttachActor, FName& DriverAttachmentBone);
	void DetachDriver(APawn* p);
	void UpdateRocketAcceleration(float DeltaTime, float YawChange, float PitchChange);
	void SetTeamNum(uint8 t);
	void Died(AController* Killer, UaDamageType* DamageType, FVector HitLocation, FVector HitDir, FBoneInfo Bone);
	//void TakeDamage(int32 Damage, Pawn EventInstigator, FVector HitLocation, FVector Momentum, UaDamageType* DamageType, optional Actor.BoneInfo Bone, optional Controller KillerController, optional Actor ResponsibleActor, optional Material HitMaterial);
	bool CanLean();
	void LeanLeft(bool bFullLeft);
	void LeanRight(bool bFullRight);
	void LimitPitch(int32 Pitch);
	void TeamLink(int32 TeamNum);
	void DrawHUD(UCanvas* Canvas);
	void PostNetReceive();
	void NotifyControllerOutOfBounds(int32 Seconds);
	//void StaticPrecache(LevelInfo L);

};
