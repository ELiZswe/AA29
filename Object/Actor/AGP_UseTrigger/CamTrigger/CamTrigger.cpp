// All the original content belonged to the US Army

#include "AA29/Object/Actor/AGP_UseTrigger/CamTrigger/CamTrigger.h"
#include "AA29/Object/Actor/Controller/PlayerController/HumanController/HumanController.h"

ACamTrigger::ACamTrigger()
{
	UseFOV = 85;
	bUseTriggered = true;
	SwitchState = "Viewing_RemoteCam";
	//HUDCamOverlay = Texture'T_AA2_FX.Overlay.fx2_overlay_monitor_a';
	HUDCamOverlay = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_FX/Overlay/fx2_overlay_monitor_a_Mat.fx2_overlay_monitor_a_Mat'"), NULL, LOAD_None, NULL);
	Texture = LoadObject<UTexture2D>(NULL, TEXT("Texture2D'/Game/AmericasArmy/Textures/AGP_Gameplay/S_CamTrigger.S_CamTrigger'"), NULL, LOAD_None, NULL);
	LoadEditorIcon();

	//bBlockNonZeroExtentTraces = true;
}

void ACamTrigger::SetActive(bool Active)
{
	bActive = Active;
}

bool ACamTrigger::IsActive()
{
	return bActive;
}

void ACamTrigger::Trigger(AActor* Other, APawn* EventInstigator)
{
	AActor* A = nullptr;
	if (!bActive)
	{
		return;
	}
	/*
	HC = Cast<AHumanController>(EventInstigator.Controller);
	if (IsError())
	{
		return;
	}
	A = GetActorByTag(ViewActorTag);
	if (A != nullptr)
	{
		HC.SetCamera(GetActorByTag(ViewActorTag), HUDCamOverlay);
		HC.SetFOVAngle(float(UseFOV));
		HC.GotoState(SwitchState);
		TriggerEvent(Event, this, EventInstigator);
	}
	else
	{
		Log("CamTrigger::Trigger(): Error: Can't find actor with tag: " + FString::FromInt(ViewActorTag));
		return;
	}
	*/
}

bool ACamTrigger::UsedBy(APawn* User)
{
	/*
	if (((!bActive) || (!bUseTriggered)) || (User.Physics != 1))
	{
		return false;
	}
	*/
	Trigger(nullptr, User);
	return true;
}

bool ACamTrigger::IsError()
{
	if (HC == nullptr)
	{
		//Log("CamTrigger::IsError(): ERROR: Invalid HumanController in Pawn");
		return true;
	}
	if (ViewActorTag == "None")
	{
		//Log("CamTrigger::IsError(): ERROR: ViewActorTag == nullptr");
		return true;
	}
	return false;   //FAKE   /ELIZ
}
