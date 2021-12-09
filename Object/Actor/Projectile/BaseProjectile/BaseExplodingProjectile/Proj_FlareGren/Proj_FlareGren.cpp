// All the original content belonged to the US Army


#include "Proj_FlareGren.h"

AProj_FlareGren::AProj_FlareGren(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	//cTrailEmitterClass = Class'AGP_Effects.aux_em_FlareSmokeTrail'
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