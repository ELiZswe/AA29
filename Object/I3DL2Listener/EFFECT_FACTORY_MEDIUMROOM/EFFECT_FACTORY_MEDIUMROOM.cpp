// All the original content belonged to the US Army


#include "AA29/Object/I3DL2Listener/EFFECT_FACTORY_MEDIUMROOM/EFFECT_FACTORY_MEDIUMROOM.h"

UEFFECT_FACTORY_MEDIUMROOM::UEFFECT_FACTORY_MEDIUMROOM()
{
	EnvironmentSize = 1.9;
		EnvironmentDiffusion = 0.82;
		Room = -1200;
		RoomHF = -200;
		RoomLF = -600;
		DecayTime = 2.76;
		DecayHFRatio = 0.65;
		DecayLFRatio = 1.31;
		Reflections = -1100;
		ReflectionsDelay = 0.022;
		Reverb = -400;
		ReverbDelay = 0.023;
		EchoTime = 0.174;
		EchoDepth = 0.07;
		AirAbsorptionHF = 0;
		HFReference = 3762.600098;
		LFReference = 362.5;
}