// All the original content belonged to the US Army

#include "AA29/Object/Actor/Emitter/BaseContactEmitter/em_bt_grenexplosionB/em_bt_grenexplosionB.h"
#include "AA29/Object/BaseEmitter/ParticleEmitter/SpriteEmitter/SpriteEmitter.h"
#include "AA29/Object/BaseEmitter/ParticleEmitter/MeshEmitter/MeshEmitter.h"
#include "AA29/Object/Actor/Emitter/aux_light_ExpLight/aux_light_ExpLight.h"

Aem_bt_grenexplosionB::Aem_bt_grenexplosionB()
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
	SpriteEmitter1->Acceleration = FVector(0, 0, 50);
	//SpriteEmitter1->ColorScale[0]=FParticleColorScale({0,FColor(0, 0, 0, 255)});
	//SpriteEmitter1->ColorScale[1]=FParticleColorScale({0.1,FColor(110, 110, 110, 255)});
	SpriteEmitter1->Opacity = 0.5;
	SpriteEmitter1->FadeOutStartTime = 0.5;
	SpriteEmitter1->MaxParticles = 1;
	SpriteEmitter1->UseRotationFrom = EParticleRotationSource::PTRS_Normal;
	//SpriteEmitter1->SpinsPerSecondRange=X=(Min=0.05, Max=0.07)|Y=(Min=0, Max=0)|Z=(Min=0, Max=0);
	//SpriteEmitter1->SizeScale[0]=FParticleTimeScale({2,4});
	SpriteEmitter1->InitialParticlesPerSecond = 1000;
	SpriteEmitter1->DrawStyle = EParticleDrawStyle::PTDS_AlphaBlend;
	SpriteEmitter1->Texture = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_FX/Particles/fx_smk_ball01_Mat.fx_smk_ball01_Mat'"), NULL, LOAD_None, NULL);
	SpriteEmitter1->SecondsBeforeInactive = 0;
	SpriteEmitter1->LifetimeRange = FRange({ 1.5, 1.5 });
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
	//SpriteEmitter2->SizeScale[0]=FParticleTimeScale({1,5});
	SpriteEmitter2->InitialParticlesPerSecond = 2000;
	SpriteEmitter2->DrawStyle = EParticleDrawStyle::PTDS_Brighten;
	SpriteEmitter2->Texture = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_FX/Particles/fx_particle_startblast01_Mat.fx_particle_startblast01_Mat'"), NULL, LOAD_None, NULL);
	SpriteEmitter2->SecondsBeforeInactive = 0;
	SpriteEmitter2->LifetimeRange = FRange({ 0.1, 0.1 });
	USpriteEmitter* SpriteEmitter3 = NewObject<USpriteEmitter>(USpriteEmitter::StaticClass());
	SpriteEmitter3->RespawnDeadParticles = false;
	SpriteEmitter3->AutoDestroy = true;
	SpriteEmitter3->SpinParticles = true;
	SpriteEmitter3->UseSizeScale = true;
	SpriteEmitter3->UseRegularSizeScale = false;
	SpriteEmitter3->UniformSize = true;
	SpriteEmitter3->AutomaticInitialSpawning = false;
	SpriteEmitter3->BlendBetweenSubdivisions = true;
	SpriteEmitter3->Acceleration = FVector(0, 0, 300);
	SpriteEmitter3->MaxParticles = 1;
	SpriteEmitter3->StartLocationOffset = FVector(30, 0, 0);
	SpriteEmitter3->UseRotationFrom = EParticleRotationSource::PTRS_Actor;
	//SpriteEmitter3->StartSpinRange=X=(Min=30, Max=-30)|Y=(Min=0, Max=0)|Z=(Min=0, Max=0);
	//SpriteEmitter3->SizeScale[0]=FParticleTimeScale({5,3});
	SpriteEmitter3->InitialParticlesPerSecond = 1000;
	SpriteEmitter3->DrawStyle = EParticleDrawStyle::PTDS_AlphaBlend;
	SpriteEmitter3->Texture = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_FX/Particles/fx_part_explosion01_Mat.fx_part_explosion01_Mat'"), NULL, LOAD_None, NULL);
	SpriteEmitter3->TextureUSubdivisions = 4;
	SpriteEmitter3->TextureVSubdivisions = 2;
	SpriteEmitter3->SecondsBeforeInactive = 0;
	SpriteEmitter3->LifetimeRange = FRange({ 0.3, 0.3 });
	UMeshEmitter* MeshEmitter0 = NewObject<UMeshEmitter>(UMeshEmitter::StaticClass());
	MeshEmitter0->StaticMesh = LoadObject<UStaticMesh>(NULL, TEXT("StaticMesh'/Game/AmericasArmy/Meshes/M_AA2_FX/Particles/fx_part_con_chunk1.fx_part_con_chunk1'"), NULL, LOAD_None, NULL);
	MeshEmitter0->UseCollision = true;
	MeshEmitter0->UseMaxCollisions = true;
	MeshEmitter0->RespawnDeadParticles = false;
	MeshEmitter0->AutoDestroy = true;
	MeshEmitter0->SpinParticles = true;
	MeshEmitter0->AutomaticInitialSpawning = false;
	MeshEmitter0->Acceleration = FVector(0, 0, -740);
	//MeshEmitter0->DampingFactorRange=X=(Min=0.6, Max=0.6)|Y=(Min=0.6, Max=0.6)|Z=(Min=0.2, Max=0.2);
	MeshEmitter0->MaxCollisions = FRange({ 1, 1 });
	MeshEmitter0->MaxParticles = 7;
	MeshEmitter0->UseRotationFrom = EParticleRotationSource::PTRS_Actor;
	//MeshEmitter0->SpinsPerSecondRange=X=(Min=0.2, Max=0.2)|Y=(Min=0.2, Max=0.2)|Z=(Min=0, Max=0);
	//MeshEmitter0->StartSizeRange=X=(Min=0.35, Max=0.35)|Y=(Min=0.35, Max=0.35)|Z=(Min=0.35, Max=0.35);
	MeshEmitter0->InitialParticlesPerSecond = 1111;
	MeshEmitter0->SecondsBeforeInactive = 0;
	MeshEmitter0->LifetimeRange = FRange({ 5, 5 });
	//MeshEmitter0->StartVelocityRange=X=(Min=900, Max=600)|Y=(Min=-900, Max=600)|Z=(Min=600, Max=-900);
	USpriteEmitter* SpriteEmitter6 = NewObject<USpriteEmitter>(USpriteEmitter::StaticClass());
	SpriteEmitter6->UseColorScale = true;
	SpriteEmitter6->RespawnDeadParticles = false;
	SpriteEmitter6->SpinParticles = true;
	SpriteEmitter6->DampRotation = true;
	SpriteEmitter6->UseSizeScale = true;
	SpriteEmitter6->UseRegularSizeScale = false;
	SpriteEmitter6->UniformSize = true;
	SpriteEmitter6->AutomaticInitialSpawning = false;
	SpriteEmitter6->BlendBetweenSubdivisions = true;
	SpriteEmitter6->Acceleration = FVector(0, 0, 200);
	//SpriteEmitter6->ColorScale[0]=FParticleColorScale({0,FColor(0, 0, 0, 150)});
	//SpriteEmitter6->ColorScale[1]=FParticleColorScale({0.1,FColor(200, 200, 200, 70)});
	SpriteEmitter6->Opacity = 0.5;
	SpriteEmitter6->MaxParticles = 15;
	SpriteEmitter6->UseRotationFrom = EParticleRotationSource::PTRS_Actor;
	//SpriteEmitter6->SpinsPerSecondRange=X=(Min=0.2, Max=0.1)|Y=(Min=0, Max=0)|Z=(Min=0, Max=0);
	//SpriteEmitter6->StartSpinRange=X=(Min=0, Max=32600)|Y=(Min=0, Max=0)|Z=(Min=0, Max=0);
	//SpriteEmitter6->SizeScale[0]=FParticleTimeScale({0,1});
	//SpriteEmitter6->SizeScale[1]=FParticleTimeScale({7,7});
	//SpriteEmitter6->StartSizeRange=X=(Min=60, Max=70)|Y=(Min=100, Max=100)|Z=(Min=100, Max=100);
	SpriteEmitter6->InitialParticlesPerSecond = 1111;
	SpriteEmitter6->DrawStyle = EParticleDrawStyle::PTDS_AlphaBlend;
	SpriteEmitter6->Texture = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_FX/Particles/fx_part_smokeanim_fade_Mat.fx_part_smokeanim_fade_Mat'"), NULL, LOAD_None, NULL);
	SpriteEmitter6->TextureUSubdivisions = 4;
	SpriteEmitter6->TextureVSubdivisions = 2;
	SpriteEmitter6->LifetimeRange = FRange({ 0.3, 0.3 });
	//SpriteEmitter6->StartVelocityRange=X=(Min=900, Max=700)|Y=(Min=-700, Max=700)|Z=(Min=700, Max=-700);
	//SpriteEmitter6->VelocityLossRange=X=(Min=6, Max=6)|Y=(Min=10, Max=10)|Z=(Min=10, Max=10);
	USpriteEmitter* SpriteEmitter7 = NewObject<USpriteEmitter>(USpriteEmitter::StaticClass());
	SpriteEmitter7->UseColorScale = true;
	SpriteEmitter7->RespawnDeadParticles = false;
	SpriteEmitter7->SpinParticles = true;
	SpriteEmitter7->DampRotation = true;
	SpriteEmitter7->UseSizeScale = true;
	SpriteEmitter7->UseRegularSizeScale = false;
	SpriteEmitter7->UniformSize = true;
	SpriteEmitter7->AutomaticInitialSpawning = false;
	SpriteEmitter7->BlendBetweenSubdivisions = true;
	SpriteEmitter7->Acceleration = FVector(0, 0, 200);
	//SpriteEmitter7->ColorScale[0]=FParticleColorScale({0,FColor(0, 0, 0, 110)});
	//SpriteEmitter7->ColorScale[1]=FParticleColorScale({0.1,FColor(200, 200, 200, 70)});
	SpriteEmitter7->Opacity = 0.3;
	SpriteEmitter7->MaxParticles = 15;
	SpriteEmitter7->UseRotationFrom = EParticleRotationSource::PTRS_Actor;
	//SpriteEmitter7->SpinsPerSecondRange=X=(Min=0.2, Max=0.1)|Y=(Min=0, Max=0)|Z=(Min=0, Max=0);
	//SpriteEmitter7->StartSpinRange=X=(Min=0, Max=32600)|Y=(Min=0, Max=0)|Z=(Min=0, Max=0);
	//SpriteEmitter7->SizeScale[0]=FParticleTimeScale({0,1});
	//SpriteEmitter7->SizeScale[1]=FParticleTimeScale({6,5});
	//SpriteEmitter7->StartSizeRange=X=(Min=30, Max=40)|Y=(Min=100, Max=100)|Z=(Min=100, Max=100);
	SpriteEmitter7->InitialParticlesPerSecond = 1111;
	SpriteEmitter7->DrawStyle = EParticleDrawStyle::PTDS_AlphaBlend;
	SpriteEmitter7->Texture = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_FX/Particles/fx_part_smokeanim_fade_Mat.fx_part_smokeanim_fade_Mat'"), NULL, LOAD_None, NULL);
	SpriteEmitter7->TextureUSubdivisions = 4;
	SpriteEmitter7->TextureVSubdivisions = 2;
	SpriteEmitter7->LifetimeRange = FRange({ 0.3, 0.3 });
	//SpriteEmitter7->StartVelocityRange=X=(Min=300, Max=200)|Y=(Min=-1400, Max=1400)|Z=(Min=800, Max=-800);
	//SpriteEmitter7->VelocityLossRange=X=(Min=3, Max=3)|Y=(Min=6, Max=6)|Z=(Min=15, Max=15);
	USpriteEmitter* SpriteEmitter8 = NewObject<USpriteEmitter>(USpriteEmitter::StaticClass());
	SpriteEmitter8->UseColorScale = true;
	SpriteEmitter8->RespawnDeadParticles = false;
	SpriteEmitter8->SpinParticles = true;
	SpriteEmitter8->UseSizeScale = true;
	SpriteEmitter8->UseRegularSizeScale = false;
	SpriteEmitter8->UniformSize = true;
	SpriteEmitter8->AutomaticInitialSpawning = false;
	SpriteEmitter8->BlendBetweenSubdivisions = true;
	SpriteEmitter8->Acceleration = FVector(0, 0, 50);
	//SpriteEmitter8->ColorScale[0]=FParticleColorScale({0,FColor(0, 0, 0, 120)});
	//SpriteEmitter8->ColorScale[1]=FParticleColorScale({1,FColor(200, 200, 200, 100)});
	SpriteEmitter8->Opacity = 0.5;
	SpriteEmitter8->MaxParticles = 15;
	SpriteEmitter8->StartLocationOffset = FVector(0, 0, -30);
	SpriteEmitter8->UseRotationFrom = EParticleRotationSource::PTRS_Actor;
	//SpriteEmitter8->SpinsPerSecondRange=X=(Min=0.1, Max=0.1)|Y=(Min=0, Max=0)|Z=(Min=0, Max=0);
	//SpriteEmitter8->StartSpinRange=X=(Min=0, Max=32600)|Y=(Min=0, Max=0)|Z=(Min=0, Max=0);
	//SpriteEmitter8->SizeScale[0]=FParticleTimeScale({0,1});
	//SpriteEmitter8->SizeScale[1]=FParticleTimeScale({7,7});
	//SpriteEmitter8->StartSizeRange=X=(Min=30, Max=50)|Y=(Min=100, Max=100)|Z=(Min=100, Max=100);
	SpriteEmitter8->InitialParticlesPerSecond = 1111;
	SpriteEmitter8->DrawStyle = EParticleDrawStyle::PTDS_AlphaBlend;
	SpriteEmitter8->Texture = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_FX/Particles/fx_part_smokeanim_fade_Mat.fx_part_smokeanim_fade_Mat'"), NULL, LOAD_None, NULL);
	SpriteEmitter8->TextureUSubdivisions = 4;
	SpriteEmitter8->TextureVSubdivisions = 2;
	SpriteEmitter8->LifetimeRange = FRange({ 0.3, 0.3 });
	//SpriteEmitter8->StartVelocityRange=X=(Min=1500, Max=1200)|Y=(Min=750, Max=-750)|Z=(Min=-1150, Max=1150);
	//SpriteEmitter8->VelocityLossRange=X=(Min=20, Max=20)|Y=(Min=8, Max=8)|Z=(Min=7, Max=7);
	USpriteEmitter* SpriteEmitter9 = NewObject<USpriteEmitter>(USpriteEmitter::StaticClass());
	SpriteEmitter9->UseColorScale = true;
	SpriteEmitter9->FadeOut = true;
	SpriteEmitter9->RespawnDeadParticles = false;
	SpriteEmitter9->UseSizeScale = true;
	SpriteEmitter9->UseRegularSizeScale = false;
	SpriteEmitter9->UniformSize = true;
	SpriteEmitter9->AutomaticInitialSpawning = false;
	SpriteEmitter9->Acceleration = FVector(0, 0, -977);
	//SpriteEmitter9->ColorScale[0]=FParticleColorScale({0,FColor(140, 194, 255, 0)});
	//SpriteEmitter9->ColorScale[1]=FParticleColorScale({1,FColor(38, 57, 89, 0)});
	SpriteEmitter9->FadeOutStartTime = 0.5;
	SpriteEmitter9->MaxParticles = 125;
	//SpriteEmitter9->StartLocationRange=X=(Min=-80, Max=80)|Y=(Min=-80, Max=80)|Z=(Min=0, Max=0);
	SpriteEmitter9->UseRotationFrom = EParticleRotationSource::PTRS_Actor;
	//SpriteEmitter9->SizeScale[0]=FParticleTimeScale({0,1});
	//SpriteEmitter9->SizeScale[1]=FParticleTimeScale({1,0.8});
	//SpriteEmitter9->StartSizeRange=X=(Min=4, Max=4.5)|Y=(Min=100, Max=100)|Z=(Min=100, Max=100);
	SpriteEmitter9->InitialParticlesPerSecond = 1111;
	SpriteEmitter9->DrawStyle = EParticleDrawStyle::PTDS_Brighten;
	SpriteEmitter9->Texture = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_FX/Corona/fx2_cor_05_Mat.fx2_cor_05_Mat'"), NULL, LOAD_None, NULL);
	SpriteEmitter9->LifetimeRange = FRange({ 0.7, 0.7 });
	//SpriteEmitter9->StartVelocityRange=X=(Min=755, Max=755)|Y=(Min=-1422, Max=1422)|Z=(Min=1422, Max=-1422);
	//SpriteEmitter9->VelocityLossRange=X=(Min=4, Max=2)|Y=(Min=3, Max=3)|Z=(Min=3, Max=3);
	USpriteEmitter* SpriteEmitter10 = NewObject<USpriteEmitter>(USpriteEmitter::StaticClass());
	SpriteEmitter10->UseColorScale = true;
	SpriteEmitter10->FadeOut = true;
	SpriteEmitter10->RespawnDeadParticles = false;
	SpriteEmitter10->UseSizeScale = true;
	SpriteEmitter10->UseRegularSizeScale = false;
	SpriteEmitter10->UniformSize = true;
	SpriteEmitter10->AutomaticInitialSpawning = false;
	SpriteEmitter10->Acceleration = FVector(0, 0, -977);
	//SpriteEmitter10->ColorScale[0]=FParticleColorScale({0,FColor(140, 194, 255, 0)});
	//SpriteEmitter10->ColorScale[1]=FParticleColorScale({1,FColor(38, 57, 89, 0)});
	SpriteEmitter10->FadeOutStartTime = 0.5;
	SpriteEmitter10->MaxParticles = 75;
	//SpriteEmitter10->StartLocationRange=X=(Min=-80, Max=80)|Y=(Min=-80, Max=80)|Z=(Min=0, Max=0);
	SpriteEmitter10->UseRotationFrom = EParticleRotationSource::PTRS_Actor;
	//SpriteEmitter10->SizeScale[0]=FParticleTimeScale({0,1});
	//SpriteEmitter10->SizeScale[1]=FParticleTimeScale({1,0.8});
	//SpriteEmitter10->StartSizeRange=X=(Min=4, Max=4.5)|Y=(Min=100, Max=100)|Z=(Min=100, Max=100);
	SpriteEmitter10->InitialParticlesPerSecond = 1111;
	SpriteEmitter10->DrawStyle = EParticleDrawStyle::PTDS_Brighten;
	SpriteEmitter10->Texture = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_FX/Corona/fx2_cor_05_Mat.fx2_cor_05_Mat'"), NULL, LOAD_None, NULL);
	SpriteEmitter10->LifetimeRange = FRange({ 0.6, 0.6 });
	//SpriteEmitter10->StartVelocityRange=X=(Min=1455, Max=1055)|Y=(Min=-922, Max=922)|Z=(Min=922, Max=-922);
	//SpriteEmitter10->VelocityLossRange=X=(Min=2, Max=2)|Y=(Min=3, Max=3)|Z=(Min=3, Max=3);
	Emitters = { nullptr,SpriteEmitter1,SpriteEmitter2,SpriteEmitter3,MeshEmitter0,nullptr,SpriteEmitter6,SpriteEmitter7,SpriteEmitter8,SpriteEmitter9,SpriteEmitter10 };
	LifeSpan = 20;
}

void Aem_bt_grenexplosionB::PostBeginPlay()
{
	SpawnLight();
}

void Aem_bt_grenexplosionB::SpawnLight()
{
	//Spawn(Aaux_light_ExpLight::StaticClass());
}

void Aem_bt_grenexplosionB::BeginPlay()
{
	Cast<UMeshEmitter>(Emitters[4])->StaticMesh = LoadObject<UStaticMesh>(NULL, TEXT("StaticMesh'/Game/AmericasArmy/Meshes/M_AA2_FX/Particles/fx_part_con_chunk2.fx_part_con_chunk2'"), NULL, LOAD_None, NULL);
}
