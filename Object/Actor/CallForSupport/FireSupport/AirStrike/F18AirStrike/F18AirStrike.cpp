// All the original content belonged to the US Army


#include "AA29/Object/Actor/CallForSupport/FireSupport/AirStrike/F18AirStrike/F18AirStrike.h"

AF18AirStrike::AF18AirStrike()
{
	GlobalSound = LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_Explosions/PlainExplosions/Explosion3_Que.Explosion3_Que'"), NULL, LOAD_None, NULL);
	//SupportEffectClass = class'AGP_Gameplay.SupportEffect';
	Damage = 1200;
	MomentumTransfer = 150000;
	DamageRadius = 1056;
	KillRadius = 524.799988;
	DamageTypeClassName = "AGP_Inventory.MaverickMissileDamage";
	ShakeRotMag = FVector(0, 0, 50);
	ShakeRotRate = FVector(0, 0, 500);
	ShakeRotTime = 10;
	ShakeOffsetMag = FVector(0, 0, 2);
	ShakeOffsetRate = FVector(0, 0, 50);
	ShakeOffsetTime = 8;
	ArrivalTime = 5;
	StrikesAvailable = 4;
	StrikeSound = LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_Amb_Aircraft/jet/flyover3_Que.flyover3_Que'"), NULL, LOAD_None, NULL);
	//bHidden = true;
	//TransientSoundVolume = 1;
	//TransientSoundRadius = 2000;
	//bRotateToDesired = true;
	//RotationRate = FRotator(15000, 15000, 15000);
}

