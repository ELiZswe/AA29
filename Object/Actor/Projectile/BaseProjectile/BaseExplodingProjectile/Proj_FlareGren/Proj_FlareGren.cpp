// All the original content belonged to the US Army

#include "AA29/Object/Actor/Projectile/BaseProjectile/BaseExplodingProjectile/Proj_FlareGren/Proj_FlareGren.h"
#include "AA29/Object/Actor/Emitter/aux_em_FlareSmokeTrail/aux_em_FlareSmokeTrail.h"

AProj_FlareGren::AProj_FlareGren(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	//cTrailEmitterClass = Aaux_em_FlareSmokeTrail::StaticClass()
	EnemyProjectileClass  = AProj_FlareGren::StaticClass();
	LightHue              = 22;
	LightSaturation       = 177;
	LightBrightness       = 55;
	LightRadius           = 399;
	StaticMesh            = LoadObject<UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AA2_Weapons/Projectiles/m-m203.m-m203"), NULL, LOAD_None, NULL);
	bDynamicLight         = true;
	LifeSpan              = 40;
	DrawScale             = 1;
	Skins = {
		Cast<UMaterialInstance>(StaticLoadObject(UMaterialInstance::StaticClass(), NULL, TEXT("MaterialInstance'/Game/AmericasArmy/Textures/T_AA2_FX/Animated/fx2_anim_05_Mat.fx2_anim_05_Mat'")))
	};
}

void AProj_FlareGren::Collision(AActor* HitActor, FVector HitLocation, FVector HitNormal, UMaterialInstance* HitMaterial, ECollisionType Type)
{
	if (bFlareOn)
	{
		LightRadius = 122;
	}
	else
	{
		/*
		if ((HitActor != nullptr) && (HitActor != Instigator))
		{
			HitActor.TakeDamage(int(ImpactDamage), Instigator, HitLocation, FVector(0, 0, 0), ImpactDamageType, , , this);
		}
		*/
		Destroy();
	}
}

void AProj_FlareGren::BeginPlay()
{
	Super::BeginPlay();
	//SetTimer(3, false);
}

void AProj_FlareGren::Timer()
{
	SpawnFlare();
}

void AProj_FlareGren::SpawnFlare()
{
	//SetDrawType(DT_Sprite);
	LightType = ELightType::LT_Steady;
	//bCorona = true;
	//SetTimer(12, false);
	//MaximumVelocity = 112;
	bFlareOn = true;
}
