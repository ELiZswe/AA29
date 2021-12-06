// All the original content belonged to the US Army


#include "BassLaserBeam.h"

ABassLaserBeam::ABassLaserBeam()
{
	mParticleType = ExParticleTypes::PT_Beam;
	mMaxParticles = 4;
	mRegenDist = 150;
	mSizeRange = { 3 };
	mColorRange = { FColor(240, 240, 240, 255), FColor(240, 240, 240, 255) };
	mAttenuate = false;
	//Skins(0) = FinalBlend'T_AA2_FX.Particles.fx_flash_tracer_new1f'
	//Style = 7
}


void ABassLaserBeam::SetBeamLocation()
{
	/*
	if (IlltemperedSeaBass != None && IlltemperedSeaBass.LaserAttachment != None)
	{
		SetLocation(IlltemperedSeaBass.LaserAttachment.GetTipLocation());
	}
	*/
}
FVector ABassLaserBeam::SetBeamRotation()
{
	/*
	if (IlltemperedSeaBass != None && IlltemperedSeaBass.LaserAttachment != None)
	{
		SetRotation(IlltemperedSeaBass.LaserAttachment.Rotation);
		Return Normal(Vector(IlltemperedSeaBass.LaserAttachment.Rotation));
	}
	else
	{
		return vect(0 0 0);
	}
	*/

	return FVector(0, 0, 0);     //FAKE   /ELiZ
}

void ABassLaserBeam::Tick(float dt)
{
	FVector BeamDir = FVector(0, 0, 0);
	FVector HitLocation = FVector(0, 0, 0);
	FVector HitNormal = FVector(0, 0, 0);
	if (IlltemperedSeaBass == nullptr)
	{
		Destroy();
		return;
	}
	SetBeamLocation();
	/*
	BeamDir = SetBeamRotation();
	Trace(HitLocation, HitNormal, Location + BeamDir * 1000, Location, true);
	mSpawnVecA = HitLocation;
	*/
}