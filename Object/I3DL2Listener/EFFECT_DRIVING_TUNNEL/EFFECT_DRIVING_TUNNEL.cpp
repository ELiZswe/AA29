// All the original content belonged to the US Army


#include "AA29/Object/I3DL2Listener/EFFECT_DRIVING_TUNNEL/EFFECT_DRIVING_TUNNEL.h"

UEFFECT_DRIVING_TUNNEL::UEFFECT_DRIVING_TUNNEL()
{
	EnvironmentSize = 3.1;
		EnvironmentDiffusion = 0.81;
		Room = -900;
		RoomHF = -800;
		RoomLF = -100;
		DecayTime = 3.42;
		DecayHFRatio = 0.94;
		DecayLFRatio = 1.31;
		Reflections = -300;
		ReflectionsDelay = 0.051;
		Reverb = -500;
		ReverbDelay = 0.047;
		EchoTime = 0.214;
		EchoDepth = 0.05;
		AirAbsorptionHF = 0;
		LFReference = 155.300003;
}