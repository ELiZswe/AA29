// All the original content belonged to the US Army

#include "AA29/Object/Actor/Triggers/Trigger/TeamTrigger/TeamTrigger.h"

ATeamTrigger::ATeamTrigger()
{

}

void ATeamTrigger::PostBeginPlay()
{
	Super::PostBeginPlay();
	if (bTimed)
	{
		//SetTimer(2.5, true);
	}
}

void ATeamTrigger::Timer()
{
	AController* p = nullptr;
	/*
	for (p=Level.ControllerList; p!=nullptr; p=p.nextController)
	{
		if (((p.Pawn != nullptr) && (FMath::Abs((Location.Z - p.Pawn.Location.Z)) < (CollisionHeight + p.CollisionHeight))) && (VSize((Location - p.Pawn.Location)) < CollisionRadius))
		{
			Touch(p.Pawn);
		}
	}
	SetTimer(2.5,true);
	*/
}

bool ATeamTrigger::IsRelevant(AActor* Other)
{
	/*
	if ((((!bInitiallyActive) || (!Level.Game.bTeamGame)) || (Other.Instigator == nullptr)) || Level.Game.IsOnTeam(Other.Instigator.Controller, Team))
	{
		return false;
	}
	return Super::IsRelevant(Other);
	*/
	return false;    //FAKE   /ELiZ
}
/*
void ATeamTrigger::TakeDamage(int32 Damage, Pawn instigatedBy, Vector HitLocation, Vector Momentum, class<DamageType>  DamageType, FBoneInfo Bone, Controller KillerController, Actor ResponsibleActor, Material HitMaterial)
{
	if (((instigatedBy != nullptr) && Level.Game.bTeamGame) && (!Level.Game.IsOnTeam(instigatedBy.Controller, Team)))
	{
		Super::TakeDamage(Damage, instigatedBy, HitLocation, Momentum, DamageType);
	}
}
*/

