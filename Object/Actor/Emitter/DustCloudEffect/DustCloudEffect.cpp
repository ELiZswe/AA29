// All the original content belonged to the US Army

#include "AA29/Object/Actor/Emitter/DustCloudEffect/DustCloudEffect.h"
#include "AA29/Object/BaseEmitter/ParticleEmitter/SpriteEmitter/SpriteEmitter.h"

ADustCloudEffect::ADustCloudEffect()
{
	USpriteEmitter* SpriteEmitter0 = NewObject<USpriteEmitter>(USpriteEmitter::StaticClass());
	SpriteEmitter0->UseColorScale = true;
	SpriteEmitter0->FadeOut = true;
	SpriteEmitter0->RespawnDeadParticles = false;
	SpriteEmitter0->SpinParticles = true;
	SpriteEmitter0->UniformSize = true;
	SpriteEmitter0->AutomaticInitialSpawning = false;
	SpriteEmitter0->BlendBetweenSubdivisions = true;
	SpriteEmitter0->UseRandomSubdivision = true;
	SpriteEmitter0->Acceleration = FVector(0, 0, -550);
	SpriteEmitter0->FadeOutStartTime = 0.5;
	SpriteEmitter0->MaxParticles = 30;
	SpriteEmitter0->StartLocationRange = FRangeVector({ {-10, 10}, {-10, 10}, {-10, 10} });
	SpriteEmitter0->UseRotationFrom = EParticleRotationSource::PTRS_Actor;
	SpriteEmitter0->SpinsPerSecondRange = FRangeVector({ {0.5, 2}, {0, 0}, {0, 0} });
	SpriteEmitter0->StartSizeRange = FRangeVector({ {2, 8}, {100, 100}, {100, 100} });
	SpriteEmitter0->DrawStyle = EParticleDrawStyle::PTDS_AlphaBlend;
	SpriteEmitter0->Texture = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_FX/Particle/fx2_part_dirtclumps_Mat.fx2_part_dirtclumps_Mat'"), NULL, LOAD_None, NULL);
	SpriteEmitter0->TextureUSubdivisions = 16;
	SpriteEmitter0->TextureVSubdivisions = 16;
	SpriteEmitter0->SecondsBeforeInactive = 0;
	SpriteEmitter0->LifetimeRange = FRange({ 0.65, 0.65 });
	SpriteEmitter0->StartVelocityRange = FRangeVector({ {-150, -250}, {-80, 80}, {50, 250} });
	USpriteEmitter* SpriteEmitter1 = NewObject<USpriteEmitter>(USpriteEmitter::StaticClass());
	SpriteEmitter1->UseColorScale = true;
	SpriteEmitter1->FadeOut = true;
	SpriteEmitter1->RespawnDeadParticles = false;
	SpriteEmitter1->SpinParticles = true;
	SpriteEmitter1->UseSizeScale = true;
	SpriteEmitter1->UseRegularSizeScale = false;
	SpriteEmitter1->UniformSize = true;
	SpriteEmitter1->AutomaticInitialSpawning = false;
	SpriteEmitter1->Acceleration = FVector(0, 0, 5);
	//SpriteEmitter1->ColorScale[0]=FParticleColorScale({0,FColor(30, 90, 110, 0)});
	//SpriteEmitter1->ColorScale[1]=FParticleColorScale({0.1,FColor(34, 44, 66, 128)});
	//SpriteEmitter1->ColorScale[2]=FParticleColorScale({0.9,FColor(36, 49, 64, 128)});
	//SpriteEmitter1->ColorScale[3]=FParticleColorScale({1,FColor(20, 50, 80, 0)});
	SpriteEmitter1->FadeOutStartTime = 1.5;
	SpriteEmitter1->MaxParticles = 100;
	SpriteEmitter1->StartLocationRange = FRangeVector({ {0, 0}, {-24, 24}, {0, 0} });
	SpriteEmitter1->UseRotationFrom = EParticleRotationSource::PTRS_Actor;
	SpriteEmitter1->SpinsPerSecondRange = FRangeVector({ {0, 0.025}, {0, 0}, {0, 0} });
	SpriteEmitter1->StartSpinRange = FRangeVector({ {0, 1}, {0, 0}, {0, 0} });
	//SpriteEmitter1->SizeScale[0]=FParticleTimeScale({0,1.2});
	//SpriteEmitter1->SizeScale[1]=FParticleTimeScale({0.5,3.7});
	//SpriteEmitter1->SizeScale[2]=FParticleTimeScale({0.9,8.7});
	SpriteEmitter1->StartSizeRange = FRangeVector({ {50, 50}, {50, 50}, {50, 50} });
	SpriteEmitter1->DrawStyle = EParticleDrawStyle::PTDS_AlphaBlend;
	SpriteEmitter1->Texture = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_FX/Particles/fx_drt_cloud01_Mat.fx_drt_cloud01_Mat'"), NULL, LOAD_None, NULL);
	SpriteEmitter1->SecondsBeforeInactive = 0;
	SpriteEmitter1->LifetimeRange = FRange({ 3.5, 4.5 });
	MaxSpritePPS = 8;
	MaxMeshPPS = 70;
	DustVelThresh = 5;
	Emitters = { SpriteEmitter1,SpriteEmitter0 };
	//CullDistance = 5000;
	//bNoDelete = false;
	//RemoteRole = ROLE_None;
	//bHardAttach = true;
}

