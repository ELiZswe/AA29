// All the original content belonged to the US Army

#include "AA29/Object/Actor/Triggers/TriggeredCondition/ResetTriggeredCondition/ResetTriggeredCondition.h"

AResetTriggeredCondition::AResetTriggeredCondition()
{

}

void AResetTriggeredCondition::PostBeginPlay()
{
	bSavedInitialEnabled = bEnabled;
	Super::PostBeginPlay();
}

void AResetTriggeredCondition::Reset()
{
	Super::Reset();
	bEnabled = bSavedInitialEnabled;
}

void AResetTriggeredCondition::MatchStarting()
{
	if (bResetAtRoundEnd)
	{
		Reset();
	}
}

