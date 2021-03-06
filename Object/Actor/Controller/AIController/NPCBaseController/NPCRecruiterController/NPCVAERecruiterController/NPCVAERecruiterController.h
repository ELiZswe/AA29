// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Controller/AIController/NPCBaseController/NPCRecruiterController/NPCRecruiterController.h"
#include "NPCVAERecruiterController.generated.h"

class AStudentController;

UCLASS()
class ANPCVAERecruiterController : public ANPCRecruiterController
{
	GENERATED_BODY()
public:
	ANPCVAERecruiterController();

	UPROPERTY()			float					fpVertCollisionOffsetDown;				//var float fpVertCollisionOffsetDown;
	UPROPERTY()			bool					bGivesLanyards;							//var bool bGivesLanyards;
	UPROPERTY()			AStudentController*		scPlayer;								//var StudentController scPlayer;
	UPROPERTY()			AActor*					ivaelLanyard;							//var Actor ivaelLanyard;
	UPROPERTY()			bool					bDebug;									//var bool bDebug;
	UPROPERTY()			FName					nameVAEBlockingNPC;						//var FName nameVAEBlockingNPC;

	void PostBeginPlay();
	bool UsedBy(APawn* User);
	void FocusOnPlayer(APawn* Player);
	void LoseFocusOnPlayer();
	void BackupAfterBump(APawn* pawnBumpedInto);
	//void Possess(APawn* aPawn);
	void NotifyPlayerPawnWatchingMe(APawn* pawnSeen);
};
