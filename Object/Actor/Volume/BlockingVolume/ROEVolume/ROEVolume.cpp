// All the original content belonged to the US Army


#include "AA29/Object/Actor/Volume/BlockingVolume/ROEVolume/ROEVolume.h"

AROEVolume::AROEVolume()
{
	DefaultDamage = 90;
	DamageMultiplier = 0.333;
	sTextToDisplay = "Cease Fire!";
	//bBlockZeroExtentTraces = true;
}

void AROEVolume::PostBeginPlay()
{
	/*
	if (Role == 4)
	{
		ConfigureLinkDamage();
	}
	*/
}

void AROEVolume::ConfigureLinkDamage()
{
	/*
	local AGP_Objective AO;
	if ((DamageTag != 'None') && (DamageTag != 'None'))
	{
		ForEach AllActors(class'AGP.AGP_Objective', AO)
		{
			if (AO.DamageTag == DamageTag)
			{
				if (DamageObjective == None)
				{
					DamageObjective = AO;
				}
				else
				{
					DebugLog(DEBUG_Warn, "ROEVolume::PostBeginPlay()	Already have a DamageObjective! " $ string(AO) @ string(DamageObjective));
				}
			}
		}
		if (DamageObjective == None)
		{
			DebugLog(DEBUG_Warn, "ROEVolume::PostBeginPlay()	Could not find DamageObjective for DamageTag " $ string(DamageTag));
		}
	}
	*/
}
/*
void AROEVolume::TakeDamage(int32 Damage, Pawn instigatedBy, Vector HitLocation, Vector Momentum, class<DamageType>  DamageType, Actor.BoneInfo Bone, Controller KillerController, Actor ResponsibleActor, Material HitMaterial)
{
	if (DamageEvent != 'None')
	{
		TriggerEvent(DamageEvent, Self, instigatedBy);
	}
	if (DamageObjective != None)
	{
		if (Damage == 0)
		{
			Damage = DefaultDamage;
		}
		DamageObjective.NotifyLinkDamage(instigatedBy, int((DamageMultiplier * float(Damage))));
		if (((instigatedBy != None) && (instigatedBy.Controller != None)) && instigatedBy.Controller.IsA('HumanController'))
		{
			HumanController(instigatedBy.Controller).NotifyAdminMessage(sTextToDisplay);
		}
	}
}
*/
