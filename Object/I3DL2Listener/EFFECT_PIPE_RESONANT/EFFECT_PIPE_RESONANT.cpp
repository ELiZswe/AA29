// All the original content belonged to the US Army


#include "AA29/Object/I3DL2Listener/EFFECT_PIPE_RESONANT/EFFECT_PIPE_RESONANT.h"

UEFFECT_PIPE_RESONANT::UEFFECT_PIPE_RESONANT()
{
	EnvironmentSize = 1.3;
		EnvironmentDiffusion = 0.91;
		Room = -1200;
		RoomHF = -700;
		RoomLF = -1100;
		DecayTime = 6.81;
		DecayHFRatio = 0.18;
		DecayLFRatio = 0.1;
		Reflections = -300;
		ReflectionsDelay = 0.01;
		Reverb = -700;
		ReverbDelay = 0.022;
		HFReference = 2854.399902;
		LFReference = 20;
}