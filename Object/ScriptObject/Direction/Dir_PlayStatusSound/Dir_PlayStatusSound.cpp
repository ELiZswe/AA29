// All the original content belonged to the US Army

#include "AA29/Object/ScriptObject/Direction/Dir_PlayStatusSound/Dir_PlayStatusSound.h"
#include "AA29/Object/Actor/Controller/PlayerController/HumanController/HumanController.h"
#include "AA29/Object/Actor/HUD/AGP_HUD/AGP_HUD.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Pawn.h"

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
	USoundBase* Sound = nullptr;
	if (_bDebug)
	{
		//Log("Dir_PlayStatusSound::DirectionStart()");
	}
	if (_HumanController != nullptr)
	{
		if (Cast<AAGP_HUD>(_HumanController->MyHUD) != nullptr)
		{
			if (Cast<AAGP_HUD>(_HumanController->MyHUD)->mrFrame != nullptr)
			{
				//Sound = Cast<AAGP_HUD>(_HumanController->MyHUD)->mrFrame->GetStatusSound();
				if (Sound != nullptr)
				{
					//Cast<AAGP_Pawn>(_HumanController->Pawn)->PlaySound(Sound);
					//_HumanController.ScreenPrint(string(Sound) + " " + FString::FromInt(Sound.Name));
					return;
				}
			}
		}
	}
	if (_bDebug)
	{
		//Log("Dir_PlayStatusSound::DirectionStart() FAILED");
	}
}

bool UDir_PlayStatusSound::ProcessParams()
{
	//_HumanController = Cast<AHumanController>(_ParentScreenplay.GetHumanController());
	return true;
}

