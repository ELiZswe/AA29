// All the original content belonged to the US Army

#include "AA29/Object/Actor/Triggers/Trigger/ESSTrigger/ESSTrigger.h"
#include "AA29/Object/Actor/Controller/PlayerController/HumanController/HumanController.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Pawn.h"
#include "AA29/Object/Actor/Keypoint/BaseObjective/AGP_Objective/AGP_Objective.h"
#include "AA29/Object/Actor/Emitter/EmitterSpawner/EmitterSpawner.h"
#include "AA29/Object/DamageType/AGP_DamageType/ExplosionDamage/ExplosionDamage.h"
#include "AA29/Object/Actor/StaticMeshActor/FlagMeshActor/FlagMeshActor.h"
#include "AA29/Object/Actor/Keypoint/BaseObjective/AGP_Objective/AGP_TriggeredObjective/AGP_ActivatedObjective/AGP_ESSObjective/AGP_CoopESSObjective/AGP_CoopESSObjective.h"
#include "Particles/Emitter.h"

AESSTrigger::AESSTrigger()
{
	bTriggerOnceOnly = true;
}

void AESSTrigger::Reset()
{
	AEmitterSpawner* esIter = nullptr;
	Super::Reset();
	/*
	ForEach AllActors(AEmitterSpawner::StaticClass(), esIter, Tag)
	{
		sndBoomBoom = esIter.EmitterSound;
	}
	*/
}

void AESSTrigger::DoTouch(AActor* Other)
{
	AAGP_Objective* essobjIter = nullptr;
	AFlagMeshActor* fmaIter = nullptr;
	Super::DoTouch(Other);
	/*
	ForEach AllActors(AAGP_Objective::StaticClass(), essobjIter)
	{
		if (essobjIter->IsA(AAGP_CoopESSObjective::StaticClass()) && (essobjIter.Tag == Tag))
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
					ForEach AllActors(AFlagMeshActor::StaticClass(), fmaIter)
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
	Cast<APlayerController>(Other.Instigator.Controller).ClientPlaySound(sndBoomBoom);
	if (Cast<AAGP_Pawn>(Other) != nullptr)
	{
		Cast<AAGP_Pawn>(Other).bHitByIED = true;
	}
	if (Cast<AHumanController>(Other.Instigator.Controller) != nullptr)
	{
		Level.Game.Stats.PlayerStats[HumanController(Other.Instigator.Controller).PlayerStatsIndex].StatEvent_PlayerTotalInjuriesByObject(Cast<AHumanController>(Other.Instigator.Controller).Pawn.Location);
	}
	Other.TakeDamage(10000, Other.Instigator, Other->GetActorLocation(), FVector(0, 0, 0), AExplosionDamage::StaticClass());
	*/
}
