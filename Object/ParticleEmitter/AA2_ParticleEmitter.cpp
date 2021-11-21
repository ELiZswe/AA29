// All the original content belonged to the US Army


#include "AA29/Object/ParticleEmitter/AA2_ParticleEmitter.h"

UAA2_ParticleEmitter::UAA2_ParticleEmitter()
{
	RespawnDeadParticles = true;
	UniformMeshScale = true;
	UniformVelocityScale = true;
	AlphaTest = true;
	ZTest = true;
	UseRegularSizeScale = true;
	AutomaticInitialSpawning = true;
	TriggerDisabled = true;
	LowDetailFactor = 0.65;
	ExtentMultiplier = FVector(1, 1, 1);
	//DampingFactorRange = X = (Min = 1, Max = 1) | Y = (Min = 1, Max = 1) | Z = (Min = 1, Max = 1);
	SpawnFromOtherEmitter = -1;
	//ColorMultiplierRange = X = (Min = 1, Max = 1) | Y = (Min = 1, Max = 1) | Z = (Min = 1, Max = 1);
	Opacity = 1;
	//FadeOutFactor = (W = 1, X = 1, Y = 1, Z = 1);
	//FadeInFactor = (W = 1, X = 1, Y = 1, Z = 1);
	MaxParticles = 10;
	AddLocationFromOtherEmitter = -1;
	StartMassRange = FRange({ 1,1 });
	//VelocityScaleRange = X = (Min = 1, Max = 1) | Y = (Min = 1, Max = 1) | Z = (Min = 1, Max = 1);
	//MeshScaleRange = X = (Min = 1, Max = 1) | Y = (Min = 1, Max = 1) | Z = (Min = 1, Max = 1);
	MeshNormal = FVector(0, 0, 1);
	SpinCCWorCW = FVector(0.5, 0.5, 0.5);
	//StartSizeRange = X = (Min = 100, Max = 100) | Y = (Min = 100, Max = 100) | Z = (Min = 100, Max = 100);
	ScaleSizeByVelocityMultiplier = FVector(1, 1, 1);
	ScaleSizeByVelocityMax = 10000000;
	SkeletalScale = FVector(1, 1, 1);
	RelativeBoneIndexRange = FRange({ 0, 1 });
	//DrawStyle = 3;
	Texture = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/Engine/S_Emitter_Mat.S_Emitter_Mat'"), NULL, LOAD_None, NULL);
	SecondsBeforeInactive = 1;
	LifetimeRange = FRange({ 4, 4 });
	MaxAbsVelocity = FVector(10000, 10000, 10000);
	AddVelocityFromOtherEmitter = -1;
	//AddVelocityMultiplierRange = X = (Min = 1, Max = 1) | Y = (Min = 1, Max = 1) | Z = (Min = 1, Max = 1);
}

//native Function SpawnParticle(int32 Amount);
void SpawnParticle(int32 Amount)
{

}

//native Function Trigger();
void Trigger()
{

}

//native Function Reset();
void Reset()
{

}