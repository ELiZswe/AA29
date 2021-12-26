// All the original content belonged to the US Army

#include "AA29/Object/Actor/Projectile/BaseProjectile/BaseExplodingProjectile/Proj_60mmMortar/Proj_60mmTrainingMortar/Proj_60mmTrainingMortar.h"
#include "AA29/Object/Actor/GrenadeHelper/GrenadeHelper.h"

AProj_60mmTrainingMortar::AProj_60mmTrainingMortar(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	//ExplosionEmitter = Class'AGP_Effects.em_bt_flashbang'
	fKillRadius           = 0;
	ExplosionSound        = LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/Grenades/WeaponsUS_Grenades_M83SmokeBang.WeaponsUS_Grenades_M83SmokeBang"), NULL, LOAD_None, NULL);
	EnemyProjectileClass  = AProj_60mmTrainingMortar::StaticClass();
	Damage                = 50;
	DamageRadius          = 50;
}

void AProj_60mmTrainingMortar::PreBeginPlay()
{
	idTeamOwner = 0;
}

bool AProj_60mmTrainingMortar::IsEnemyProjectile()
{
	return false;
}

void AProj_60mmTrainingMortar::PostBeginPlay()
{
	USoundBase* sndMortar = nullptr;
	AActor* actMortarLaunchSound = nullptr;
	/*
	sndMortar = Sound'S_AAO_Armory.60mm_Mortar.s_arm_mortar_incoming_whistle';
	actMortarLaunchSound = Spawn(Class'EffectLocation', , , Location);
	actMortarLaunchSound.LifeSpan = GetSoundDuration(sndMortar);
	actMortarLaunchSound.PlaySound(sndMortar, 0, 1, false, 2500, , true);
	*/
}

void AProj_60mmTrainingMortar::BeginPlay()
{
	Super::BeginPlay();
	//SetRotation(MakeRot(0, 16384, 0));
}

bool AProj_60mmTrainingMortar::ShouldExplode()
{
	return true;
}

void AProj_60mmTrainingMortar::Collision(AActor* HitActor, FVector HitLocation, FVector HitNormal, UMaterialInstance* HitMaterial, ECollisionType Type)
{
	FRotator Rot = FRotator(0, 0, 0);
	FVector HitLoc = FVector(0, 0, 0);
	FVector HitNorm = FVector(0, 0, 0);
	FVector ExplodeLoc = FVector(0, 0, 0);
	AGrenadeHelper* GH = nullptr;
	float HitDamage = 0;
	FVector HitRay = FVector(0, 0, 0);
	FBoneInfo HitBone;
	FVector SavedCollisionLocation = FVector(0, 0, 0);
	FRotator SavedRotation = FRotator(0, 0, 0);
	UMaterialInstance* thisHitMaterial = nullptr;
	FVector ThisHitLocation = FVector(0, 0, 0);
	FVector ThisHitNormal = FVector(0, 0, 0);
	bool bOldUseCollisionStaticMesh = false;
	bReachedCollision = true;
	/*
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
			if (HitMaterial != None)
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

void AProj_60mmTrainingMortar::Boom(FVector HitLocation, FVector HitNormal)
{
	/*
	local PickupT_M83_Smoke ptm83smoke;
	PlayOwnedSound(sndSmoke, 0, 1, , ExplosionSoundRadius, , true);
	Spawn(ExplosionEmitter, , , HitLocation, rotator((-HitNormal)));
	(HitLocation.Z += float(20));
	ptm83smoke = Spawn(class'AGP_Inventory.PickupT_M83_Smoke', , , HitLocation);
	ptm83smoke._bBlewUp = true;
	ptm83smoke._EffectDuration = (0.5 + (FRand() * 1));
	ptm83smoke.bHidden = true;
	SetDrawType(DT_None);
	SetPhysics(PHYS_None);
	Velocity = vect(0, 0, 0);
	if ((Pawn(Owner).Controller != None) && (Pawn(Owner).Controller.EventLab != None))
	{
		Pawn(Owner).Controller.EventLab.MortarTrainingRoundLanded(HitLocation);
	}
	*/
}