/*
State Ready
{
	simulated Function bool CheckMark(Pawn Aimer, Vector TestMark, bool bFire)
	{
		local Actor Other;
		FVector HitLocation = FVector(0,0,0);
		FVector HitNormal = FVector(0,0,0);
		FVector Top = FVector(0,0,0);
		local Actor.BoneInfo HitBone;
		local Material HitMaterial;
		bool bOldUseCollisionStaticMesh = false;
		if (IsFiring())
		{
			return false;
		}
		Top = TestMark;
		Top.Z = Location.Z;
		Other = Trace(HitLocation,HitNormal,Top,TestMark,false,,HitMaterial);
		if (HitMaterial == None)
		{
			bOldUseCollisionStaticMesh = bUseCollisionStaticMesh;
			bUseCollisionStaticMesh = true;
			BoneTrace(HitLocation,HitNormal,Top,TestMark,HitMaterial,HitBone,false);
			bUseCollisionStaticMesh = bOldUseCollisionStaticMesh;
		}
		DamageBone = HitBone;
		DamageMaterial = HitMaterial;
		if (Other != None)
		{
			return false;
		}
		if (bFire)
		{
			Instigator = Aimer;
			MarkLocation = TestMark;
		}
		return true;
	}
}

State FireSequence
{
	simulated Function bool IsFiring()
	{
		return true;
	}
	Function BeginState()
	{
		StrikeDirection = vect(0,0,-1);
		DamageLocation = (MarkLocation - (StrikeDirection * 200));
	}
	Function SpawnEffect()
	{
		local SupportEffect AirStrikeEffect;
		local Actor Other;
		FVector HitLocation = FVector(0,0,0);
		FVector HitNormal = FVector(0,0,0);
		FVector Top = FVector(0,0,0);
		FVector CP = FVector(0,0,0);
		Other = Trace(HitLocation,HitNormal,(MarkLocation + vect(0,0,10000)),MarkLocation,false);
		Top = MarkLocation;
		Top.Z = FMax(HitLocation.Z,Location.Z);
		AirStrikeEffect = Spawn(SupportEffectClass,,,Top);
		if (AirStrikeEffect != None)
		{
			AirStrikeEffect.AimAt(MarkLocation,vect(0,0,1));
		}
		if (Instigator != None)
		{
			CP = Normal((vect(0,0,1) Cross(Location - Instigator.Location)));
		}
		else
		{
			CP = vect(1,0,0);
		}
		(CP *= (0.5 * (Location.Z - MarkLocation.Z)));
		Other = Trace(HitLocation,HitNormal,(Top + CP),MarkLocation,false);
		if (Other == None)
		{
			AirStrikeEffect = Spawn(SupportEffectClass,,,(Top + CP));
			if (AirStrikeEffect != None)
			{
				AirStrikeEffect.AimAt(MarkLocation,vect(0,0,1));
			}
		}
		Other = Trace(HitLocation,HitNormal,(Top - CP),MarkLocation,false);
		if (Other == None)
		{
			AirStrikeEffect = Spawn(SupportEffectClass,,,(Top - CP));
			if (AirStrikeEffect != None)
			{
				AirStrikeEffect.AimAt(MarkLocation,vect(0,0,1));
			}
		}
	}
	Function SpawnSupportEffects(Vector StrikeLocation, Vector StrikeNormal)
	{
		local AGP_Effects.BaseContactProjector Impact;
		local AGP_Effects.BaseContactEmitter Explosion;
		Impact = Spawn(Class'AGP_Effects.de_bt_MaverickMissileImpact',,,StrikeLocation);
		Explosion = Spawn(Class'AGP_Effects.em_bt_MaverickMissileExplosion',,,StrikeLocation);
	}
	Function ShakeView()
	{
		local Controller C;
		local PlayerController PC;
		float dist = 0;
		float Scale = 0;
		C = Level.ControllerList;
		if (C != None)
		{
			PC = PlayerController(C);
			if (((PC != None) && (PC.ViewTarget != None)) && (PC.ViewTarget.Base != None))
			{
				dist = VSize((DamageLocation - PC.ViewTarget.Location));
				if (dist < (DamageRadius * 2))
				{
					if (dist < DamageRadius)
					{
						Scale = 1;
					}
					else
					{
						Scale = (((DamageRadius * 2) - dist) / DamageRadius);
					}
					C.ShakeView((ShakeRotMag * Scale),ShakeRotRate,ShakeRotTime,(ShakeOffsetMag * Scale),ShakeOffsetRate,ShakeOffsetTime);
				}
			}
			C = C.nextController;
		}
	}
	Function PlayGlobalSound(Sound S)
	{
		local PlayerController p;
		ForEach DynamicActors(Class'PlayerController',p)
		{
			p.ClientPlaySound(S);
		}
	}
	simulated Function HitRadius(float DamageAmount, float DamageRadius, class<DamageType>  DamageType, float Momentum, Vector HitLocation, Actor.BoneInfo Bone, Material HitMaterial)
	{
		local Actor Victims;
		float damageScale = 0;
		float dist = 0;
		FVector Dir = FVector(0,0,0);
		float HitDamage = 0;
		if (bHurtEntry)
		{
			return;
		}
		bHurtEntry = true;
		ForEach VisibleCollidingActors(Class'Actor',Victims,DamageRadius,HitLocation)
		{
			if (((Victims != Self) && (Victims.Role == 4)) && (!Victims.IsA('FluidSurfaceInfo')))
			{
				Dir = (Victims.Location - HitLocation);
				dist = FMax(1,VSize(Dir));
				Dir = (Dir / dist);
				damageScale = (1 - FMax(0,((dist - Victims.CollisionRadius) / DamageRadius)));
				HitDamage = (damageScale * DamageAmount);
				if ((!Victims.IsA('Vehicle')) && (!Victims.IsA('VehicleWeapon')))
				{
					Victims.TakeDamage(int(HitDamage),Instigator,(Victims.Location - ((0.5 * (Victims.CollisionHeight + Victims.CollisionRadius)) * Dir)),((damageScale * Momentum) * Dir),DamageType,Bone,,Self,HitMaterial);
				}
				else
				{
					Victims.TakeProjectileImpactDamage(int(HitDamage),Instigator,(Victims.Location - ((0.5 * (Victims.CollisionHeight + Victims.CollisionRadius)) * Dir)),((damageScale * Momentum) * Dir),DamageType,Bone,,Self,HitMaterial);
				}
			}
		}
		bHurtEntry = false;
	}
	Function RadiusDamage(float DamageAmount, float DamageRadius, class<DamageType>  DamageType, float Momentum, Vector HitLocation, float KillRadius)
	{
		local Actor Victim;
		float damageScale = 0;
		float dist = 0;
		FVector Dir = FVector(0,0,0);
		float HitDamage = 0;
		ForEach RadiusActors(Class'Actor',Victim,DamageRadius,HitLocation)
		{
			if ((Victim.Role == 4) && (!Victim.bHidden))
			{
				Dir = (Victim.Location - HitLocation);
				dist = FMax(1,VSize(Dir));
				Dir = (Dir / dist);
				damageScale = (1 - FMax(0,((dist - Victim.CollisionRadius) / DamageRadius)));
				HitDamage = (damageScale * DamageAmount);
				if (Victim.IsA('Vehicle'))
				{
					if (Vehicle(Victim).TakeRadiusDamage(DamageAmount,Instigator,HitLocation,Momentum,DamageType,DamageRadius))
					{
						continue;
					}
				}
				if (((Pawn(Victim) != None) && (Pawn(Victim).Controller == None)) && (Pawn(Victim).DrivenVehicle != None))
				{
					continue;
				}
				Victim.TakeDamage(int((damageScale * DamageAmount)),Instigator,(Victim.Location - ((0.5 * (Victim.CollisionHeight + Victim.CollisionRadius)) * Dir)),((damageScale * Momentum) * Dir),DamageType,,,Self);
			}
		}
	}
	Function EndState()
	{
	}
Begin:
	PlayGlobalSound(StrikeSound);
	Sleep(2);
	PlayGlobalSound(FireSound);
	Sleep(1);
	SpawnEffect();
	SpawnSupportEffects(MarkLocation);
	ShakeView();
	DamageTypeClassName = "AGP_Inventory.MaverickMissileDamage";
	DamageType = class<DamageType>(DynamicLoadObject(DamageTypeClassName,Class'Class'));
	RadiusDamage(float(Damage),DamageRadius,DamageType,MomentumTransfer,DamageLocation,KillRadius);
	Sleep(0.1);
	PlayGlobalSound(GlobalSound);
	GotoState('Waiting');
}
*/

void AF18AirStrike::Reset()
{
	//Super::Reset();
}

void AF18AirStrike::Respond()
{
	//Super::Respond();
}
