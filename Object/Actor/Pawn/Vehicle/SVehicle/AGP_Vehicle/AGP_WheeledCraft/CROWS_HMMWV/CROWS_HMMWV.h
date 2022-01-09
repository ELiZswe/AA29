// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Pawn/Vehicle/SVehicle/AGP_Vehicle/AGP_WheeledCraft/AGP_WheeledCraft.h"
#include "CROWS_HMMWV.generated.h"

class AVehicle;
class ALevelInfo;

class ABodyPanel;
UCLASS()
class ACROWS_HMMWV : public AAGP_WheeledCraft
{
	GENERATED_BODY()
public:
	ACROWS_HMMWV();

	UPROPERTY()									FRotator ViewRotationOffset;					//var Object.Rotator ViewRotationOffset;
	UPROPERTY()									bool bCanSteerAnim;								//var bool bCanSteerAnim;
	UPROPERTY()									bool bHoodDisabled;								//var bool bHoodDisabled;
	UPROPERTY()									AEmitter* HMMWVHoodSmokeEmitter;				//var Emitter HMMWVHoodSmokeEmitter;
	UPROPERTY()									float StopBrakeFriction;						//var float StopBrakeFriction;
	UPROPERTY()									FString SteeringWheelHintText;					//var string SteeringWheelHintText;
	UPROPERTY()									float DriftFactor;								//var float DriftFactor;
	UPROPERTY()									int32 WheelsDestroyed;							//var int32 WheelsDestroyed;
	UPROPERTY()									float FlatTireRadius;							//var float FlatTireRadius;
	UPROPERTY()									float WheelRadii;								//var float WheelRadii;
	UPROPERTY()									bool bVehicleUpsideDownLastCheck;				//var bool bVehicleUpsideDownLastCheck;
	UPROPERTY()									bool bVehicleDisabled;							//var bool bVehicleDisabled;
	UPROPERTY()									bool bHitIgnition;								//var bool bHitIgnition;
	UPROPERTY()									bool bRearViewIsLeft;							//var bool bRearViewIsLeft;
	UPROPERTY()									bool bIsRearView;								//var bool bIsRearView;
	UPROPERTY()									bool bDisturbedDamage;							//var bool bDisturbedDamage;
	UPROPERTY()									bool bJumpIt;									//var bool bJumpIt;
	UPROPERTY()									bool bCanShiftDrive;							//var bool bCanShiftDrive;
	UPROPERTY()									bool bCanShiftHiLo;								//var bool bCanShiftHiLo;
	UPROPERTY()									float fLowGearMultiplier;						//var float fLowGearMultiplier;
	UPROPERTY()									bool bIsInHighGear;								//var bool bIsInHighGear;
	UPROPERTY()									EeShifterState Shifter;							//var eShifterState Shifter;
	UPROPERTY()									float IdleSoundRestartTimer;					//var float IdleSoundRestartTimer;
	UPROPERTY()									float LastRollSoundTime;						//var float LastRollSoundTime;
	UPROPERTY()									float RollTriggerThreshold;						//var float RollTriggerThreshold;
	UPROPERTY()									float LastRollThresholdTime;					//var float LastRollThresholdTime;
	UPROPERTY()									float LastTotalRollAcceleration;				//var float LastTotalRollAcceleration;
	UPROPERTY()									bool bTransitioningCenter;						//var bool bTransitioningCenter;
	UPROPERTY()									bool bInitialSound;								//var bool bInitialSound;
	UPROPERTY()									bool bPlayingSlide;								//var bool bPlayingSlide;
	UPROPERTY()									float SlideThreshold;							//var float SlideThreshold;
	UPROPERTY()									int32 LastRollRandSqueak;						//var int32 LastRollRandSqueak;
	UPROPERTY()									int32 LastSusRandSqueak;						//var int32 LastSusRandSqueak;
	UPROPERTY()									float LastSuspensionSoundTime;					//var float LastSuspensionSoundTime;
	UPROPERTY()									float SuspensionTriggerThreshold;				//var float SuspensionTriggerThreshold;
	UPROPERTY()									float LastSuspensionThreshold;					//var float LastSuspensionThreshold;
	UPROPERTY()									float LastSuspensionThresholdTime;				//var float LastSuspensionThresholdTime;
	UPROPERTY()									float LastTotalSuspensionPosition;				//var float LastTotalSuspensionPosition;
	UPROPERTY()									float ShiftRadius;								//var float ShiftRadius;
	UPROPERTY()									float ShiftDelay;								//var float ShiftDelay;
	UPROPERTY()									float ShiftVolume;								//var float ShiftVolume;
	UPROPERTY()									USoundBase* SlideSound;							//var Sound SlideSound;
	UPROPERTY()									TArray<USoundBase*> FrameSqueaksSound;			//var Sound FrameSqueaksSound;
	UPROPERTY()									TArray<USoundBase*> SuspensionSqueaksSound;		//var Sound SuspensionSqueaksSound;
	UPROPERTY()									USoundBase* CollisionSound;						//var Sound CollisionSound;
	UPROPERTY()									USoundBase* ShiftGearsSound;					//var Sound ShiftGearsSound;
	UPROPERTY()									USoundBase* EngineDamagedHissSound;				//var Sound EngineDamagedHissSound;
	UPROPERTY()									USoundBase* EngineDamagedIdleSound;				//var Sound EngineDamagedIdleSound;
	UPROPERTY()									bool bAttachedPanels;							//var bool bAttachedPanels;
	UPROPERTY()									FName CameraBone;								//var name CameraBone;
	UPROPERTY()									UStaticMesh* SeatBeltOffMesh;					//var StaticMesh SeatBeltOffMesh;
	UPROPERTY()									UStaticMesh* SeatBeltOnMesh;					//var StaticMesh SeatBeltOnMesh;
	UPROPERTY()									ABodyPanel* Seatbelt;							//var AGP.BodyPanel Seatbelt;
	UPROPERTY()									ABodyPanel* BodyPanels;							//var AGP.BodyPanel BodyPanels;
	UPROPERTY(EditAnywhere)						TArray<FBodyPanelStruct>	StartBodyPanels;					//var() array<BodyPanelStruct> StartBodyPanels;
	UPROPERTY(config)							bool						bRealisticGrav;						//var config bool bRealisticGrav;
	UPROPERTY()									float						NotDirectImpactMultiplier;			//var float NotDirectImpactMultiplier;
	UPROPERTY()									float						NoSeatbeltMultiplier;				//var float NoSeatbeltMultiplier;
	UPROPERTY()									int32						PANEL_Collision_Seat_RB;			//var const int PANEL_Collision_Seat_RB;
	UPROPERTY()									int32						PANEL_Collision_Seat_RF;			//var const int PANEL_Collision_Seat_RF;
	UPROPERTY()									int32						PANEL_Collision_Seat_LB;			//var const int PANEL_Collision_Seat_LB;
	UPROPERTY()									int32						PANEL_Collision_Seat_LF;			//var const int PANEL_Collision_Seat_LF;
	UPROPERTY()									int32						PANEL_Collision_Dashboard;			//var const int PANEL_Collision_Dashboard;
	UPROPERTY()									int32						PANEL_Collision_CROWS_Interface;	//var const int PANEL_Collision_CROWS_Interface;
	UPROPERTY()									int32						PANEL_Collision_Door_RB;			//var const int PANEL_Collision_Door_RB;
	UPROPERTY()									int32						PANEL_Collision_Door_LB;			//var const int PANEL_Collision_Door_LB;
	UPROPERTY()									int32						PANEL_Collision_Door_RF;			//var const int PANEL_Collision_Door_RF;
	UPROPERTY()									int32						PANEL_Collision_Door_LF;			//var const int PANEL_Collision_Door_LF;
	UPROPERTY()									int32						PANEL_Collision;					//var const int PANEL_Collision;
	UPROPERTY()									int32						PANEL_Rail_R;						//var const int PANEL_Rail_R;
	UPROPERTY()									int32						PANEL_Rail_L;						//var const int PANEL_Rail_L;
	UPROPERTY()									int32						PANEL_Window_RB;					//var const int PANEL_Window_RB;
	UPROPERTY()									int32						PANEL_Window_RF;					//var const int PANEL_Window_RF;
	UPROPERTY()									int32						PANEL_Window_LB;					//var const int PANEL_Window_LB;
	UPROPERTY()									int32						PANEL_Window_LF;					//var const int PANEL_Window_LF;
	UPROPERTY()									int32						PANEL_Windshield;					//var const int PANEL_Windshield;
	UPROPERTY()									int32						PANEL_Seat_RB;						//var const int PANEL_Seat_RB;
	UPROPERTY()									int32						PANEL_Seat_RF;						//var const int PANEL_Seat_RF;
	UPROPERTY()									int32						PANEL_Seat_LB;						//var const int PANEL_Seat_LB;
	UPROPERTY()									int32						PANEL_Seat_LF;						//var const int PANEL_Seat_LF;
	UPROPERTY()									int32						PANEL_Dashboard;					//var const int PANEL_Dashboard;
	UPROPERTY()									int32						PANEL_Cap;							//var const int PANEL_Cap;
	UPROPERTY()									int32						PANEL_Body_R;						//var const int PANEL_Body_R;
	UPROPERTY()									int32						PANEL_Body_L;						//var const int PANEL_Body_L;
	UPROPERTY()									int32 PANEL_Interior;							//var const int PANEL_Interior;
	UPROPERTY()									int32 PANEL_EBrake;								//var const int PANEL_EBrake;
	UPROPERTY()									int32 PANEL_CROWS_Interface;					//var const int PANEL_CROWS_Interface;
	UPROPERTY()									int32 PANEL_Tailgate;							//var const int PANEL_Tailgate;
	UPROPERTY()									int32 PANEL_Roof;								//var const int PANEL_Roof;
	UPROPERTY()									int32 PANEL_Bumper_Front;						//var const int PANEL_Bumper_Front;
	UPROPERTY()									int32 PANEL_Bumper_Rear;						//var const int PANEL_Bumper_Rear;
	UPROPERTY()									int32 PANEL_TrunkLid;							//var const int PANEL_TrunkLid;
	UPROPERTY()									int32 PANEL_Hood;								//var const int PANEL_Hood;
	UPROPERTY()									int32 PANEL_Pedal_Brake;						//var const int PANEL_Pedal_Brake;
	UPROPERTY()									int32 PANEL_Pedal_Accelerator;					//var const int PANEL_Pedal_Accelerator;
	UPROPERTY()									int32 PANEL_Shifter_HiLo;						//var const int PANEL_Shifter_HiLo;
	UPROPERTY()									int32 PANEL_Shifter_Gear;						//var const int PANEL_Shifter_Gear;
	UPROPERTY()									int32 PANEL_SteeringWheel;						//var const int PANEL_SteeringWheel;
	UPROPERTY()									int32 PANEL_Fender_RB;							//var const int PANEL_Fender_RB;
	UPROPERTY()									int32 PANEL_Fender_LB;							//var const int PANEL_Fender_LB;
	UPROPERTY()									int32 PANEL_Fender_RF;							//var const int PANEL_Fender_RF;
	UPROPERTY()									int32 PANEL_Fender_LF;							//var const int PANEL_Fender_LF;
	UPROPERTY()									int32 PANEL_Door_RB;							//var const int PANEL_Door_RB;
	UPROPERTY()									int32 PANEL_Door_LB;							//var const int PANEL_Door_LB;
	UPROPERTY()									int32 PANEL_Door_RF;							//var const int PANEL_Door_RF;
	UPROPERTY()									int32 PANEL_Door_LF;							//var const int PANEL_Door_LF;
	UPROPERTY()									int32 PANEL_Wheel_RB;							//var const int PANEL_Wheel_RB;
	UPROPERTY()									int32 PANEL_Wheel_LB;							//var const int PANEL_Wheel_LB;
	UPROPERTY()									int32 PANEL_Wheel_RF;							//var const int PANEL_Wheel_RF;
	UPROPERTY()									int32 PANEL_Wheel_LF;							//var const int PANEL_Wheel_LF;
	UPROPERTY()									int32 POSITION_RBBoard;							//var const int POSITION_RBBoard;
	UPROPERTY()									int32 POSITION_RB;								//var const int POSITION_RB;
	UPROPERTY()									int32 POSITION_RFBoard;							//var const int POSITION_RFBoard;
	UPROPERTY()									int32 POSITION_RF;								//var const int POSITION_RF;
	UPROPERTY()									int32 POSITION_LBBoard;							//var const int POSITION_LBBoard;
	UPROPERTY()									int32 POSITION_LB;								//var const int POSITION_LB;
	UPROPERTY()									int32 POSITION_LFBoard;							//var const int POSITION_LFBoard;
	UPROPERTY()									int32 POSITION_LF;								//var const int POSITION_LF;
	UPROPERTY()									bool bDriverWearingSeatbelt;					//var bool bDriverWearingSeatbelt;

