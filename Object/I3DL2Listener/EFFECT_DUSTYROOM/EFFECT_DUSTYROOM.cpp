// All the original content belonged to the US Army


#include "AA29/Object/I3DL2Listener/EFFECT_DUSTYROOM/EFFECT_DUSTYROOM.h"

UEFFECT_DUSTYROOM::UEFFECT_DUSTYROOM()
{
	EnvironmentSize = 1.8;
		EnvironmentDiffusion = 0.56;
		Room = -1100;
		RoomHF = -200;
		RoomLF = -300;
		DecayTime = 1.79;
		DecayHFRatio = 0.38;
		DecayLFRatio = 0.21;
		Reflections = -600;
		ReflectionsDelay = 0.002;
		ReverbDelay = 0.006;
		EchoTime = 0.202;
		EchoDepth = 0.05;
		AirAbsorptionHF = -3;
		HFReference = 13046;
		LFReference = 163.300003;
}