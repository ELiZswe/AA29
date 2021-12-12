// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/EventLab/EventLab.h"
#include "EL_SFTrainingOne.generated.h"

class AAGP_Location;
class ACameraPoint;
class ANPC_Ambient;
class AMedExam;
class ANPC_MedInstructor;
class ARelayTrigger;
class ASlideProjector;

UCLASS()
class AEL_SFTrainingOne : public AEventLab
{
	GENERATED_BODY()
public:
	AEL_SFTrainingOne();

	UPROPERTY()						bool bHackSkipSlides;									//var bool bHackSkipSlides;
	UPROPERTY()						bool bHackChopper;										//var bool bHackChopper;
	UPROPERTY()						ACameraPoint* ChopperCam01;								//var AGP_Gameplay.CameraPoint ChopperCam01;
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
	UPROPERTY()						ARelayTrigger* Truck1;									//var AGP_Gameplay.RelayTrigger Truck1;
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
	UPROPERTY()						ATriggerVolume* TruckSplineTrigger;						//var ATriggerVolume* TruckSplineTrigger;
	UPROPERTY()						ATriggerVolume* SodaGuy_Trigger;						//var ATriggerVolume* SodaGuy_Trigger;
	UPROPERTY()						ATriggerVolume* SFIntelligence_Trigger;					//var ATriggerVolume* SFIntelligence_Trigger;
	UPROPERTY()						ATriggerVolume* SFCommunication_Trigger;				//var ATriggerVolume* SFCommunication_Trigger;
	UPROPERTY()						ATriggerVolume* SFMedical_Trigger;						//var ATriggerVolume* SFMedical_Trigger;
	UPROPERTY()						ATriggerVolume* SFEngineer_Trigger;						//var ATriggerVolume* SFEngineer_Trigger;
	UPROPERTY()						ATriggerVolume* SFWeapons_Trigger;						//var ATriggerVolume* SFWeapons_Trigger;
	UPROPERTY()						ATriggerVolume* SFSergeant_Trigger;						//var ATriggerVolume* SFSergeant_Trigger;
	UPROPERTY()						ATriggerVolume* SFCommander_Trigger;					//var ATriggerVolume* SFCommander_Trigger;
	UPROPERTY()						ATriggerVolume* SFLeader_Trigger;						//var ATriggerVolume* SFLeader_Trigger;
	UPROPERTY()						AMedExam* SFExamOne;									//var AGP_Gameplay.MedExam SFExamOne;
	UPROPERTY()						AAGP_Trigger* SeatVolumeOne;							//var AAGP_Trigger* SeatVolumeOne;
	UPROPERTY()						ATriggerVolume* TestVolumeOne;							//var ATriggerVolume* TestVolumeOne;
	UPROPERTY()						ATriggerVolume* LeavingVolumeOne;						//var ATriggerVolume* LeavingVolumeOne;
	UPROPERTY()						AAGP_UseTrigger* SeatTriggerOne;						//var AGP.AGP_UseTrigger SeatTriggerOne;
	UPROPERTY()						ASlideProjector* SlideProjectorOne;						//var SlideProjector SlideProjectorOne;
	UPROPERTY()						ANPC_MedInstructor* InstructorOne;						//var AGP_Characters.NPC_MedInstructor InstructorOne;
	UPROPERTY()						AAGP_UseTrigger* InstructorTriggerOne;					//var AGP.AGP_UseTrigger InstructorTriggerOne;
	UPROPERTY()						ADoorTrigger* DoorTriggerOne;							//var ADoorTrigger* DoorTriggerOne;

	bool AGP_UseTrigger_UsedBy(AAGP_UseTrigger* Trigger, AActor* aInstigator);
	bool SeatTriggerOne_UsedBy(AAGP_UseTrigger* Trigger, AActor* aInstigator);
	bool InstructorTriggerOne_UsedBy(AAGP_UseTrigger* Trigger, AActor* aInstigator);
	bool AGP_Trigger_Trigger(AAGP_Trigger* Trigger, AActor* aInstigator);
	bool AGP_Trigger_UnTrigger(AAGP_Trigger* Trigger, AActor* aInstigator);
	bool SeatVolumeOne_Trigger(AAGP_Trigger* Trigger, AActor* aInstigator);
	bool SeatVolumeOne_UnTrigger(AAGP_Trigger* Trigger, AActor* aInstigator);
	bool DoorTrigger_UsedBy(ADoorTrigger* Trigger, AActor* aInstigator);
	bool DoorTriggerOne_UsedBy(ADoorTrigger* Trigger, AActor* aInstigator);
	bool TriggerVolume_Enter(ATriggerVolume* Trigger, AActor* aInstigator);
	bool ClassVolumeOne_Enter(ATriggerVolume* Trigger, AActor* aInstigator);
	bool LeavingVolumeOne_Enter(ATriggerVolume* Trigger, AActor* aInstigator);
	bool TestVolumeOne_Enter(ATriggerVolume* Trigger, AActor* aInstigator);
	bool SFLeader_Trigger_Enter(ATriggerVolume* Trigger, AActor* aInstigator);
	bool SFCommander_Trigger_Enter(ATriggerVolume* Trigger, AActor* aInstigator);
	bool SFSergeant_Trigger_Enter(ATriggerVolume* Trigger, AActor* aInstigator);
	bool SFWeapons_Trigger_Enter(ATriggerVolume* Trigger, AActor* aInstigator);
	bool SFEngineer_Trigger_Enter(ATriggerVolume* Trigger, AActor* aInstigator);
	bool SFMedical_Trigger_Enter(ATriggerVolume* Trigger, AActor* aInstigator);
	bool SFCommunication_Trigger_Enter(ATriggerVolume* Trigger, AActor* aInstigator);
	bool SFIntelligence_Trigger_Enter(ATriggerVolume* Trigger, AActor* aInstigator);
	void PreInit();
	void Init();
	void PostInit();
	void PostPostInit();
	FRotator RandLookRotation();
	bool SodaGuy_Trigger_Enter(ATriggerVolume* Trigger, AActor* aInstigator);
	bool OutOfBounds_Trigger_Enter(ATriggerVolume* Trigger, AActor* aInstigator);
	bool DeskVolumeOne_Trigger(AAGP_Trigger* Trigger, AActor* aInstigator);
	bool GlobalTimer(FName Name);
	int32 GetCrypticValue();
	bool DemoCompleted();
	int32 RemainingConversations();
	void ConversationEvent();
	void StopLipSincAnims();
};
