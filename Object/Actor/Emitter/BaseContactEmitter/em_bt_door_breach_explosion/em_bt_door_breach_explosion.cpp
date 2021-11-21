// All the original content belonged to the US Army

#include "AA29/Object/Actor/Emitter/BaseContactEmitter/em_bt_door_breach_explosion/em_bt_door_breach_explosion.h"
#include "AA29/Object/ParticleEmitter/SpriteEmitter/SpriteEmitter.h"

Aem_bt_door_breach_explosion::Aem_bt_door_breach_explosion()
{
	USpriteEmitter* SpriteEmitter1 = NewObject<USpriteEmitter>(USpriteEmitter::StaticClass());
	SpriteEmitter1->UseColorScale = true;
	SpriteEmitter1->FadeOut = true;
	SpriteEmitter1->RespawnDeadParticles = false;
	SpriteEmitter1->AutoDestroy = true;
	SpriteEmitter1->SpinParticles = true;
	SpriteEmitter1->DampRotation = true;
	SpriteEmitter1->UseSizeScale = true;
	SpriteEmitter1->UseRegularSizeScale = false;
	SpriteEmitter1->UniformSize = true;
	SpriteEmitter1->AutomaticInitialSpawning = false;
	SpriteEmitter1->Acceleration = FVector(0, 0, 20);
	//SpriteEmitter1->ColorScale[0]=FParticleColorScale({0,FColor(0, 0, 0, 255)});
	//SpriteEmitter1->ColorScale[1]=FParticleColorScale({0.1,FColor(110, 110, 110, 255)});
	SpriteEmitter1->Opacity = 0.5;
	SpriteEmitter1->FadeOutStartTime = 0.5;
	SpriteEmitter1->MaxParticles = 1;
	SpriteEmitter1->UseRotationFrom = EParticleRotationSource::PTRS_Normal;
	//SpriteEmitter1->SpinsPerSecondRange=X=(Min=0.05, Max=0.07)|Y=(Min=0, Max=0)|Z=(Min=0, Max=0);
	//SpriteEmitter1->SizeScale[0]=FParticleTimeScale({2,4});
	//SpriteEmitter1->StartSizeRange=X=(Min=60, Max=75)|Y=(Min=100, Max=100)|Z=(Min=100, Max=100);
	SpriteEmitter1->InitialParticlesPerSecond = 1000;
	SpriteEmitter1->DrawStyle = EParticleDrawStyle::PTDS_AlphaBlend;
	SpriteEmitter1->Texture = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_FX/Particles/fx_smk_ball01_Mat.fx_smk_ball01_Mat'"), NULL, LOAD_None, NULL);
	SpriteEmitter1->SecondsBeforeInactive = 0;
	SpriteEmitter1->LifetimeRange = FRange({ 2, 2.5 });
	USpriteEmitter* SpriteEmitter2 = NewObject<USpriteEmitter>(USpriteEmitter::StaticClass());
	SpriteEmitter2->FadeOut = true;
	SpriteEmitter2->FadeIn = true;
	SpriteEmitter2->RespawnDeadParticles = false;
	SpriteEmitter2->AutoDestroy = true;
	SpriteEmitter2->SpinParticles = true;
	SpriteEmitter2->UseSizeScale = true;
	SpriteEmitter2->UseRegularSizeScale = false;
	SpriteEmitter2->UniformSize = true;
	SpriteEmitter2->AutomaticInitialSpawning = false;
	SpriteEmitter2->MaxParticles = 1;
	SpriteEmitter2->UseRotationFrom = EParticleRotationSource::PTRS_Normal;
	//SpriteEmitter2->StartSpinRange=X=(Min=3, Max=-3)|Y=(Min=0, Max=0)|Z=(Min=0, Max=0);
	//SpriteEmitter2->SizeScale[0]=FParticleTimeScale({1,8});
	//SpriteEmitter2->StartSizeRange=X=(Min=20, Max=30)|Y=(Min=100, Max=100)|Z=(Min=100, Max=100);
	SpriteEmitter2->InitialParticlesPerSecond = 2000;
	SpriteEmitter2->DrawStyle = EParticleDrawStyle::PTDS_Brighten;
	SpriteEmitter2->Texture = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_FX/Particles/fx_particle_startblast01_Mat.fx_particle_startblast01_Mat'"), NULL, LOAD_None, NULL);
	SpriteEmitter2->SecondsBeforeInactive = 0;
	SpriteEmitter2->LifetimeRange = FRange({ 0.1, 0.2 });
	USpriteEmitter* SpriteEmitter3 = NewObject<USpriteEmitter>(USpriteEmitter::StaticClass());
	SpriteEmitter3->RespawnDeadParticles = false;
	SpriteEmitter3->AutoDestroy = true;
	SpriteEmitter3->SpinParticles = true;
	SpriteEmitter3->UseSizeScale = true;
	SpriteEmitter3->UseRegularSizeScale = false;
	SpriteEmitter3->UniformSize = true;
	SpriteEmitter3->AutomaticInitialSpawning = false;
	SpriteEmitter3->BlendBetweenSubdivisions = true;
	SpriteEmitter3->MaxParticles = 1;
	SpriteEmitter3->StartLocationOffset = FVector(-15, 0, 0);
	SpriteEmitter3->UseRotationFrom = EParticleRotationSource::PTRS_Actor;
	//SpriteEmitter3->StartSpinRange=X=(Min=30, Max=-30)|Y=(Min=0, Max=0)|Z=(Min=0, Max=0);
	//SpriteEmitter3->SizeScale[0]=FParticleTimeScale({2,3});
	//SpriteEmitter3->StartSizeRange=X=(Min=35, Max=35)|Y=(Min=100, Max=100)|Z=(Min=100, Max=100);
	SpriteEmitter3->InitialParticlesPerSecond = 1000;
	SpriteEmitter3->DrawStyle = EParticleDrawStyle::PTDS_AlphaBlend;
	SpriteEmitter3->Texture = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_FX/Particles/fx_door_breach_exp01_Mat.fx_door_breach_exp01_Mat'"), NULL, LOAD_None, NULL);
	SpriteEmitter3->TextureUSubdivisions = 4;
	SpriteEmitter3->TextureVSubdivisions = 2;
	SpriteEmitter3->SecondsBeforeInactive = 0;
	SpriteEmitter3->LifetimeRange = FRange({ 0.3, 0.3 });
	USpriteEmitter* SpriteEmitter4 = NewObject<USpriteEmitter>(USpriteEmitter::StaticClass());
	SpriteEmitter4->UseColorScale = true;
	SpriteEmitter4->FadeOut = true;
	SpriteEmitter4->RespawnDeadParticles = false;
	SpriteEmitter4->AutoDestroy = true;
	SpriteEmitter4->SpinParticles = true;
	SpriteEmitter4->DampRotation = true;
	SpriteEmitter4->UseSizeScale = true;
	SpriteEmitter4->UseRegularSizeScale = false;
	SpriteEmitter4->UniformSize = true;
	SpriteEmitter4->AutomaticInitialSpawning = false;
	SpriteEmitter4->Acceleration = FVector(0, 0, 100);
	//SpriteEmitter4->ColorScale[0]=FParticleColorScale({0,FColor(0, 0, 0, 255)});
	//SpriteEmitter4->ColorScale[1]=FParticleColorScale({0.1,FColor(110, 110, 110, 255)});
	SpriteEmitter4->FadeOutStartTime = 0.5;
	SpriteEmitter4->MaxParticles = 16;
	SpriteEmitter4->StartLocationOffset = FVector(-35, 0, 0);
	//SpriteEmitter4->StartLocationRange=X=(Min=-7, Max=7)|Y=(Min=-3, Max=3)|Z=(Min=0, Max=0);
	SpriteEmitter4->UseRotationFrom = EParticleRotationSource::PTRS_Actor;
	//SpriteEmitter4->SpinsPerSecondRange=X=(Min=0.05, Max=0.08)|Y=(Min=0, Max=0)|Z=(Min=0, Max=0);
	//SpriteEmitter4->SizeScale[0]=FParticleTimeScale({2,7});
	//SpriteEmitter4->StartSizeRange=X=(Min=30, Max=25)|Y=(Min=100, Max=100)|Z=(Min=100, Max=100);
	SpriteEmitter4->InitialParticlesPerSecond = 1111;
	SpriteEmitter4->DrawStyle = EParticleDrawStyle::PTDS_AlphaBlend;
	SpriteEmitter4->Texture = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_FX/Particles/fx_smk_ball01_Mat.fx_smk_ball01_Mat'"), NULL, LOAD_None, NULL);
	SpriteEmitter4->SecondsBeforeInactive = 0;
	SpriteEmitter4->LifetimeRange = FRange({ 4, 5 });
	//SpriteEmitter4->StartVelocityRange=X=(Min=500, Max=-300)|Y=(Min=750, Max=-650)|Z=(Min=750, Max=-650);
	//SpriteEmitter4->VelocityLossRange=X=(Min=9, Max=7)|Y=(Min=9, Max=9)|Z=(Min=9, Max=9);
	USpriteEmitter* SpriteEmitter5 = NewObject<USpriteEmitter>(USpriteEmitter::StaticClass());
	SpriteEmitter5->UseColorScale = true;
	SpriteEmitter5->FadeOut = true;
	SpriteEmitter5->RespawnDeadParticles = false;
	SpriteEmitter5->AutoDestroy = true;
	SpriteEmitter5->SpinParticles = true;
	SpriteEmitter5->DampRotation = true;
	SpriteEmitter5->UseSizeScale = true;
	SpriteEmitter5->UseRegularSizeScale = false;
	SpriteEmitter5->UniformSize = true;
	SpriteEmitter5->AutomaticInitialSpawning = false;
	SpriteEmitter5->Acceleration = FVector(50, 50, 110);
	//SpriteEmitter5->ColorScale[0]=FParticleColorScale({0,FColor(200, 200, 200, 255)});
	//SpriteEmitter5->ColorScale[1]=FParticleColorScale({1,FColor(226, 226, 226, 255)});
	SpriteEmitter5->FadeOutStartTime = 0.5;
	SpriteEmitter5->MaxParticles = 20;
	SpriteEmitter5->StartLocationOffset = FVector(-150, 0, 0);
	//SpriteEmitter5->StartLocationRange=X=(Min=-5, Max=5)|Y=(Min=-3, Max=3)|Z=(Min=0, Max=0);
	SpriteEmitter5->UseRotationFrom = EParticleRotationSource::PTRS_Actor;
	//SpriteEmitter5->SpinsPerSecondRange=X=(Min=0.05, Max=0.08)|Y=(Min=0, Max=0)|Z=(Min=0, Max=0);
	//SpriteEmitter5->SizeScale[0]=FParticleTimeScale({3,9});
	//SpriteEmitter5->StartSizeRange=X=(Min=20, Max=25)|Y=(Min=100, Max=100)|Z=(Min=100, Max=100);
	SpriteEmitter5->InitialParticlesPerSecond = 1111;
	SpriteEmitter5->DrawStyle = EParticleDrawStyle::PTDS_AlphaBlend;
	SpriteEmitter5->Texture = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_FX/Particles/fx_drt_cloud01_Mat.fx_drt_cloud01_Mat'"), NULL, LOAD_None, NULL);
	SpriteEmitter5->SecondsBeforeInactive = 0;
	SpriteEmitter5->LifetimeRange = FRange({ 3, 4 });
	//SpriteEmitter5->StartVelocityRange=X=(Min=700, Max=-500)|Y=(Min=550, Max=-650)|Z=(Min=550, Max=-650);
	//SpriteEmitter5->VelocityLossRange=X=(Min=10, Max=10)|Y=(Min=7, Max=7)|Z=(Min=7, Max=7);
	USpriteEmitter* SpriteEmitter6 = NewObject<USpriteEmitter>(USpriteEmitter::StaticClass());
	SpriteEmitter6->UseDirectionAs = EParticleDirectionUsage::PTDU_Up;
	SpriteEmitter6->UseColorScale = true;
	SpriteEmitter6->FadeOut = true;
	SpriteEmitter6->ResetAfterChange = true;
	SpriteEmitter6->RespawnDeadParticles = false;
	SpriteEmitter6->UseSizeScale = true;
	SpriteEmitter6->UseRegularSizeScale = false;
	SpriteEmitter6->AutomaticInitialSpawning = false;
	SpriteEmitter6->Acceleration = FVector(0, 0, -550);
	//SpriteEmitter6->ColorScale[0]=FParticleColorScale({0,FColor(210, 255, 255, 0)});
	//SpriteEmitter6->ColorScale[1]=FParticleColorScale({1,FColor(230, 255, 255, 0)});
	SpriteEmitter6->FadeOutStartTime = 0.4;
	SpriteEmitter6->MaxParticles = 100;
	//SpriteEmitter6->StartLocationRange=X=(Min=-7, Max=5)|Y=(Min=-3, Max=3)|Z=(Min=-3, Max=3);
	SpriteEmitter6->UseRotationFrom = EParticleRotationSource::PTRS_Actor;
	//SpriteEmitter6->SizeScale[0]=FParticleTimeScale({0,1});
	//SpriteEmitter6->SizeScale[1]=FParticleTimeScale({0.7,0.9});
	//SpriteEmitter6->SizeScale[2]=FParticleTimeScale({1,0.3});
	//SpriteEmitter6->StartSizeRange=X=(Min=3.5, Max=3.5)|Y=(Min=3.5, Max=3.5)|Z=(Min=3.5, Max=3.5);
	SpriteEmitter6->InitialParticlesPerSecond = 1000;
	SpriteEmitter6->DrawStyle = EParticleDrawStyle::PTDS_Brighten;
	SpriteEmitter6->Texture = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_FX/Particle/fx2_part_spark01_Mat.fx2_part_spark01_Mat'"), NULL, LOAD_None, NULL);
	SpriteEmitter6->SecondsBeforeInactive = 0;
	SpriteEmitter6->LifetimeRange = FRange({ 0.2, 0.4 });
	//SpriteEmitter6->StartVelocityRange=X=(Min=800, Max=-800)|Y=(Min=1000, Max=-1000)|Z=(Min=1000, Max=-1000);
	//SpriteEmitter6->VelocityLossRange=X=(Min=5, Max=5)|Y=(Min=4, Max=4)|Z=(Min=4, Max=4);
	Emitters = { nullptr,SpriteEmitter1,SpriteEmitter2,SpriteEmitter3,SpriteEmitter4,SpriteEmitter5,SpriteEmitter6 };
	//LifeSpan = 20;
}

void Aem_bt_door_breach_explosion::PostBeginPlay()
{
	SpawnLight();
}

void Aem_bt_door_breach_explosion::SpawnLight()
{
	//Spawn(class'AGP_Effects.aux_light_ExpLight');
}

void Aem_bt_door_breach_explosion::BeginPlay()
{
	/*
	if ((Emitters[4] != None) && (MeshEmitter(Emitters[4]) != None))
	{
		MeshEmitter(Emitters[4]).StaticMesh = StaticMesh(DynamicLoadObject("T_AA2_FX.Particles.fx_part_con_chunk2", Class'StaticMesh'));
	}
	else
	{
		Log("AGP_Effects.em_bt_door_breach_explosion was None!");
	}
	*/
}