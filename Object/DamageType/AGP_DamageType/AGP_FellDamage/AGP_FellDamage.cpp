// All the original content belonged to the US Army


#include "AGP_FellDamage.h"
#include "AA29/Object/Actor/SideEffect/SideEffectSlow\SideEffectSlowFell.h"
#include "AA29/Object/Actor/SideEffect/SideEffectViewShake\SideEffectViewShakeFell.h"
#include "AA29/Object/Actor/SideEffect/SideEffectWeaponDrop\SideEffectWeaponDropFell.h"

UAGP_FellDamage::UAGP_FellDamage()
{
	SideEffects         = { ASideEffectSlowFell::StaticClass(), ASideEffectViewShakeFell::StaticClass(), ASideEffectWeaponDropFell::StaticClass() };
	DeathString         = "%o left a small crater";
	FemaleSuicide       = "%o left a small crater";
	MaleSuicide         = "%o left a small crater";
	bLocationalHit      = false;
	bCausedByWorld      = true;
	GibModifier         = 2;
	GibPerterbation     = 0.5;
	DamageBleedPercent  = 0;
}


void GetSideEffects(AController* Affected, int32 Damage, APawn* instigatedBy, FVector HitLocation, FVector Momentum, FBoneInfo Bone, AController* KillerController, AActor* ResponsibleActor)
{
	/*
	local int i;
	local HumanController HC;
	local array<class<SideEffect> > ResultingSideEffects;
	HC = HumanController(Affected);
	if (HC != None)
	{
		for (i = 0; i < Default.SideEffects.Length; i++)
		{
			ResultingSideEffects.insert(ResultingSideEffects.Length, 1);
			ResultingSideEffects[ResultingSideEffects.Length - 1] = Default.SideEffects[i];
		}
	}
	Return ResultingSideEffects;
	*/
}