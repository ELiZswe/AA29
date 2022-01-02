// All the original content belonged to the US Army

#include "AA29/Object/DamageType/aDamageType.h"
#include "AA29/AA2_PlayerState.h"

UaDamageType::UaDamageType()
{
	DeathString				= "%o was killed by %k.";
	IEDDeathString			= " %o was killed by an IED Explosion.";
	FemaleSuicide			= "%o killed herself.";
	MaleSuicide				= "%o killed himself.";
	bArmorStops				= true;
	bLocationalHit			= true;
	bCausesBlood			= true;
	bExtraMomentumZ			= true;
	GibModifier				= 1;
	FlashScale				= 0.3;
	FlashFog				= FVector(900, 0, 0);
	DamageDesc				= 1;
	DeathOverlayTime		= 6;
	GibPerterbation			= 0.06;
	DamageBleedPercent		= 0.5;
	FFMultiplier			= 1;
	KDamageImpulse			= 8000;
	VehicleDamageScaling	= 1;
	VehicleMomentumScaling	= 1;
	MinFragDamageScale		= 1;
}

void UaDamageType::IncrementKills(AController* Killer)
{
}

void UaDamageType::ScoreKill(AController* Killer, AController* Killed, UDamageType* DamageType)
{
	//IncrementKills(Killer);
}

int32 UaDamageType::GetDirectDamage(int32 Armor)
{
	if (Armor >= 0 && Armor < 11)
	{
		return GetDefault<UaDamageType>()->DirectDamage[Armor];
	}
	return 0;
}

int32 UaDamageType::GetSplashDamage(int32 Armor)
{
	if (Armor >= 0 && Armor < 11)
	{
		return GetDefault<UaDamageType>()->SplashDamage[Armor];
	}
	return 0;
}

bool UaDamageType::IsInstantKill()
{
	return GetDefault<UaDamageType>()->bInstantKill;
}

FString UaDamageType::DeathMessage(AAA2_PlayerState* Killer, AAA2_PlayerState* Victim)
{
	return GetDefault<UaDamageType>()->DeathString;
}

FString UaDamageType::SuicideMessage(AAA2_PlayerState* Victim)
{
	/*
	if (Victim.Level.GamePlayMode == 1)
	{
		if (Victim.bIsFemale)
		{
			return "%o tagged herself with a laser.";
		}
		else
		{
			return "%o tagged himself with a laser.";
		}
	}
	*/

	if (Victim->bIsFemale)
	{
		return GetDefault<UaDamageType>()->FemaleSuicide;
	}
	else
	{
		return GetDefault<UaDamageType>()->MaleSuicide;
	}
}

FString UaDamageType::IEDDeathMessage(AAA2_PlayerState* Victim)
{
	return GetDefault<UaDamageType>()->IEDDeathString;
}

AEffects* UaDamageType::GetPawnDamageEffect(FVector HitLocation, float Damage, FVector Momentum, APawn* Victim, bool bLowDetail)
{
	return nullptr;
}
AEmitter* UaDamageType::GetPawnDamageEmitter(FVector HitLocation, float Damage, FVector Momentum, APawn* Victim, bool bLowDetail)
{
	/*
		if ('GameInfo'.UseLowGore())
		{
			if (Default.LowGoreDamageEmitter != None)
			{
				return Default.LowGoreDamageEmitter;
			}
			else
			{
				return None;
			}
		}
		else
		{
			if (bLowDetail)
			{
				if (Default.LowDetailEmitter != None)
				{
					return Default.LowDetailEmitter;
				}
				else
				{
					return None;
				}
			}
			else
			{
				if (Default.PawnDamageEmitter != None)
				{
					return Default.PawnDamageEmitter;
				}
				else
				{
					return None;
				}
			}
		}
	*/
	return nullptr;    //FAKE   /EliZ
}
void UaDamageType::GetPawnDamageSound()
{
	/*
		if ('GameInfo'.UseLowGore())
		{
			if (Default.LowGoreDamageSounds.Length > 0)
			{
				return Default.LowGoreDamageSounds[Rand(Default.LowGoreDamageSounds.Length)];
			}
			else
			{
				return None;
			}
		}
		else
		{
			if (Default.PawnDamageSounds.Length > 0)
			{
				return Default.PawnDamageSounds[Rand(Default.PawnDamageSounds.Length)];
			}
			else
			{
				return None;
			}
		}
	*/
}
void UaDamageType::IsOfType(int32 Description)
{
	/*
		local int Result;
		Result=Description & Default.DamageDesc;
		return Result == Description;
	*/
}

void UaDamageType::GetHitEffects(AxEmitter*  HitEffects, int32 VictemHealth)
{
}

FString UaDamageType::GetWeaponClass()
{
	return "";
}
