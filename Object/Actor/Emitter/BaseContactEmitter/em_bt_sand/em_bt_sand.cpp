// All the original content belonged to the US Army

#include "AA29/Object/Actor/Emitter/BaseContactEmitter/em_bt_sand/em_bt_sand.h"
#include "AA29/Object/BaseEmitter/ParticleEmitter/SpriteEmitter/SpriteEmitter.h"

Aem_bt_sand::Aem_bt_sand()
{
	USpriteEmitter* SpriteEmitter0 = NewObject<USpriteEmitter>(USpriteEmitter::StaticClass());
	SpriteEmitter0->UseColorScale = true;
	SpriteEmitter0->RespawnDeadParticles = false;
	SpriteEmitter0->SpinParticles = true;
	SpriteEmitter0->UseSizeScale = true;
	SpriteEmitter0->UseRegularSizeScale = false;
	SpriteEmitter0->UniformSize = true;
	SpriteEmitter0->AutomaticInitialSpawning = false;
	//SpriteEmitter0->ColorScale[0]=FParticleColorScale({0,FColor(121, 138, 155, 44)});
	//SpriteEmitter0->ColorScale[1]=FParticleColorScale({1,FColor(121, 138, 155, 0)});
	SpriteEmitter0->FadeOutStartTime = 1;
	SpriteEmitter0->MaxParticles = 1;
	SpriteEmitter0->StartLocationOffset = FVector(15, 0, 0);
	SpriteEmitter0->UseRotationFrom = EParticleRotationSource::PTRS_Actor;
	SpriteEmitter0->SpinsPerSecondRange = FRangeVector({ {0.1, 0.1}, {0, 0}, {0, 0} });
	SpriteEmitter0->StartSpinRange = FRangeVector({ {0, 32000}, {0, 0}, {0, 0} });
	//SpriteEmitter0->SizeScale[0]=FParticleTimeScale({0,1});
	//SpriteEmitter0->SizeScale[1]=FParticleTimeScale({1,5});
	SpriteEmitter0->StartSizeRange = FRangeVector({ {22, 22}, {100, 100}, {100, 100} });
	SpriteEmitter0->InitialParticlesPerSecond = 1000;
	SpriteEmitter0->DrawStyle = EParticleDrawStyle::PTDS_AlphaBlend;
	SpriteEmitter0->Texture = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_FX/Particles/fx_smk_ball01_Mat.fx_smk_ball01_Mat'"), NULL, LOAD_None, NULL);
	SpriteEmitter0->SecondsBeforeInactive = 0;
	SpriteEmitter0->LifetimeRange = FRange({ 2, 3 });
	SpriteEmitter0->StartVelocityRange = FRangeVector({ {-25, -25}, {-10, 10}, {-10, 10} });
	USpriteEmitter* SpriteEmitter1 = NewObject<USpriteEmitter>(USpriteEmitter::StaticClass());
	SpriteEmitter1->UseDirectionAs = EParticleDirectionUsage::PTDU_Up;
	SpriteEmitter1->UseColorScale = true;
	SpriteEmitter1->FadeOut = true;
	SpriteEmitter1->ResetAfterChange = true;
	SpriteEmitter1->RespawnDeadParticles = false;
	SpriteEmitter1->UseSizeScale = true;
	SpriteEmitter1->UseRegularSizeScale = false;
	SpriteEmitter1->AutomaticInitialSpawning = false;
	SpriteEmitter1->BlendBetweenSubdivisions = true;
	//SpriteEmitter1->ColorScale[0]=FParticleColorScale({0,FColor(79, 131, 169, 0)});
	//SpriteEmitter1->ColorScale[1]=FParticleColorScale({1,FColor(0, 0, 0, 0)});
	SpriteEmitter1->FadeOutStartTime = 0.1;
	SpriteEmitter1->MaxParticles = 3;
	SpriteEmitter1->UseRotationFrom = EParticleRotationSource::PTRS_Actor;
	//SpriteEmitter1->SizeScale[0]=FParticleTimeScale({0,0.1});
	//SpriteEmitter1->SizeScale[1]=FParticleTimeScale({1,0.4});
	SpriteEmitter1->StartSizeRange = FRangeVector({ {5, 5}, {100, 100}, {150, 150} });
	SpriteEmitter1->InitialParticlesPerSecond = 2000;
	SpriteEmitter1->DrawStyle = EParticleDrawStyle::PTDS_Brighten;
	SpriteEmitter1->Texture = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_FX/Particles/fx_part_smokeanim01_Mat.fx_part_smokeanim01_Mat'"), NULL, LOAD_None, NULL);
	SpriteEmitter1->TextureUSubdivisions = 4;
	SpriteEmitter1->TextureVSubdivisions = 2;
	SpriteEmitter1->SecondsBeforeInactive = 0;
	SpriteEmitter1->LifetimeRange = FRange({ 0.3, 0.3 });
	SpriteEmitter1->StartVelocityRange = FRangeVector({ {150, 150}, {-250, 250}, {-250, 250} });
	USpriteEmitter* SpriteEmitter2 = NewObject<USpriteEmitter>(USpriteEmitter::StaticClass());
	SpriteEmitter2->FadeOut = true;
	SpriteEmitter2->ResetAfterChange = true;
	SpriteEmitter2->RespawnDeadParticles = false;
	SpriteEmitter2->UseSizeScale = true;
	SpriteEmitter2->UseRegularSizeScale = false;
	SpriteEmitter2->UniformSize = true;
	SpriteEmitter2->AutomaticInitialSpawning = false;
	SpriteEmitter2->Acceleration = FVector(0, 0, -1111);
	SpriteEmitter2->FadeOutStartTime = 0.3;
	SpriteEmitter2->MaxParticles = 1;
	SpriteEmitter2->StartLocationRange = FRangeVector({ {0, 0}, {0, 0}, {-15, -15} });
	//SpriteEmitter2->SizeScale[0]=FParticleTimeScale({0,1});
	//SpriteEmitter2->SizeScale[1]=FParticleTimeScale({1,4});
	SpriteEmitter2->StartSizeRange = FRangeVector({ {11, 15}, {100, 100}, {100, 100} });
	SpriteEmitter2->InitialParticlesPerSecond = 2000;
	SpriteEmitter2->DrawStyle = EParticleDrawStyle::PTDS_AlphaBlend;
	SpriteEmitter2->Texture = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_FX/Particle/fx2_part_dirtclumps_Mat.fx2_part_dirtclumps_Mat'"), NULL, LOAD_None, NULL);
	SpriteEmitter2->SecondsBeforeInactive = 0;
	SpriteEmitter2->LifetimeRange = FRange({ 0.4, 0.4 });
	SpriteEmitter2->StartVelocityRange = FRangeVector({ {0, 0}, {0, 0}, {315, 337} });
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
	//SpriteEmitter3->ColorScale[0]=FParticleColorScale({0,FColor(121, 138, 155, 99)});
	//SpriteEmitter3->ColorScale[1]=FParticleColorScale({1,FColor(121, 138, 155, 99)});
	SpriteEmitter3->FadeOutStartTime = 0.5;
	SpriteEmitter3->MaxParticles = 1;
	SpriteEmitter3->StartLocationRange = FRangeVector({ {-3, -3}, {0, 0}, {0, 0} });
	SpriteEmitter3->UseRotationFrom = EParticleRotationSource::PTRS_Actor;
	SpriteEmitter3->SpinsPerSecondRange = FRangeVector({ {0.2, 0.3}, {0, 0}, {0, 0} });
	SpriteEmitter3->StartSpinRange = FRangeVector({ {0, 32600}, {0, 0}, {0, 0} });
	//SpriteEmitter3->SizeScale[0]=FParticleTimeScale({0,1});
	//SpriteEmitter3->SizeScale[1]=FParticleTimeScale({1,1.7});
	SpriteEmitter3->StartSizeRange = FRangeVector({ {14, 17}, {100, 100}, {100, 100} });
	SpriteEmitter3->InitialParticlesPerSecond = 1111;
	SpriteEmitter3->DrawStyle = EParticleDrawStyle::PTDS_AlphaBlend;
	SpriteEmitter3->Texture = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_FX/Particles/fx_smk_ball01_Mat.fx_smk_ball01_Mat'"), NULL, LOAD_None, NULL);
	SpriteEmitter3->LifetimeRange = FRange({ 2.5, 2.7 });
	SpriteEmitter3->StartVelocityRange = FRangeVector({ {350, 370}, {0, 0}, {0, 0} });
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
	//SpriteEmitter4->ColorScale[0]=FParticleColorScale({0,FColor(121, 138, 155, 99)});
	//SpriteEmitter4->ColorScale[1]=FParticleColorScale({1,FColor(121, 138, 155, 99)});
	SpriteEmitter4->FadeOutStartTime = 0.5;
	SpriteEmitter4->MaxParticles = 1;
	SpriteEmitter4->StartLocationRange = FRangeVector({ {-4, -2}, {0, 0}, {0, 0} });
	SpriteEmitter4->UseRotationFrom = EParticleRotationSource::PTRS_Actor;
	SpriteEmitter4->SpinsPerSecondRange = FRangeVector({ {0.2, 0.3}, {0, 0}, {0, 0} });
	SpriteEmitter4->StartSpinRange = FRangeVector({ {0, 32600}, {0, 0}, {0, 0} });
	//SpriteEmitter4->SizeScale[0]=FParticleTimeScale({0,1});
	//SpriteEmitter4->SizeScale[1]=FParticleTimeScale({1,1.7});
	SpriteEmitter4->StartSizeRange = FRangeVector({ {11, 13}, {100, 100}, {100, 100} });
	SpriteEmitter4->InitialParticlesPerSecond = 1111;
	SpriteEmitter4->DrawStyle = EParticleDrawStyle::PTDS_AlphaBlend;
	SpriteEmitter4->Texture = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_FX/Particles/fx_smk_ball01_Mat.fx_smk_ball01_Mat'"), NULL, LOAD_None, NULL);
	SpriteEmitter4->LifetimeRange = FRange({ 2.5, 2.7 });
	SpriteEmitter4->StartVelocityRange = FRangeVector({ {510, 530}, {0, 0}, {0, 0} });
	SpriteEmitter4->VelocityLossRange = FRangeVector({ {15, 15}, {15, 15}, {15, 15} });
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
	//SpriteEmitter5->ColorScale[0]=FParticleColorScale({0,FColor(121, 138, 155, 99)});
	//SpriteEmitter5->ColorScale[1]=FParticleColorScale({1,FColor(121, 138, 155, 99)});
	SpriteEmitter5->FadeOutStartTime = 0.5;
	SpriteEmitter5->MaxParticles = 1;
	SpriteEmitter5->StartLocationRange = FRangeVector({ {-4, -2}, {0, 0}, {0, 0} });
	SpriteEmitter5->UseRotationFrom = EParticleRotationSource::PTRS_Actor;
	SpriteEmitter5->SpinsPerSecondRange = FRangeVector({ {0.1, 0.1}, {0, 0}, {0, 0} });
	SpriteEmitter5->StartSpinRange = FRangeVector({ {0, 32600}, {0, 0}, {0, 0} });
	//SpriteEmitter5->SizeScale[0]=FParticleTimeScale({0,1});
	//SpriteEmitter5->SizeScale[1]=FParticleTimeScale({1,1.7});
	SpriteEmitter5->StartSizeRange = FRangeVector({ {9, 10}, {100, 100}, {100, 100} });
	SpriteEmitter5->InitialParticlesPerSecond = 1111;
	SpriteEmitter5->DrawStyle = EParticleDrawStyle::PTDS_AlphaBlend;
	SpriteEmitter5->Texture = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_FX/Particles/fx_smk_ball01_Mat.fx_smk_ball01_Mat'"), NULL, LOAD_None, NULL);
	SpriteEmitter5->LifetimeRange = FRange({ 2.5, 2.7 });
	SpriteEmitter5->StartVelocityRange = FRangeVector({ {570, 650}, {0, 0}, {0, 0} });
	SpriteEmitter5->VelocityLossRange = FRangeVector({ {15, 15}, {15, 15}, {15, 15} });

	Emitters = { SpriteEmitter0,SpriteEmitter1,SpriteEmitter2,SpriteEmitter3,SpriteEmitter4,SpriteEmitter5 };

}
