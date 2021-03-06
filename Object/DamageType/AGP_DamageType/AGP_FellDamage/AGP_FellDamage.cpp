// All the original content belonged to the US Army

#include "AA29/Object/DamageType/AGP_DamageType/AGP_FellDamage/AGP_FellDamage.h"
#include "AA29/Object/Actor/SideEffect/SideEffectSlow/SideEffectSlowFell.h"
#include "AA29/Object/Actor/SideEffect/SideEffectViewShake/SideEffectViewShakeFell.h"
#include "AA29/Object/Actor/SideEffect/SideEffectWeaponDrop/SideEffectWeaponDropFell.h"
#include "AA29/Object/Actor/Controller/PlayerController/HumanController/HumanController.h"

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

TArray<TSubclassOf<ASideEffect>> UAGP_FellDamage::GetSideEffects(AController* Affected, int32 Damage, APawn* instigatedBy, FVector HitLocation, FVector Momentum, FBoneInfo Bone, AController* KillerController, AActor* ResponsibleActor)
{
	int32 i = 0;
	AHumanController* HC = nullptr;
	TArray<TSubclassOf<ASideEffect>> ResultingSideEffects = {};
	HC = Cast<AHumanController>(Affected);
	if (HC != nullptr)
	{
		for (i = 0; i < GetDefault<UAGP_FellDamage>()->SideEffects.Num(); i++)
		{
			ResultingSideEffects.Add(GetDefault<UAGP_FellDamage>()->SideEffects[i]);
		}
	}
	return ResultingSideEffects;
}
