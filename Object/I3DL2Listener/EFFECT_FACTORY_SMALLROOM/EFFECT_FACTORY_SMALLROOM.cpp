// All the original content belonged to the US Army


#include "AA29/Object/I3DL2Listener/EFFECT_FACTORY_SMALLROOM/EFFECT_FACTORY_SMALLROOM.h"

UEFFECT_FACTORY_SMALLROOM::UEFFECT_FACTORY_SMALLROOM()
{
	EnvironmentSize = 1.8;
		EnvironmentDiffusion = 0.82;
		Room = -1200;
		RoomHF = -200;
		RoomLF = -600;
		DecayTime = 1.72;
		DecayHFRatio = 0.65;
		DecayLFRatio = 1.31;
		Reflections = -300;
		ReflectionsDelay = 0.01;
		Reverb = -200;
		ReverbDelay = 0.024;
		EchoTime = 0.119;
		EchoDepth = 0.07;
		AirAbsorptionHF = 0;
		HFReference = 3762.600098;
		LFReference = 362.5;
}