	bool CheckDriverCanExit(APawn* TestDriver, FName ExitBone);
	void UpdateAttachedActorLocations();
	bool VehicleDisabled();
	void SetDriverHiddenAttachments();
	void ShiftDriveGearsUp();
	void ShiftDriveGearsDown();
	void ShiftHiLoGears();
	void LookRearViewLeft();
	void LookRearViewRight();
	void Horn();
	void PlayEngineStartUpSound();
	void PlayEngineDamagedSounds(bool bDestroyed);
	AVehicle* GetVehicleBase();
	void PostBeginPlay();
	void PostNetBeginPlay();
	void PostNetReceive();
	void StartSounds();
	void DriverDied();
	void Destroyed();
	void KDriverEnter(APawn* p);
	bool KDriverLeave(bool bForceLeave);
	void ClientKDriverEnter(APlayerController* PC);
	void ClientKDriverLeave(APlayerController* PC);
	void AttachDriver(APawn* p);
	AVehicle* FindEntryVehicle(APawn* p);
	bool UsedBy(APawn* User);
	void LeanLeft(bool bFullLeft);
	void LeanRight(bool bFullRight);
	APawn* CheckForHeadShot(FVector loc, FVector ray, float AdditionalScale);
	void StaticPrecache(ALevelInfo* L);
	void UpdatePrecacheStaticMeshes();
	void UpdatePrecacheMaterials();
	int32 GetVehiclePositionIndex(AVehicle* VehiclePosition);
	void FixBoneRotations();
	void AttachBodyPanels();
	void StopReplicateMovement();
	bool PanelUsedBy(APawn* User, int32 Id);
	bool DoDoor(APawn* User, AVehicle* EntryVehicle, AVehicle* EntryBoard, bool bSideStep);
	void Ignition();
	void DevSuperJump();
	void ClientSetIgnition(bool bNewHitIgnition);
	void CalcRearView(APlayerController* PC, AActor*& ViewActor, FVector& CameraLocation, FRotator& CameraRotation);
	void SpecialCalcFirstPersonView(APlayerController* PC, AActor*& ViewActor, FVector& CameraLocation, FRotator& CameraRotation);
	void SpecialSetFirstPersonViewRotation(APlayerController* PC, FRotator CameraRotation);
	bool SpecialCalcView(AActor*& ViewActor, FVector& CameraLocation, FRotator& CameraRotation);
	void ServerTryToShiftHiLoGears();
	void ShiftHiLoTimer();
	void ServerShiftHiLoGears();
	void ServerTryToShiftDriveGears(bool ShiftUp);
	void ShiftDriveTimer();
	void ServerShiftDriveGears(bool ShiftUp);
	void ServerSetSeatbelt();
	void ServerRemoveSeatbelt();
	void GetDamageModifier(int32 BodyPanelID, UaDamageType* DamageType, int32 Damage);
	void NotifyVehiclePanelDamaged(int32 PanelID, int32 DamageLevel);
	void NotifyVehiclePanelDestroyed(int32 PanelID);
	void TakeImpactDamage(float AccelMag);
	void TakeRollOverDamage();
	void SpawnHoodEmitter();
	void ActivateSmoke();
	void SuspensionThreshold(float DeltaTravel);
	void RollThreshold(float DeltaRoll);
	void DisplayVehicleDebug(UCanvas* Canvas, float &YL, float &YPos);
	void DisplayDebug(UCanvas* Canvas, const class FDebugDisplayInfo& DebugDisplay, float& YL, float& YPos);
	//void TakeDamage(int32 Damage, Pawn instigatedBy, Object.Vector HitLocation, Object.Vector Momentum, UaDamageType* DamageType, optional FBoneInfo Bone, optional Controller KillerController, optional Actor ResponsibleActor, optional Material HitMaterial);
	void Timer();
};
