// All the original content belonged to the US Army

#include "AA29/Object/ParticleEmitter/BeamEmitter/BeamEmitter.h"

UBeamEmitter::UBeamEmitter()
{
	BeamTextureUScale = 1;
	BeamTextureVScale = 1;
	LowFrequencyPoints = 3;
	HighFrequencyPoints = 10;
	BranchHFPointsRange = FRange({ 0, 1000 });
	BranchEmitter = -1;
}
