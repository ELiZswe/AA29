// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/AAGUIPage/AAGameMenu/AAGameMenuVAE/AAGameMenuVAE.h"
#include "AA29/Object/GUI/GUIComponent/GUIComponent.h"
#include "AA29/Object/Interactions/Interaction/BaseGUIController/GUIController/GUIController.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIButton.h"
#include "AA29/Object/Actor/Controller/PlayerController/HumanController/StudentController/StudentController.h"
#include "AA29/Object/Actor/Controller/PlayerController/HumanController/HumanController.h"

UAAGameMenuVAE::UAAGameMenuVAE()
{
}

void UAAGameMenuVAE::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	AStudentController* SC = nullptr;
	Super::InitComponent(MyController, MyOwner);
	SC = Cast<AStudentController>(PlayerOwner());
	if (SC == nullptr)
	{
		return;
	}
	b_Leave->Caption = "LEAVE VAE";
}

bool UAAGameMenuVAE::ButtonClick(UGUIComponent* Sender)
{
	int32 iPoster = 0;
	/*
	if (Sender == b_Leave)
	{
		Log("Building VAE mission complete message");
		Cast<AHumanController>(PlayerOwner())->iTour = 19;
		Cast<AHumanController>(PlayerOwner())->iMission = 0;
		Cast<AStudentController>(PlayerOwner()).SetAuthMissionPassFlag(true);
		Cast<AStudentController>(PlayerOwner()).ResetAuthExtraMissionData();
		if (Cast<AStudentController>(PlayerOwner()).fpVAETimeLanyardTaken > 0)
		{
			if (Cast<AStudentController>(PlayerOwner()).fpVAETimeLanyardReturned > 0)
			{
				Cast<AStudentController>(PlayerOwner()).AddAuthExtraMissionData("VAETime" + ":" + FString::FromInt((Cast<AStudentController>(PlayerOwner()).fpVAETimeLanyardReturned - Cast<AStudentController>(PlayerOwner()).fpVAETimeLanyardTaken)));
			}
			else
			{
				Cast<AStudentController>(PlayerOwner()).AddAuthExtraMissionData("VAETime" + ":-" + FString::FromInt((Cast<AStudentController>(PlayerOwner()).GetWorld()->GetTimeSeconds() - Cast<AStudentController>(PlayerOwner()).fpVAETimeLanyardTaken)));
			}
		}
		else
		{
			Cast<AStudentController>(PlayerOwner()).AddAuthExtraMissionData("VAETime" + ":0");
		}
		for (iPoster = 0; iPoster < Cast<AStudentController>(PlayerOwner()).avaepviPosterTracking.Num(); iPoster++)
		{
			Cast<AStudentController>(PlayerOwner()).AddAuthExtraMissionData(Cast<AStudentController>(PlayerOwner()).avaepviPosterTracking[iPoster].sPosterMaterial + ":" + FString::FromInt(Cast<AStudentController>(PlayerOwner()).avaepviPosterTracking[iPoster].fpViewingTime));
		}
		Log("Transmitting mission complete");
		Cast<AHumanController>(PlayerOwner())->DisplayVAECompleteMessage();
	}
	else
	{
		return Super::ButtonClick(Sender);
	}
	*/
	return true;
}
