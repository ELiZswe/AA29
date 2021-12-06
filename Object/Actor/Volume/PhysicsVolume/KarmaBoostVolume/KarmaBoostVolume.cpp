// All the original content belonged to the US Army


#include "AA29/Object/Actor/Volume/PhysicsVolume/KarmaBoostVolume/KarmaBoostVolume.h"

AKarmaBoostVolume::AKarmaBoostVolume()
{
	EntryAngleFactor = 0.7;
	//bDirectional = true;
}

void AKarmaBoostVolume::Touch(AActor* Other)
{
	/*
	int32 i = 0;
	Super::Touch(Other);
	if (Other != None)
	{
		i = 0;
		if (i < AffectedClasses.Length)
		{
			if (Other.Class == AffectedClasses[i])
			{
				TryBoost(Other);
			}
			else
			{
				i++;
			}
		}
	}
	*/
}

void AKarmaBoostVolume::UnTouch(AActor* Other)
{
	/*
	Super::UnTouch(Other);
	Gravity = Default.Gravity;
	*/
}

void AKarmaBoostVolume::TryBoost(AActor* Other)
{
	/*
	float EntryAngle = 0;
	EntryAngle = (Normal(Other.Velocity) Dot  Vector(Rotation));
	if (EntryAngle > EntryAngleFactor)
	{
		ActivateBoost(Other);
	}
	*/
}

void AKarmaBoostVolume::ActivateBoost(AActor* Other)
{
	/*
	if (bBoostRelative)
	{
		Gravity = (Default.Gravity + (BoostForce * Normal(Other.Velocity)));
	}
	else
	{
		Gravity = (Default.Gravity + (BoostForce * Vector(Rotation)));
	}
	*/
}
