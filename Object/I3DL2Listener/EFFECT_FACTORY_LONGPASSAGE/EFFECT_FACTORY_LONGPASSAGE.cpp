// All the original content belonged to the US Army


#include "AA29/Object/I3DL2Listener/EFFECT_FACTORY_LONGPASSAGE/EFFECT_FACTORY_LONGPASSAGE.h"

UEFFECT_FACTORY_LONGPASSAGE::UEFFECT_FACTORY_LONGPASSAGE()
{
	EnvironmentSize = 1.8;
		EnvironmentDiffusion = 0.64;
		Room = -1200;
		RoomHF = -200;
		RoomLF = -600;
		DecayTime = 4.06;
		DecayHFRatio = 0.65;
		DecayLFRatio = 1.31;
		Reflections = 0;
		ReflectionsDelay = 0.02;
		Reverb = -900;
		ReverbDelay = 0.037;
		EchoTime = 0.135;
		EchoDepth = 0.23;
		AirAbsorptionHF = 0;
		HFReference = 3762.600098;
		LFReference = 362.5;
}