// All the original content belonged to the US Army

#include "AA29/Object/I3DL2Listener/EFFECT_FACTORY_LARGEROOM/EFFECT_FACTORY_LARGEROOM.h"

UEFFECT_FACTORY_LARGEROOM::UEFFECT_FACTORY_LARGEROOM()
{
	EnvironmentSize = 1.9;
		EnvironmentDiffusion = 0.75;
		Room = -1200;
		RoomHF = -300;
		RoomLF = -400;
		DecayTime = 4.24;
		DecayHFRatio = 0.51;
		DecayLFRatio = 1.31;
		Reflections = -1500;
		ReflectionsDelay = 0.039;
		Reverb = -600;
		ReverbDelay = 0.023;
		EchoTime = 0.231;
		EchoDepth = 0.07;
		AirAbsorptionHF = 0;
		HFReference = 3762.600098;
		LFReference = 362.5;
}
