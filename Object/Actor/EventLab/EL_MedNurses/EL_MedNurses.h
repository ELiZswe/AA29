// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/EventLab/EventLab.h"
#include "EL_MedNurses.generated.h"

class ANPC_Nurse;
class ADoorTrigger;
class AAGP_UseTrigger;
class AAGP_Trigger;

UCLASS()
class AA29_API AEL_MedNurses : public AEventLab
{
	GENERATED_BODY()
public:
	AEL_MedNurses();

	UPROPERTY()						int32 ConversationCount;								//var int ConversationCount;
	UPROPERTY()						int32 NicholeUseCount;									//var int NicholeUseCount;
	UPROPERTY()						int32 JoanneUseCount;									//var int JoanneUseCount;
	UPROPERTY()						AAGP_Trigger* JoanneTouch;								//var AGP_Gameplay.AGP_Trigger JoanneTouch;
	UPROPERTY()						AAGP_UseTrigger* NicholeTrigger;						//var AGP.AGP_UseTrigger NicholeTrigger;
	UPROPERTY()						AAGP_UseTrigger* JoanneTrigger;							//var AGP.AGP_UseTrigger JoanneTrigger;
	UPROPERTY()						ADoorTrigger* NurseCloset2;								//var AGP_Gameplay.DoorTrigger NurseCloset2;
	UPROPERTY()						ADoorTrigger* NurseCloset1;								//var AGP_Gameplay.DoorTrigger NurseCloset1;
	UPROPERTY()						ANPC_Nurse* Nichole;									//var AGP_Characters.NPC_Nurse Nichole;
	UPROPERTY()						ANPC_Nurse* Joanne;										//var AGP_Characters.NPC_Nurse Joanne;
};
