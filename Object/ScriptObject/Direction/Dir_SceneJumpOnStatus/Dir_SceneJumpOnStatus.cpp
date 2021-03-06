// All the original content belonged to the US Army

#include "AA29/Object/ScriptObject/Direction/Dir_SceneJumpOnStatus/Dir_SceneJumpOnStatus.h"
#include "AA29/Object/Actor/Controller/PlayerController/HumanController/HumanController.h"
#include "AA29/Object/Actor/HUD/AGP_HUD/AGP_HUD.h"

UDir_SceneJumpOnStatus::UDir_SceneJumpOnStatus()
{
	_nNumParamsDefined = 2;
}

void UDir_SceneJumpOnStatus::Destroyed()
{
	Super::Destroyed();
	_HumanController = nullptr;
}

void UDir_SceneJumpOnStatus::DirectionStart()
{
	/*
	if (_bDebug)
	{
		Log("Dir_SceneJumpOnStatus::DirectionStart()");
	}
	if (_HumanController != nullptr)
	{
		if (Cast<AAGP_HUD>(_HumanController.myHUD) != nullptr)
		{
			if (Cast<AAGP_HUD>(_HumanController.myHUD).mrFrame != nullptr)
			{
				if (Cast<AAGP_HUD>(_HumanController.myHUD).mrFrame.ShouldRestartScene())
				{
					if (Cast<AAGP_HUD>(_HumanController.myHUD).mrFrame.DidPlayerPass())
					{
						if (_bDebug)
						{
							Log("Dir_SceneJumpOnStatus::DirectionStart() - player passed - jumping to scene " + FString::FromInt(_PassScene));
						}
						if (_ParentScreenplay != nullptr)
						{
							_ParentScreenplay.SceneJump(_PassScene);
							return;
						}
					}
					else
					{
						if (_bDebug)
						{
							Log("Dir_SceneJumpOnStatus::DirectionStart() - player failed - jumping to scene " + FString::FromInt(_FailScene));
						}
						if (_ParentScreenplay != nullptr)
						{
							_ParentScreenplay.SceneJump(_FailScene);
							return;
						}
					}
				}
				else
				{
					if (_bDebug)
					{
						Log("Dir_SceneJumpOnStatus::DirectionStart() - calling SceneEnd");
					}
					_ParentScreenplay.SceneEnd();
					return;
				}
			}
		}
	}
	if (_bDebug)
	{
		Log("Dir_SceneJumpOnStatus::DirectionStart() FAILED");
	}
	*/
}

bool UDir_SceneJumpOnStatus::ProcessParams()
{
	/*
	_HumanController = Cast<AHumanController>(_ParentScreenplay.GetHumanController());
	_PassScene = FString::FromInt(GetParam(0));
	_FailScene = FString::FromInt(GetParam(1));
	*/
	return true;
}
