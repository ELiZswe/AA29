// All the original content belonged to the US Army

#include "AA29/Object/Actor/Controller/PlayerController/HumanController/FSTS_PlayerController/WF_PlayerController/WF_PlayerController.h"

AWF_PlayerController::AWF_PlayerController()
{

}

void AWF_PlayerController::Crouching()
{
	bool bOldLockMovement = false;
	bool bOldLockRotation = false;
	//bOldLockMovement = GetLockMovement();
	//bOldLockRotation = GetLockRotation();
	//LockPlayer(false, false);
	//Super::Crouching();
	//LockPlayer(bOldLockMovement, bOldLockRotation);
}

void AWF_PlayerController::Crawling()
{
	bool bOldLockMovement = false;
	bool bOldLockRotation = false;
	if (bBlockCrawlingChanges)
	{
		return;
	}
	//bOldLockMovement = GetLockMovement();
	//bOldLockRotation = GetLockRotation();
	//LockPlayer(false, false);
	//Super::Crawling();
	//LockPlayer(bOldLockMovement, bOldLockRotation);
}

