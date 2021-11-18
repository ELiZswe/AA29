// All the original content belonged to the US Army


#include "AA29/Object/I3DL2Listener/EFFECT_FACTORY_SHORTPASSAGE/EFFECT_FACTORY_SHORTPASSAGE.h"

UEFFECT_FACTORY_SHORTPASSAGE::UEFFECT_FACTORY_SHORTPASSAGE()
{
	EnvironmentSize = 1.8;
		EnvironmentDiffusion = 0.64;
		Room = -1200;
		RoomHF = -200;
		RoomLF = -600;
		DecayTime = 2.53;
		DecayHFRatio = 0.65;
		DecayLFRatio = 1.31;
		Reflections = 0;
		ReflectionsDelay = 0.01;
		Reverb = -600;
		ReverbDelay = 0.038;
		EchoTime = 0.135;
		EchoDepth = 0.23;
		AirAbsorptionHF = 0;
		HFReference = 3762.600098;
		LFReference = 362.5;
}