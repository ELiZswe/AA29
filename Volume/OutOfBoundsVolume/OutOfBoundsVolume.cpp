// All the original content belonged to the US Army


#include "AA29/Volume/OutOfBoundsVolume/OutOfBoundsVolume.h"

AOutOfBoundsVolume::AOutOfBoundsVolume()
{
	TimeToKillPlayer = 15;

}

void AOutOfBoundsVolume::Touch(AActor* Other)
{
	/*
	local AGP_Pawn p;
	p = AGP_Pawn(Other);
	if (p != None && p.IsHumanControlled())
	{
		p.bOOBIsTrainingVolume = bIsTrainingVolume;
		p.OutOfBounds++;
		p.CurrentZoneTimeToKill = TimeToKillPlayer;
		p.ClientAlertOutOfBounds(Ceil(TimeToKillPlayer - p.TimeOutOfBounds));
		p.SetCustomTimer(0.5, True, 'OutOfBoundsCheck');
	}
	*/
}
void AOutOfBoundsVolume::UnTouch(AActor* Other)
{
	/*
	local AGP_Pawn p;
	p = AGP_Pawn(Other);
	if (p != None && p.IsHumanControlled() && p.OutOfBounds > 0)
	{
		p.OutOfBounds--;
		if (p.OutOfBounds == 0)
		{
			p.TimeOutOfBounds = 0;
			p.ClientAlertReturnedToCombat();
			StopCustomTimer('OutOfBoundsCheck');
		}
	}
	*/
}