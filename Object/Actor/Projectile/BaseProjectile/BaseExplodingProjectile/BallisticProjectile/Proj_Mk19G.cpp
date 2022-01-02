// All the original content belonged to the US Army

#include "AA29/Object/Actor/Projectile/BaseProjectile/BaseExplodingProjectile/BallisticProjectile/Proj_Mk19G.h"
#include "AA29/Object/DamageType/CROWS_Mk19Damage/CROWS_Mk19Damage.h"

AProj_Mk19G::AProj_Mk19G(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	ArmingTimeRange = FObjectRange({ 0.16, 0.16 });
	ImpactDamage = 125;
	//ImpactDamageType = class'AGP_Vehicles.CROWS_Mk19Damage';
	//ExplosionEmitter = Class'AGP_Effects.em_bt_mk19grenexplosion';
	ExplosionSoundRadius = 4000;
	DamageClasses = {
		//Class'Engine.DecoMesh'
		//Class'Engine.Pawn'
		//Class'Engine.BaseProjectile'
		//Class'AGP.ThrowWeaponPickup'
		//Class'Engine.Triggers'
		//Class'Engine.KActor'
		//Class'AGP.BodyPanel'
	};
	fKillRadius = 296;
	ExplosionSound = LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Armory/MK19/s_arm_mk19_impact_explosion_Cue.s_arm_mk19_impact_explosion_Cue'"), NULL, LOAD_None, NULL);
	//EnemyProjectileClass = class'AGP_Vehicles.Proj_Mk19G';
	Speed = 6000;
	Damage = 125;
	DamageRadius = 890;
	MomentumTransfer = 5000;
	//MyDamageType = class'AGP_Vehicles.CROWS_Mk19Damage';
	StaticMesh = LoadObject<UStaticMesh>(NULL, TEXT("StaticMesh'/Game/AmericasArmy/Meshes/M_AA2_Weapons/Projectiles/m-m203.m-m203'"), NULL, LOAD_None, NULL);
	DrawScale = 1;
	CollisionRadius = 1;
	CollisionHeight = 1;
}

