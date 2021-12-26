// All the original content belonged to the US Army

#include "AA29/Object/Actor/Projectile/BaseProjectile/BaseExplodingProjectile/Proj_60mmMortar/Proj_60mmMortar.h"
#include "AA29/Object/DamageType/AGP_DamageType\FragDamage\Mortar_60mm_FragDamage.h"
#include "AA29/Object/DamageType/AGP_DamageType\RocketImpact\Mortar_60mm_ImpactDamage.h"
#include "AA29/Object/Actor/Projectile/BaseProjectile\BaseExplodingProjectile\Proj_60mmMortar\Proj_60mmMortar.h"
#include "AA29/Object/DamageType/ArtilleryDamage/MortarDamage/MortarDamage.h"

AProj_60mmMortar::AProj_60mmMortar(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	ImpactDamage          = 250;
	ImpactDamageType      = UMortar_60mm_ImpactDamage::StaticClass();
	FragDamageType        = UMortar_60mm_FragDamage::StaticClass();
	//ExplosionEmitter = Class'AGP_Effects.em_bt_PG7Bexplosion'

	DamageClasses = {
		//Class'Engine.DecoMesh',
		//Class'Engine.Pawn',
		//Class'Engine.BaseProjectile',
		//Class'AGP.ThrowWeaponPickup',
		//Class'Engine.Triggers',
		//Class'AGP.BodyPanel',
		//Class'AGP_Gameplay.AGP_MortarRangeDestroyableObjective'
	};
	fKillRadius = 200;
	ExplosionSound        = LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AAO_Armory/60mm_Mortar/s_arm_mortar_impact_explosion.s_arm_mortar_impact_explosion"), NULL, LOAD_None, NULL);
	EnemyProjectileClass  = AProj_60mmMortar::StaticClass();
	Speed                 = 5000;
	MaxSpeed              = 5500;
	DamageRadius          = 750;
	MyDamageType          = UMortarDamage::StaticClass();
	StaticMesh            = LoadObject<UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AA2_Weapons/Projectiles/wpn2_shells_usmortar.wpn2_shells_usmortar"), NULL, LOAD_None, NULL);
	Rotation              = FRotator (0, 0, 90);
	DrawScale3D           = FVector(4, 4, 4);
}

void AProj_60mmMortar::PostNetBeginPlay()
{
	//Super::PostNetBeginPlay();
	//SetRotation(MakeRot(0, 16384, 0));
}

void AProj_60mmMortar::PreBeginPlay()
{
	idTeamOwner = 2;
}

bool AProj_60mmMortar::IsEnemyProjectile()
{
	return false;
}

void AProj_60mmMortar::PostBeginPlay()
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

void AProj_60mmMortar::BeginPlay()
{
	Super::BeginPlay();
	//SetRotation(MakeRot(0, 16384, 0));
}

void AProj_60mmMortar::Boom(FVector HitLocation, FVector HitNormal)
{
	/*
	local Controller ctrlIterator;
	Super::Boom(HitLocation, HitNormal);
	if (Level.NetMode == NM_Client)
	{
		return;
	}
	ctrlIterator = Level.ControllerList;
	if (ctrlIterator != None)
	{
		if (!ctrlIterator.IsA("AIController"))
		{
		}
		if ((AIController(ctrlIterator).Pawn != None) && (VSize((AIController(ctrlIterator).Pawn.Location - HitLocation)) < float(1650)))
		{
			AIController(ctrlIterator).NotifyBuzzedByBullet(Owner);
		}
		ctrlIterator = ctrlIterator.nextController;
	}
	if ((Level.NetMode == NM_Standalone) && (Pawn(Owner).Controller != None))
	{
		if (Pawn(Owner).Controller.EventLab != None)
		{
			Pawn(Owner).Controller.EventLab.MortarTrainingRoundLanded(HitLocation);
		}
	}
	*/
}
