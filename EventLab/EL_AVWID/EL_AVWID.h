// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/EventLab/EventLab.h"
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

/**
 * 
 */
UCLASS()
class AA29_API AEL_AVWID : public AEventLab
{
	GENERATED_BODY()
public:
	AEL_AVWID();

	UPROPERTY(EditAnywhere)			bool bHackSkipSlides;									//var bool bHackSkipSlides;
	UPROPERTY(EditAnywhere)			bool bHackChopper;										//var bool bHackChopper;
	UPROPERTY(EditAnywhere)			ACameraPoint* ChopperCam01;								//var AGP_Gameplay.CameraPoint ChopperCam01;
	UPROPERTY(EditAnywhere)			USoundBase* SodaGuySound;								//var Sound SodaGuySound;
	UPROPERTY(EditAnywhere)			FVector NewPosForTruck;									//var FVector NewPosForTruck;
	UPROPERTY(EditAnywhere)			bool bSodaGuy_Trigger_Used;								//var bool bSodaGuy_Trigger_Used;
	UPROPERTY(EditAnywhere)			bool bInClass_DidSitDown;								//var bool bInClass_DidSitDown;
	UPROPERTY(EditAnywhere)			int32 Grade;											//var int Grade;
	UPROPERTY(EditAnywhere)			int32 LookCount;										//var int LookCount;
	UPROPERTY(EditAnywhere)			int32 GoofCount;										//var int GoofCount;
	UPROPERTY(EditAnywhere)			int32 InstructorUseCount;								//var int InstructorUseCount;
	UPROPERTY(EditAnywhere)			AAGP_Location* ClassRoom;								//var AGP_Gameplay.AGP_Location ClassRoom;
	//UPROPERTY(EditAnywhere)			ARelayTrigger* Truck1;								//var AGP_Gameplay.RelayTrigger Truck1;
	UPROPERTY(EditAnywhere)			AAGP_Location* PlayerStartLocation;						//var AGP_Gameplay.AGP_Location PlayerStartLocation;
	UPROPERTY(EditAnywhere)			AAGP_Location* Chopper;									//var AGP_Gameplay.AGP_Location Chopper;
	UPROPERTY(EditAnywhere)			AAGP_Location* GoToClass;								//var AGP_Gameplay.AGP_Location GoToClass;
	UPROPERTY(EditAnywhere)			ANPC_Ambient* SodaMachine;								//var AGP_Characters.NPC_Ambient SodaMachine;
	UPROPERTY(EditAnywhere)			ANPC_Ambient* SodaGuy;									//var AGP_Characters.NPC_Ambient SodaGuy;
	UPROPERTY(EditAnywhere)			ANPC_SpecialForces* SargChopper;						//var AGP_Characters.NPC_SpecialForces SargChopper;
	UPROPERTY(EditAnywhere)			ANPC_SpecialForces* Guy2;								//var AGP_Characters.NPC_SpecialForces Guy2;
	UPROPERTY(EditAnywhere)			ANPC_SpecialForces* Guy1;								//var AGP_Characters.NPC_SpecialForces Guy1;
	UPROPERTY(EditAnywhere)			ATriggerVolume* TruckSplineTrigger;						//var AGP_Gameplay.TriggerVolume TruckSplineTrigger;
	UPROPERTY(EditAnywhere)			ATriggerVolume* SodaGuy_Trigger;						//var AGP_Gameplay.TriggerVolume SodaGuy_Trigger;
	UPROPERTY(EditAnywhere)			AMedExam* SFExamOne;									//var AGP_Gameplay.MedExam SFExamOne;
	UPROPERTY(EditAnywhere)			AAGP_Trigger* SeatVolumeOne;							//var AGP_Gameplay.AGP_Trigger SeatVolumeOne;
	UPROPERTY(EditAnywhere)			ATriggerVolume* TestVolumeOne;							//var AGP_Gameplay.TriggerVolume TestVolumeOne;
	UPROPERTY(EditAnywhere)			ATriggerVolume* LeavingVolumeOne;						//var AGP_Gameplay.TriggerVolume LeavingVolumeOne;
	UPROPERTY(EditAnywhere)			AAGP_UseTrigger* SeatTriggerOne;						//var AGP.AGP_UseTrigger SeatTriggerOne;
	//UPROPERTY(EditAnywhere)			ASlideProjector* SlideProjectorOne;					//var SlideProjector SlideProjectorOne;
	UPROPERTY(EditAnywhere)			ANPC_MedInstructor* InstructorOne;						//var AGP_Characters.NPC_MedInstructor InstructorOne;
	UPROPERTY(EditAnywhere)			AAGP_UseTrigger* InstructorTriggerOne;					//var AGP.AGP_UseTrigger InstructorTriggerOne;
	UPROPERTY(EditAnywhere)			ADoorTrigger* DoorTriggerOne;							//var AGP_Gameplay.DoorTrigger DoorTriggerOne;


};
