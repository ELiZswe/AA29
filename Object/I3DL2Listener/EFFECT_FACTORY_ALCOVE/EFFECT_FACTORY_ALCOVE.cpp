// All the original content belonged to the US Army


#include "AA29/Object/I3DL2Listener/EFFECT_FACTORY_ALCOVE/EFFECT_FACTORY_ALCOVE.h"

UEFFECT_FACTORY_ALCOVE::UEFFECT_FACTORY_ALCOVE()
{
	EnvironmentSize = 1.8;
		EnvironmentDiffusion = 0.59;
		Room = -1200;
		RoomHF = -200;
		RoomLF = -600;
		DecayTime = 3.14;
		DecayHFRatio = 0.65;
		DecayLFRatio = 1.31;
		Reflections = 300;
		ReflectionsDelay = 0.01;
		Reverb = -1200;
		ReverbDelay = 0.038;
		EchoTime = 0.114;
		EchoDepth = 0.1;
		AirAbsorptionHF = 0;
		HFReference = 3762.600098;
		LFReference = 362.5;
}