// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Pawn/Vehicle/VehiclePosition/HMMWV_Passenger/HMMWV_Passenger.h"
#include "CROWS_Gunner.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API ACROWS_Gunner : public AHMMWV_Passenger
{
	GENERATED_BODY()
public:
	ACROWS_Gunner();

	UPROPERTY()						USoundBase*					LaseSound;								//var Sound LaseSound;
	UPROPERTY()						USoundBase*					StartUpSound;							//var Sound StartUpSound;
	UPROPERTY()						USoundBase*					ZoomSound;								//var Sound ZoomSound;
	UPROPERTY()						float						DefShakeOffsetTime;						//var float DefShakeOffsetTime;
	UPROPERTY()						float						DefShakeRotTime;						//var float DefShakeRotTime;
	UPROPERTY()						FVector						DefShakeOffsetMag;						//var Object.Vector DefShakeOffsetMag;
	UPROPERTY()						FVector						DefShakeRotMag;							//var Object.Vector DefShakeRotMag;
	UPROPERTY()						bool						bGotGunShakeValues;						//var bool bGotGunShakeValues;
	UPROPERTY()						int32						DesiredYaw;								//var int DesiredYaw;
	UPROPERTY()						float						CurrentYaw;								//var float CurrentYaw;
	UPROPERTY()						int32						LastYawUpdate;							//var int LastYawUpdate;
	UPROPERTY()						FName						LaserRechargeCallbackName;				//var name LaserRechargeCallbackName;
	UPROPERTY()						bool						bLaserRecharging;						//var bool bLaserRecharging;
	UPROPERTY()						float						LaseDistance;							//var float LaseDistance;
	UPROPERTY()						float						CurrentZoom;							//var float CurrentZoom;
	UPROPERTY()						float						ZoomLevel12;							//var float ZoomLevel12;
	UPROPERTY()						float						ZoomLevel8;								//var float ZoomLevel8;
	UPROPERTY()						float						ZoomLevel4;								//var float ZoomLevel4;
	UPROPERTY()						float						ZoomLevel2;								//var float ZoomLevel2;
	UPROPERTY()						float						ZoomLevel1;								//var float ZoomLevel1;
	UPROPERTY()						float						ZoomLevel0;								//var float ZoomLevel0;
	//UPROPERTY()					ACROWS_Hud*					HudClass;								//var class<CROWS_Hud> HudClass;
	//UPROPERTY()					AHUD*						PCHUD;									//var HUD PCHUD;
	//UPROPERTY()					ACROWS_Hud*					myHUD;									//var CROWS_Hud myHUD;
	UPROPERTY()						FName						GunCameraBone;							//var name GunCameraBone;
	UPROPERTY()						bool						bFromBehind;							//var bool bFromBehind;
	UPROPERTY()						bool						bInCROWS;								//var bool bInCROWS;

	void SpecialCalcCROWSView(APlayerController* PC, AActor*& ViewActor, FVector& CameraLocation, FRotator& CameraRotation);
	bool SpecialCalcView(AActor*& ViewActor, FVector& CameraLocation, FRotator& CameraRotation);
	void AttachToVehicle(AAGP_Vehicle* VehiclePawn, FName WeaponBone);
	void SpecialCalcBehindView(APlayerController* PC, AActor*& ViewActor, FVector& CameraLocation, FRotator& CameraRotation);
	bool Using(AActor* Other);
	void ActivateCrows();
	void ServerActivateCrows();
	void ChargeWeapon();
	void ClientBeginCrows();
	void ClientFinishCrows();
	void BeginCrows();
	void FinishCrows();
	void UnPossessed();
	void ValidateView();
	void DrawHUD(UCanvas* C);
	void ZoomIn();
	void ZoomOut();
	void CROWSZeroRange();
	void DoLase();
	void LaseCallback();
	void LaserRechargingTimer();
	void Tick(float DeltaTime);
	void AltFire(float F);

};
