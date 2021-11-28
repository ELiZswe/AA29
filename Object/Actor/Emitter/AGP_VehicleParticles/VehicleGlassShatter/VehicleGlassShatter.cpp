// All the original content belonged to the US Army

#include "AA29/Object/Actor/Emitter/AGP_VehicleParticles/VehicleGlassShatter/VehicleGlassShatter.h"
#include "AA29/Object/BaseEmitter/ParticleEmitter/SpriteEmitter/SpriteEmitter.h"

AVehicleGlassShatter::AVehicleGlassShatter()
{
	USpriteEmitter* SpriteEmitter0 = NewObject<USpriteEmitter>(USpriteEmitter::StaticClass());
	SpriteEmitter0->RespawnDeadParticles = false;
	SpriteEmitter0->AutoDestroy = true;
	SpriteEmitter0->SpinParticles = true;
	SpriteEmitter0->UniformSize = true;
	SpriteEmitter0->AutomaticInitialSpawning = false;
	SpriteEmitter0->UseRandomSubdivision = true;
	SpriteEmitter0->UseVelocityScale = true;
	SpriteEmitter0->AddVelocityFromOwner = true;
	SpriteEmitter0->Acceleration = FVector(0, 0, 1000);
	//SpriteEmitter0->ColorScale[0]=FParticleColorScale({0,FColor(255, 255, 255, 255)});
	//SpriteEmitter0->ColorScale[1]=FParticleColorScale({1,FColor(255, 255, 255, 255)});
	SpriteEmitter0->MaxParticles = 30;
	SpriteEmitter0->StartLocationRange = FRangeVector({ {0, 0}, {-10, 10}, {-10, 10} });
	SpriteEmitter0->SpinsPerSecondRange = FRangeVector({ {0.5, 1}, {0.5, 1}, {0.5, 1} });
	SpriteEmitter0->StartSizeRange = FRangeVector({ {1, 1.5}, {1, 1.5}, {1, 1.5} });
	SpriteEmitter0->InitialParticlesPerSecond = 5000;
	SpriteEmitter0->DrawStyle = EParticleDrawStyle::PTDS_AlphaBlend;
	SpriteEmitter0->Texture = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_FX/Particles/fx_part_glasschunk_Mat.fx_part_glasschunk_Mat'"), NULL, LOAD_None, NULL);
	SpriteEmitter0->TextureUSubdivisions = 2;
	SpriteEmitter0->TextureVSubdivisions = 2;
	SpriteEmitter0->LifetimeRange = FRange({ 1, 1 });
	SpriteEmitter0->StartVelocityRange = FRangeVector({ {-200, 200}, {-400, 400}, {50, 100} });
	//SpriteEmitter0->VelocityScale(0) = (RelativeTime = 0.15, RelativeVelocity = FVector(0, 0, -1));
	Emitters = { SpriteEmitter0 };
	AutoDestroy = true;
	//bNoDelete = false;
}