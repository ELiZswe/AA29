// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/EventLab/EventLab.h"
#include "EL_MedicTrainingTwo.generated.h"

class AMedExam;
class AAGP_Trigger;
class ANPC_MedInstructor;
class ADoorTrigger;

UCLASS()
class AEL_MedicTrainingTwo : public AEventLab
{
	GENERATED_BODY()
public:
	AEL_MedicTrainingTwo();

	UPROPERTY()		bool bInstUseDisable;					//var bool bInstUseDisable;
	UPROPERTY()		int32 Grade;							//var int Grade;
	UPROPERTY()		int32 LookCount;						//var int LookCount;
	UPROPERTY()		int32 GoofCount;						//var int GoofCount;
	UPROPERTY()		int32 InstructorUseCount;				//var int InstructorUseCount;
	UPROPERTY()		AMedExam* MedExamTwo;					//var AGP_Gameplay.MedExam MedExamTwo;
	UPROPERTY()		AAGP_Trigger* SeatVolumeTwo;			//var AGP_Gameplay.AGP_Trigger SeatVolumeTwo;
	UPROPERTY()		ATriggerVolume* TestVolumeTwo;			//var AGP_Gameplay.TriggerVolume TestVolumeTwo;
	UPROPERTY()		ATriggerVolume* LeavingVolumeTwo;		//var AGP_Gameplay.TriggerVolume LeavingVolumeTwo;
	UPROPERTY()		ATriggerVolume* ClassVolumeTwo;			//var AGP_Gameplay.TriggerVolume ClassVolumeTwo;
	UPROPERTY()		AAGP_UseTrigger* SeatTriggerTwo;		//var AGP.AGP_UseTrigger SeatTriggerTwo;
	//UPROPERTY()	ASlideProjector* SlideProjectorTwo;		//var SlideProjector SlideProjectorTwo;
	UPROPERTY()		ANPC_MedInstructor* InstructorTwo;		//var AGP_Characters.NPC_MedInstructor InstructorTwo;
	UPROPERTY()		AAGP_UseTrigger* InstructorTriggerTwo;	//var AGP.AGP_UseTrigger InstructorTriggerTwo;
	UPROPERTY()		ADoorTrigger* DoorTriggerThree;			//var AGP_Gameplay.DoorTrigger DoorTriggerThree;
	UPROPERTY()		ADoorTrigger* DoorTriggerTwo;			//var AGP_Gameplay.DoorTrigger DoorTriggerTwo;

};
