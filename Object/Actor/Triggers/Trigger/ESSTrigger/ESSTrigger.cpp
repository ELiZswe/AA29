// All the original content belonged to the US Army

#include "AA29/Object/Actor/Triggers/Trigger/ESSTrigger/ESSTrigger.h"

AESSTrigger::AESSTrigger()
{
	bTriggerOnceOnly = true;
}

void AESSTrigger::Reset()
{
	/*
	local EmitterSpawner esIter;
	Super::Reset();
	ForEach AllActors(Class'EmitterSpawner', esIter, Tag)
	{
		sndBoomBoom = esIter.EmitterSound;
	}
	*/
}

void AESSTrigger::DoTouch(AActor* Other)
{
	/*
	local AGP_Objective essobjIter;
	local FlagMeshActor fmaIter;
	Super::DoTouch(Other);
	ForEach AllActors(Class'AGP.AGP_Objective', essobjIter)
	{
		if (essobjIter.IsA("AGP_CoopESSObjective") && (essobjIter.Tag == Tag))
		{
			if (!essobjIter.bHidden)
			{
				essobjIter.bHidden = true;
				essobjIter.bDisabled = true;
				essobjIter.SetCollision(false, false, false);
				fmaIter = AGP_CoopESSObjective(essobjIter).getFlagReference();
				if (fmaIter != nullptr)
				{
					fmaIter.bHidden = true;
				}
				else
				{
					ForEach AllActors(Class'AGP.FlagMeshActor', fmaIter)
					{
						if (essobjIter.getFlagTag() == fmaIter.Tag)
						{
							fmaIter.bHidden = true;
						}
					}
				}
			}
		}
	}
	PlayerController(Other.Instigator.Controller).ClientPlaySound(sndBoomBoom);
	if (AGP_Pawn(Other) != nullptr)
	{
		AGP_Pawn(Other).bHitByIED = true;
	}
	if (HumanController(Other.Instigator.Controller) != nullptr)
	{
		Level.Game.Stats.PlayerStats[HumanController(Other.Instigator.Controller).PlayerStatsIndex].StatEvent_PlayerTotalInjuriesByObject(HumanController(Other.Instigator.Controller).Pawn.Location);
	}
	Other.TakeDamage(10000, Other.Instigator, Other.Location, vect(0, 0, 0), Class'AGP.ExplosionDamage');
	*/
}
