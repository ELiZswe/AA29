// All the original content belonged to the US Army

#include "AA29/Object/ScriptObject/Direction/Dir_PlayStatusSound/Dir_PlayStatusSound.h"
#include "AA29/Object/Actor/Controller/PlayerController/HumanController/HumanController.h"

UDir_PlayStatusSound::UDir_PlayStatusSound()
{

}

void UDir_PlayStatusSound::Destroyed()
{
	Super::Destroyed();
	_HumanController = nullptr;
}

void UDir_PlayStatusSound::DirectionStart()
{
	/*
	local Sound Sound;
	if (_bDebug)
	{
		Log("Dir_PlayStatusSound::DirectionStart()");
	}
	if (_HumanController != nullptr)
	{
		if (AGP_HUD(_HumanController.myHUD) != nullptr)
		{
			if (AGP_HUD(_HumanController.myHUD).mrFrame != nullptr)
			{
				Sound = AGP_HUD(_HumanController.myHUD).mrFrame.GetStatusSound();
				if (Sound != nullptr)
				{
					AGP_Pawn(_HumanController.Pawn).PlaySound(Sound);
					_HumanController.ScreenPrint(string(Sound) $ " " $ string(Sound.Name));
					return;
				}
			}
		}
	}
	if (_bDebug)
	{
		Log("Dir_PlayStatusSound::DirectionStart() FAILED");
	}
	*/
}

bool UDir_PlayStatusSound::ProcessParams()
{
	//_HumanController = HumanController(_ParentScreenplay.GetHumanController());
	return true;
}

