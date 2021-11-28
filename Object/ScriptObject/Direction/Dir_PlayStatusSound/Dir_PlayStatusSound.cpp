// All the original content belonged to the US Army


#include "AA29/Object/ScriptObject/Direction/Dir_PlayStatusSound/Dir_PlayStatusSound.h"

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
	if (_HumanController != None)
	{
		if (AGP_HUD(_HumanController.myHUD) != None)
		{
			if (AGP_HUD(_HumanController.myHUD).mrFrame != None)
			{
				Sound = AGP_HUD(_HumanController.myHUD).mrFrame.GetStatusSound();
				if (Sound != None)
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

