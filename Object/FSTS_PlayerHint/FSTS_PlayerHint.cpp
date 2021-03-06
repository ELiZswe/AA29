// All the original content belonged to the US Army

#include "AA29/Object/FSTS_PlayerHint/FSTS_PlayerHint.h"
#include "AA29/Object/Actor/EventLab/EventLab.h"
#include "AA29/Object/Actor/EventLab/FSTS_EventLab/FSTS_EventLab.h"

UFSTS_PlayerHint::UFSTS_PlayerHint()
{
	MsgTxt1 = "Default Message";
	TimeToDisplay = 5;
	TimeLastDisplayed = -1;
	TimeBeforeRedisplay = 20;
	bDisplayOnlyOnce = true;
	bRemoveWhenSatisfied = true;
	//__IsAppropriate__Delegate = "FSTS_PlayerHint.Always";
	//__IsSatisfied__Delegate = "FSTS_PlayerHint.Never";
}

bool UFSTS_PlayerHint::IsAppropriate()
{
	return true;   //FAKE   /ELiZ
}

bool UFSTS_PlayerHint::IsSatisfied()
{
	return true;   //FAKE   /ELiZ
}

bool UFSTS_PlayerHint::StartDisplay()
{
	/*
	if (TimeBeforeDisplay > 0)
	{
		if (TimeDelayStarted == 0)
		{
			TimeDelayStarted = MyEventlab.GetWorld()->GetTimeSeconds();
			return false;
		}
		else
		{
			if (MyEventlab.GetWorld()->GetTimeSeconds() - TimeDelayStarted > TimeBeforeDisplay)
			{
				return false;
			}
		}
	}
	if (TimeBeforeRedisplay > 0 && bHasDisplayed)
	{
		if (MyEventlab.GetWorld()->GetTimeSeconds() - TimeLastDisplayed < TimeBeforeRedisplay)
		{
			return false;
		}
	}
	if (IsAppropriate() && !IsSatisfied())
	{
		MyEventlab.PlayTip(MsgTxt1, MsgTxt2, TimeToDisplay);
		TimeLastDisplayed = MyEventlab.GetWorld()->GetTimeSeconds();
		bHasDisplayed = true;
		bIsDisplaying = true;
		if (LSMessage.Num() > 0)
		{
			EL_VehicleTraining(MyEventlab).PlayLSMessage(LSMessage[Rand(LSMessage.Num())]);
		}
		return true;
	}
	else
	{
		return false;
	}
	*/
	return false;   //FAKE   /ELiZ
}
bool UFSTS_PlayerHint::ContinueDisplay()
{
	/*
	if (MyEventlab.GetWorld()->GetTimeSeconds() - TimeLastDisplayed < TimeToDisplay + 1 && IsAppropriate() && !IsSatisfied())
	{
		return true;
	}
	else
	{
		if (IsSatisfied() && SatisfiedLSMessage.Num() > 0)
		{
			EL_VehicleTraining(MyEventlab).PlayLSMessage(SatisfiedLSMessage[Rand(SatisfiedLSMessage.Num())]);
		}
		MyEventlab.PlayTip("", "", 0);
		bIsDisplaying = false;
		if (bDisplayOnlyOnce || IsSatisfied() && bRemoveWhenSatisfied && FSTS_EventLab(MyEventlab) != nullptr)
		{
			FSTS_EventLab(MyEventlab).RemoveHint(this);
		}
		return false;
	}
	*/
	return false;
}

void UFSTS_PlayerHint::Reset()
{
	/*
	if (Cast<AFSTS_EventLab>(MyEventlab) != nullptr)
	{
		FSTS_EventLab(MyEventlab).RemoveHint(this);
	}
	bHasDisplayed = false;
	bIsDisplaying = false;
	TimeDelayStarted = 0;
	TimeLastDisplayed = -1;
	*/
}

bool UFSTS_PlayerHint::Always()
{
	return true;
}

bool UFSTS_PlayerHint::Never()
{
	return false;
}
