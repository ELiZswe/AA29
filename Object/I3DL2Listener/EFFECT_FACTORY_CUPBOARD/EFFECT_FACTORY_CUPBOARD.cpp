// All the original content belonged to the US Army


#include "AA29/Object/I3DL2Listener/EFFECT_FACTORY_CUPBOARD/EFFECT_FACTORY_CUPBOARD.h"

UEFFECT_FACTORY_CUPBOARD::UEFFECT_FACTORY_CUPBOARD()
{
	EnvironmentSize = 1.7;
		EnvironmentDiffusion = 0.63;
		Room = -1200;
		RoomHF = -200;
		RoomLF = -600;
		DecayTime = 0.49;
		DecayHFRatio = 0.65;
		DecayLFRatio = 1.31;
		Reflections = 200;
		ReflectionsDelay = 0.01;
		ReverbDelay = 0.032;
		EchoTime = 0.107;
		EchoDepth = 0.07;
		AirAbsorptionHF = 0;
		HFReference = 3762.600098;
		LFReference = 362.5;
}