void AProj_Mk19G::Collision(AActor* HitActor, FVector HitLocation, FVector HitNormal, UMaterialInstance* HitMaterial, ECollisionType Type)
{
	FRotator Rot = FRotator(0, 0, 0);
	FVector HitLoc = FVector(0, 0, 0);
	FVector HitNorm = FVector(0, 0, 0);
	FVector ExplodeLoc = FVector(0, 0, 0);
	/*
	local GrenadeHelper GH;
	float HitDamage = 0;
	FVector HitRay = FVector(0, 0, 0);
	local Actor.BoneInfo HitBone;
	FVector SavedCollisionLocation = FVector(0, 0, 0);
	FRotator SavedRotation = FRotator(0, 0, 0);
	local Material thisHitMaterial;
	FVector ThisHitLocation = FVector(0, 0, 0);
	FVector ThisHitNormal = FVector(0, 0, 0);
	bool bOldUseCollisionStaticMesh = False;
	FinishedBallistics = true;
	bReachedCollision = true;
	if (IsInstigator(HitActor) && (ProjState != 2))
	{
		if (Level.debugGrenade)
		{
			DebugLog(DEBUG_Vehicle, "Skip collision - Hit instigator before dudding");
		}
		return;
	}
	if (((HitActor != nullptr) && (!IsZero(Velocity))) && (Physics != 1))
	{
		SavedCollisionLocation = HitLocation;
		SavedRotation = rotator(Velocity);
		HitRay = (SavedCollisionLocation + (Vector(SavedRotation) * float(100)));
		bOldUseCollisionStaticMesh = bUseCollisionStaticMesh;
		bUseCollisionStaticMesh = true;
		BoneTrace(ThisHitLocation, ThisHitNormal, HitRay, (SavedCollisionLocation + (Vector(SavedRotation) * float(-35))), thisHitMaterial, HitBone, false);
		bUseCollisionStaticMesh = bOldUseCollisionStaticMesh;
		DebugLog(DEBUG_Vehicle, "HitMaterial is " $ string(HitMaterial) $ " and thisHitMaterial is " $ string(thisHitMaterial));
		if (HitBone.HitBone != 0)
		{
			HitDamage = Damage;
			DebugLog(DEBUG_Vehicle, " In ProjectileCollision, Un modified Hitdamage= " $ string(HitDamage));
			if (HitBone.DamageModifier > 0)
			{
				(HitDamage *= HitBone.DamageModifier);
			}
		}
		HitActor.TakeDamage(int(Damage), Instigator, HitLocation, (Normal(HitRay) * MomentumTransfer), ImpactDamageType, , , Self, thisHitMaterial);
		if (ShouldExplode() && (ProjState != 2))
		{
			HitActor.TakeProjectileImpactDamage(int(HitDamage), Instigator, HitLocation, (Normal(HitRay) * MomentumTransfer), ImpactDamageType, , , Self, thisHitMaterial);
		}
	}
	Log("Project " $ string(Self) $ " colliding with " $ string(HitActor));
	if (!_bResolvedState)
	{
		if (Level.NetMode == NM_Client)
		{
			if (ProjState == 1)
			{
				_bResolvedState = true;
				Boom(HitLocation, HitNormal);
				HandleDestroyCall();
			}
			else
			{
				if (ProjState == 2)
				{
					_bResolvedState = true;
				}
				else
				{
					if (!bAlreadySaved)
					{
						SavedHitactor = HitActor;
						SavedHitLocation = HitLocation;
						SavedHitNormal = HitNormal;
						SavedHitMaterial = HitMaterial;
						SavedType = Type;
						SavedLocation = Location;
						SavedVelocity = Velocity;
					}
					SetTimer(0.1, false);
				}
			}
		}
		else
		{
			_bResolvedState = true;
			if (ShouldExplode())
			{
				ProjState = 1;
				Boom(HitLocation, HitNormal);
				ExplodeLoc = (Location + (HitNormal * CollisionHeight));
				GH = Level.GetGrenadeHelper();
				if (!HitActor.IsA("DecoMesh"))
				{
					HitActor = Self;
				}
				GH.GrenHurtRadius(HitActor, ExplodeLoc, DamageRadius, fKillRadius, Damage, MyDamageType, FragDamageType, MomentumTransfer, Default.DamageClasses, InstigatorController);
				GH.GrenadeEffects(HitActor, ExplodeLoc, DamageRadius, fKillRadius, _fEffectDuration, _fAudIntensity, 0);
				HandleDestroyCall();
			}
			else
			{
				ProjState = 2;
			}
		}
	}
	if (ProjState == 2)
	{
		LifeSpan = Default.LifeSpan;
		if ((VSize(Velocity) > float(200)) && (Level.NetMode != NM_DedicatedServer))
		{
			if (HitMaterial == nullptr)
			{
				Trace(HitLoc, HitNorm, (Location + (Velocity * float(1000))), Location, true, vect(0, 0, 0), HitMaterial);
			}
			if (HitMaterial != nullptr)
			{
				PlayLandedSound(HitMaterial);
			}
			else
			{
				PlayOwnedSound(ImpactSound, 1, 1.5, , 150, 0.5, true);
			}
		}
		if (Type == 1)
		{
			if (VSize(Velocity) < float(400))
			{
				bBounce = false;
			}
			Velocity = (MirrorVectorByNormal(Velocity, HitNormal) * RandRange(0.15, 0.25));
		}
		else
		{
			if (Type == 2)
			{
				Velocity = vect(0, 0, 0);
				SetPhysics(PHYS_None);
				Rot = Rotation;
				Rot.Pitch = int((float(-16384) * (vect(0, 0, 1) Dot HitNormal)));
				SetRotation(Rot);
			}
			else
			{
				if (Type == 3)
				{
					Velocity = (MirrorVectorByNormal(Velocity, HitNormal) * RandRange(0.005, 0.1));
				}
			}
		}
	}
	*/
}

void AProj_Mk19G::Boom(FVector HitLocation, FVector HitNormal)
{
	AController* ctrlIterator = nullptr;
	/*
	Super::Boom(HitLocation, HitNormal);
	for (ctrlIterator = Level.ControllerList; ctrlIterator != nullptr; ctrlIterator = ctrlIterator.nextController)
	{
		if (!ctrlIterator.IsA("AIController"))
		{
		}
		if ((AIController(ctrlIterator).Pawn != nullptr) && (VSize((AIController(ctrlIterator).Pawn.Location - HitLocation)) < float(1650)))
		{
			if (ctrlIterator.Pawn.LineOfSightTo(Self))
			{
				AIController(ctrlIterator).NotifyBuzzedByBullet(Owner);
			}
		}
	}
	*/
}

void AProj_Mk19G::Tick(float DeltaTime)
{
	//DrawDebugSphere(GetActorLocation(), 128, 10, 255, 0, 0);
}
