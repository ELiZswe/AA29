// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Inventory/Weapon/AGP_Weapon/AGP_Weapon.h"
#include "Item_Parachute.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AItem_Parachute : public AAGP_Weapon
{
	GENERATED_BODY()
public:
	AItem_Parachute();

	
	UPROPERTY()		bool bCameraLocked;						//var bool bCameraLocked;
	UPROPERTY()		int32 LastStrafe;						//var int LastStrafe;
	UPROPERTY()		int32 LastForward;						//var int LastForward;
	UPROPERTY()		FName ExitState;						//var name ExitState;
	UPROPERTY()		FName DesiredState;						//var name DesiredState;
	UPROPERTY()		FRotator RigRotationLimits;				//var Object.Rotator RigRotationLimits;


	virtual void Fire(float Value) override;
	virtual void AltFire(float Value) override;
	virtual void Reload() override;
	virtual void FixJam() override;
	void ChangeFireMode();
	void CycleZoom();
	void ToggleZoom();
	void ForceUnzoom(bool bForce);
	virtual void UnZoom() override;
	virtual void Zoom() override;
	void SpawnAndAttachMILESGear();
	bool CanUseWeapon(int32 DesiredAction);
	void DropFrom(FVector StartLocation, bool bAttach);
	void SetupClientWeapon();
	EUpperBodyAnim GetUpperBodyReadyAnim();
	FString DisplayDebugMessage();
	void BeginPlay();
	void AttachToPawn(APawn* p);
	void NotifyBaseChange();
	void SetMesh();
	void GetStaticMesh(bool bFriendly);
	void NotifyNewParachuteState(int32 NewState);
	void CleanupParachute();
	void Timer();
	void Tick(float DeltaTime);
	void RenderOverlays(UCanvas* Canvas, bool bWeaponAndAttachmentsOnly);
	void SetupCamera(bool bOn);
	void NotifyReplicationComplete();
	virtual void PlayIdleAnim() override;
	void IsInExitState();
	void ShouldDrawCrosshair();

};
