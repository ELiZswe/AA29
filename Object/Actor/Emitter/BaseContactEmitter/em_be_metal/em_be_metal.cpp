// All the original content belonged to the US Army

#include "AA29/Object/Actor/Emitter/BaseContactEmitter/em_be_metal/em_be_metal.h"
#include "AA29/Object/BaseEmitter/ParticleEmitter/SpriteEmitter/SpriteEmitter.h"

Aem_be_metal::Aem_be_metal()
{
	USpriteEmitter* SpriteEmitter0 = NewObject<USpriteEmitter>(USpriteEmitter::StaticClass());
	SpriteEmitter0->UseDirectionAs = EParticleDirectionUsage::PTDU_Up;
	SpriteEmitter0->UseCollision = true;
	SpriteEmitter0->UseMaxCollisions = true;
	SpriteEmitter0->UseColorScale = true;
	SpriteEmitter0->FadeOut = true;
	SpriteEmitter0->ResetAfterChange = true;
	SpriteEmitter0->RespawnDeadParticles = false;
	SpriteEmitter0->UseSizeScale = true;
	SpriteEmitter0->UseRegularSizeScale = false;
	SpriteEmitter0->AutomaticInitialSpawning = false;
	SpriteEmitter0->Acceleration = FVector(0, 0, -950);
	//SpriteEmitter0->DampingFactorRange=X=(Min=1, Max=1)|Y=(Min=1, Max=1)|Z=(Min=0.1, Max=0.5);
	SpriteEmitter0->MaxCollisions = FRange({ 2, 2 });
	SpriteEmitter0->bOnlyBSPCollision = true;
	//SpriteEmitter0->ColorScale[0]=FParticleColorScale({0,FColor(175, 204, 253, 0)});
	//SpriteEmitter0->ColorScale[1]=FParticleColorScale({1,FColor(33, 136, 250, 0)});
	SpriteEmitter0->FadeOutStartTime = 0.4;
	SpriteEmitter0->MaxParticles = 3;
	SpriteEmitter0->UseRotationFrom = EParticleRotationSource::PTRS_Actor;
	SpriteEmitter0->SizeScale = { FParticleTimeScale({0,1}),FParticleTimeScale({0.7,0.9}),FParticleTimeScale({1,0.3}) };
	//SpriteEmitter0->StartSizeRange=X=(Min=1, Max=2.5)|Y=(Min=5, Max=10)|Z=(Min=5, Max=10);
	SpriteEmitter0->InitialParticlesPerSecond = 1000;
	SpriteEmitter0->DrawStyle = EParticleDrawStyle::PTDS_Brighten;
	SpriteEmitter0->Texture = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_FX/Particle/fx2_part_spark01_Mat.fx2_part_spark01_Mat'"), NULL, LOAD_None, NULL);
	SpriteEmitter0->SecondsBeforeInactive = 0;
	SpriteEmitter0->LifetimeRange = FRange({ 0.1, 1.5 });
	//SpriteEmitter0->StartVelocityRange=X=(Min=200, Max=900)|Y=(Min=57, Max=-57)|Z=(Min=57, Max=-57);
	USpriteEmitter* SpriteEmitter1 = NewObject<USpriteEmitter>(USpriteEmitter::StaticClass());
	SpriteEmitter1->ResetAfterChange = true;
	SpriteEmitter1->RespawnDeadParticles = false;
	SpriteEmitter1->SpinParticles = true;
	SpriteEmitter1->UseSizeScale = true;
	SpriteEmitter1->UniformSize = true;
	SpriteEmitter1->AutomaticInitialSpawning = false;
	SpriteEmitter1->MaxParticles = 1;
	SpriteEmitter1->UseRotationFrom = EParticleRotationSource::PTRS_Actor;
	//SpriteEmitter1->StartSpinRange=X=(Min=0, Max=32600)|Y=(Min=0, Max=0)|Z=(Min=0, Max=0);
	SpriteEmitter1->SizeScale = { FParticleTimeScale({0,1}),FParticleTimeScale({1,5}) };
	//SpriteEmitter1->StartSizeRange=X=(Min=4, Max=8)|Y=(Min=100, Max=100)|Z=(Min=100, Max=100);
	SpriteEmitter1->InitialParticlesPerSecond = 1000;
	SpriteEmitter1->DrawStyle = EParticleDrawStyle::PTDS_AlphaBlend;
	SpriteEmitter1->Texture = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_FX/Particles/fx_particle_startblast01_Mat.fx_particle_startblast01_Mat'"), NULL, LOAD_None, NULL);
	SpriteEmitter1->SecondsBeforeInactive = 0;
	SpriteEmitter1->LifetimeRange = FRange({ 0.03, 0.03 });
	USpriteEmitter* SpriteEmitter2 = NewObject<USpriteEmitter>(USpriteEmitter::StaticClass());
	SpriteEmitter2->UseColorScale = true;
	SpriteEmitter2->FadeOut = true;
	SpriteEmitter2->RespawnDeadParticles = false;
	SpriteEmitter2->SpinParticles = true;
	SpriteEmitter2->UseSizeScale = true;
	SpriteEmitter2->UseRegularSizeScale = false;
	SpriteEmitter2->UniformSize = true;
	SpriteEmitter2->AutomaticInitialSpawning = false;
	SpriteEmitter2->Acceleration = FVector(0, 0, -100);
	SpriteEmitter2->ColorScale = { FParticleColorScale({0,FColor(142, 150, 157, 44)}),FParticleColorScale({1,FColor(142, 150, 157, 40)}) };
	SpriteEmitter2->FadeOutStartTime = 0.5;
	SpriteEmitter2->MaxParticles = 1;
	//SpriteEmitter2->StartLocationRange=X=(Min=-3, Max=-3)|Y=(Min=0, Max=0)|Z=(Min=0, Max=0);
	SpriteEmitter2->UseRotationFrom = EParticleRotationSource::PTRS_Actor;
	//SpriteEmitter2->SpinsPerSecondRange=X=(Min=0.2, Max=0.3)|Y=(Min=0, Max=0)|Z=(Min=0, Max=0);
	//SpriteEmitter2->StartSpinRange=X=(Min=0, Max=32600)|Y=(Min=0, Max=0)|Z=(Min=0, Max=0);
	SpriteEmitter2->SizeScale = { FParticleTimeScale({0,1}),FParticleTimeScale({1,1.7}) };
	//SpriteEmitter2->StartSizeRange=X=(Min=14, Max=17)|Y=(Min=100, Max=100)|Z=(Min=100, Max=100);
	SpriteEmitter2->InitialParticlesPerSecond = 1111;
	SpriteEmitter2->DrawStyle = EParticleDrawStyle::PTDS_AlphaBlend;
	SpriteEmitter2->Texture = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_FX/Particles/fx_smk_ball03_Mat.fx_smk_ball03_Mat'"), NULL, LOAD_None, NULL);
	SpriteEmitter2->LifetimeRange = FRange({ 1.5, 1.7 });
	//SpriteEmitter2->StartVelocityRange=X=(Min=350, Max=370)|Y=(Min=0, Max=0)|Z=(Min=0, Max=0);
	//SpriteEmitter2->VelocityLossRange=X=(Min=15, Max=15)|Y=(Min=15, Max=15)|Z=(Min=15, Max=15);
	USpriteEmitter* SpriteEmitter3 = NewObject<USpriteEmitter>(USpriteEmitter::StaticClass());
	SpriteEmitter3->UseColorScale = true;
	SpriteEmitter3->FadeOut = true;
	SpriteEmitter3->RespawnDeadParticles = false;
	SpriteEmitter3->SpinParticles = true;
	SpriteEmitter3->UseSizeScale = true;
	SpriteEmitter3->UseRegularSizeScale = false;
	SpriteEmitter3->UniformSize = true;
	SpriteEmitter3->AutomaticInitialSpawning = false;
	SpriteEmitter3->Acceleration = FVector(0, 0, -100);
	SpriteEmitter3->ColorScale = { FParticleColorScale({0,FColor(142, 150, 157, 44)}),FParticleColorScale({1,FColor(142, 150, 157, 40)}) };
	SpriteEmitter3->FadeOutStartTime = 0.5;
	SpriteEmitter3->MaxParticles = 1;
	//SpriteEmitter3->StartLocationRange=X=(Min=-4, Max=-2)|Y=(Min=0, Max=0)|Z=(Min=0, Max=0);
	SpriteEmitter3->UseRotationFrom = EParticleRotationSource::PTRS_Actor;
	//SpriteEmitter3->SpinsPerSecondRange=X=(Min=0.2, Max=0.3)|Y=(Min=0, Max=0)|Z=(Min=0, Max=0);
	//SpriteEmitter3->StartSpinRange=X=(Min=0, Max=32600)|Y=(Min=0, Max=0)|Z=(Min=0, Max=0);
	SpriteEmitter3->SizeScale = { FParticleTimeScale({0,1}),FParticleTimeScale({1,1.7}) };
	//SpriteEmitter3->StartSizeRange=X=(Min=11, Max=13)|Y=(Min=100, Max=100)|Z=(Min=100, Max=100);
	SpriteEmitter3->InitialParticlesPerSecond = 1111;
	SpriteEmitter3->DrawStyle = EParticleDrawStyle::PTDS_AlphaBlend;
	SpriteEmitter3->Texture = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_FX/Particles/fx_smk_ball03_Mat.fx_smk_ball03_Mat'"), NULL, LOAD_None, NULL);
	SpriteEmitter3->LifetimeRange = FRange({ 1.5, 1.7 });
	//SpriteEmitter3->StartVelocityRange=X=(Min=510, Max=530)|Y=(Min=0, Max=0)|Z=(Min=0, Max=0);
	//SpriteEmitter3->VelocityLossRange=X=(Min=15, Max=15)|Y=(Min=15, Max=15)|Z=(Min=15, Max=15);
	USpriteEmitter* SpriteEmitter4 = NewObject<USpriteEmitter>(USpriteEmitter::StaticClass());
	SpriteEmitter4->UseColorScale = true;
	SpriteEmitter4->FadeOut = true;
	SpriteEmitter4->RespawnDeadParticles = false;
	SpriteEmitter4->SpinParticles = true;
	SpriteEmitter4->UseSizeScale = true;
	SpriteEmitter4->UseRegularSizeScale = false;
	SpriteEmitter4->UniformSize = true;
	SpriteEmitter4->AutomaticInitialSpawning = false;
	SpriteEmitter4->Acceleration = FVector(0, 0, -100);
	SpriteEmitter4->ColorScale = { FParticleColorScale({0,FColor(142, 150, 157, 33)}),FParticleColorScale({1,FColor(142, 150, 157, 30)}) };
	SpriteEmitter4->FadeOutStartTime = 0.5;
	SpriteEmitter4->MaxParticles = 1;
	//SpriteEmitter4->StartLocationRange=X=(Min=-4, Max=-2)|Y=(Min=0, Max=0)|Z=(Min=0, Max=0);
	SpriteEmitter4->UseRotationFrom = EParticleRotationSource::PTRS_Actor;
	//SpriteEmitter4->SpinsPerSecondRange=X=(Min=0.1, Max=0.1)|Y=(Min=0, Max=0)|Z=(Min=0, Max=0);
	//SpriteEmitter4->StartSpinRange=X=(Min=0, Max=32600)|Y=(Min=0, Max=0)|Z=(Min=0, Max=0);
	SpriteEmitter4->SizeScale = { FParticleTimeScale({0,1}),FParticleTimeScale({1,1.7}) };
	//SpriteEmitter4->StartSizeRange=X=(Min=9, Max=10)|Y=(Min=100, Max=100)|Z=(Min=100, Max=100);
	SpriteEmitter4->InitialParticlesPerSecond = 1111;
	SpriteEmitter4->DrawStyle = EParticleDrawStyle::PTDS_AlphaBlend;
	SpriteEmitter4->Texture = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_FX/Particles/fx_smk_ball03_Mat.fx_smk_ball03_Mat'"), NULL, LOAD_None, NULL);
	SpriteEmitter4->LifetimeRange = FRange({ 1.5, 1.7 });
	//SpriteEmitter4->StartVelocityRange=X=(Min=570, Max=650)|Y=(Min=0, Max=0)|Z=(Min=0, Max=0);
	//SpriteEmitter4->VelocityLossRange=X=(Min=15, Max=15)|Y=(Min=15, Max=15)|Z=(Min=15, Max=15);

	Emitters = { SpriteEmitter0,SpriteEmitter1,SpriteEmitter2,SpriteEmitter3,SpriteEmitter4 };
}
