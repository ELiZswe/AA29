// All the original content belonged to the US Army

#include "AA29/Object/Actor/Projectile/BaseProjectile/BaseExplodingProjectile/Proj_60mmMortar/Proj_60mmSmokeMortar/Proj_60mmSmokeMortar.h"
#include "AA29/Object/Actor/GrenadeHelper/GrenadeHelper.h"
#include "AA29/Object/Actor/Pickup/AGP_WeaponPickup/ThrowWeaponPickup/PickupT_M83_Smoke/PickupT_M83_Smoke.h"
#include "AA29/Object/Actor/EffectLocation/EffectLocation.h"

AProj_60mmSmokeMortar::AProj_60mmSmokeMortar(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	ExplosionSound = LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/Grenades/WeaponsUS_Grenades_M83SmokeBang.WeaponsUS_Grenades_M83SmokeBang"), NULL, LOAD_None, NULL);
}

void AProj_60mmSmokeMortar::PreBeginPlay()
{
	idTeamOwner = 2;
}

bool AProj_60mmSmokeMortar::IsEnemyProjectile()
{
	return false;
}

void AProj_60mmSmokeMortar::PostBeginPlay()
{
	USoundBase* sndMortar = nullptr;
	AActor* actMortarLaunchSound = nullptr;
	/*
	sndMortar = Sound'S_AAO_Armory.60mm_Mortar.s_arm_mortar_incoming_whistle';
	actMortarLaunchSound = Spawn(AEffectLocation::StaticClass(), , , Location);
	actMortarLaunchSound.LifeSpan = GetSoundDuration(sndMortar);
	actMortarLaunchSound.PlaySound(sndMortar, 0, 1, false, 2500, , true);
	*/
}

bool AProj_60mmSmokeMortar::ShouldExplode()
{
	return true;
}

void AProj_60mmSmokeMortar::Collision(AActor* HitActor, FVector HitLocation, FVector HitNormal, UMaterialInstance* HitMaterial, ECollisionType Type)
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
		if (GetWorld()->GetNetMode() == NM_Client)
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
		if ((VSize(Velocity) > float(200)) && (GetNetMode() != ENetMode::NM_DedicatedServer))
		{
			if (HitMaterial == nullptr)
			{
				Trace(HitLoc, HitNorm, (Location + (Velocity * float(1000))), Location, true, FVector(0, 0, 0), HitMaterial);
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
				Velocity = FVector(0, 0, 0);
				SetPhysics(PHYS_None);
				Rot = Rotation;
				Rot.Pitch = int((float(-16384) * (FVector(0, 0, 1) Dot HitNormal)));
				SetActorRotation(Rot);
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

void AProj_60mmSmokeMortar::Boom(FVector HitLocation, FVector HitNormal)
{
	APickupT_M83_Smoke* ptm83smoke = nullptr;
	/*
	PlayOwnedSound(sndSmoke, 0, 1, , ExplosionSoundRadius, , true);
	Spawn(ExplosionEmitter, , , HitLocation, rotator((-HitNormal)));
	(HitLocation.Z += float(20));
	ptm83smoke = Spawn(APickupT_M83_Smoke::StaticClass(), , , HitLocation);
	ptm83smoke._bBlewUp = true;
	SetDrawType(DT_None);
	SetPhysics(PHYS_None);
	Velocity = FVector(0, 0, 0);
	*/
}
