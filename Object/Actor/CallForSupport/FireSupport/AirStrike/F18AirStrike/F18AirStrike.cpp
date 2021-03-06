// All the original content belonged to the US Army

#include "AA29/Object/Actor/CallForSupport/FireSupport/AirStrike/F18AirStrike/F18AirStrike.h"
#include "AA29/Object/Actor/SupportEffect/SupportEffect.h"
#include "AA29/Object/Actor/Projector/BaseContactProjector/de_bt_MissileImpact/de_bt_MaverickMissileImpact/de_bt_MaverickMissileImpact.h"
#include "AA29/Object/Actor/Emitter/BaseContactEmitter/em_bt_MissileExplosion/em_bt_MaverickMissileExplosion/em_bt_MaverickMissileExplosion.h"
#include "AA29/Object/Actor/Pawn/Vehicle/Vehicle.h"
#include "AA29/Object/Actor/VehicleWeapon/VehicleWeapon.h"
#include "AA29/Object/Actor/Info/FluidSurfaceInfo/FluidSurfaceInfo.h"

AF18AirStrike::AF18AirStrike()
{
	GlobalSound = LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_Explosions/PlainExplosions/Explosion3_Cue.Explosion3_Cue'"), NULL, LOAD_None, NULL);
	//SupportEffectClass = ASupportEffect::StaticClass();
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
	StrikeSound = LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_Amb_Aircraft/jet/flyover3_Cue.flyover3_Cue'"), NULL, LOAD_None, NULL);
	//bHidden = true;
	//TransientSoundVolume = 1;
	//TransientSoundRadius = 2000;
	//bRotateToDesired = true;
	//RotationRate = FRotator(15000, 15000, 15000);
}

/*
State Ready
{
	simulated Function bool CheckMark(APawn* Aimer, Vector TestMark, bool bFire)
	{
		AActor* Other = nullptr;
		FVector HitLocation = FVector(0,0,0);
		FVector HitNormal = FVector(0,0,0);
		FVector Top = FVector(0,0,0);
		FBoneInfo HitBone = FBoneInfo({});
		UMaterialInstance* HitMaterial = nullptr;
		bool bOldUseCollisionStaticMesh = false;
		if (IsFiring())
		{
			return false;
		}
		Top=TestMark;
		Top.Z=Location.Z;
		Other=Trace(HitLocation,HitNormal,Top,TestMark,false,,HitMaterial);
		if (HitMaterial == nullptr)
		{
			bOldUseCollisionStaticMesh=bUseCollisionStaticMesh;
			bUseCollisionStaticMesh=true;
			BoneTrace(HitLocation,HitNormal,Top,TestMark,HitMaterial,HitBone,false);
			bUseCollisionStaticMesh=bOldUseCollisionStaticMesh;
		}
		DamageBone=HitBone;
		DamageMaterial=HitMaterial;
		if (Other != nullptr)
		{
			return false;
		}
		if (bFire)
		{
			Instigator=Aimer;
			MarkLocation=TestMark;
		}
		return true;
	}
}
*/

