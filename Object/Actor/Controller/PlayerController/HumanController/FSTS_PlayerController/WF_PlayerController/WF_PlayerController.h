// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Controller/PlayerController/HumanController/FSTS_PlayerController/FSTS_PlayerController.h"
#include "WF_PlayerController.generated.h"

UCLASS()
class AWF_PlayerController : public AFSTS_PlayerController
{
	GENERATED_BODY()
public:
	AWF_PlayerController();
	
	UPROPERTY()		bool	bBlockCrawlingChanges;			//var bool bBlockCrawlingChanges;

	void Crouching();
	void Crawling();
};
