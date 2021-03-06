// All the original content belonged to the US Army

#include "AA29/Object/Actor/Info/FluidSurfaceInfo/FluidSurfaceInfo.h"

AFluidSurfaceInfo::AFluidSurfaceInfo()
{
	FluidGridType = EFluidGridType::FGT_Hexagonal;
	FluidGridSpacing = 24;
	FluidXSize = 48;
	FluidYSize = 48;
	FluidHeightScale = 1;
	FluidSpeed = 170;
	FluidTimeScale = 1;
	FluidDamping = 0.5;
	FluidNoiseFrequency = 60;
	FluidNoiseStrength = FRange({ -70, 70 });
	TestRippleSpeed = 3000;
	TestRippleStrength = -20;
	TestRippleRadius = 48;
	UTiles = 1;
	VTiles = 1;
	AlphaHeightScale = 10;
	AlphaMax = 128;
	ShootStrength = -50;
	RippleVelocityFactor = -0.05;
	TouchStrength = -50;
	WarmUpTime = 2;
	UpdateRate = 50;
	//DrawType = DT_FluidSurface;
	//bHidden = false;
	//bNoDelete = true;
	//Texture = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/Engine/S_FluidSurf_Mat.S_FluidSurf_Mat'"), NULL, LOAD_None, NULL);
	//bUnlit = true;
	//bCollideActors = true;
	//bEdShouldSnap = true;
}

//native final Function Pling(Vector Position, float Strength, float Radius);
void AFluidSurfaceInfo::Pling(FVector Position, float Strength, float Radius)
{

}
/*
void AFluidSurfaceInfo::TakeDamage(int32 Damage, Pawn instigatedBy, Vector HitLocation, Vector Momentum, class<DamageType>  DamageType, FBoneInfo Bone, Controller KillerController, Actor ResponsibleActor, Material HitMaterial)
{
	if (DamageType.Default.FluidSurfaceShootStrengthMod ~= 0)
	{
		return;
	}
	Pling(HitLocation, (ShootStrength * DamageType.Default.FluidSurfaceShootStrengthMod), ShootRadius);
	if ((ShootEffect != nullptr) && EffectIsRelevant(HitLocation, false))
	{
		if (OrientShootEffect)
		{
			Spawn(ShootEffect, this, , HitLocation, rotator(Momentum));
		}
		else
		{
			Spawn(ShootEffect, this, , HitLocation);
		}
	}
}
*/

void AFluidSurfaceInfo::Touch(AActor* Other)
{
	FVector touchLocation = FVector(0, 0, 0);
	/*
	Super::Touch(Other);
	if ((Other == nullptr) || (!Other.bDisturbFluidSurface))
	{
		return;
	}
	touchLocation = Other.Location;
	Pling(touchLocation, (ShootStrength * Other.FluidSurfaceShootStrengthMod), Other.CollisionRadius);
	touchLocation.Z = Location.Z;
	if ((TouchEffect != nullptr) && EffectIsRelevant(touchLocation, false))
	{
		if (OrientTouchEffect)
		{
			Spawn(TouchEffect, this, , touchLocation, rotator(Other.Velocity));
		}
		else
		{
			Spawn(TouchEffect, this, , touchLocation);
		}
	}
	*/
}
