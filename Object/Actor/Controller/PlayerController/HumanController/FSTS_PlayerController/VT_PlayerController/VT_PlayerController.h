// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Controller/PlayerController/HumanController/FSTS_PlayerController/FSTS_PlayerController.h"
#include "VT_PlayerController.generated.h"

class AFSTS_EventLab;
UCLASS()
class AVT_PlayerController : public AFSTS_PlayerController
{
	GENERATED_BODY()
public:
	AVT_PlayerController();

	UPROPERTY()		AFSTS_EventLab*	SingleScript;			//var FSTS_EventLab SingleScript;

	void SetMasterScriptEventLab();
	void DrillSergeantUsed(AActor* Sarge);
	void ShowMenu();
};
