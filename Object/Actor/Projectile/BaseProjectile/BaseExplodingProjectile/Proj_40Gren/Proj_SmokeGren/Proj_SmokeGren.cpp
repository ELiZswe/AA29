// All the original content belonged to the US Army

#include "AA29/Object/Actor/Projectile/BaseProjectile/BaseExplodingProjectile/Proj_40Gren/Proj_SmokeGren/Proj_SmokeGren.h"

AProj_SmokeGren::AProj_SmokeGren(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	EnemyProjectileClass  = AProj_SmokeGren::StaticClass();
	LightHue              = 22;
	LightSaturation       = 177;
	LightBrightness       = 55;
	LightRadius           = 399;
	DrawType              = EDrawType::DT_None;
	bDynamicLight         = true;
	LifeSpan              = 40;
	DrawScale             = 1;
	Skins = {
		Cast<UMaterialInstance>(StaticLoadObject(UMaterialInstance::StaticClass(), NULL, TEXT("MaterialInstance'/Game/AmericasArmy/Textures/T_AA2_FX/Animated/fx2_anim_05_Mat.fx2_anim_05_Mat'")))
	};
}
