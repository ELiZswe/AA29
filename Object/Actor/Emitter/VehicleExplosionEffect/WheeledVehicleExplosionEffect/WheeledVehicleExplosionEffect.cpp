// All the original content belonged to the US Army

#include "WheeledVehicleExplosionEffect.h"
#include "AA29/Object/BaseEmitter/ParticleEmitter/MeshEmitter/MeshEmitter.h"
#include "AA29/Object/BaseEmitter/ParticleEmitter/SpriteEmitter/SpriteEmitter.h"

AWheeledVehicleExplosionEffect::AWheeledVehicleExplosionEffect()
{
	UMeshEmitter* MeshEmitter0 = NewObject<UMeshEmitter>(UMeshEmitter::StaticClass());
	MeshEmitter0->UseCollision = true;
	MeshEmitter0->UseColorScale = true;
	MeshEmitter0->RespawnDeadParticles = false;
	MeshEmitter0->AlphaTest = false;
	MeshEmitter0->SpinParticles = true;
	MeshEmitter0->DampRotation = true;
	MeshEmitter0->UseSizeScale = true;
	MeshEmitter0->UseRegularSizeScale = false;
	MeshEmitter0->UniformSize = true;
	MeshEmitter0->AutomaticInitialSpawning = false;
	MeshEmitter0->Acceleration = FVector(0, 0, -500);
	MeshEmitter0->ExtentMultiplier = FVector(1, 1, 0.5);
	MeshEmitter0->DampingFactorRange = FRangeVector({ {0.6, 0.6}, {0.6, 0.6}, {0.2, 0.2} });
	//MeshEmitter0->ColorScale[0]=FParticleColorScale({0,FColor(255, 255, 255, 255)});
	//MeshEmitter0->ColorScale[1]=FParticleColorScale({1,FColor(255, 255, 255, 0)});
	MeshEmitter0->FadeOutStartTime = 2;
	MeshEmitter0->MaxParticles = 1;
	MeshEmitter0->AddLocationFromOtherEmitter = 0;
	MeshEmitter0->SpinsPerSecondRange = FRangeVector({ {0, 0.5}, {1, -1}, {0, 0.5} });
	MeshEmitter0->StartSpinRange = FRangeVector({ {0, 0}, {0, 0}, {0.25, 0.25} });
	//MeshEmitter0->SizeScale[0]=FParticleTimeScale({0,1});
	//MeshEmitter0->SizeScale[1]=FParticleTimeScale({0.9,1});
	//MeshEmitter0->SizeScale[2]=FParticleTimeScale({0.97,1});
	//MeshEmitter0->SizeScale[3]=FParticleTimeScale({1,0});
	MeshEmitter0->StartSizeRange = FRangeVector({ {0.7, 0.7}, {0.7, 0.7}, {0.7, 0.7} });
	MeshEmitter0->InitialParticlesPerSecond = 1000;
	MeshEmitter0->DrawStyle = EParticleDrawStyle::PTDS_Regular;
	MeshEmitter0->Texture = nullptr;
	MeshEmitter0->LifetimeRange = FRange({ 5, 5 });
	MeshEmitter0->AddVelocityFromOtherEmitter = 0;
	/*
	Emitters(0) = SpriteEmitter'AGP_Vehicles.VehicleExplosionEffect.SpriteEmitter0'
		Emitters(1) = SpriteEmitter'AGP_Vehicles.VehicleExplosionEffect.SpriteEmitter1'
		Emitters(2) = SpriteEmitter'AGP_Vehicles.VehicleExplosionEffect.SpriteEmitter2'
		Emitters(3) = SpriteEmitter'AGP_Vehicles.VehicleExplosionEffect.SpriteEmitter11'
		Emitters(4) = SpriteEmitter'AGP_Vehicles.VehicleExplosionEffect.SpriteEmitter3'
		Emitters(5) = SpriteEmitter'AGP_Vehicles.VehicleExplosionEffect.SpriteEmitter7'
		Emitters(6) = MeshEmitter'AGP_Vehicles.WheeledVehicleExplosionEffect.MeshEmitter0';
		*/
};