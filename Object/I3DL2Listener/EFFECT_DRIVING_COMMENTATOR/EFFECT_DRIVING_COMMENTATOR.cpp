// All the original content belonged to the US Army


#include "AA29/Object/I3DL2Listener/EFFECT_DRIVING_COMMENTATOR/EFFECT_DRIVING_COMMENTATOR.h"

UEFFECT_DRIVING_COMMENTATOR::UEFFECT_DRIVING_COMMENTATOR()
{
	EnvironmentSize = 3;
		EnvironmentDiffusion = 0;
		Room = -900;
		RoomHF = -500;
		RoomLF = -600;
		DecayTime = 2.42;
		DecayHFRatio = 0.88;
		DecayLFRatio = 0.68;
		Reflections = -1400;
		ReflectionsDelay = 0.093;
		Reverb = -1200;
		ReverbDelay = 0.017;
		EchoDepth = 1;
		AirAbsorptionHF = 0;
}