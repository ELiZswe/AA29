// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/EventLab/EventLab.h"
#include "EL_MedicTrainingOne.generated.h"

class ADoorTrigger;
class AMedExam;
class AAGP_Trigger;
class ANPC_MedInstructor;

UCLASS()
class AA29_API AEL_MedicTrainingOne : public AEventLab
{
	GENERATED_BODY()
public:
	AEL_MedicTrainingOne();

	UPROPERTY()   bool bInstUseDisable;          //var bool bInstUseDisable;
	UPROPERTY()   int32 Grade;          //var int Grade;
	UPROPERTY()   int32 LookCount;          //var int LookCount;
	UPROPERTY()   int32 GoofCount;          //var int GoofCount;
	UPROPERTY()   int32 InstructorUseCount;          //var int InstructorUseCount;
	UPROPERTY()   AMedExam* MedExamOne;          //var AGP_Gameplay.MedExam MedExamOne;
	UPROPERTY()   AAGP_Trigger* SeatVolumeOne;          //var AGP_Gameplay.AGP_Trigger SeatVolumeOne;
	UPROPERTY()   ATriggerVolume* TestVolumeOne;          //var AGP_Gameplay.TriggerVolume TestVolumeOne;
	UPROPERTY()   ATriggerVolume* LeavingVolumeOne;          //var AGP_Gameplay.TriggerVolume LeavingVolumeOne;
	UPROPERTY()   ATriggerVolume* ClassVolumeOne;          //var AGP_Gameplay.TriggerVolume ClassVolumeOne;
	UPROPERTY()   AAGP_UseTrigger* SeatTriggerOne;          //var AGP.AGP_UseTrigger SeatTriggerOne;
	//UPROPERTY()   ASlideProjector* SlideProjectorOne;          //var SlideProjector SlideProjectorOne;
	UPROPERTY()   ANPC_MedInstructor* InstructorOne;          //var AGP_Characters.NPC_MedInstructor InstructorOne;
	UPROPERTY()   AAGP_UseTrigger* InstructorTriggerOne;          //var AGP.AGP_UseTrigger InstructorTriggerOne;
	UPROPERTY()   ADoorTrigger* DoorTriggerTwo;          //var AGP_Gameplay.DoorTrigger DoorTriggerTwo;
	UPROPERTY()   ADoorTrigger* DoorTriggerOne;          //var AGP_Gameplay.DoorTrigger DoorTriggerOne;
};
