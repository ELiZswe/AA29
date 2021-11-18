// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/EventLab/EventLab.h"
#include "EL_Rifle_Range.generated.h"

class ANPC_TowerObserver;
class ATriggerVolume;
class AAGP_Location;
class ANPC_DrillInstructor;

UCLASS()
class AA29_API AEL_Rifle_Range : public AEventLab
{
	GENERATED_BODY()
public:
	AEL_Rifle_Range();


	UPROPERTY()						float fadeoutTimer;												//var float fadeoutTimer;
	UPROPERTY()						bool InstructorMoved;											//var bool InstructorMoved;
	UPROPERTY()						AAGP_Location* locDrillStart;									//var AGP_Gameplay.AGP_Location locDrillStart;
	UPROPERTY()						AAGP_Location* TranslatePosition;								//var AGP_Gameplay.AGP_Location TranslatePosition;
	UPROPERTY()						ATriggerVolume* InstructorStart;								//var AGP_Gameplay.TriggerVolume InstructorStart;
	UPROPERTY()						ATriggerVolume* TranslateInstructor;							//var AGP_Gameplay.TriggerVolume TranslateInstructor;
	UPROPERTY()						ANPC_TowerObserver* pawnTower1;									//var AGP_Characters.NPC_TowerObserver pawnTower1;
	UPROPERTY()						ANPC_DrillInstructor* PawnInstructorTwo;						//var AGP_Characters.NPC_DrillInstructor PawnInstructorTwo;
	UPROPERTY()						ANPC_DrillInstructor* pawnInstructor;							//var AGP_Characters.NPC_DrillInstructor pawnInstructor;
	UPROPERTY()						bool bInstructorTranslate;										//var bool bInstructorTranslate;
};
