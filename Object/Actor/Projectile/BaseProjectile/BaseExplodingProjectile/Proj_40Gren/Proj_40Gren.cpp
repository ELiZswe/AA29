// All the original content belonged to the US Army

#include "AA29/Object/Actor/Projectile/BaseProjectile/BaseExplodingProjectile/Proj_40Gren/Proj_40Gren.h"
#include "AA29/Object/Actor/Projectile/BaseProjectile\BaseExplodingProjectile\Proj_30Gren\Proj_30Gren.h"
#include "AA29/Object/DamageType/AGP_DamageType\GrenadeImpact\SpecialGrenadeImpact.h"
#include "AA29/Object/Actor/Projectile/BaseProjectile/BaseExplodingProjectile/Proj_30Gren/Proj_30Gren.h"
AProj_40Gren::AProj_40Gren(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	ImpactDamageType      = USpecialGrenadeImpact::StaticClass();
	EnemyProjectileClass  = AProj_30Gren::StaticClass();
	StaticMesh            = LoadObject<UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AA2_Weapons/Projectiles/m-m203.m-m203"), NULL, LOAD_None, NULL);
}

void AProj_40Gren::Boom(FVector HitLocation, FVector HitNormal)
{
	AController* ctrlIterator = nullptr;
	/*
	Super::Boom(HitLocation, HitNormal);
	if (GetWorld()->GetNetMode() == NM_Client)
	{
		return;
	}
	for (ctrlIterator = Level.ControllerList; ctrlIterator != nullptr; ctrlIterator = ctrlIterator.nextController)
	{
		if (!ctrlIterator->IsA(AaAIController::StaticClass()))
		{
		}
		if ((Cast<AAIController>(ctrlIterator).Pawn != nullptr) && (VSize((Cast<AAIController>(ctrlIterator).Pawn.Location - HitLocation)) < float(825)))
		{
			if (ctrlIterator.Pawn.LineOfSightTo(this))
			{
				Cast<AaAIController>(ctrlIterator).NotifyBuzzedByBullet(GetOwner());
			}
		}
	}
	*/
}
