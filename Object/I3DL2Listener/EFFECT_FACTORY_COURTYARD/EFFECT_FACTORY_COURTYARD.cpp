// All the original content belonged to the US Army


#include "AA29/Object/I3DL2Listener/EFFECT_FACTORY_COURTYARD/EFFECT_FACTORY_COURTYARD.h"

UEFFECT_FACTORY_COURTYARD::UEFFECT_FACTORY_COURTYARD()
{
	EnvironmentSize = 1.7;
		EnvironmentDiffusion = 0.57;
		RoomHF = -1000;
		RoomLF = -400;
		DecayTime = 2.32;
		DecayHFRatio = 0.29;
		DecayLFRatio = 0.56;
		Reflections = -2400;
		ReflectionsDelay = 0.09;
		Reverb = -2000;
		ReverbDelay = 0.039;
		EchoDepth = 0.29;
		AirAbsorptionHF = 0;
		HFReference = 3762.600098;
		LFReference = 362.5;
}