// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Pawn/Vehicle/SVehicle/AGP_Vehicle/AGP_WheeledCraft/AGP_WheeledCraft.h"
#include "AGP_TreadCraft.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AAGP_TreadCraft : public AAGP_WheeledCraft
{
	GENERATED_BODY()
public:
	AAGP_TreadCraft();

	UPROPERTY(EditAnywhere)					FName RightTreadDamageBone;									//var() name RightTreadDamageBone;
	UPROPERTY(EditAnywhere)					FName RightTreadBone;										//var() name RightTreadBone;
	UPROPERTY(EditAnywhere)					FName LeftTreadDamageBone;									//var() name LeftTreadDamageBone;
	UPROPERTY(EditAnywhere)					FName LeftTreadBone;										//var() name LeftTreadBone;
	UPROPERTY(EditAnywhere)					int32 RightTreadSkinNum;									//var() int32 RightTreadSkinNum;
	UPROPERTY(EditAnywhere)					int32 LeftTreadSkinNum;										//var() int32 LeftTreadSkinNum;
	UPROPERTY(EditAnywhere)					FRotator TreadPannerRotation;								//var() Object.Rotator TreadPannerRotation;
	UPROPERTY()								UMaterialInstance* RightTreadPanner;						//var VariableTexPanner RightTreadPanner;
	UPROPERTY()								UMaterialInstance* LeftTreadPanner;							//var VariableTexPanner LeftTreadPanner;
	UPROPERTY(EditAnywhere)					TArray<FName> RightTreadWheels;								//var() array<name> RightTreadWheels;
	UPROPERTY(EditAnywhere)					TArray<FName> LeftTreadWheels;								//var() array<name> LeftTreadWheels;
	UPROPERTY()								float RightTreadWheelRoll;									//var float RightTreadWheelRoll;
	UPROPERTY()								float LeftTreadWheelRoll;									//var float LeftTreadWheelRoll;
	UPROPERTY()								float WheelVelocityScale;									//var float WheelVelocityScale;
	UPROPERTY()								float TreadVelocityScale;									//var float TreadVelocityScale;
	//UPROPERTY(EditAnywhere)					FInterpCurve SteerSpeedCurve;								//var() Object.InterpCurve SteerSpeedCurve;
	UPROPERTY(EditAnywhere)					float SteerThrottleScale;									//var() float SteerThrottleScale;
	UPROPERTY()								bool bTurnThrottle;											//var const bool bTurnThrottle;

	void DisplayVehicleDebug(UCanvas* Canvas, float& YL, float& YPos);
	void PostBeginPlay();
	void InitializeDamageZones();
	void Destroyed();
	void rightside(float Size);
	void leftside(float Size);
	bool VerifyVehicleSystemBones(bool bFoundBadBones);
	void DamageTread(bool bRightTread);
	void SetupTreads();
	void DestroyTreads();
	void DrivingStatusChanged();
	void Tick(float DeltaTime);
	void ChangeDamageState(uint8 ZoneNum, uint8 NewStateNum);
};
