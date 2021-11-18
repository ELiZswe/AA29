// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/EventLab/EventLab.h"
#include "EL_SFTrainingOne.generated.h"

class AAGP_Location;
//class AACameraPoint;
class ANPC_Ambient;
class AMedExam;
class ANPC_MedInstructor;

UCLASS()
class AA29_API AEL_SFTrainingOne : public AEventLab
{
	GENERATED_BODY()
public:
	AEL_SFTrainingOne();

	UPROPERTY()						bool bHackSkipSlides;									//var bool bHackSkipSlides;
	UPROPERTY()						bool bHackChopper;										//var bool bHackChopper;
//	UPROPERTY()						AACameraPoint* ChopperCam01;							//var AGP_Gameplay.CameraPoint ChopperCam01;
	UPROPERTY()						int32 GDC;												//var int GDC;
	UPROPERTY()						USoundBase* SodaGuySound;								//var Sound SodaGuySound;
	UPROPERTY()						FVector NewPosForTruck;									//var FVector NewPosForTruck;
	UPROPERTY()						bool bSodaGuy_Trigger_Used;								//var bool bSodaGuy_Trigger_Used;
	UPROPERTY()						bool bSFIntelligence_Trigger_Used;						//var bool bSFIntelligence_Trigger_Used;
	UPROPERTY()						bool bSFCommunication_Trigger_Used;						//var bool bSFCommunication_Trigger_Used;
	UPROPERTY()						bool bSFMedical_Trigger_Used;							//var bool bSFMedical_Trigger_Used;
	UPROPERTY()						bool bSFEngineer_Trigger_Used;							//var bool bSFEngineer_Trigger_Used;
	UPROPERTY()						bool bSFWeapons_Trigger_Used;							//var bool bSFWeapons_Trigger_Used;
	UPROPERTY()						bool bSFSergeant_Trigger_Used;							//var bool bSFSergeant_Trigger_Used;
	UPROPERTY()						bool bSFCommander_Trigger_Used;							//var bool bSFCommander_Trigger_Used;
	UPROPERTY()						bool bSFLeader_Trigger_Used;							//var bool bSFLeader_Trigger_Used;
	UPROPERTY()						bool bInClass_DidSitDown;								//var bool bInClass_DidSitDown;
	UPROPERTY()						int32 Grade;											//var int Grade;
	UPROPERTY()						int32 LookCount;										//var int LookCount;
	UPROPERTY()						int32 GoofCount;										//var int GoofCount;
	UPROPERTY()						int32 InstructorUseCount;								//var int InstructorUseCount;
	UPROPERTY()						AAGP_Location* ClassRoom;								//var AGP_Gameplay.AGP_Location ClassRoom;
	//UPROPERTY()						ARelayTrigger* Truck1;									//var AGP_Gameplay.RelayTrigger Truck1;
	UPROPERTY()						AAGP_Location* PlayerStartLocation;						//var AGP_Gameplay.AGP_Location PlayerStartLocation;
	UPROPERTY()						AAGP_Location* Chopper;									//var AGP_Gameplay.AGP_Location Chopper;
	UPROPERTY()						AAGP_Location* GoToClass;								//var AGP_Gameplay.AGP_Location GoToClass;
	UPROPERTY()						ANPC_Ambient* SodaMachine;								//var AGP_Characters.NPC_Ambient SodaMachine;
	UPROPERTY()						ANPC_Ambient* SodaGuy;									//var AGP_Characters.NPC_Ambient SodaGuy;
	UPROPERTY()						ANPC_SpecialForces* SargChopper;						//var AGP_Characters.NPC_SpecialForces SargChopper;
	UPROPERTY()						ANPC_SpecialForces* Guy2;								//var AGP_Characters.NPC_SpecialForces Guy2;
	UPROPERTY()						ANPC_SpecialForces* Guy1;								//var AGP_Characters.NPC_SpecialForces Guy1;
	UPROPERTY()						ANPC_SpecialForces* SFIntelligence;						//var AGP_Characters.NPC_SpecialForces SFIntelligence;
	UPROPERTY()						ANPC_SpecialForces* SFCommunication;					//var AGP_Characters.NPC_SpecialForces SFCommunication;
	UPROPERTY()						ANPC_SpecialForces* SFMedical;							//var AGP_Characters.NPC_SpecialForces SFMedical;
	UPROPERTY()						ANPC_SpecialForces* SFEngineer;							//var AGP_Characters.NPC_SpecialForces SFEngineer;
	UPROPERTY()						ANPC_SpecialForces* SFWeapons;							//var AGP_Characters.NPC_SpecialForces SFWeapons;
	UPROPERTY()						ANPC_SpecialForces* SFSergeant;							//var AGP_Characters.NPC_SpecialForces SFSergeant;
	UPROPERTY()						ANPC_SpecialForces* SFCommander;						//var AGP_Characters.NPC_SpecialForces SFCommander;
	UPROPERTY()						ANPC_SpecialForces* SFLeader;							//var AGP_Characters.NPC_SpecialForces SFLeader;
	UPROPERTY()						ATriggerVolume* TruckSplineTrigger;						//var AGP_Gameplay.TriggerVolume TruckSplineTrigger;
	UPROPERTY()						ATriggerVolume* SodaGuy_Trigger;						//var AGP_Gameplay.TriggerVolume SodaGuy_Trigger;
	UPROPERTY()						ATriggerVolume* SFIntelligence_Trigger;					//var AGP_Gameplay.TriggerVolume SFIntelligence_Trigger;
	UPROPERTY()						ATriggerVolume* SFCommunication_Trigger;				//var AGP_Gameplay.TriggerVolume SFCommunication_Trigger;
	UPROPERTY()						ATriggerVolume* SFMedical_Trigger;						//var AGP_Gameplay.TriggerVolume SFMedical_Trigger;
	UPROPERTY()						ATriggerVolume* SFEngineer_Trigger;						//var AGP_Gameplay.TriggerVolume SFEngineer_Trigger;
	UPROPERTY()						ATriggerVolume* SFWeapons_Trigger;						//var AGP_Gameplay.TriggerVolume SFWeapons_Trigger;
	UPROPERTY()						ATriggerVolume* SFSergeant_Trigger;						//var AGP_Gameplay.TriggerVolume SFSergeant_Trigger;
	UPROPERTY()						ATriggerVolume* SFCommander_Trigger;					//var AGP_Gameplay.TriggerVolume SFCommander_Trigger;
	UPROPERTY()						ATriggerVolume* SFLeader_Trigger;						//var AGP_Gameplay.TriggerVolume SFLeader_Trigger;
	UPROPERTY()						AMedExam* SFExamOne;									//var AGP_Gameplay.MedExam SFExamOne;
	//UPROPERTY()						AAGP_Trigger* SeatVolumeOne;							//var AGP_Gameplay.AGP_Trigger SeatVolumeOne;
	UPROPERTY()						ATriggerVolume* TestVolumeOne;							//var AGP_Gameplay.TriggerVolume TestVolumeOne;
	UPROPERTY()						ATriggerVolume* LeavingVolumeOne;						//var AGP_Gameplay.TriggerVolume LeavingVolumeOne;
	UPROPERTY()						AAGP_UseTrigger* SeatTriggerOne;						//var AGP.AGP_UseTrigger SeatTriggerOne;
	//UPROPERTY()						ASlideProjector* SlideProjectorOne;						//var SlideProjector SlideProjectorOne;
	UPROPERTY()						ANPC_MedInstructor* InstructorOne;						//var AGP_Characters.NPC_MedInstructor InstructorOne;
	UPROPERTY()						AAGP_UseTrigger* InstructorTriggerOne;					//var AGP.AGP_UseTrigger InstructorTriggerOne;
	//UPROPERTY()						ADoorTrigger* DoorTriggerOne;							//var AGP_Gameplay.DoorTrigger DoorTriggerOne;


};
