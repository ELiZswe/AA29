// All the original content belonged to the US Army

#include "AA29/Object/Actor/Inventory/Ammunition/AGP_Ammunition/AGP_Ammunition.h"
#include "AA29/AA2_WorldSettings.h"
#include "AA29/Object/Actor/Projectile/Projectile.h"
#include "AA29/Object/Actor/Inventory/Weapon/Weapon.h"

AAGP_Ammunition::AAGP_Ammunition()
{
	Damage             = 30;
	MomentumTransfer   = 2000;
	//_cTracerClass = Class'AGP.BaseTracer'
	_iTracerCount      = -1;
	bInstantHit        = true;
	bVirtualInventory  = true;
}

void AAGP_Ammunition::PreBeginPlay()
{
	//Super::PreBeginPlay();
	switch (Cast<AAA2_WorldSettings>(GetWorldSettings())->GamePlayMode)
	{
		case EGameplayModes::GM_MILES:
			//MyDamageType = Class'AGP.MilesDamage';
			_iTracerCount = -1;
			break;
		default:
			break;
	}
}

bool AAGP_Ammunition::IncrementTracer(FVector Start, FRotator Dir)
{
	/*
	if (Level.GamePlayMode != GM_Normal)
	{
		return false;
	}
	if (_iTracerCount > 0)
	{
		_iTracerCount--;
	}
	if (_iTracerCount == 0)
	{
		if (Instigator.bIsProne)
		{
			(Start += (7 * Vector(Dir)));
		}
		_iTracerCount = Default._iTracerCount;
		Spawn(_cTracerClass, Instigator, , Start, Dir);
		return true;
	}
	*/
	return false;
}

void AAGP_Ammunition::UseBullet(FVector StartTrace, FRotator Direction)
{
	DecrementAmmo();
	if (AmmoAmount == 0)
	{
		/*
		if ((((Owner != nullptr) && (Pawn(Owner) != nullptr)) && (Pawn(Owner).Weapon != nullptr)) && Pawn(Owner).Weapon.IsA("AGP_Weapon"))
		{
			AGP_Weapon(Pawn(Owner).Weapon).NotifyOutOfAmmo();
		}
		*/
		return;
	}
	IncrementTracer(StartTrace, Direction);
}

void AAGP_Ammunition::DecrementAmmo()
{
	/*
	if (((Owner != nullptr) && (AGP_Pawn(Owner) != nullptr)) && AGP_Pawn(Owner).HaveUnlimitedAmmo())
	{
		return;
	}
	else
	{
		if ((AmmoAmount > 0) && (AmmoAmount <= (MaxAmmo + 1)))
		{
			AmmoAmount--;
		}
		else
		{
			DebugLog(DEBUG_Bullet, "AGP_Ammunition.DecrementAmmo() - Out of bullets");
			AmmoAmount = 0;
		}
	}
	*/
}

void AAGP_Ammunition::ProcessTraceHit(AWeapon* W, FVector StartTrace, FRotator Direction, AActor* HitActor, FBoneInfo HitBone, FVector HitLocation, FVector HitNormal, UMaterialInstance* HitMaterial, FVector X, FVector Y, FVector Z, float fStrength)
{
	float TrueDamage = 0;
	/*
	if ((HitActor != nullptr) && (HitActor != W.Instigator))
	{
		TrueDamage = (float(Damage) * fStrength);
		if (HitBone.HitBone != 0)
		{
			if (HitBone.DamageModifier > 0)
			{
				(TrueDamage *= HitBone.DamageModifier);
			}
			if ((HumanController(W.Instigator.Controller) != nullptr) && ((HitBone.Name ~= "Head") || (HitBone.Name ~= "Neck")))
			{
				Level.Game.Stats.PlayerStats[HumanController(W.Instigator.Controller).PlayerStatsIndex].StatEvent_CombatHeadshots();
			}
		}
		HitActor.TakeDamage(int(TrueDamage), W.Instigator, HitLocation, (MomentumTransfer * X), MyDamageType, HitBone, , W, HitMaterial);
		if (((HumanController(W.Instigator.Controller) != nullptr) && (AGP_Pawn(HitActor) != nullptr)) && (!AGP_Character(HitActor).bIsDead))
		{
			Level.Game.Stats.PlayerStats[HumanController(W.Instigator.Controller).PlayerStatsIndex].StatEvent_CombatEnemyContactTime(Level.TimeSeconds);
			Level.Game.Stats.PlayerStats[HumanController(W.Instigator.Controller).PlayerStatsIndex].StatEvent_CombatDamageCount();
			Level.Game.Stats.PlayerStats[HumanController(W.Instigator.Controller).PlayerStatsIndex].StatEvent_CombatTotalDamage(int(TrueDamage));
		}
	}
	*/
}

void AAGP_Ammunition::NPC_ProcessTraceHit(AWeapon* W, FVector StartTrace, FRotator Direction, AActor* HitActor, FBoneInfo HitBone, FVector HitLocation, FVector HitNormal, UMaterialInstance* HitMaterial, FVector X, FVector Y, FVector Z, float fStrength)
{
	float TrueDamage = 0;
	/*
	if ((HitActor != nullptr) && (HitActor != W.Instigator))
	{
		TrueDamage = (float(Damage) * fStrength);
		if (HitBone.HitBone != 0)
		{
			if (HitBone.DamageModifier > 0)
			{
				(TrueDamage *= HitBone.DamageModifier);
			}
		}
		Spawn(_cTracerClass, Instigator, , StartTrace, Direction);
		HitActor.TakeDamage(int(TrueDamage), W.Instigator, HitLocation, (MomentumTransfer * X), MyDamageType, HitBone, , W, HitMaterial);
	}
	*/
}

AProjectile* AAGP_Ammunition::SpawnProjectile(FVector Start, FRotator Dir)
{
	AProjectile* Proj = nullptr;
	UseBullet(Start, Dir);
	/*
	Proj = Spawn(ProjectileClass, Instigator.Weapon, , Start, Dir);
	Proj.Instigator = Instigator;
	*/
	return Proj;
}

FString AAGP_Ammunition::GetHumanReadableName() const
{
	FString retval = "";
	//retval = Super::GetHumanReadableName() + ":" + string(AmmoAmount);
	return retval;
}
