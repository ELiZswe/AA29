// All the original content belonged to the US Army


#include "AA29/Object/Actor/AGP_Trigger/StateSwitcher/StateSwitcher.h"

AStateSwitcher::AStateSwitcher()
{
	bReturnToOriginal = true;
	//RemoteRole = 2;

	Texture = LoadObject<UTexture2D>(NULL, TEXT("Texture2D'/Game/AmericasArmy/Textures/AGP_Gameplay/S_StateSwitcher.S_StateSwitcher'"), NULL, LOAD_None, NULL);
	LoadEditorIcon();
}



void AStateSwitcher::Trigger(AActor* Other, APawn* EventInstigator)
{
	//C = EventInstigator.Controller;

	if (IsError())
	{
		return;
	}
	if (!bSwitch)
	{
		OriginalState = C->GetStateName();
		//C->GotoState(SwitchState);
		if (bToggle)
		{
			bSwitch = true;
		}
	}
	else
	{
		if (bReturnToOriginal)
		{
			//C->GotoState(OriginalState);
		}
		else
		{
			//C->GotoState(ReturnState);
		}
		bSwitch = false;
	}
}
void AStateSwitcher::UnTrigger(AActor* Other, APawn* EventInstigator)
{
	//C = EventInstigator.Controller;
	if (IsError())
	{
		return;
	}
	if (bReturnToOriginal)
	{
		if (OriginalState != "None")
		{
			//GotoState(OriginalState);
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("StateSwitcher::UnTrigger(): ERROR: OriginalState is None"));
			return;
		}
	}
	else
	{
		//GotoState(ReturnState);
	}
}
bool AStateSwitcher::IsError()
{
	if (C == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("StateSwitcher::IsError(): ERROR: Invalid Controller in Pawn"));
		return true;
	}
	if (SwitchState == "None")
	{
		UE_LOG(LogTemp, Warning, TEXT("StateSwitcher::IsError(): ERROR: SwitchState is None"));
		return true;
	}
	if (ReturnState == "None" && !bReturnToOriginal && bToggle)
	{
		UE_LOG(LogTemp, Warning, TEXT("StateSwitcher::IsError(): ERROR: ReturnState is None"));
		return true;
	}
	return false;
}
