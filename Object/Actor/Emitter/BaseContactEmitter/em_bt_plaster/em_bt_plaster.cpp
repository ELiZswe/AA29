// All the original content belonged to the US Army

#include "AA29/Object/Actor/Emitter/BaseContactEmitter/em_bt_plaster/em_bt_plaster.h"
#include "AA29/Object/BaseEmitter/ParticleEmitter/SpriteEmitter/SpriteEmitter.h"

Aem_bt_plaster::Aem_bt_plaster()
{
	USpriteEmitter* SpriteEmitter0 = NewObject<USpriteEmitter>(USpriteEmitter::StaticClass());
	SpriteEmitter0->FadeOut = true;
	SpriteEmitter0->RespawnDeadParticles = false;
	SpriteEmitter0->AutoDestroy = true;
	SpriteEmitter0->SpinParticles = true;
	SpriteEmitter0->UseSizeScale = true;
	SpriteEmitter0->UniformSize = true;
	SpriteEmitter0->AutomaticInitialSpawning = false;
	SpriteEmitter0->BlendBetweenSubdivisions = true;
	SpriteEmitter0->Acceleration = FVector(0, 0, -100);
	SpriteEmitter0->FadeOutStartTime = 0.2;
	SpriteEmitter0->MaxParticles = 6;
	SpriteEmitter0->UseRotationFrom = EParticleRotationSource::PTRS_Actor;
	SpriteEmitter0->SpinsPerSecondRange = FRangeVector({ {-2, 3}, {0, 0}, {0, 0} });
	SpriteEmitter0->StartSpinRange = FRangeVector({ {0, 32000}, {0, 0}, {0, 0} });
	//SpriteEmitter0->SizeScale[0]=FParticleTimeScale({0,1});
	//SpriteEmitter0->SizeScale[1]=FParticleTimeScale({0.5,1});
	//SpriteEmitter0->SizeScale[2]=FParticleTimeScale({1,0.1});
	SpriteEmitter0->StartSizeRange = FRangeVector({ {1, 2}, {100, 100}, {100, 100} });
	SpriteEmitter0->InitialParticlesPerSecond = 5000;
	SpriteEmitter0->DrawStyle = EParticleDrawStyle::PTDS_AlphaBlend;
	SpriteEmitter0->Texture = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_FX/Particles/fx_part_woodchip_Mat.fx_part_woodchip_Mat'"), NULL, LOAD_None, NULL);
	SpriteEmitter0->TextureUSubdivisions = 4;
	SpriteEmitter0->TextureVSubdivisions = 4;
	SpriteEmitter0->SecondsBeforeInactive = 0;
	SpriteEmitter0->LifetimeRange = FRange({ 0.8, 1 });
	SpriteEmitter0->StartVelocityRange = FRangeVector({ {600, 200}, {-200, 150}, {-200, 150} });
	SpriteEmitter0->VelocityLossRange = FRangeVector({ {5, 5}, {7, 7}, {7, 7} });
	USpriteEmitter* SpriteEmitter1 = NewObject<USpriteEmitter>(USpriteEmitter::StaticClass());
	SpriteEmitter1->UseColorScale = true;
	SpriteEmitter1->FadeOut = true;
	SpriteEmitter1->RespawnDeadParticles = false;
	SpriteEmitter1->UseSizeScale = true;
	SpriteEmitter1->UseRegularSizeScale = false;
	SpriteEmitter1->UniformSize = true;
	SpriteEmitter1->AutomaticInitialSpawning = false;
	SpriteEmitter1->BlendBetweenSubdivisions = true;
	//SpriteEmitter1->ColorScale[0]=FParticleColorScale({0,FColor(14, 15, 15, 0)});
	//SpriteEmitter1->ColorScale[1]=FParticleColorScale({1,FColor(0, 0, 0, 0)});
	SpriteEmitter1->FadeOutStartTime = 1.5;
	SpriteEmitter1->MaxParticles = 1;
	SpriteEmitter1->StartLocationOffset = FVector(15, 0, 0);
	SpriteEmitter1->UseRotationFrom = EParticleRotationSource::PTRS_Actor;
	//SpriteEmitter1->SizeScale[0]=FParticleTimeScale({0,0.1});
	//SpriteEmitter1->SizeScale[1]=FParticleTimeScale({1,0.5});
	SpriteEmitter1->InitialParticlesPerSecond = 1000;
	SpriteEmitter1->Texture = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_FX/Particles/fx_part_smokeanim01_Mat.fx_part_smokeanim01_Mat'"), NULL, LOAD_None, NULL);
	SpriteEmitter1->TextureUSubdivisions = 4;
	SpriteEmitter1->TextureVSubdivisions = 2;
	SpriteEmitter1->SecondsBeforeInactive = 0;
	SpriteEmitter1->LifetimeRange = FRange({ 1, 2 });
	SpriteEmitter1->StartVelocityRange = FRangeVector({ {-25, -25}, {-10, 10}, {-10, 10} });
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
	//SpriteEmitter2->ColorScale[0]=FParticleColorScale({0,FColor(71, 94, 103, 80)});
	//SpriteEmitter2->ColorScale[1]=FParticleColorScale({1,FColor(96, 134, 157, 90)});
	SpriteEmitter2->FadeOutStartTime = 0.2;
	SpriteEmitter2->MaxParticles = 1;
	SpriteEmitter2->StartLocationRange = FRangeVector({ {-32, -30}, {0, 0}, {0, 0} });
	SpriteEmitter2->UseRotationFrom = EParticleRotationSource::PTRS_Actor;
	SpriteEmitter2->SpinsPerSecondRange = FRangeVector({ {0.2, 0.3}, {0, 0}, {0, 0} });
	SpriteEmitter2->StartSpinRange = FRangeVector({ {0, 32600}, {0, 0}, {0, 0} });
	//SpriteEmitter2->SizeScale[0]=FParticleTimeScale({0,1});
	//SpriteEmitter2->SizeScale[1]=FParticleTimeScale({0.7,1.7});
	SpriteEmitter2->StartSizeRange = FRangeVector({ {3, 5}, {100, 100}, {100, 100} });
	SpriteEmitter2->InitialParticlesPerSecond = 1111;
	SpriteEmitter2->DrawStyle = EParticleDrawStyle::PTDS_AlphaBlend;
	SpriteEmitter2->Texture = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_FX/Particles/FX_dust_hitA_Mat.FX_dust_hitA_Mat'"), NULL, LOAD_None, NULL);
	SpriteEmitter2->LifetimeRange = FRange({ 1, 1 });
	SpriteEmitter2->StartVelocityRange = FRangeVector({ {650, 650}, {0, 0}, {0, 0} });
	SpriteEmitter2->VelocityLossRange = FRangeVector({ {15, 15}, {15, 15}, {15, 15} });
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
	//SpriteEmitter3->ColorScale[0]=FParticleColorScale({0,FColor(142, 167, 181, 75)});
	//SpriteEmitter3->ColorScale[1]=FParticleColorScale({1,FColor(142, 167, 181, 85)});
	SpriteEmitter3->FadeOutStartTime = 0.3;
	SpriteEmitter3->MaxParticles = 1;
	SpriteEmitter3->StartLocationRange = FRangeVector({ {-32, -28}, {0, 0}, {0, 0} });
	SpriteEmitter3->UseRotationFrom = EParticleRotationSource::PTRS_Actor;
	SpriteEmitter3->SpinsPerSecondRange = FRangeVector({ {0.2, 0.3}, {0, 0}, {0, 0} });
	SpriteEmitter3->StartSpinRange = FRangeVector({ {0, 32600}, {0, 0}, {0, 0} });
	//SpriteEmitter3->SizeScale[0]=FParticleTimeScale({0,1});
	//SpriteEmitter3->SizeScale[1]=FParticleTimeScale({0.5,1.7});
	SpriteEmitter3->StartSizeRange = FRangeVector({ {8, 11}, {100, 100}, {100, 100} });
	SpriteEmitter3->InitialParticlesPerSecond = 1111;
	SpriteEmitter3->DrawStyle = EParticleDrawStyle::PTDS_AlphaBlend;
	SpriteEmitter3->Texture = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_FX/Particles/FX_dust_hitA_Mat.FX_dust_hitA_Mat'"), NULL, LOAD_None, NULL);
	SpriteEmitter3->LifetimeRange = FRange({ 1.3, 1.3 });
	SpriteEmitter3->StartVelocityRange = FRangeVector({ {750, 770}, {0, 0}, {0, 0} });
	SpriteEmitter3->VelocityLossRange = FRangeVector({ {15, 15}, {15, 15}, {15, 15} });
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
	//SpriteEmitter4->ColorScale[0]=FParticleColorScale({0,FColor(154, 163, 167, 60)});
	//SpriteEmitter4->ColorScale[1]=FParticleColorScale({1,FColor(154, 163, 167, 75)});
	SpriteEmitter4->FadeOutStartTime = 0.4;
	SpriteEmitter4->MaxParticles = 1;
	SpriteEmitter4->StartLocationRange = FRangeVector({ {-30, -26}, {0, 0}, {0, 0} });
	SpriteEmitter4->UseRotationFrom = EParticleRotationSource::PTRS_Actor;
	SpriteEmitter4->SpinsPerSecondRange = FRangeVector({ {0.2, 0.3}, {0, 0}, {0, 0} });
	SpriteEmitter4->StartSpinRange = FRangeVector({ {0, 32600}, {0, 0}, {0, 0} });
	//SpriteEmitter4->SizeScale[0]=FParticleTimeScale({0,1});
	//SpriteEmitter4->SizeScale[1]=FParticleTimeScale({0.8,1.7});
	SpriteEmitter4->StartSizeRange = FRangeVector({ {14, 16}, {100, 100}, {100, 100} });
	SpriteEmitter4->InitialParticlesPerSecond = 1111;
	SpriteEmitter4->DrawStyle = EParticleDrawStyle::PTDS_AlphaBlend;
	SpriteEmitter4->Texture = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_FX/Particles/FX_dust_hitA_Mat.FX_dust_hitA_Mat'"), NULL, LOAD_None, NULL);
	SpriteEmitter4->LifetimeRange = FRange({ 1.5, 1.5 });
	SpriteEmitter4->StartVelocityRange = FRangeVector({ {1050, 1080}, {0, 0}, {0, 0} });
	SpriteEmitter4->VelocityLossRange = FRangeVector({ {17, 17}, {17, 17}, {17, 17} });
	USpriteEmitter* SpriteEmitter5 = NewObject<USpriteEmitter>(USpriteEmitter::StaticClass());
	SpriteEmitter5->UseColorScale = true;
	SpriteEmitter5->FadeOut = true;
	SpriteEmitter5->RespawnDeadParticles = false;
	SpriteEmitter5->SpinParticles = true;
	SpriteEmitter5->UseSizeScale = true;
	SpriteEmitter5->UseRegularSizeScale = false;
	SpriteEmitter5->UniformSize = true;
	SpriteEmitter5->AutomaticInitialSpawning = false;
	SpriteEmitter5->Acceleration = FVector(0, 0, -300);
	//SpriteEmitter5->ColorScale[0]=FParticleColorScale({0,FColor(142, 150, 157, 30)});
	//SpriteEmitter5->ColorScale[1]=FParticleColorScale({1,FColor(142, 150, 157, 40)});
	SpriteEmitter5->FadeOutStartTime = 0.5;
	SpriteEmitter5->MaxParticles = 2;
	SpriteEmitter5->StartLocationRange = FRangeVector({ {-28, -24}, {0, 0}, {0, 0} });
	SpriteEmitter5->UseRotationFrom = EParticleRotationSource::PTRS_Actor;
	SpriteEmitter5->SpinsPerSecondRange = FRangeVector({ {0.1, 0.1}, {0, 0}, {0, 0} });
	SpriteEmitter5->StartSpinRange = FRangeVector({ {0, 32600}, {0, 0}, {0, 0} });
	//SpriteEmitter5->SizeScale[0]=FParticleTimeScale({0,1});
	//SpriteEmitter5->SizeScale[1]=FParticleTimeScale({0.4,1.7});
	SpriteEmitter5->StartSizeRange = FRangeVector({ {21, 24}, {100, 100}, {100, 100} });
	SpriteEmitter5->InitialParticlesPerSecond = 1111;
	SpriteEmitter5->DrawStyle = EParticleDrawStyle::PTDS_AlphaBlend;
	SpriteEmitter5->Texture = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_FX/Particles/FX_dust_hitA_Mat.FX_dust_hitA_Mat'"), NULL, LOAD_None, NULL);
	SpriteEmitter5->LifetimeRange = FRange({ 1.6, 1.6 });
	SpriteEmitter5->StartVelocityRange = FRangeVector({ {1500, 1500}, {0, 0}, {0, 0} });
	SpriteEmitter5->VelocityLossRange = FRangeVector({ {18, 18}, {18, 18}, {18, 18} });
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
	//SpriteEmitter6->ColorScale[0]=FParticleColorScale({0,FColor(142, 150, 157, 20)});
	//SpriteEmitter6->ColorScale[1]=FParticleColorScale({1,FColor(142, 150, 157, 30)});
	SpriteEmitter6->FadeOutStartTime = 0.5;
	SpriteEmitter6->MaxParticles = 3;
	SpriteEmitter6->StartLocationRange = FRangeVector({ {-28, -24}, {0, 0}, {0, 0} });
	SpriteEmitter6->UseRotationFrom = EParticleRotationSource::PTRS_Actor;
	SpriteEmitter6->SpinsPerSecondRange = FRangeVector({ {0.1, 0.1}, {0, 0}, {0, 0} });
	SpriteEmitter6->StartSpinRange = FRangeVector({ {0, 32600}, {0, 0}, {0, 0} });
	//SpriteEmitter6->SizeScale[0]=FParticleTimeScale({0,1});
	//SpriteEmitter6->SizeScale[1]=FParticleTimeScale({0.4,1.7});
	SpriteEmitter6->StartSizeRange = FRangeVector({ {21, 24}, {100, 100}, {100, 100} });
	SpriteEmitter6->InitialParticlesPerSecond = 1111;
	SpriteEmitter6->DrawStyle = EParticleDrawStyle::PTDS_AlphaBlend;
	SpriteEmitter6->Texture = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_FX/Particles/FX_dust_hitA_Mat.FX_dust_hitA_Mat'"), NULL, LOAD_None, NULL);
	SpriteEmitter6->LifetimeRange = FRange({ 1.6, 1.6 });
	SpriteEmitter6->StartVelocityRange = FRangeVector({ {1900, 1900}, {400, -400}, {400, -400} });
	SpriteEmitter6->VelocityLossRange = FRangeVector({ {16, 16}, {16, 16}, {16, 16} });
	USpriteEmitter* SpriteEmitter7 = NewObject<USpriteEmitter>(USpriteEmitter::StaticClass());
	SpriteEmitter7->UseDirectionAs = EParticleDirectionUsage::PTDU_Up;
	SpriteEmitter7->UseColorScale = true;
	SpriteEmitter7->FadeOut = true;
	SpriteEmitter7->ResetAfterChange = true;
	SpriteEmitter7->RespawnDeadParticles = false;
	SpriteEmitter7->UseSizeScale = true;
	SpriteEmitter7->UseRegularSizeScale = false;
	SpriteEmitter7->AutomaticInitialSpawning = false;
	SpriteEmitter7->UseRandomSubdivision = true;
	SpriteEmitter7->Acceleration = FVector(0, 0, -950);
	//SpriteEmitter7->ColorScale[0]=FParticleColorScale({0,FColor(175, 204, 253, 0)});
	//SpriteEmitter7->ColorScale[1]=FParticleColorScale({1,FColor(33, 136, 250, 0)});
	SpriteEmitter7->FadeOutStartTime = 0.5;
	SpriteEmitter7->MaxParticles = 6;
	SpriteEmitter7->UseRotationFrom = EParticleRotationSource::PTRS_Actor;
	//SpriteEmitter7->SizeScale[0]=FParticleTimeScale({0,0.05});
	//SpriteEmitter7->SizeScale[1]=FParticleTimeScale({1,0.01});
	SpriteEmitter7->StartSizeRange = FRangeVector({ {5, 5}, {0, 44}, {0, 44} });
	SpriteEmitter7->InitialParticlesPerSecond = 1000;
	SpriteEmitter7->DrawStyle = EParticleDrawStyle::PTDS_Brighten;
	SpriteEmitter7->Texture = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_FX/Particles/fx_part_threads_Mat.fx_part_threads_Mat'"), NULL, LOAD_None, NULL);
	SpriteEmitter7->TextureUSubdivisions = 2;
	SpriteEmitter7->TextureVSubdivisions = 2;
	SpriteEmitter7->SecondsBeforeInactive = 0;
	SpriteEmitter7->LifetimeRange = FRange({ 0.05, 0.07 });
	SpriteEmitter7->StartVelocityRange = FRangeVector({ {250, 250}, {125, -125}, {125, -125} });
	USpriteEmitter* SpriteEmitter8 = NewObject<USpriteEmitter>(USpriteEmitter::StaticClass());
	SpriteEmitter8->UseDirectionAs = EParticleDirectionUsage::PTDU_Up;
	SpriteEmitter8->UseColorScale = true;
	SpriteEmitter8->FadeOut = true;
	SpriteEmitter8->ResetAfterChange = true;
	SpriteEmitter8->RespawnDeadParticles = false;
	SpriteEmitter8->UseSizeScale = true;
	SpriteEmitter8->UseRegularSizeScale = false;
	SpriteEmitter8->AutomaticInitialSpawning = false;
	//SpriteEmitter8->ColorScale[0]=FParticleColorScale({0,FColor(142, 150, 157, 175)});
	//SpriteEmitter8->ColorScale[1]=FParticleColorScale({1,FColor(142, 150, 157, 175)});
	SpriteEmitter8->FadeOutStartTime = 0.1;
	SpriteEmitter8->MaxParticles = 1;
	SpriteEmitter8->UseRotationFrom = EParticleRotationSource::PTRS_Actor;
	//SpriteEmitter8->SizeScale[0]=FParticleTimeScale({0,1});
	//SpriteEmitter8->SizeScale[1]=FParticleTimeScale({1,4});
	SpriteEmitter8->StartSizeRange = FRangeVector({ {9, 9}, {7, 17}, {9, 9} });
	SpriteEmitter8->InitialParticlesPerSecond = 2000;
	SpriteEmitter8->DrawStyle = EParticleDrawStyle::PTDS_AlphaBlend;
	SpriteEmitter8->Texture = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_FX/Particle/fx2_part_dirtbits_Mat.fx2_part_dirtbits_Mat'"), NULL, LOAD_None, NULL);
	SpriteEmitter8->SecondsBeforeInactive = 0;
	SpriteEmitter8->LifetimeRange = FRange({ 0.25, 0.25 });
	SpriteEmitter8->StartVelocityRange = FRangeVector({ {99, 99}, {0, 0}, {0, 0} });
	SpriteEmitter8->VelocityLossRange = FRangeVector({ {15, 15}, {15, 15}, {15, 15} });

	Emitters = { SpriteEmitter0,SpriteEmitter1,SpriteEmitter2,SpriteEmitter3,SpriteEmitter4,SpriteEmitter5,SpriteEmitter6,SpriteEmitter7,SpriteEmitter8 };
}
