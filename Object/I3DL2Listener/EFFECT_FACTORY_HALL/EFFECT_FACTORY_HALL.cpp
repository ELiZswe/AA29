// All the original content belonged to the US Army


#include "AA29/Object/I3DL2Listener/EFFECT_FACTORY_HALL/EFFECT_FACTORY_HALL.h"

UEFFECT_FACTORY_HALL::UEFFECT_FACTORY_HALL()
{
	EnvironmentSize = 1.9;
		EnvironmentDiffusion = 0.75;
		RoomHF = -300;
		RoomLF = -400;
		DecayTime = 7.43;
		DecayHFRatio = 0.51;
		DecayLFRatio = 1.31;
		Reflections = -2400;
		ReflectionsDelay = 0.073;
		Reverb = -500;
		ReverbDelay = 0.027;
		EchoDepth = 0.07;
		AirAbsorptionHF = 0;
		HFReference = 3762.600098;
		LFReference = 362.5;
}