// All the original content belonged to the US Army

#include "AA29/Object/Actor/Emitter/BaseContactEmitter/em_bt_grass/em_bt_grass.h"
#include "AA29/Object/BaseEmitter/ParticleEmitter/SpriteEmitter/SpriteEmitter.h"
#include "AA29/Object/BaseEmitter/ParticleEmitter/MeshEmitter/MeshEmitter.h"

Aem_bt_grass::Aem_bt_grass()
{
	UMeshEmitter* MeshEmitter0 = NewObject<UMeshEmitter>(UMeshEmitter::StaticClass());
	MeshEmitter0->StaticMesh = LoadObject<UStaticMesh>(NULL, TEXT("StaticMesh'/Game/AmericasArmy/Meshes/M_AA2_FX/Particles/fx_part_grass.fx_part_grass'"), NULL, LOAD_None, NULL);
	MeshEmitter0->RespawnDeadParticles = false;
	MeshEmitter0->AutoDestroy = true;
	MeshEmitter0->SpinParticles = true;
	MeshEmitter0->AutomaticInitialSpawning = false;
	MeshEmitter0->Acceleration = FVector(0, 0, -777);
	MeshEmitter0->MaxParticles = 3;
	MeshEmitter0->UseRotationFrom = EParticleRotationSource::PTRS_Actor;
	//MeshEmitter0->SpinsPerSecondRange=X=(Min=-0.2, Max=-0.25)|Y=(Min=-0.2, Max=-0.25)|Z=(Min=-0.2, Max=-0.25);
	//MeshEmitter0->StartSpinRange=X=(Min=300, Max=-300)|Y=(Min=0, Max=0)|Z=(Min=0, Max=0);
	//MeshEmitter0->SizeScale[0]=FParticleTimeScale({0,0.06});
	//MeshEmitter0->StartSizeRange=X=(Min=0.08, Max=0.1)|Y=(Min=0.08, Max=0.1)|Z=(Min=0.08, Max=0.1);
	MeshEmitter0->InitialParticlesPerSecond = 5000;
	MeshEmitter0->SecondsBeforeInactive = 0;
	MeshEmitter0->LifetimeRange = FRange({ 1, 1 });
	//MeshEmitter0->StartVelocityRange=X=(Min=150, Max=350)|Y=(Min=-200, Max=200)|Z=(Min=-200, Max=200);
	//MeshEmitter0->VelocityLossRange=X=(Min=5, Max=5)|Y=(Min=5, Max=5)|Z=(Min=5, Max=5);
	USpriteEmitter* SpriteEmitter1 = NewObject<USpriteEmitter>(USpriteEmitter::StaticClass());
	SpriteEmitter1->FadeOut = true;
	SpriteEmitter1->ResetAfterChange = true;
	SpriteEmitter1->RespawnDeadParticles = false;
	SpriteEmitter1->UseSizeScale = true;
	SpriteEmitter1->UseRegularSizeScale = false;
	SpriteEmitter1->UniformSize = true;
	SpriteEmitter1->AutomaticInitialSpawning = false;
	SpriteEmitter1->Acceleration = FVector(0, 0, -999);
	SpriteEmitter1->FadeOutStartTime = 0.3;
	SpriteEmitter1->MaxParticles = 1;
	//SpriteEmitter1->StartLocationRange=X=(Min=0, Max=0)|Y=(Min=0, Max=0)|Z=(Min=-5, Max=-5);
	//SpriteEmitter1->SizeScale[0]=FParticleTimeScale({0,1});
	//SpriteEmitter1->SizeScale[1]=FParticleTimeScale({1,9});
	//SpriteEmitter1->StartSizeRange=X=(Min=5, Max=7)|Y=(Min=100, Max=100)|Z=(Min=100, Max=100);
	SpriteEmitter1->InitialParticlesPerSecond = 2000;
	SpriteEmitter1->DrawStyle = EParticleDrawStyle::PTDS_AlphaBlend;
	SpriteEmitter1->Texture = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_FX/Particle/fx2_part_dirtbits_Mat.fx2_part_dirtbits_Mat'"), NULL, LOAD_None, NULL);
	SpriteEmitter1->SecondsBeforeInactive = 0;
	SpriteEmitter1->LifetimeRange = FRange({ 0.8, 0.8 });
	//SpriteEmitter1->StartVelocityRange=X=(Min=0, Max=0)|Y=(Min=0, Max=0)|Z=(Min=150, Max=200);
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
	//SpriteEmitter2->ColorScale[0]=FParticleColorScale({0,FColor(79, 131, 169, 99)});
	//SpriteEmitter2->ColorScale[1]=FParticleColorScale({1,FColor(79, 131, 169, 55)});
	SpriteEmitter2->FadeOutStartTime = 0.5;
	SpriteEmitter2->MaxParticles = 1;
	//SpriteEmitter2->StartLocationRange=X=(Min=-4, Max=-2)|Y=(Min=0, Max=0)|Z=(Min=0, Max=0);
	SpriteEmitter2->UseRotationFrom = EParticleRotationSource::PTRS_Actor;
	//SpriteEmitter2->SpinsPerSecondRange=X=(Min=0.2, Max=0.3)|Y=(Min=0, Max=0)|Z=(Min=0, Max=0);
	//SpriteEmitter2->StartSpinRange=X=(Min=0, Max=32600)|Y=(Min=0, Max=0)|Z=(Min=0, Max=0);
	//SpriteEmitter2->SizeScale[0]=FParticleTimeScale({0,1});
	//SpriteEmitter2->SizeScale[1]=FParticleTimeScale({1,1.7});
	//SpriteEmitter2->StartSizeRange=X=(Min=11, Max=13)|Y=(Min=100, Max=100)|Z=(Min=100, Max=100);
	SpriteEmitter2->InitialParticlesPerSecond = 1111;
	SpriteEmitter2->DrawStyle = EParticleDrawStyle::PTDS_AlphaBlend;
	SpriteEmitter2->Texture = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_FX/Particles/fx_smk_ball01_Mat.fx_smk_ball01_Mat'"), NULL, LOAD_None, NULL);
	SpriteEmitter2->LifetimeRange = FRange({ 2.5, 2.7 });
	//SpriteEmitter2->StartVelocityRange=X=(Min=410, Max=430)|Y=(Min=0, Max=0)|Z=(Min=0, Max=0);
	//SpriteEmitter2->VelocityLossRange=X=(Min=15, Max=15)|Y=(Min=15, Max=15)|Z=(Min=15, Max=15);
	USpriteEmitter* SpriteEmitter3 = NewObject<USpriteEmitter>(USpriteEmitter::StaticClass());
	SpriteEmitter3->UseColorScale = true;
	SpriteEmitter3->FadeOut = true;
	SpriteEmitter3->RespawnDeadParticles = false;
	SpriteEmitter3->UseSizeScale = true;
	SpriteEmitter3->UseRegularSizeScale = false;
	SpriteEmitter3->UniformSize = true;
	SpriteEmitter3->AutomaticInitialSpawning = false;
	//SpriteEmitter3->ColorScale[0]=FParticleColorScale({0,FColor(79, 131, 169, 99)});
	//SpriteEmitter3->ColorScale[1]=FParticleColorScale({1,FColor(79, 131, 169, 55)});
	SpriteEmitter3->FadeOutStartTime = 1.5;
	SpriteEmitter3->MaxParticles = 1;
	SpriteEmitter3->StartLocationOffset = FVector(15, 0, 0);
	SpriteEmitter3->UseRotationFrom = EParticleRotationSource::PTRS_Actor;
	//SpriteEmitter3->SizeScale[0]=FParticleTimeScale({0,1});
	//SpriteEmitter3->SizeScale[1]=FParticleTimeScale({1,5});
	//SpriteEmitter3->StartSizeRange=X=(Min=15, Max=20)|Y=(Min=100, Max=100)|Z=(Min=100, Max=100);
	SpriteEmitter3->InitialParticlesPerSecond = 1000;
	SpriteEmitter3->DrawStyle = EParticleDrawStyle::PTDS_AlphaBlend;
	SpriteEmitter3->Texture = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_FX/Particles/fx_smk_ball01_Mat.fx_smk_ball01_Mat'"), NULL, LOAD_None, NULL);
	SpriteEmitter3->SecondsBeforeInactive = 0;
	SpriteEmitter3->LifetimeRange = FRange({ 2, 3 });
	//SpriteEmitter3->StartVelocityRange=X=(Min=-25, Max=-25)|Y=(Min=-10, Max=10)|Z=(Min=-10, Max=10);
	Emitters = { MeshEmitter0,SpriteEmitter1,SpriteEmitter2,SpriteEmitter3 };

}



void Aem_bt_grass::BeginPlay()
{
	Cast <UMeshEmitter>(Emitters[0])->StaticMesh = LoadObject<UStaticMesh>(NULL, TEXT("StaticMesh'/Game/AmericasArmy/Meshes/M_AA2_FX/Particles/fx_part_grass.fx_part_grass'"), NULL, LOAD_None, NULL);
}
