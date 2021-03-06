// All the original content belonged to the US Army

#include "AA29/Object/Actor/Emitter/VehicleExplosionEffect/VehicleExplosionEffect.h"
#include "AA29/Object/BaseEmitter/ParticleEmitter/SpriteEmitter/SpriteEmitter.h"

AVehicleExplosionEffect::AVehicleExplosionEffect()
{
	USpriteEmitter* SpriteEmitter7 = NewObject<USpriteEmitter>(USpriteEmitter::StaticClass());
	SpriteEmitter7->RespawnDeadParticles = false;
	SpriteEmitter7->SpinParticles = true;
	SpriteEmitter7->UseSizeScale = true;
	SpriteEmitter7->UseRegularSizeScale = false;
	SpriteEmitter7->UniformSize = true;
	SpriteEmitter7->AutomaticInitialSpawning = false;
	SpriteEmitter7->BlendBetweenSubdivisions = true;
	SpriteEmitter7->Opacity = 0.5;
	SpriteEmitter7->StartLocationRange = FRangeVector({ {0, 0}, {0, 0}, {0, 15} });
	SpriteEmitter7->StartLocationShape = EParticleStartLocationShape::PTLS_All;
	SpriteEmitter7->StartLocationPolarRange = FRangeVector({ {0, 65536}, {16384, 16384}, {80, 150} });
	SpriteEmitter7->StartSpinRange = FRangeVector({ {0, 1}, {0, 0}, {0, 0} });
	//SpriteEmitter7->SizeScale[0]=FParticleTimeScale({0,0.2});
	//SpriteEmitter7->SizeScale[1]=FParticleTimeScale({1,1.5});
	SpriteEmitter7->InitialParticlesPerSecond = 50;
	SpriteEmitter7->TextureUSubdivisions = 2;
	SpriteEmitter7->TextureVSubdivisions = 4;
	SpriteEmitter7->LifetimeRange = FRange({ 0.7, 0.7 });
	SpriteEmitter7->InitialDelayRange = FRange({ 0.15, 0.15 });
	USpriteEmitter* SpriteEmitter3 = NewObject<USpriteEmitter>(USpriteEmitter::StaticClass());
	SpriteEmitter3->RespawnDeadParticles = false;
	SpriteEmitter3->SpinParticles = true;
	SpriteEmitter3->UseSizeScale = true;
	SpriteEmitter3->UseRegularSizeScale = false;
	SpriteEmitter3->UniformSize = true;
	SpriteEmitter3->AutomaticInitialSpawning = false;
	SpriteEmitter3->BlendBetweenSubdivisions = true;
	SpriteEmitter3->UseVelocityScale = true;
	SpriteEmitter3->MaxParticles = 5;
	SpriteEmitter3->DetailMode = EDetailMode::DM_Medium;
	SpriteEmitter3->StartLocationRange = FRangeVector({ {0, 0}, {0, 0}, {0, 15} });
	SpriteEmitter3->StartLocationShape = EParticleStartLocationShape::PTLS_All;
	SpriteEmitter3->StartLocationPolarRange = FRangeVector({ {0, 65536}, {16384, 16384}, {100, 100} });
	SpriteEmitter3->StartSpinRange = FRangeVector({ {0, 1}, {0, 0}, {0, 0} });
	//SpriteEmitter3->SizeScale[0]=FParticleTimeScale({0,0.5});
	//SpriteEmitter3->SizeScale[1]=FParticleTimeScale({1,1.5});
	SpriteEmitter3->InitialParticlesPerSecond = 30;
	SpriteEmitter3->TextureUSubdivisions = 4;
	SpriteEmitter3->TextureVSubdivisions = 4;
	SpriteEmitter3->LifetimeRange = FRange({ 0.7, 0.7 });
	SpriteEmitter3->StartVelocityRadialRange = FRange({ -150, -150 });
	SpriteEmitter3->GetVelocityDirectionFrom = EParticleVelocityDirection::PTVD_AddRadial;
	//SpriteEmitter3->VelocityScale(0) = (RelativeTime = 0, RelativeVelocity = FVector(1, 1, 1));
	//SpriteEmitter3->VelocityScale(1) = (RelativeTime = 0.5, RelativeVelocity = FVector(1, 1, 1));
	//SpriteEmitter3->VelocityScale(2) = (RelativeTime = 0.75, RelativeVelocity = FVector(0, 0, 0));
	//SpriteEmitter3->VelocityScale(3) = (RelativeTime = 1, RelativeVelocity = FVector(0, 0, 0));
	USpriteEmitter* SpriteEmitter11 = NewObject<USpriteEmitter>(USpriteEmitter::StaticClass());
	SpriteEmitter11->UseColorScale = true;
	SpriteEmitter11->RespawnDeadParticles = false;
	SpriteEmitter11->SpinParticles = true;
	SpriteEmitter11->UseSizeScale = true;
	SpriteEmitter11->UseRegularSizeScale = false;
	SpriteEmitter11->UniformSize = true;
	SpriteEmitter11->AutomaticInitialSpawning = false;
	//SpriteEmitter11->ColorScale[0]=FParticleColorScale({0,FColor(255, 255, 255, 0)});
	//SpriteEmitter11->ColorScale[1]=FParticleColorScale({0.3,FColor(106, 196, 255, 255)});
	//SpriteEmitter11->ColorScale[2]=FParticleColorScale({0.5,FColor(0, 0, 0, 255)});
	//SpriteEmitter11->ColorScale[3]=FParticleColorScale({1,FColor(0, 0, 0, 0)});
	SpriteEmitter11->MaxParticles = 5;
	SpriteEmitter11->DetailMode = EDetailMode::DM_Medium;
	SpriteEmitter11->StartLocationRange = FRangeVector({ {0, 0}, {0, 0}, {0, 15} });
	SpriteEmitter11->StartLocationShape = EParticleStartLocationShape::PTLS_All;
	SpriteEmitter11->StartLocationPolarRange = FRangeVector({ {0, 65536}, {16384, 16384}, {100, 100} });
	SpriteEmitter11->StartSpinRange = FRangeVector({ {0, 1}, {0, 0}, {0, 0} });
	//SpriteEmitter11->SizeScale[0]=FParticleTimeScale({0,0.5});
	//SpriteEmitter11->SizeScale[1]=FParticleTimeScale({1,1});
	SpriteEmitter11->StartSizeRange = FRangeVector({ {120, 120}, {100, 100}, {100, 100} });
	SpriteEmitter11->InitialParticlesPerSecond = 500;
	SpriteEmitter11->DrawStyle = EParticleDrawStyle::PTDS_AlphaBlend;
	SpriteEmitter11->TextureUSubdivisions = 4;
	SpriteEmitter11->TextureVSubdivisions = 4;
	SpriteEmitter11->LifetimeRange = FRange({ 1, 1 });
	USpriteEmitter* SpriteEmitter2 = NewObject<USpriteEmitter>(USpriteEmitter::StaticClass());
	SpriteEmitter2->RespawnDeadParticles = false;
	SpriteEmitter2->SpinParticles = true;
	SpriteEmitter2->UseSizeScale = true;
	SpriteEmitter2->UseRegularSizeScale = false;
	SpriteEmitter2->UniformSize = true;
	SpriteEmitter2->BlendBetweenSubdivisions = true;
	SpriteEmitter2->MaxParticles = 8;
	SpriteEmitter2->StartLocationRange = FRangeVector({ {-20, 20}, {-20, 20}, {-10, 10} });
	SpriteEmitter2->AddLocationFromOtherEmitter = 0;
	SpriteEmitter2->StartSpinRange = FRangeVector({ {0, 1}, {0, 0}, {0, 0} });
	//SpriteEmitter2->SizeScale[0]=FParticleTimeScale({0,0.5});
	//SpriteEmitter2->SizeScale[1]=FParticleTimeScale({1,1});
	SpriteEmitter2->InitialParticlesPerSecond = 10;
	SpriteEmitter2->TextureUSubdivisions = 2;
	SpriteEmitter2->TextureVSubdivisions = 4;
	SpriteEmitter2->LifetimeRange = FRange({ 0.6, 0.6 });
	SpriteEmitter2->AddVelocityFromOtherEmitter = 0;
	SpriteEmitter2->AddVelocityMultiplierRange = FRangeVector({ {0.2, 0.2}, {0.2, 0.2}, {0.2, 0.2} });
	USpriteEmitter* SpriteEmitter1 = NewObject<USpriteEmitter>(USpriteEmitter::StaticClass());
	SpriteEmitter1->UseColorScale = true;
	SpriteEmitter1->RespawnDeadParticles = false;
	SpriteEmitter1->SpinParticles = true;
	SpriteEmitter1->UseSizeScale = true;
	SpriteEmitter1->UseRegularSizeScale = false;
	SpriteEmitter1->UniformSize = true;
	SpriteEmitter1->AutomaticInitialSpawning = false;
	//SpriteEmitter1->ColorScale[0]=FParticleColorScale({0,FColor(0, 0, 0, 255)});
	//SpriteEmitter1->ColorScale[1]=FParticleColorScale({0.5,FColor(0, 0, 0, 255)});
	//SpriteEmitter1->ColorScale[2]=FParticleColorScale({1,FColor(0, 0, 0, 0)});
	SpriteEmitter1->MaxParticles = 5;
	SpriteEmitter1->StartLocationRange = FRangeVector({ {-20, 20}, {-20, 20}, {10, 10} });
	SpriteEmitter1->AddLocationFromOtherEmitter = 0;
	SpriteEmitter1->StartSpinRange = FRangeVector({ {0, 1}, {0, 0}, {0, 0} });
	//SpriteEmitter1->SizeScale[0]=FParticleTimeScale({0,0.75});
	//SpriteEmitter1->SizeScale[1]=FParticleTimeScale({1,1.25});
	SpriteEmitter1->InitialParticlesPerSecond = 10;
	SpriteEmitter1->DrawStyle = EParticleDrawStyle::PTDS_AlphaBlend;
	SpriteEmitter1->TextureUSubdivisions = 4;
	SpriteEmitter1->TextureVSubdivisions = 4;
	SpriteEmitter1->LifetimeRange = FRange({ 0.8, 0.8 });
	USpriteEmitter* SpriteEmitter0 = NewObject<USpriteEmitter>(USpriteEmitter::StaticClass());
	SpriteEmitter0->RespawnDeadParticles = false;
	SpriteEmitter0->UniformSize = true;
	SpriteEmitter0->AutomaticInitialSpawning = false;
	SpriteEmitter0->MaxParticles = 1;
	SpriteEmitter0->StartSizeRange = FRangeVector({ {0, 0}, {100, 100}, {100, 100} });
	SpriteEmitter0->InitialParticlesPerSecond = 500;
	SpriteEmitter0->LifetimeRange = FRange({ 0.5, 0.5 });
	SpriteEmitter0->StartVelocityRange = FRangeVector({ {-200, 200}, {-200, 200}, {500, 500} });
	Emitters = { SpriteEmitter0,SpriteEmitter1,SpriteEmitter2,SpriteEmitter11,SpriteEmitter3,SpriteEmitter7 };
	AutoDestroy = true;
	//bNoDelete = false;
};
