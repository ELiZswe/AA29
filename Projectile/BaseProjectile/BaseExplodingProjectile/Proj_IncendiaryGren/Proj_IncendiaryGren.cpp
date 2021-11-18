// All the original content belonged to the US Army


#include "Proj_IncendiaryGren.h"

AProj_IncendiaryGren::AProj_IncendiaryGren(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	EnemyProjectileClass  = AProj_IncendiaryGren::StaticClass();
	LightHue              = 22;
	LightSaturation       = 177;
	LightBrightness       = 55;
	LightRadius           = 399;
	DrawType              = EDrawType::DT_None;
	bDynamicLight         = true;
	LifeSpan              = 40;
	DrawScale             = 1;
	Skins                 = {
	                                 Cast<UMaterialInstance>(StaticLoadObject(UMaterialInstance::StaticClass(), NULL, TEXT("MaterialInstance'/Game/AmericasArmy/Textures/T_AA2_FX/Animated/fx2_anim_05_Mat.fx2_anim_05_Mat'")))
	                        };
}