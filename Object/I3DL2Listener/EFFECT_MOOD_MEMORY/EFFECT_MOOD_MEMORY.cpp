// All the original content belonged to the US Army


#include "AA29/Object/I3DL2Listener/EFFECT_MOOD_MEMORY/EFFECT_MOOD_MEMORY.h"

UEFFECT_MOOD_MEMORY::UEFFECT_MOOD_MEMORY()
{
	EnvironmentSize = 8;
	EnvironmentDiffusion = 0.85;
	RoomHF = -400;
	RoomLF = -900;
	DecayTime = 4.06;
	DecayHFRatio = 0.82;
	DecayLFRatio = 0.56;
	Reflections = -2800;
	ReflectionsDelay = 0;
	Reverb = -500;
	ReverbDelay = 0;
	ModulationTime = 0.474;
	ModulationDepth = 0.45;
	AirAbsorptionHF = -2;
}