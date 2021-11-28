// All the original content belonged to the US Army


#include "HelicopterDustCloudEffect.h"

AHelicopterDustCloudEffect::AHelicopterDustCloudEffect()
{
	MaxSpritePPS = 8;
	MaxMeshPPS = 70;
	DustVelThresh = 5;
//	Emitters(0) = SpriteEmitter'AGP_Vehicles.DustCloudEffect.SpriteEmitter1'
//	Emitters(1) = SpriteEmitter'AGP_Vehicles.DustCloudEffect.SpriteEmitter0';
	AutoDestroy = true;
	//CullDistance = 5000;
	//bNoDelete = false;
	//RemoteRole = ROLE_None;
	//bHardAttach = true;
};

FEffectMatProps AHelicopterDustCloudEffect::GetEffectProps(UMaterialInstance* M)
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

void AHelicopterDustCloudEffect::Timer()
{
	/*
	if (Emitters[0].ColorScale[0].Color.A > 0)
	{
		(Emitters[0].ColorScale[0].Color.A -= byte(8));
	}
	else
	{
		Destroy();
	}
	*/
}

void AHelicopterDustCloudEffect::Destroyed()
{
	//Super::Destroyed();
}

void AHelicopterDustCloudEffect::SetDirtColor(FColor DirtColor)
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

void AHelicopterDustCloudEffect::HideDirt()
{
	/*
	if (!bAutoDestroyPrepped)
	{
		Kill();
		bAutoDestroyPrepped = true;
	}
	*/
}

void AHelicopterDustCloudEffect::ShowDirt()
{
}

void AHelicopterDustCloudEffect::UpdateDust(FVector vStartLocation)
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
	Start = vStartLocation;
	End = Start;
	(End.Z -= float(500));
	Trace(HitLoc, HitNorm, End, Start, false, , HitMat);
	EMP.DirtColor = Class'Canvas'.MakeColor(244, 226, 170);
	EMP.DirtAmount = 0.3;
	if (!EMP.bNoEffect)
	{
		SetDirtColor(EMP.DirtColor);
		SpritePPS = FMin(((EMP.DirtAmount * 0.013) * (float(500) - VSize((HitLoc - Start)))), float(MaxSpritePPS));
		EmitterScale = (0.05 * 4);
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
	Emitters[0].ParticlesPerSecond = 0;
	Emitters[0].InitialParticlesPerSecond = 0;
	Emitters[1].ParticlesPerSecond = 0;
	Emitters[1].InitialParticlesPerSecond = 0;
	*/
}

void AHelicopterDustCloudEffect::disableEffect()
{
	/*
	Emitters[0].ParticlesPerSecond = 0;
	Emitters[0].InitialParticlesPerSecond = 0;
	Emitters[1].ParticlesPerSecond = 0;
	Emitters[1].InitialParticlesPerSecond = 0;
	*/
}