FEffectMatProps ADustCloudEffect::GetEffectProps(UMaterialInstance* M)
{
	FEffectMatProps EMP;
	/*
	switch (M.GetMaterialType())
	{
	case 16:
	case 3:
		EMP.DirtColor = Class'Canvas'.MakeColor(244, 226, 170);
		EMP.DirtAmount = 0.3;
		break;
	case 14:
	case 12:
	case 15:
		EMP.DirtColor = Class'Canvas'.MakeColor(204, 153, 102);
		EMP.DirtAmount = 0.15;
		break;
	case 2:
		EMP.DirtColor = Class'Canvas'.MakeColor(200, 200, 200);
		EMP.DirtAmount = 0.2;
		break;
	default:
		EMP.bNoEffect = true;
	}
	*/
	return EMP;
}

void ADustCloudEffect::SetDirtColor(FColor DirtColor)
{
	/*
	FColor DirtColorZeroAlpha = FColor(0, 0, 0, 0);
	FColor DirtColorHalfAlpha = FColor(0, 0, 0, 0);
	if (((DirtColor.R == 0) && (DirtColor.G == 0)) && (DirtColor.B == 0))
	{
		return;
	}
	DirtColor.A = 255;
	DirtColorZeroAlpha = DirtColor;
	DirtColorZeroAlpha.A = 0;
	DirtColorHalfAlpha = DirtColor;
	DirtColorHalfAlpha.A = 128;
	Emitters[0].ColorScale[0].Color = DirtColorZeroAlpha;
	Emitters[0].ColorScale[1].Color = DirtColorHalfAlpha;
	Emitters[0].ColorScale[2].Color = DirtColorHalfAlpha;
	Emitters[0].ColorScale[3].Color = DirtColorZeroAlpha;
	*/
}

void ADustCloudEffect::UpdateDust(ASVehicleWheel* vw, FCoords WheelCoords, float VehicleVel)
{
	/*
	float SpritePPS = 0;
	float EmitterScale = 0;
	FVector Start = FVector(0, 0, 0);
	FVector End = FVector(0, 0, 0);
	FVector HitLoc = FVector(0, 0, 0);
	FVector HitNorm = FVector(0, 0, 0);
	local Material HitMat;
	local EffectMatProps EMP;
	if (vw.bWheelOnGround && (VehicleVel > DustVelThresh))
	{
		Start = WheelCoords.Origin;
		End = Start;
		(End.Z -= (vw.WheelRadius + float(20)));
		Trace(HitLoc, HitNorm, End, Start, false, , HitMat);
		if (HitMat != None)
		{
			EMP = GetEffectProps(HitMat);
			if (!EMP.bNoEffect)
			{
				SetDirtColor(EMP.DirtColor);
				SpritePPS = FMin(((EMP.DirtAmount * 0.013) * (VehicleVel - DustVelThresh)), float(MaxSpritePPS));
				EmitterScale = (0.05 * VehicleVel);
				Emitters[0].ParticlesPerSecond = SpritePPS;
				Emitters[0].InitialParticlesPerSecond = SpritePPS;
				Emitters[0].AllParticlesDead = false;
				Emitters[0].StartSizeRange.X.Min = (30 + EmitterScale);
				Emitters[0].StartSizeRange.X.Max = (45 + EmitterScale);
				Emitters[0].StartSizeRange.Y.Min = (30 + EmitterScale);
				Emitters[0].StartSizeRange.Y.Max = (45 + EmitterScale);
				Emitters[0].StartSizeRange.Z.Min = (30 + EmitterScale);
				Emitters[0].StartSizeRange.Z.Max = (45 + EmitterScale);
				return;
			}
		}
	}
	Emitters[0].ParticlesPerSecond = 0;
	Emitters[0].InitialParticlesPerSecond = 0;
	Emitters[1].ParticlesPerSecond = 0;
	Emitters[1].InitialParticlesPerSecond = 0;
	*/
}

void ADustCloudEffect::disableEffect()
{
	Emitters[0]->ParticlesPerSecond = 0;
	Emitters[0]->InitialParticlesPerSecond = 0;
	Emitters[1]->ParticlesPerSecond = 0;
	Emitters[1]->InitialParticlesPerSecond = 0;
}