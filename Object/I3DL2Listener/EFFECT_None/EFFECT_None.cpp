// All the original content belonged to the US Army


#include "AA29/Object/I3DL2Listener/EFFECT_None/EFFECT_None.h"

UEFFECT_None::UEFFECT_None()
{
	EnvironmentSize = 1;
		EnvironmentDiffusion = 0;
		Room = -10000;
		RoomHF = -10000;
		DecayTime = 0.1;
		Reflections = -10000;
		ReflectionsDelay = 0;
		Reverb = -10000;
		ReverbDelay = 0;
		bDecayTimeScale = false;
		bReflectionsScale = false;
		bReflectionsDelayScale = false;
		bReverbScale = false;
		bReverbDelayScale = false;
		bDecayHFLimit = false;
}