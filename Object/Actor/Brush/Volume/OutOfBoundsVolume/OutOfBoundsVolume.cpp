// All the original content belonged to the US Army

#include "AA29/Object/Actor/Brush/Volume/OutOfBoundsVolume/OutOfBoundsVolume.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Pawn.h"

AOutOfBoundsVolume::AOutOfBoundsVolume()
{
	TimeToKillPlayer = 15;

}

void AOutOfBoundsVolume::Touch(AActor* Other)
{
	AAGP_Pawn* p = nullptr;
	p = Cast<AAGP_Pawn>(Other);
	if (p != nullptr && p->IsHumanControlled())
	{
		p->bOOBIsTrainingVolume = bIsTrainingVolume;
		p->OutOfBounds++;
		p->CurrentZoneTimeToKill = TimeToKillPlayer;
		//p->ClientAlertOutOfBounds(Ceil(TimeToKillPlayer - p.TimeOutOfBounds));
		//p->SetCustomTimer(0.5, true, "OutOfBoundsCheck");
	}
}
void AOutOfBoundsVolume::UnTouch(AActor* Other)
{
	AAGP_Pawn* p = nullptr;
	p = Cast<AAGP_Pawn>(Other);
	if (p != nullptr && p->IsHumanControlled() && p->OutOfBounds > 0)
	{
		p->OutOfBounds--;
		if (p->OutOfBounds == 0)
		{
			p->TimeOutOfBounds = 0;
			p->ClientAlertReturnedToCombat();
			//StopCustomTimer("OutOfBoundsCheck");
		}
	}
}
