// All the original content belonged to the US Army


#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/AAGUIPage/AAGameMenu/AAGameMenuVAE/AAGameMenuVAE.h"

UAAGameMenuVAE::UAAGameMenuVAE()
{
}


void UAAGameMenuVAE::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	/*
	local StudentController SC;
	Super::InitComponent(MyController, MyOwner);
	SC = StudentController(PlayerOwner());
	if (SC == None)
	{
		return;
	}
	b_Leave.Caption = "LEAVE VAE";
	*/
}

bool UAAGameMenuVAE::ButtonClick(UGUIComponent* Sender)
{
	/*
	local int32 iPoster;
	if (Sender == b_Leave)
	{
		Log("Building VAE mission complete message");
		HumanController(PlayerOwner()).iTour = 19;
		HumanController(PlayerOwner()).iMission = 0;
		StudentController(PlayerOwner()).SetAuthMissionPassFlag(true);
		StudentController(PlayerOwner()).ResetAuthExtraMissionData();
		if (StudentController(PlayerOwner()).fpVAETimeLanyardTaken > 0)
		{
			if (StudentController(PlayerOwner()).fpVAETimeLanyardReturned > 0)
			{
				StudentController(PlayerOwner()).AddAuthExtraMissionData("VAETime" $ ":" $ string((StudentController(PlayerOwner()).fpVAETimeLanyardReturned - StudentController(PlayerOwner()).fpVAETimeLanyardTaken)));
			}
			else
			{
				StudentController(PlayerOwner()).AddAuthExtraMissionData("VAETime" $ ":-" $ string((StudentController(PlayerOwner()).Level.TimeSeconds - StudentController(PlayerOwner()).fpVAETimeLanyardTaken)));
			}
		}
		else
		{
			StudentController(PlayerOwner()).AddAuthExtraMissionData("VAETime" $ ":0");
		}
		for (iPoster = 0; iPoster < StudentController(PlayerOwner()).avaepviPosterTracking.Length; iPoster++)
		{
			StudentController(PlayerOwner()).AddAuthExtraMissionData(StudentController(PlayerOwner()).avaepviPosterTracking[iPoster].sPosterMaterial $ ":" $ string(StudentController(PlayerOwner()).avaepviPosterTracking[iPoster].fpViewingTime));
		}
		Log("Transmitting mission complete");
		HumanController(PlayerOwner()).DisplayVAECompleteMessage();
	}
	else
	{
		return Super::ButtonClick(Sender);
	}
	*/
	return true;
}
