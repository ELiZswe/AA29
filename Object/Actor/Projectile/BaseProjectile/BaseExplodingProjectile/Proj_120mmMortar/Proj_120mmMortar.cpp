// All the original content belonged to the US Army

#include "AA29/Object/Actor/Projectile/BaseProjectile/BaseExplodingProjectile/Proj_120mmMortar/Proj_120mmMortar.h"
#include "AA29/Object/DamageType/AGP_DamageType\RocketImpact\Mortar_120mm_ImpactDamage.h"
#include "AA29/Object/DamageType/AGP_DamageType\FragDamage\Mortar_60mm_FragDamage.h"
#include "AA29/Object/Actor/Projectile/BaseProjectile\BaseExplodingProjectile\Proj_60mmMortar\Proj_60mmMortar.h"
#include "AA29/Object/DamageType/ArtilleryDamage/MortarDamage/MortarDamage.h"
#include "AA29/Object/Actor/Projectile/BaseProjectile/BaseProjectile.h"
#include "AA29/Object/Actor/BodyPanel/BodyPanel.h"
#include "AA29/Object/Actor/DecoMesh/DecoMesh.h"
#include "AA29/Object/Actor/EffectLocation/EffectLocation.h"
#include "AA29/Object/Actor/Emitter/BaseContactEmitter/em_bt_PG7Bexplosion/em_bt_PG7Bexplosion.h"
#include "AA29/Object/Actor/Projectile/BaseProjectile/BaseExplodingProjectile/Proj_60mmMortar/Proj_60mmMortar.h"
#include "AA29/Object/Actor/Pickup/AGP_WeaponPickup/ThrowWeaponPickup/ThrowWeaponPickup.h"
#include "AA29/Object/Actor/Triggers/Triggers.h"

AProj_120mmMortar::AProj_120mmMortar(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	ImpactDamage          = 350;
	ImpactDamageType      = UMortar_120mm_ImpactDamage::StaticClass();
	FragDamageType        = UMortar_60mm_FragDamage::StaticClass();
	//ExplosionEmitter = Aem_bt_PG7Bexplosion::StaticClass()
	DamageClasses = {
		//ADecoMesh::StaticClass(),
		//Class'Engine.Pawn',
		//ABaseProjectile::StaticClass(),
		//AThrowWeaponPickup::StaticClass(),
		//ATriggers::StaticClass(),
		//ABodyPanel::StaticClass(),
		//Class'AGP_Gameplay.AGP_MortarRangeDestroyableObjective'
	};
	fKillRadius = 600;
	ExplosionSound        = LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AAO_Armory/60mm_Mortar/s_arm_mortar_impact_explosion.s_arm_mortar_impact_explosion"), NULL, LOAD_None, NULL);
	EnemyProjectileClass  = AProj_60mmMortar::StaticClass();
	Speed                 = 5000;
	MaxSpeed              = 5500;
	Damage                = 200;
	DamageRadius          = 1500;
	MyDamageType          = UMortarDamage::StaticClass();
	StaticMesh            = LoadObject<UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AA2_Weapons/Projectiles/wpn2_shells_usmortar.wpn2_shells_usmortar"), NULL, LOAD_None, NULL);
	Rotation              = FRotator(0, 0, 90);
	DrawScale3D           = FVector(4, 4, 4);
}

void AProj_120mmMortar::PreBeginPlay()
{
	idTeamOwner = 2;
}

bool AProj_120mmMortar::IsEnemyProjectile()
{
	return false;
}

void AProj_120mmMortar::PostBeginPlay()
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

void AProj_120mmMortar::BeginPlay()
{
	Super::BeginPlay();
	//SetRotation(FRotator(0, 16384, 0));
}

void AProj_120mmMortar::Boom(FVector HitLocation, FVector HitNormal)
{
	AController* ctrlIterator = nullptr;
	Super::Boom(HitLocation, HitNormal);
	/*
	if (GetWorld()->GetNetMode() == NM_Client)
	{
		return;
	}
	for (ctrlIterator = Level.ControllerList; ctrlIterator != nullptr; ctrlIterator = ctrlIterator.nextController)
	{
		if (!ctrlIterator->IsA(AaAIController::StaticClass()))
		{
		}
		if ((Cast<AAIController>(ctrlIterator).Pawn != nullptr) && (VSize((Cast<AAIController>(ctrlIterator).Pawn.Location - Location)) < float(3300)))
		{
			Cast<AaAIController>(ctrlIterator).NotifyBuzzedByBullet(GetOwner());
		}
	}
	*/
}
