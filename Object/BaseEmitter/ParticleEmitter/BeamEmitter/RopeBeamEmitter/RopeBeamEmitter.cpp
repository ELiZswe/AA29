// All the original content belonged to the US Army

#include "AA29/Object/BaseEmitter/ParticleEmitter/BeamEmitter/RopeBeamEmitter/RopeBeamEmitter.h"

URopeBeamEmitter::URopeBeamEmitter()
{
	vInitialDirection = FVector(0, 1, -1);
	fMinVelThreshold = 2.5;
	fSlideDeadZone = 0.25;
	fSegmentLength = 25;
	fBounciness = 1;
	iFlexOffset = 1;
	fFlexThreshold = 0.5;
	iRelaxFactor = 2;
	fTwistFactor = 0.01;
	cAnchorClass = nullptr;
	iVerletIntegrationCount = 3;
	DetermineEndPointBy = EBeamEndPointType::PTEP_RopeSegment;
	LowFrequencyPoints = 2;
	HighFrequencyPoints = 2;
	RespawnDeadParticles = false;
	AutomaticInitialSpawning = false;
	//StartSizeRange = X = (Min = 10, Max = 10) | Y = (Min = 10, Max = 10) | Z = (Min = 10, Max = 10);
	InitialParticlesPerSecond = 1000;
	DrawStyle = EParticleDrawStyle::PTDS_Regular;
	LifetimeRange = FRange({ 0, 0 });
}

//native Function LinkAnchors(class<Object>  baseClass);
void URopeBeamEmitter::LinkAnchors(UObject* baseClass)
{

}

//native Function DetachPawn(AGP_Pawn Pawn);
void URopeBeamEmitter::DetachPawn(AAGP_Pawn* Pawn)
{

}