// All the original content belonged to the US Army

#include "AA29/Object/Actor/Projectile/BaseProjectile/BaseExplodingProjectile/BaseExplodingProjectile.h"
#include "AA29/Object/DamageType/AGP_DamageType/ExplosionDamage/ExplosionDamage.h"
#include "AA29/Object/DamageType/AGP_DamageType/FragDamage/FragDamage.h"
#include "AA29/Object/DamageType/AGP_DamageType/GrenadeImpact/GrenadeImpact.h"
#include "AA29/Object/Actor/AuxCollisionCylinder/AuxCollisionCylinder.h"
#include "AA29/Object/Actor/GrenadeHelper/GrenadeHelper.h"
#include "AA29/Object/Actor/DecoMesh/DecoMesh.h"
#include "AA29/Object/Actor/Projectile/BaseProjectile/BaseProjectile.h"
#include "AA29/Object/Actor/BodyPanel/BodyPanel.h"
#include "AA29/Object/Actor/Projector/BaseContactProjector/de_bt_grenimpact/de_bt_grenimpact.h"
#include "AA29/Object/Actor/Emitter/BaseContactEmitter/em_bt_grenexplosion/em_bt_grenexplosion.h"
#include "AA29/Object/Actor/Pickup/AGP_WeaponPickup/ThrowWeaponPickup/ThrowWeaponPickup.h"
#include "AA29/Object/Actor/Triggers/Triggers.h"
#include "AA29/Object/Actor/Pawn/Vehicle/Vehicle.h"
#include "AA29/Object/Actor/VehicleWeapon/VehicleWeapon.h"
#include "AA29/Object/Actor/DecoMesh/Mover/Mover.h"

ABaseExplodingProjectile::ABaseExplodingProjectile(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	ArmingTimeRange.Min  = 0.183727f;
	ArmingTimeRange.Max  = 0.498688f;
	ImpactDamage         = 30;
	ImpactDamageType     = UGrenadeImpact::StaticClass();
	FragDamageType       = UFragDamage::StaticClass();
//		ExplosionEmitter = Aem_bt_grenexplosion::StaticClass()

	sWood = {
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/Grenades/WeaponsUS_Grenades_GrenadeBounceWood1_Cue.WeaponsUS_Grenades_GrenadeBounceWood1_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/Grenades/WeaponsUS_Grenades_GrenadeBounceWood2_Cue.WeaponsUS_Grenades_GrenadeBounceWood2_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/Grenades/WeaponsUS_Grenades_GrenadeBounceWood3_Cue.WeaponsUS_Grenades_GrenadeBounceWood3_Cue'"), NULL, LOAD_None, NULL)
	};
	sDirt = {
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/Grenades/WeaponsUS_Grenades_GrenadeBounceDirt1_Cue.WeaponsUS_Grenades_GrenadeBounceDirt1_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/Grenades/WeaponsUS_Grenades_GrenadeBounceDirt2_Cue.WeaponsUS_Grenades_GrenadeBounceDirt2_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/Grenades/WeaponsUS_Grenades_GrenadeBounceDirt3_Cue.WeaponsUS_Grenades_GrenadeBounceDirt3_Cue'"), NULL, LOAD_None, NULL)
	};
	sMetal = {
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/Grenades/WeaponsUS_Grenades_GrenadeBounceMetal1_Cue.WeaponsUS_Grenades_GrenadeBounceMetal1_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/Grenades/WeaponsUS_Grenades_GrenadeBounceMetal2_Cue.WeaponsUS_Grenades_GrenadeBounceMetal2_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/Grenades/WeaponsUS_Grenades_GrenadeBounceMetal3_Cue.WeaponsUS_Grenades_GrenadeBounceMetal3_Cue'"), NULL, LOAD_None, NULL)
	};
	sMuffled = {
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/Grenades/WeaponsUS_Grenades_GrenadebounceMuffled1_Cue.WeaponsUS_Grenades_GrenadebounceMuffled1_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/Grenades/WeaponsUS_Grenades_GrenadebounceMuffled2_Cue.WeaponsUS_Grenades_GrenadebounceMuffled2_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/Grenades/WeaponsUS_Grenades_GrenadebounceMuffled3_Cue.WeaponsUS_Grenades_GrenadebounceMuffled3_Cue'"), NULL, LOAD_None, NULL)
	};
	sConcrete = {
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/Grenades/WeaponsUS_Grenades_Grenadebounce1_Cue.WeaponsUS_Grenades_Grenadebounce1_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/Grenades/WeaponsUS_Grenades_Grenadebounce2_Cue.WeaponsUS_Grenades_Grenadebounce2_Cue'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/Grenades/WeaponsUS_Grenades_Grenadebounce3_Cue.WeaponsUS_Grenades_Grenadebounce3_Cue'"), NULL, LOAD_None, NULL)
	};
	_fAudIntensity        = 1;
	_fEffectDuration      = 10;
	bSetRotation          = true;
	ExplosionSoundRadius  = 1500;
	DamageClasses = {
		//ADecoMesh::StaticClass(),
		//Class'Engine.Pawn',
		//ABaseProjectile::StaticClass(),
		//AThrowWeaponPickup::StaticClass(),
		//ATriggers::StaticClass(),
		//ABodyPanel::StaticClass()
	};
	ExplosionSound			= LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/M203/WeaponsUS_M203_Explosion1_Cue.WeaponsUS_M203_Explosion1_Cue'"), NULL, LOAD_None, NULL);
	Speed					= 4000;
	Damage					= 100;
	DamageRadius			= 1049.868774;
	MomentumTransfer		= 20000;
	MyDamageType			= UExplosionDamage::StaticClass();
	ImpactSound				= LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AA2_WeaponsUS/Grenades/WeaponsUS_Grenades_GrenadeBounceWood1_Cue.WeaponsUS_Grenades_GrenadeBounceWood1_Cue'"), NULL, LOAD_None, NULL);
	//ExplosionDecal = Ade_bt_grenimpact::StaticClass()
	DrawType				= EDrawType::DT_StaticMesh;
	bNetTemporary			= false;
	bAlwaysRelevant			= true;
	//Physics = 2;
	LifeSpan				= 20;
	DrawScale				= 0.5;
	//bUnlit				= false;
	CollisionRadius			= 4;
	CollisionHeight			= 3;
	//bProjTarget			= true;
	//bBounce				= true;
}

