// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/EventLab/EventLab.h"
#include "EL_AVWID.generated.h"

class AAGP_Location;
class ACameraPoint;
class ANPC_Ambient;
class ANPC_SpecialForces;
class ATriggerVolume;
class AMedExam;
class ANPC_MedInstructor;
class AAGP_Trigger;
class ADoorTrigger;
class ARelayTrigger;
class ASlideProjector;

UCLASS()
class AA29_API AEL_AVWID : public AEventLab
{
	GENERATED_BODY()
public:
	AEL_AVWID();

	UPROPERTY()			bool bHackSkipSlides;									//var bool bHackSkipSlides;
	UPROPERTY()			bool bHackChopper;										//var bool bHackChopper;
	UPROPERTY()			ACameraPoint* ChopperCam01;								//var AGP_Gameplay.CameraPoint ChopperCam01;
	UPROPERTY()			USoundBase* SodaGuySound;								//var Sound SodaGuySound;
	UPROPERTY()			FVector NewPosForTruck;									//var FVector NewPosForTruck;
	UPROPERTY()			bool bSodaGuy_Trigger_Used;								//var bool bSodaGuy_Trigger_Used;
	UPROPERTY()			bool bInClass_DidSitDown;								//var bool bInClass_DidSitDown;
	UPROPERTY()			int32 Grade;											//var int Grade;
	UPROPERTY()			int32 LookCount;										//var int LookCount;
	UPROPERTY()			int32 GoofCount;										//var int GoofCount;
	UPROPERTY()			int32 InstructorUseCount;								//var int InstructorUseCount;
	UPROPERTY()			AAGP_Location* ClassRoom;								//var AGP_Gameplay.AGP_Location ClassRoom;
	UPROPERTY()			ARelayTrigger* Truck1;									//var AGP_Gameplay.RelayTrigger Truck1;
	UPROPERTY()			AAGP_Location* PlayerStartLocation;						//var AGP_Gameplay.AGP_Location PlayerStartLocation;
	UPROPERTY()			AAGP_Location* Chopper;									//var AGP_Gameplay.AGP_Location Chopper;
	UPROPERTY()			AAGP_Location* GoToClass;								//var AGP_Gameplay.AGP_Location GoToClass;
	UPROPERTY()			ANPC_Ambient* SodaMachine;								//var AGP_Characters.NPC_Ambient SodaMachine;
	UPROPERTY()			ANPC_Ambient* SodaGuy;									//var AGP_Characters.NPC_Ambient SodaGuy;
	UPROPERTY()			ANPC_SpecialForces* SargChopper;						//var AGP_Characters.NPC_SpecialForces SargChopper;
	UPROPERTY()			ANPC_SpecialForces* Guy2;								//var AGP_Characters.NPC_SpecialForces Guy2;
	UPROPERTY()			ANPC_SpecialForces* Guy1;								//var AGP_Characters.NPC_SpecialForces Guy1;
	UPROPERTY()			ATriggerVolume* TruckSplineTrigger;						//var AGP_Gameplay.TriggerVolume TruckSplineTrigger;
	UPROPERTY()			ATriggerVolume* SodaGuy_Trigger;						//var AGP_Gameplay.TriggerVolume SodaGuy_Trigger;
	UPROPERTY()			AMedExam* SFExamOne;									//var AGP_Gameplay.MedExam SFExamOne;
	UPROPERTY()			AAGP_Trigger* SeatVolumeOne;							//var AGP_Gameplay.AGP_Trigger SeatVolumeOne;
	UPROPERTY()			ATriggerVolume* TestVolumeOne;							//var AGP_Gameplay.TriggerVolume TestVolumeOne;
	UPROPERTY()			ATriggerVolume* LeavingVolumeOne;						//var AGP_Gameplay.TriggerVolume LeavingVolumeOne;
	UPROPERTY()			AAGP_UseTrigger* SeatTriggerOne;						//var AGP.AGP_UseTrigger SeatTriggerOne;
	UPROPERTY()			ASlideProjector* SlideProjectorOne;						//var SlideProjector SlideProjectorOne;
	UPROPERTY()			ANPC_MedInstructor* InstructorOne;						//var AGP_Characters.NPC_MedInstructor InstructorOne;
	UPROPERTY()			AAGP_UseTrigger* InstructorTriggerOne;					//var AGP.AGP_UseTrigger InstructorTriggerOne;
	UPROPERTY()			ADoorTrigger* DoorTriggerOne;							//var AGP_Gameplay.DoorTrigger DoorTriggerOne;

	bool AGP_UseTrigger_UsedBy(AAGP_UseTrigger* Trigger, AActor* Instigator);
	bool SeatTriggerOne_UsedBy(AAGP_UseTrigger* Trigger, AActor* Instigator);
	bool InstructorTriggerOne_UsedBy(AAGP_UseTrigger* Trigger, AActor* Instigator);
	bool AGP_Trigger_Trigger(AAGP_Trigger* Trigger, AActor* Instigator);
	bool AGP_Trigger_UnTrigger(AAGP_Trigger* Trigger, AActor* Instigator);
	bool SeatVolumeOne_Trigger(AAGP_Trigger* Trigger, AActor* Instigator);
	bool SeatVolumeOne_UnTrigger(AAGP_Trigger* Trigger, AActor* Instigator);
	bool DoorTrigger_UsedBy(ADoorTrigger* Trigger, AActor* Instigator);
	bool DoorTriggerOne_UsedBy(ADoorTrigger* Trigger, AActor* Instigator);
	bool TriggerVolume_Enter(ATriggerVolume* Trigger, AActor* Instigator);
	bool ClassVolumeOne_Enter(ATriggerVolume* Trigger, AActor* Instigator);
	bool LeavingVolumeOne_Enter(ATriggerVolume* Trigger, AActor* Instigator);
	bool TestVolumeOne_Enter(ATriggerVolume* Trigger, AActor* Instigator);
	void PreInit();
	void Init();
	void PostInit();
	void PostPostInit();
	FRotator RandLookRotation();
	bool SodaGuy_Trigger_Enter(ATriggerVolume* Trigger, AActor* Instigator);
	bool OutOfBounds_Trigger_Enter(ATriggerVolume* Trigger, AActor* Instigator);
	bool GlobalTimer(FName Name);
	void StopLipSincAnims();
};
