// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/EventLab/EventLab.h"
#include "EL_MedicTrainingThree.generated.h"

class AMedExam;
class AAGP_Trigger;
class ANPC_MedInstructor;
class ADoorTrigger;

UCLASS()
class AEL_MedicTrainingThree : public AEventLab
{
	GENERATED_BODY()
public:
	AEL_MedicTrainingThree();


	UPROPERTY()		bool bInstUseDisable;						//var bool bInstUseDisable;
	UPROPERTY()		int32 Grade;								//var int Grade;
	UPROPERTY()		int32 LookCount;							//var int LookCount;
	UPROPERTY()		int32 GoofCount;							//var int GoofCount;
	UPROPERTY()		int32 InstructorUseCount;					//var int InstructorUseCount;
	UPROPERTY()		AMedExam* MedExamThree;						//var AGP_Gameplay.MedExam MedExamThree;
	UPROPERTY()		AMedExam* MedExamTwo;						//var AGP_Gameplay.MedExam MedExamTwo;
	UPROPERTY()		AMedExam* MedExamOne;						//var AGP_Gameplay.MedExam MedExamOne;
	UPROPERTY()		AAGP_Trigger* SeatVolumeThree;				//var AGP_Gameplay.AGP_Trigger SeatVolumeThree;
	UPROPERTY()		ATriggerVolume* TestVolumeThree;			//var AGP_Gameplay.TriggerVolume TestVolumeThree;
	UPROPERTY()		ATriggerVolume* LeavingVolumeThree;			//var AGP_Gameplay.TriggerVolume LeavingVolumeThree;
	UPROPERTY()		ATriggerVolume* ClassVolumeThree;			//var AGP_Gameplay.TriggerVolume ClassVolumeThree;
	UPROPERTY()		AAGP_UseTrigger* SeatTriggerThree;			//var AGP.AGP_UseTrigger SeatTriggerThree;
	//UPROPERTY()		ASlideProjector* SlideProjectorThree;		//var SlideProjector SlideProjectorThree;
	UPROPERTY()		ANPC_MedInstructor* InstructorThree;		//var AGP_Characters.NPC_MedInstructor InstructorThree;
	UPROPERTY()		AAGP_UseTrigger* InstructorTriggerThree;	//var AGP.AGP_UseTrigger InstructorTriggerThree;
	UPROPERTY()		ADoorTrigger* DoorTriggerThree;				//var AGP_Gameplay.DoorTrigger DoorTriggerThree;
	//UPROPERTY()		AStaticMeshSwitcher* LightSwitchThree;		//var AGP_Gameplay.StaticMeshSwitcher LightSwitchThree;
};
