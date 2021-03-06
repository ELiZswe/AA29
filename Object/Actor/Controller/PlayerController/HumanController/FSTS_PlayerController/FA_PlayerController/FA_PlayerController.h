// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Controller/PlayerController/HumanController/FSTS_PlayerController/FSTS_PlayerController.h"
#include "FA_PlayerController.generated.h"

class AFA_EL_MasterScript;

UCLASS()
class AFA_PlayerController : public AFSTS_PlayerController
{
	GENERATED_BODY()
public:
	AFA_PlayerController();
	
	UPROPERTY()			AFA_EL_MasterScript*			FAMasterScript;		//var FA_EL_MasterScript FAMasterScript;

	void Fire(float F);
	void Crouching();
	void Crawling();
	void CrouchEvent();
	void CrawlEvent();
	void MannequinTrace(AActor* HitActor, FBoneInfo HitBone);
	void MedicalPickupTrace(AActor* HitActor);
	void SetMasterScriptEventLab();
};
