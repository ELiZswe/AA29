// All the original content belonged to the US Army


#include "AA29/Object/I3DL2Listener/I3DL2Listener.h"

UI3DL2Listener::UI3DL2Listener()
{
	EnvironmentSize = 7.5;
	EnvironmentDiffusion = 1;
	Room = -1000;
	RoomHF = -100;
	DecayTime = 1.49;
	DecayHFRatio = 0.83;
	DecayLFRatio = 1;
	Reflections = -2602;
	ReflectionsDelay = 0.007;
	Reverb = 200;
	ReverbDelay = 0.011;
	EchoTime = 0.25;
	ModulationTime = 0.25;
	AirAbsorptionHF = -5;
	HFReference = 5000;
	LFReference = 250;
	bDecayTimeScale = true;
	bReflectionsScale = true;
	bReflectionsDelayScale = true;
	bReverbScale = true;
	bReverbDelayScale = true;
	bEchoTimeScale = true;
	bDecayHFLimit = true;
}