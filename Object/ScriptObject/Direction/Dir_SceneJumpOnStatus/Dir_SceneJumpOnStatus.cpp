// All the original content belonged to the US Army


#include "AA29/Object/ScriptObject/Direction/Dir_SceneJumpOnStatus/Dir_SceneJumpOnStatus.h"

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
	if (_HumanController != None)
	{
		if (AGP_HUD(_HumanController.myHUD) != None)
		{
			if (AGP_HUD(_HumanController.myHUD).mrFrame != None)
			{
				if (AGP_HUD(_HumanController.myHUD).mrFrame.ShouldRestartScene())
				{
					if (AGP_HUD(_HumanController.myHUD).mrFrame.DidPlayerPass())
					{
						if (_bDebug)
						{
							Log("Dir_SceneJumpOnStatus::DirectionStart() - player passed - jumping to scene " $ string(_PassScene));
						}
						if (_ParentScreenplay != None)
						{
							_ParentScreenplay.SceneJump(_PassScene);
							return;
						}
					}
					else
					{
						if (_bDebug)
						{
							Log("Dir_SceneJumpOnStatus::DirectionStart() - player failed - jumping to scene " $ string(_FailScene));
						}
						if (_ParentScreenplay != None)
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
	_HumanController = HumanController(_ParentScreenplay.GetHumanController());
	_PassScene = string(GetParam(0));
	_FailScene = string(GetParam(1));
	*/
	return true;
}