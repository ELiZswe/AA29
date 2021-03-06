// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Controller/AIController/NPCBaseController/NPCRecruiterController/NPCRecruiterController.h"
#include "NPCRealHeroController.generated.h"

class ARealHeroIcon;

UCLASS()
class ANPCRealHeroController : public ANPCRecruiterController
{
	GENERATED_BODY()
public:
	ANPCRealHeroController();

	UPROPERTY()			ARealHeroIcon*	RHI;							//var ARealHeroIcon* RHI;
	UPROPERTY()			float			fpVertCollisionOffsetDown;		//var float fpVertCollisionOffsetDown;
	UPROPERTY()			int32			MissionID;						//var int32 MissionID;

	void PostBeginPlay();
	bool UsedBy(APawn* User);
	void DimAlpha();
	void BrightenAlpha();
	void FocusOnPlayer(APawn* Player);
	void LoseFocusOnPlayer();
	void BackupAfterBump(APawn* pawnBumpedInto);
	//void Possess(APawn* aPawn);
	void NotifyPlayerPawnWatchingMe(APawn* pawnSeen);
};
