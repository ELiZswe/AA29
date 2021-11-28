// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/EventLab/EventLab.h"
#include "EL_MedicTrainingField.generated.h"

/**
 * 
 */
class ANPC_MedStudent;
class AAGP_TeamInfo;
class AAGP_Trigger;
class ANPC_MedInstructor;


UCLASS()
class AA29_API AEL_MedicTrainingField : public AEventLab
{
	GENERATED_BODY()
public:
	AEL_MedicTrainingField();

	UPROPERTY()		bool bDidPlayHealTip;					//var bool bDidPlayHealTip;
	UPROPERTY()		bool bInstGoodJob;					//var bool bInstGoodJob;
	UPROPERTY()		bool bWalterDidGroan;					//var bool bWalterDidGroan;
	UPROPERTY()		bool bJeffreyDidWarn;					//var bool bJeffreyDidWarn;
	UPROPERTY()		bool bWalterDidWarn;					//var bool bWalterDidWarn;
	UPROPERTY()		bool bJeffreyIsHealed;				//var bool bJeffreyIsHealed;
	UPROPERTY()		bool bWalterIsHealed;					//var bool bWalterIsHealed;
	UPROPERTY()		bool bDonnyIsHealed;					//var bool bDonnyIsHealed;
	UPROPERTY()		bool bIsHealing;						//var bool bIsHealing;
	UPROPERTY()		bool bWrongOrder;						//var bool bWrongOrder;
	UPROPERTY()		int32 HealCounter;					//var int HealCounter;
	UPROPERTY()		AAGP_TeamInfo* Team;					//var AGP_Gameplay.AGP_TeamInfo Team;
	UPROPERTY()		AAGP_Trigger* Jeffrey_Proximity;		//var AGP_Gameplay.AGP_Trigger Jeffrey_Proximity;
	UPROPERTY()		AAGP_Trigger* Walter_Proximity;		//var AGP_Gameplay.AGP_Trigger Walter_Proximity;
	UPROPERTY()		AAGP_Trigger* Donny_Proximity;		//var AGP_Gameplay.AGP_Trigger Donny_Proximity;
	UPROPERTY()		AAGP_Trigger* IncidentArea;			//var AGP_Gameplay.AGP_Trigger IncidentArea;
	UPROPERTY()		ANPC_MedInstructor* Instructor;		//var AGP_Characters.NPC_MedInstructor Instructor;
	UPROPERTY()		ANPC_MedStudent* Donny;				//var AGP_Characters.NPC_MedStudent Donny;
	UPROPERTY()		ANPC_MedStudent* Walter;				//var AGP_Characters.NPC_MedStudent Walter;
	UPROPERTY()		ANPC_MedStudent* Jeffrey;				//var AGP_Characters.NPC_MedStudent Jeffrey;
};