/*
auto State Flying
{
	simulated Function Tick(float DeltaTime)
	{
		Super::Tick(DeltaTime);
		if (! IsZero(Velocity))
		{
			if (bSetRotation)
			{
				SetActorRotation((rotator(Velocity) + FRotator(-16384,0,0)));
			}
			if ((GetWorld()->GetNetMode() == NM_Client) && (! bReachedCollision))
			{
				SavedVelocity=Velocity;
			}
		}
		else
		{
			if (! bHasStopped)
			{
				bHasStopped=true;
				if ((GetWorld()->GetNetMode() == NM_Client) && (! bReachedCollision))
				{
					SetPhysics(PHYS_Falling);
					Velocity=SavedVelocity;
				}
			}
		}
	}
	simulated Function HitWall(Vector HitNormal, AActor* Wall)
	{
		ADecoMesh* DM = nullptr;
		if (GetRemoteRole() == ENetRole::ROLE_MAX)
		{
			if (Cast<AMover>(Wall) != nullptr)
			{
				Wall.TakeDamage(int(Damage),Instigator,Location,(MomentumTransfer * Normal(Velocity)),ImpactDamageType,,,Self);
			}
			MakeNoise(1);
		}
		if ((Wall != nullptr) && Wall->IsA(ADecoMesh::StaticClass()))
		{
			DM=DecoMesh(Wall);
			if (DM.bInstantGrenBreak && (DM.DamageHealth > 0))
			{
				DM.TakeDamage((DM.InitialDamageHealth * 1000),Instigator,DM->GetActorLocation(),FVector(0,0,0),nullptr,,,Self);
				return;
			}
		}
		FindCollide(Wall,1);
	}
}
*/

/*
replication
{
	reliable if (((Role == ROLE_Authority) && bNetDirty))
		ProjState, bSetRotation;
}
*/

void ABaseExplodingProjectile::BeginPlay()
{
	Super::BeginPlay();
	//ArmingTime = RandRange(ArmingTimeRange.Min, ArmingTimeRange.Max);
}

void ABaseExplodingProjectile::Boom(FVector HitLocation, FVector HitNormal)
{
	/*
	if (GetNetMode() != ENetMode::NM_DedicatedServer)
	{
		if (IsEnemyProjectile())
		{
			ExplosionSound = EnemyProjectileClass.Default.ExplosionSound;
		}
		PlayOwnedSound(ExplosionSound, 0, 1, , ExplosionSoundRadius, , true);
		if (ExplosionDecal != nullptr)
		{
			Spawn(ExplosionDecal, , , HitLocation, rotator((-HitNormal)));
		}
		if (ExplosionEmitter != nullptr)
		{
			Spawn(ExplosionEmitter, , , HitLocation, rotator((-HitNormal)));
		}
	}
	SetDrawType(DT_None);
	SetPhysics(PHYS_None);
	Velocity = FVector(0, 0, 0);
	*/
}

void ABaseExplodingProjectile::HandleDestroyCall()
{
	if (GetNetMode() != ENetMode::NM_DedicatedServer)
	{
		Destroy();
	}
	else
	{
		//SetTimer(0.5, false);
	}
}

bool ABaseExplodingProjectile::ShouldExplode()
{
	return ((DamageRadius > 0) && ((GetDefault<ABaseExplodingProjectile>()->LifeSpan - LifeSpan) > ArmingTime));
}

void ABaseExplodingProjectile::Timer()
{
	if (!_bResolvedState)
	{
		if (ProjState != 0)
		{
			//SetLocation(SavedLocation);
			//Velocity = SavedVelocity;
			Collision(SavedHitactor, SavedHitLocation, SavedHitNormal, SavedHitMaterial, SavedType);
		}
		else
		{
			//SetTimer(0.1, false);
		}
	}
	else
	{
		if (GetNetMode() == ENetMode::NM_DedicatedServer)
		{
			Destroy();
		}
	}
}

