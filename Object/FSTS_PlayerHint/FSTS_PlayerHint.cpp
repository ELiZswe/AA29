// All the original content belonged to the US Army


#include "AA29/Object/FSTS_PlayerHint/FSTS_PlayerHint.h"

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
			TimeDelayStarted = MyEventlab.Level.TimeSeconds;
			return false;
		}
		else
		{
			if (MyEventlab.Level.TimeSeconds - TimeDelayStarted > TimeBeforeDisplay)
			{
				return false;
			}
		}
	}
	if (TimeBeforeRedisplay > 0 && bHasDisplayed)
	{
		if (MyEventlab.Level.TimeSeconds - TimeLastDisplayed < TimeBeforeRedisplay)
		{
			return false;
		}
	}
	if (IsAppropriate() && !IsSatisfied())
	{
		MyEventlab.PlayTip(MsgTxt1, MsgTxt2, TimeToDisplay);
		TimeLastDisplayed = MyEventlab.Level.TimeSeconds;
		bHasDisplayed = True;
		bIsDisplaying = True;
		if (LSMessage.Length > 0)
		{
			EL_VehicleTraining(MyEventlab).PlayLSMessage(LSMessage[Rand(LSMessage.Length)]);
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
	if (MyEventlab.Level.TimeSeconds - TimeLastDisplayed < TimeToDisplay + 1 && IsAppropriate() && !IsSatisfied())
	{
		return true;
	}
	else
	{
		if (IsSatisfied() && SatisfiedLSMessage.Length > 0)
		{
			EL_VehicleTraining(MyEventlab).PlayLSMessage(SatisfiedLSMessage[Rand(SatisfiedLSMessage.Length)]);
		}
		MyEventlab.PlayTip("", "", 0);
		bIsDisplaying = False;
		if (bDisplayOnlyOnce || IsSatisfied() && bRemoveWhenSatisfied && FSTS_EventLab(MyEventlab) != None)
		{
			FSTS_EventLab(MyEventlab).RemoveHint(Self);
		}
		return false;
	}
	*/
	return false;
}

void UFSTS_PlayerHint::Reset()
{
	/*
	if (FSTS_EventLab(MyEventlab) != None)
	{
		FSTS_EventLab(MyEventlab).RemoveHint(Self);
	}
	bHasDisplayed = False;
	bIsDisplaying = False;
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