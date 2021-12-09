// All the original content belonged to the US Army


#include "AA29/Object/DamageType/aDamageType.h"

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
	/*
		IncrementKills(Killer);
	*/
}
void UaDamageType::GetDirectDamage(int32 Armor)
{
	/*
		if (Armor >= 0 && Armor < 11)
		{
			Return Default.DirectDamage[Armor];
		}
		Return 0;
	*/
}
void UaDamageType::GetSplashDamage(int32 Armor)
{
	/*
		if (Armor >= 0 && Armor < 11)
		{
			Return Default.SplashDamage[Armor];
		}
		Return 0;
	*/
}
void UaDamageType::IsInstantKill()
{
	/*
		Return Default.bInstantKill;
	*/
}
/*
void UaDamageType::DeathMessage(PlayerReplicationInfo Killer, PlayerReplicationInfo Victim)
{
	Return Default.DeathString;
}
*/
/*
void UaDamageType::SuicideMessage(PlayerReplicationInfo Victim)
{
	if (Victim.Level.GamePlayMode == 1)
	{
		if (Victim.bIsFemale)
		{
			Return "%o tagged herself with a laser.";
		}
		else
		{
			Return "%o tagged himself with a laser.";
		}
	}
	if (Victim.bIsFemale)
	{
		Return Default.FemaleSuicide;
	}
	else
	{
		Return Default.MaleSuicide;
	}
}
*/
/*
void UaDamageType::IEDDeathMessage(PlayerReplicationInfo Victim)
{
		Return Default.IEDDeathString;
}
*/
void UaDamageType::GetPawnDamageEffect(FVector HitLocation, float Damage, FVector Momentum, APawn* Victim, bool bLowDetail)
{
	/*
		Return None;
	*/
}
void UaDamageType::GetPawnDamageEmitter(FVector HitLocation, float Damage, FVector Momentum, APawn* Victim, bool bLowDetail)
{
	/*
		if ('GameInfo'.UseLowGore())
		{
			if (Default.LowGoreDamageEmitter != None)
			{
				Return Default.LowGoreDamageEmitter;
			}
			else
			{
				Return None;
			}
		}
		else
		{
			if (bLowDetail)
			{
				if (Default.LowDetailEmitter != None)
				{
					Return Default.LowDetailEmitter;
				}
				else
				{
					Return None;
				}
			}
			else
			{
				if (Default.PawnDamageEmitter != None)
				{
					Return Default.PawnDamageEmitter;
				}
				else
				{
					Return None;
				}
			}
		}
	*/
}
void UaDamageType::GetPawnDamageSound()
{
	/*
		if ('GameInfo'.UseLowGore())
		{
			if (Default.LowGoreDamageSounds.Length > 0)
			{
				Return Default.LowGoreDamageSounds[Rand(Default.LowGoreDamageSounds.Length)];
			}
			else
			{
				Return None;
			}
		}
		else
		{
			if (Default.PawnDamageSounds.Length > 0)
			{
				Return Default.PawnDamageSounds[Rand(Default.PawnDamageSounds.Length)];
			}
			else
			{
				Return None;
			}
		}
	*/
}
void UaDamageType::IsOfType(int32 Description)
{
	/*
		local int Result;
		Result=Description & Default.DamageDesc;
		Return Result == Description;
	*/
}
/*
void UaDamageType::GetHitEffects(AxEmitter*  HitEffects, int32 VictemHealth)
{
}
*/
void UaDamageType::GetWeaponClass()
{
	/*
		Return "";
	*/
}