/*
State FireSequence
{
	simulated Function bool IsFiring()
	{
		return true;
	}
	Function BeginState()
	{
		StrikeDirection=FVector(0,0,-1);
		DamageLocation=(MarkLocation - (StrikeDirection * 200));
	}
	Function SpawnEffect()
	{
		ASupportEffect* AirStrikeEffect = nullptr;
		AActor* Other = nullptr;
		FVector HitLocation = FVector(0,0,0);
		FVector HitNormal = FVector(0,0,0);
		FVector Top = FVector(0,0,0);
		FVector CP = FVector(0,0,0);
		Other=Trace(HitLocation,HitNormal,(MarkLocation + FVector(0,0,10000)),MarkLocation,false);
		Top=MarkLocation;
		Top.Z=FMax(HitLocation.Z,Location.Z);
		AirStrikeEffect=Spawn(SupportEffectClass,,,Top);
		if (AirStrikeEffect != nullptr)
		{
			AirStrikeEffect.AimAt(MarkLocation,FVector(0,0,1));
		}
		if (Instigator != nullptr)
		{
			CP=Normal((FVector(0,0,1) Cross (Location - Instigator.Location)));
		}
		else
		{
			CP=FVector(1,0,0);
		}
		(CP *= (0.5 * (Location.Z - MarkLocation.Z)));
		Other=Trace(HitLocation,HitNormal,(Top + CP),MarkLocation,false);
		if (Other == nullptr)
		{
			AirStrikeEffect=Spawn(SupportEffectClass,,,(Top + CP));
			if (AirStrikeEffect != nullptr)
			{
				AirStrikeEffect.AimAt(MarkLocation,FVector(0,0,1));
			}
		}
		Other=Trace(HitLocation,HitNormal,(Top - CP),MarkLocation,false);
		if (Other == nullptr)
		{
			AirStrikeEffect=Spawn(SupportEffectClass,,,(Top - CP));
			if (AirStrikeEffect != nullptr)
			{
				AirStrikeEffect.AimAt(MarkLocation,FVector(0,0,1));
			}
		}
	}
	Function SpawnSupportEffects(Vector StrikeLocation, Vector StrikeNormal)
	{
		AGP_Effects.BaseContactProjector* Impact = nullptr;
		AGP_Effects.BaseContactEmitter* Explosion = nullptr;
		Impact=Spawn(Ade_bt_MaverickMissileImpact::StaticClass(),,,StrikeLocation);
		Explosion=Spawn(Aem_bt_MaverickMissileExplosion::StaticClass(),,,StrikeLocation);
	}
	Function ShakeView()
	{
		AController* C = nullptr;
		APlayerController* PC = nullptr;
		float dist = 0;
		float Scale = 0;
		for (C=Level.ControllerList; C!=nullptr; C=C.nextController)
		{
			PC=Cast<APlayerController>(C);
			if (((PC != nullptr) && (PC.ViewTarget != nullptr)) && (PC.ViewTarget.Base != nullptr))
			{
				dist=VSize((DamageLocation - PC.ViewTarget.Location));
				if (dist < (DamageRadius * 2))
				{
					if (dist < DamageRadius)
					{
						Scale=1;
					}
					else
					{
						Scale=(((DamageRadius * 2) - dist) / DamageRadius);
					}
					C.ShakeView((ShakeRotMag * Scale),ShakeRotRate,ShakeRotTime,(ShakeOffsetMag * Scale),ShakeOffsetRate,ShakeOffsetTime);
				}
			}
		}
	}
	Function PlayGlobalSound(USoundBase* S)
	{
		APlayerController* p = nullptr;
		ForEach DynamicActors(Class'PlayerController',p)
		{
			p.ClientPlaySound(S);
		}
	}
	simulated Function HitRadius(float DamageAmount, float DamageRadius, class<DamageType>  DamageType, float Momentum, Vector HitLocation, FBoneInfo Bone, UMaterialInstance* HitMaterial)
	{
		AActor* Victims = nullptr;
		float damageScale = 0;
		float dist = 0;
		FVector Dir = FVector(0,0,0);
		float HitDamage = 0;
		if (bHurtEntry)
		{
			return;
		}
		bHurtEntry=true;
		ForEach VisibleCollidingActors(Class'Actor',Victims,DamageRadius,HitLocation)
		{
			if (((Victims != Self) && (Victims.Role == 4)) && (! Victims->IsA(AFluidSurfaceInfo::StaticClass())))
			{
				Dir=(Victims.Location - HitLocation);
				dist=FMax(1,VSize(Dir));
				Dir=(Dir / dist);
				damageScale=(1 - FMax(0,((dist - Victims.CollisionRadius) / DamageRadius)));
				HitDamage=(damageScale * DamageAmount);
				if ((! Victims->IsA(AVehicle::StaticClass())) && (! Victims->IsA(AVehicleWeapon::StaticClass())))
				{
					Victims.TakeDamage(int(HitDamage),Instigator,(Victims.Location - ((0.5 * (Victims.CollisionHeight + Victims.CollisionRadius)) * Dir)),((damageScale * Momentum) * Dir),DamageType,Bone,,Self,HitMaterial);
				}
				else
				{
					Victims.TakeProjectileImpactDamage(int(HitDamage),Instigator,(Victims.Location - ((0.5 * (Victims.CollisionHeight + Victims.CollisionRadius)) * Dir)),((damageScale * Momentum) * Dir),DamageType,Bone,,Self,HitMaterial);
				}
			}
		}
		bHurtEntry=false;
	}
	Function RadiusDamage(float DamageAmount, float DamageRadius, class<DamageType>  DamageType, float Momentum, Vector HitLocation, float KillRadius)
	{
		AActor* Victim = nullptr;
		float damageScale = 0;
		float dist = 0;
		FVector Dir = FVector(0,0,0);
		float HitDamage = 0;
		ForEach RadiusActors(Class'Actor',Victim,DamageRadius,HitLocation)
		{
			if ((Victim.Role == 4) && (! Victim.bHidden))
			{
				Dir=(Victim.Location - HitLocation);
				dist=FMax(1,VSize(Dir));
				Dir=(Dir / dist);
				damageScale=(1 - FMax(0,((dist - Victim.CollisionRadius) / DamageRadius)));
				HitDamage=(damageScale * DamageAmount);
				if (Victim->IsA(AVehicle::StaticClass()))
				{
					if (Cast<AVehicle>(Victim).TakeRadiusDamage(DamageAmount,Instigator,HitLocation,Momentum,DamageType,DamageRadius))
					{
						continue;
					}
				}
				if (((Cast<APawn>(Victim) != nullptr) && (Cast<APawn>(Victim).Controller == nullptr)) && (Cast<APawn>(Victim).DrivenVehicle != nullptr))
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
	DamageTypeClassName="AGP_Inventory.MaverickMissileDamage";
	DamageType=class<DamageType>(DynamicLoadObject(DamageTypeClassName,Class'Class'));
	RadiusDamage(float(Damage),DamageRadius,DamageType,MomentumTransfer,DamageLocation,KillRadius);
	Sleep(0.1);
	PlayGlobalSound(GlobalSound);
	GotoState("Waiting");
}
*/

void AF18AirStrike::Reset()
{
	Super::Reset();
}

void AF18AirStrike::Respond()
{
	Super::Respond();
}