bool ABaseExplodingProjectile::IsInstigator(AActor* Other)
{
	if (Other == nullptr)
	{
		return false;
	}
	else
	{
		if (Other == GetInstigator())
		{
			return true;
		}
		else
		{
			if (Other->IsA(AAuxCollisionCylinder::StaticClass()) && (Other->GetOwner() == GetInstigator()))
			{
				return true;
			}
			else
			{
				return false;
			}
		}
	}
}

void ABaseExplodingProjectile::Collision(AActor* HitActor, FVector HitLocation, FVector HitNormal, UMaterialInstance* HitMaterial, ECollisionType Type)
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
	if (IsInstigator(HitActor) && (ProjState != 2))
	{
		if (Level.debugGrenade)
		{
			Log("Skip collision - Hit instigator before dudding");
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
		if (Level.debugGrenade)
		{
			Log("HitMaterial is " + FString::FromInt(HitMaterial) + " and thisHitMaterial is " + FString::FromInt(thisHitMaterial));
		}
		if (HitBone.HitBone != 0)
		{
			HitDamage = (ImpactDamage * (VSize(Velocity) / Default.Speed));
			if (Level.debugGrenade)
			{
				Log(" In ProjectileCollision, Un modified Hitdamage= " + FString::FromInt(HitDamage));
			}
			if (HitBone.DamageModifier > 0)
			{
				(HitDamage *= HitBone.DamageModifier);
			}
		}
		if (((!HitActor->IsA(AVehicle::StaticClass())) && (!HitActor->IsA(AVehicleWeapon::StaticClass()))) && (!HitActor->IsA(ABodyPanel::StaticClass())))
		{
			HitActor.TakeDamage(int(HitDamage), Instigator, HitLocation, (Normal(HitRay) * MomentumTransfer), ImpactDamageType, , , this, thisHitMaterial);
		}
		else
		{
			if (ShouldExplode() && (ProjState != 2))
			{
				HitDamage = ((ImpactDamage * VSize(Velocity)) / Default.Speed);
				HitActor.TakeProjectileImpactDamage(int(HitDamage), Instigator, HitLocation, (Normal(HitRay) * MomentumTransfer), ImpactDamageType, , , this, thisHitMaterial);
			}
		}
	}
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
				ExplodeLoc = (Location + (HitNormal * CollisionHeight));
				GH = Level.GetGrenadeHelper();
				if (!HitActor->IsA(ADecoMesh::StaticClass()))
				{
					HitActor = this;
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

/*
void ABaseExplodingProjectile::TakeDamage(int32 Damage, APawn* instigatedBy, Vector HitLocation, Vector Momentum, class<DamageType>  DamageType, FBoneInfo Bone, AController* KillerController, AActor* ResponsibleActor, UMaterialInstance* HitMaterial)
{
}
*/

void ABaseExplodingProjectile::PlayLandedSound(UMaterialInstance* HitMaterial)
{
	USoundBase* S = nullptr;
	/*
	switch (HitMaterial.GetMaterialType())
	{
		case 0:
			return;
		case 18:
		case 19:
		case 20:
		case 1:
			S = sWood[FMath::Rand()*sWood.Num()];
			break;
		case 2:
			S = sDirt[FMath::Rand()*sDirt.Num()];
			break;
		case 3:
			S = sDirt[FMath::Rand()*sDirt.Num()];
			break;
		case 21:
		case 22:
		case 23:
		case 4:
			S = sMetal[FMath::Rand()*sMetal.Num()];
			break;
		case 5:
			S = sMetal[FMath::Rand()*sMetal.Num()];
			break;
		case 6:
			S = sConcrete[FMath::Rand()*sConcrete.Num()];
			break;
		case 7:
			S = sMuffled[FMath::Rand()*sMuffled.Num()];
			break;
		case 8:
			break;
		case 9:
			S = sDirt[FMath::Rand()*sDirt.Num()];
			break;
		case 10:
			S = sMetal[FMath::Rand()*sMetal.Num()];
			break;
		case 11:
			S = sWood[FMath::Rand()*sWood.Num()];
			break;
		case 12:
			S = sMuffled[FMath::Rand()*sMuffled.Num()];
			break;
		case 13:
			S = sMuffled[FMath::Rand()*sMuffled.Num()];
			break;
		case 14:
			S = sDirt[FMath::Rand()*sDirt.Num()];
			break;
		case 15:
			S = sDirt[FMath::Rand()*sDirt.Num()];
			break;
		case 16:
			S = sDirt[FMath::Rand()*sDirt.Num()];
			break;
		case 17:
			S = sMetal[FMath::Rand()*sMetal.Num()];
			break;
		default:
			break;
	}
	//PlaySound(S, 1, 0.4, , 300, 0.5, true);
	*/
}
