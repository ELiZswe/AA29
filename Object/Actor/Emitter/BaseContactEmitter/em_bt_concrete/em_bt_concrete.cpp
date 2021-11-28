// All the original content belonged to the US Army

#include "AA29/Object/Actor/Emitter/BaseContactEmitter/em_bt_concrete/em_bt_concrete.h"
#include "AA29/Object/BaseEmitter/ParticleEmitter/SpriteEmitter/SpriteEmitter.h"

Aem_bt_concrete::Aem_bt_concrete()
{
	USpriteEmitter* SpriteEmitter1 = NewObject<USpriteEmitter>(USpriteEmitter::StaticClass());
	SpriteEmitter1->FadeOut = true;
	SpriteEmitter1->RespawnDeadParticles = false;
	SpriteEmitter1->AutoDestroy = true;
	SpriteEmitter1->SpinParticles = true;
	SpriteEmitter1->UseSizeScale = true;
	SpriteEmitter1->UniformSize = true;
	SpriteEmitter1->AutomaticInitialSpawning = false;
	SpriteEmitter1->BlendBetweenSubdivisions = true;
	SpriteEmitter1->Acceleration = FVector(0, 0, -444);
	SpriteEmitter1->FadeOutStartTime = 0.2;
	SpriteEmitter1->MaxParticles = 3;
	SpriteEmitter1->UseRotationFrom = EParticleRotationSource::PTRS_Actor;
	//SpriteEmitter1->SpinsPerSecondRange=X=(Min=-2, Max=3)|Y=(Min=0, Max=0)|Z=(Min=0, Max=0);
	//SpriteEmitter1->StartSpinRange=X=(Min=0, Max=32000)|Y=(Min=0, Max=0)|Z=(Min=0, Max=0);
	//SpriteEmitter1->SizeScale[0]=FParticleTimeScale({0,1});
	//SpriteEmitter1->SizeScale[1]=FParticleTimeScale({0.5,1});
	//SpriteEmitter1->SizeScale[2]=FParticleTimeScale({1,0.1});
	//SpriteEmitter1->StartSizeRange=X=(Min=0.4, Max=3)|Y=(Min=100, Max=100)|Z=(Min=100, Max=100);
	SpriteEmitter1->InitialParticlesPerSecond = 5000;
	SpriteEmitter1->DrawStyle = EParticleDrawStyle::PTDS_AlphaBlend;
	SpriteEmitter1->Texture = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_FX/Particles/fx_part_woodchip_Mat.fx_part_woodchip_Mat'"), NULL, LOAD_None, NULL);
	SpriteEmitter1->TextureUSubdivisions = 4;
	SpriteEmitter1->TextureVSubdivisions = 4;
	SpriteEmitter1->SecondsBeforeInactive = 0;
	SpriteEmitter1->LifetimeRange = FRange({ 0.8, 1 });
	//SpriteEmitter1->StartVelocityRange=X=(Min=0, Max=333)|Y=(Min=-66, Max=66)|Z=(Min=-66, Max=66);
	USpriteEmitter* SpriteEmitter2 = NewObject<USpriteEmitter>(USpriteEmitter::StaticClass());
	SpriteEmitter2->UseColorScale = true;
	SpriteEmitter2->FadeOut = true;
	SpriteEmitter2->RespawnDeadParticles = false;
	SpriteEmitter2->UseSizeScale = true;
	SpriteEmitter2->UseRegularSizeScale = false;
	SpriteEmitter2->UniformSize = true;
	SpriteEmitter2->AutomaticInitialSpawning = false;
	SpriteEmitter2->Acceleration = FVector(0, 0, -7);
	//SpriteEmitter2->ColorScale[0]=FParticleColorScale({0,FColor(119, 124, 130, 30)});
	//SpriteEmitter2->ColorScale[1]=FParticleColorScale({1,FColor(119, 124, 130, 44)});
	SpriteEmitter2->FadeOutStartTime = 1;
	SpriteEmitter2->MaxParticles = 1;
	SpriteEmitter2->StartLocationOffset = FVector(5, 0, 0);
	SpriteEmitter2->UseRotationFrom = EParticleRotationSource::PTRS_Actor;
	//SpriteEmitter2->SizeScale[0]=FParticleTimeScale({0,1});
	//SpriteEmitter2->SizeScale[1]=FParticleTimeScale({1,3});
	//SpriteEmitter2->StartSizeRange=X=(Min=11, Max=13)|Y=(Min=100, Max=100)|Z=(Min=100, Max=100);
	SpriteEmitter2->InitialParticlesPerSecond = 1000;
	SpriteEmitter2->DrawStyle = EParticleDrawStyle::PTDS_AlphaBlend;
	SpriteEmitter2->Texture = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_FX/Particles/FX_dust_hitA_Mat.FX_dust_hitA_Mat'"), NULL, LOAD_None, NULL);
	SpriteEmitter2->SecondsBeforeInactive = 0;
	SpriteEmitter2->LifetimeRange = FRange({ 1.5, 2 });
	//SpriteEmitter2->StartVelocityRange=X=(Min=-5, Max=-5)|Y=(Min=-5, Max=5)|Z=(Min=-5, Max=5);
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
	//SpriteEmitter3->ColorScale[0]=FParticleColorScale({0,FColor(142, 150, 157, 105)});
	//SpriteEmitter3->ColorScale[1]=FParticleColorScale({1,FColor(142, 150, 157, 110)});
	SpriteEmitter3->FadeOutStartTime = 0.2;
	SpriteEmitter3->MaxParticles = 1;
	//SpriteEmitter3->StartLocationRange=X=(Min=-32, Max=-30)|Y=(Min=0, Max=0)|Z=(Min=0, Max=0);
	SpriteEmitter3->UseRotationFrom = EParticleRotationSource::PTRS_Actor;
	//SpriteEmitter3->SpinsPerSecondRange=X=(Min=0.2, Max=0.3)|Y=(Min=0, Max=0)|Z=(Min=0, Max=0);
	//SpriteEmitter3->StartSpinRange=X=(Min=0, Max=32600)|Y=(Min=0, Max=0)|Z=(Min=0, Max=0);
	//SpriteEmitter3->SizeScale[0]=FParticleTimeScale({0,1});
	//SpriteEmitter3->SizeScale[1]=FParticleTimeScale({0.7,1.7});
	//SpriteEmitter3->StartSizeRange=X=(Min=5, Max=6)|Y=(Min=100, Max=100)|Z=(Min=100, Max=100);
	SpriteEmitter3->InitialParticlesPerSecond = 1111;
	SpriteEmitter3->DrawStyle = EParticleDrawStyle::PTDS_AlphaBlend;
	SpriteEmitter3->Texture = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_FX/Particles/FX_dust_hitA_Mat.FX_dust_hitA_Mat'"), NULL, LOAD_None, NULL);
	SpriteEmitter3->LifetimeRange = FRange({ 1, 1 });
	//SpriteEmitter3->StartVelocityRange=X=(Min=650, Max=650)|Y=(Min=0, Max=0)|Z=(Min=0, Max=0);
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
	//SpriteEmitter4->ColorScale[0]=FParticleColorScale({0,FColor(142, 150, 157, 100)});
	//SpriteEmitter4->ColorScale[1]=FParticleColorScale({1,FColor(142, 150, 157, 105)});
	SpriteEmitter4->FadeOutStartTime = 0.3;
	SpriteEmitter4->MaxParticles = 1;
	//SpriteEmitter4->StartLocationRange=X=(Min=-32, Max=-28)|Y=(Min=0, Max=0)|Z=(Min=0, Max=0);
	SpriteEmitter4->UseRotationFrom = EParticleRotationSource::PTRS_Actor;
	//SpriteEmitter4->SpinsPerSecondRange=X=(Min=0.2, Max=0.3)|Y=(Min=0, Max=0)|Z=(Min=0, Max=0);
	//SpriteEmitter4->StartSpinRange=X=(Min=0, Max=32600)|Y=(Min=0, Max=0)|Z=(Min=0, Max=0);
	//SpriteEmitter4->SizeScale[0]=FParticleTimeScale({0,1});
	//SpriteEmitter4->SizeScale[1]=FParticleTimeScale({0.5,1.7});
	//SpriteEmitter4->StartSizeRange=X=(Min=7, Max=8)|Y=(Min=100, Max=100)|Z=(Min=100, Max=100);
	SpriteEmitter4->InitialParticlesPerSecond = 1111;
	SpriteEmitter4->DrawStyle = EParticleDrawStyle::PTDS_AlphaBlend;
	SpriteEmitter4->Texture = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_FX/Particles/FX_dust_hitA_Mat.FX_dust_hitA_Mat'"), NULL, LOAD_None, NULL);
	SpriteEmitter4->LifetimeRange = FRange({ 1.3, 1.3 });
	//SpriteEmitter4->StartVelocityRange=X=(Min=750, Max=770)|Y=(Min=0, Max=0)|Z=(Min=0, Max=0);
	//SpriteEmitter4->VelocityLossRange=X=(Min=15, Max=15)|Y=(Min=15, Max=15)|Z=(Min=15, Max=15);
	USpriteEmitter* SpriteEmitter5 = NewObject<USpriteEmitter>(USpriteEmitter::StaticClass());
	SpriteEmitter5->UseColorScale = true;
	SpriteEmitter5->FadeOut = true;
	SpriteEmitter5->RespawnDeadParticles = false;
	SpriteEmitter5->SpinParticles = true;
	SpriteEmitter5->UseSizeScale = true;
	SpriteEmitter5->UseRegularSizeScale = false;
	SpriteEmitter5->UniformSize = true;
	SpriteEmitter5->AutomaticInitialSpawning = false;
	SpriteEmitter5->Acceleration = FVector(0, 0, -100);
	//SpriteEmitter5->ColorScale[0]=FParticleColorScale({0,FColor(142, 150, 157, 60)});
	//SpriteEmitter5->ColorScale[1]=FParticleColorScale({1,FColor(142, 150, 157, 80)});
	SpriteEmitter5->FadeOutStartTime = 0.4;
	SpriteEmitter5->MaxParticles = 1;
	//SpriteEmitter5->StartLocationRange=X=(Min=-30, Max=-26)|Y=(Min=0, Max=0)|Z=(Min=0, Max=0);
	SpriteEmitter5->UseRotationFrom = EParticleRotationSource::PTRS_Actor;
	//SpriteEmitter5->SpinsPerSecondRange=X=(Min=0.2, Max=0.3)|Y=(Min=0, Max=0)|Z=(Min=0, Max=0);
	//SpriteEmitter5->StartSpinRange=X=(Min=0, Max=32600)|Y=(Min=0, Max=0)|Z=(Min=0, Max=0);
	//SpriteEmitter5->SizeScale[0]=FParticleTimeScale({0,1});
	//SpriteEmitter5->SizeScale[1]=FParticleTimeScale({0.8,1.7});
	//SpriteEmitter5->StartSizeRange=X=(Min=13, Max=15)|Y=(Min=100, Max=100)|Z=(Min=100, Max=100);
	SpriteEmitter5->InitialParticlesPerSecond = 1111;
	SpriteEmitter5->DrawStyle = EParticleDrawStyle::PTDS_AlphaBlend;
	SpriteEmitter5->Texture = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_FX/Particles/FX_dust_hitA_Mat.FX_dust_hitA_Mat'"), NULL, LOAD_None, NULL);
	SpriteEmitter5->LifetimeRange = FRange({ 1.5, 1.5 });
	//SpriteEmitter5->StartVelocityRange=X=(Min=1050, Max=1080)|Y=(Min=0, Max=0)|Z=(Min=0, Max=0);
	//SpriteEmitter5->VelocityLossRange=X=(Min=17, Max=17)|Y=(Min=17, Max=17)|Z=(Min=17, Max=17);
	USpriteEmitter* SpriteEmitter6 = NewObject<USpriteEmitter>(USpriteEmitter::StaticClass());
	SpriteEmitter6->UseColorScale = true;
	SpriteEmitter6->FadeOut = true;
	SpriteEmitter6->RespawnDeadParticles = false;
	SpriteEmitter6->SpinParticles = true;
	SpriteEmitter6->UseSizeScale = true;
	SpriteEmitter6->UseRegularSizeScale = false;
	SpriteEmitter6->UniformSize = true;
	SpriteEmitter6->AutomaticInitialSpawning = false;
	SpriteEmitter6->Acceleration = FVector(0, 0, -300);
	//SpriteEmitter6->ColorScale[0]=FParticleColorScale({0,FColor(142, 150, 157, 35)});
	//SpriteEmitter6->ColorScale[1]=FParticleColorScale({1,FColor(142, 150, 157, 60)});
	SpriteEmitter6->FadeOutStartTime = 0.5;
	SpriteEmitter6->MaxParticles = 3;
	//SpriteEmitter6->StartLocationRange=X=(Min=-28, Max=-24)|Y=(Min=0, Max=0)|Z=(Min=0, Max=0);
	SpriteEmitter6->UseRotationFrom = EParticleRotationSource::PTRS_Actor;
	//SpriteEmitter6->SpinsPerSecondRange=X=(Min=0.1, Max=0.1)|Y=(Min=0, Max=0)|Z=(Min=0, Max=0);
	//SpriteEmitter6->StartSpinRange=X=(Min=0, Max=32600)|Y=(Min=0, Max=0)|Z=(Min=0, Max=0);
	//SpriteEmitter6->SizeScale[0]=FParticleTimeScale({0,1});
	//SpriteEmitter6->SizeScale[1]=FParticleTimeScale({0.4,1.7});
	//SpriteEmitter6->StartSizeRange=X=(Min=18, Max=20)|Y=(Min=100, Max=100)|Z=(Min=100, Max=100);
	SpriteEmitter6->InitialParticlesPerSecond = 1111;
	SpriteEmitter6->DrawStyle = EParticleDrawStyle::PTDS_AlphaBlend;
	SpriteEmitter6->Texture = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_FX/Particles/FX_dust_hitA_Mat.FX_dust_hitA_Mat'"), NULL, LOAD_None, NULL);
	SpriteEmitter6->LifetimeRange = FRange({ 1.6, 1.6 });
	//SpriteEmitter6->StartVelocityRange=X=(Min=1500, Max=1500)|Y=(Min=400, Max=-400)|Z=(Min=400, Max=-400);
	//SpriteEmitter6->VelocityLossRange=X=(Min=18, Max=18)|Y=(Min=16, Max=16)|Z=(Min=16, Max=16);
	USpriteEmitter* SpriteEmitter7 = NewObject<USpriteEmitter>(USpriteEmitter::StaticClass());
	SpriteEmitter7->UseDirectionAs = EParticleDirectionUsage::PTDU_Up;
	SpriteEmitter7->UseColorScale = true;
	SpriteEmitter7->FadeOut = true;
	SpriteEmitter7->ResetAfterChange = true;
	SpriteEmitter7->RespawnDeadParticles = false;
	SpriteEmitter7->UseSizeScale = true;
	SpriteEmitter7->UseRegularSizeScale = false;
	SpriteEmitter7->AutomaticInitialSpawning = false;
	SpriteEmitter7->Acceleration = FVector(0, 0, -950);
	//SpriteEmitter7->ColorScale[0]=FParticleColorScale({0,FColor(175, 204, 253, 0)});
	//SpriteEmitter7->ColorScale[1]=FParticleColorScale({1,FColor(33, 136, 250, 0)});
	SpriteEmitter7->FadeOutStartTime = 0.3;
	SpriteEmitter7->MaxParticles = 6;
	SpriteEmitter7->UseRotationFrom = EParticleRotationSource::PTRS_Actor;
	//SpriteEmitter7->SizeScale[0]=FParticleTimeScale({0,1});
	//SpriteEmitter7->SizeScale[1]=FParticleTimeScale({0.7,0.9});
	//SpriteEmitter7->SizeScale[2]=FParticleTimeScale({1,0.3});
	//SpriteEmitter7->StartSizeRange=X=(Min=0.7, Max=1.7)|Y=(Min=2, Max=5)|Z=(Min=2, Max=5);
	SpriteEmitter7->InitialParticlesPerSecond = 1000;
	SpriteEmitter7->DrawStyle = EParticleDrawStyle::PTDS_Brighten;
	SpriteEmitter7->Texture = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_FX/Corona/fx2_cor_05_Mat.fx2_cor_05_Mat'"), NULL, LOAD_None, NULL);
	SpriteEmitter7->SecondsBeforeInactive = 0;
	SpriteEmitter7->LifetimeRange = FRange({ 0.05, 0.1 });
	//SpriteEmitter7->StartVelocityRange=X=(Min=150, Max=250)|Y=(Min=100, Max=-150)|Z=(Min=100, Max=-150);
	USpriteEmitter* SpriteEmitter8 = NewObject<USpriteEmitter>(USpriteEmitter::StaticClass());
	SpriteEmitter8->UseDirectionAs = EParticleDirectionUsage::PTDU_Up;
	SpriteEmitter8->UseColorScale = true;
	SpriteEmitter8->FadeOut = true;
	SpriteEmitter8->ResetAfterChange = true;
	SpriteEmitter8->RespawnDeadParticles = false;
	SpriteEmitter8->UseSizeScale = true;
	SpriteEmitter8->UseRegularSizeScale = false;
	SpriteEmitter8->AutomaticInitialSpawning = false;
	//SpriteEmitter8->ColorScale[0]=FParticleColorScale({0,FColor(142, 150, 157, 200)});
	//SpriteEmitter8->ColorScale[1]=FParticleColorScale({1,FColor(142, 150, 157, 220)});
	SpriteEmitter8->FadeOutStartTime = 0.1;
	SpriteEmitter8->MaxParticles = 1;
	SpriteEmitter8->UseRotationFrom = EParticleRotationSource::PTRS_Actor;
	//SpriteEmitter8->SizeScale[0]=FParticleTimeScale({0,1});
	//SpriteEmitter8->SizeScale[1]=FParticleTimeScale({1,4});
	//SpriteEmitter8->StartSizeRange=X=(Min=9, Max=9)|Y=(Min=7, Max=17)|Z=(Min=9, Max=9);
	SpriteEmitter8->InitialParticlesPerSecond = 2000;
	SpriteEmitter8->DrawStyle = EParticleDrawStyle::PTDS_AlphaBlend;
	SpriteEmitter8->Texture = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_FX/Particle/fx2_part_dirtbits_Mat.fx2_part_dirtbits_Mat'"), NULL, LOAD_None, NULL);
	SpriteEmitter8->SecondsBeforeInactive = 0;
	SpriteEmitter8->LifetimeRange = FRange({ 0.25, 0.25 });
	//SpriteEmitter8->StartVelocityRange=X=(Min=99, Max=99)|Y=(Min=0, Max=0)|Z=(Min=0, Max=0);
	//SpriteEmitter8->VelocityLossRange=X=(Min=15, Max=15)|Y=(Min=15, Max=15)|Z=(Min=15, Max=15);
	Emitters = { SpriteEmitter1,SpriteEmitter2,SpriteEmitter3,SpriteEmitter4,SpriteEmitter5,SpriteEmitter6,SpriteEmitter7,SpriteEmitter8 };

}