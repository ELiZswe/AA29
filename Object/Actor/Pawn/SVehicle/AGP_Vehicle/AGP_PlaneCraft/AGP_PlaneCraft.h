// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Pawn/SVehicle/AGP_Vehicle/AGP_Vehicle.h"
#include "AA29/AA29.h"
#include "AGP_PlaneCraft.generated.h"

UCLASS()
class AA29_API AAGP_PlaneCraft : public AAGP_Vehicle
{
	GENERATED_BODY()
public:
	AAGP_PlaneCraft();

	UPROPERTY()									bool bNewPlaneState;							//var bool bNewPlaneState;
	UPROPERTY()									FKRigidBodyState ChassisState;					//var Actor.KRigidBodyState ChassisState;
	UPROPERTY()									FPlaneStateStruct OldPlaneState;				//var AGP_PlaneCraft.PlaneStateStruct OldPlaneState;
	UPROPERTY()									FPlaneStateStruct PlaneState;					//var AGP_PlaneCraft.PlaneStateStruct PlaneState;
	UPROPERTY()									float BankTorque;								//var() float BankTorque;
	UPROPERTY()									float PitchTorque;								//var() float PitchTorque;
	UPROPERTY()									FRotator LastCamRot;							//var Object.Rotator LastCamRot;
	UPROPERTY()									float LastCamTime;								//var float LastCamTime;
	UPROPERTY()									float AccumulatedTime;							//var float AccumulatedTime;
	UPROPERTY()									float CurrentThrust;							//var float CurrentThrust;
	UPROPERTY()									float OutputRise;								//var float OutputRise;
	UPROPERTY()									float OutputStrafe;								//var float OutputStrafe;
	UPROPERTY()									float OutputThrust;								//var float OutputThrust;
	UPROPERTY(EditAnywhere)						float HoverCheckDist;							//var() float HoverCheckDist;
	UPROPERTY(EditAnywhere)						float HoverPenScale;							//var() float HoverPenScale;
	UPROPERTY(EditAnywhere)						float HoverSoftness;							//var() float HoverSoftness;
	UPROPERTY()									TArray<FVector> ThrusterOffsets;				//var array<Vector> ThrusterOffsets;
	UPROPERTY(EditAnywhere)						float CameraDistance;							//var() float CameraDistance;
	UPROPERTY(EditAnywhere)						float CameraSwingRatio;							//var() float CameraSwingRatio;
	//UPROPERTY(EditAnywhere)						FInterpCurve HoverForceCurve;					//var() Object.InterpCurve HoverForceCurve;
	UPROPERTY(EditAnywhere)						float COMHeight;								//var() float COMHeight;
	UPROPERTY(EditAnywhere)						bool bHoverOnGround;							//var() bool bHoverOnGround;
	UPROPERTY(EditAnywhere)						float ThrustAcceleration;						//var() float ThrustAcceleration;
	UPROPERTY(EditAnywhere)						float MaxThrust;								//var() float MaxThrust;
	UPROPERTY(EditAnywhere)						float AirFactor;								//var() float AirFactor;
	//UPROPERTY(EditAnywhere)						FInterpCurve DragCoefficientCurve;				//var() Object.InterpCurve DragCoefficientCurve;
	//UPROPERTY(EditAnywhere)						FInterpCurve LiftCoefficientCurve;				//var() Object.InterpCurve LiftCoefficientCurve;

	void PostNetBeginPlay();
	void Destroyed();
	bool KUpdateState(FKRigidBodyState NewState);
	void SVehicleUpdateParams();
	int32 GetRotDiff(int32 A, int32 B);
	void SpecialCalcBehindView(APlayerController* PC, AActor*& ViewActor, FVector& CameraLocation, FRotator& CameraRotation);
	void SpecialCalcFirstPersonView(APlayerController* PC, AActor*& ViewActor, FVector& CameraLocation, FRotator& CameraRotation);

};
