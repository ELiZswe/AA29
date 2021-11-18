// All the original content belonged to the US Army


#include "AA29/AGP_UseTrigger/GameRadio/GameRadio.h"

AGameRadio::AGameRadio()
{
	GameRadioHelp = {"A radio with changeable stations. Load up the ","RadioChannels array with your desired sounds.","","[RadioChannels] The sounds that represent radio channels.","[SwitchNoises] The sounds that represent changing stations.","[OffSound] The sound to make when radio turns off.","[StartIndex] The channel index to start out with.","[bStartOn] Whether the radio should play on level load.","[bRandomChannel] Whether changing stations picks random channels.","[bCanTurnOff] Whether user can turn off radio.","[bQuickChange] Whether channels can be changed while switch","noises are playing."};

	SwitchNoises = {
		LoadObject<USoundBase>(NULL, TEXT("Texture2D'/Game/AmericasArmy/Textures/AGP/S_AA2_UseTrigger.S_AA2_UseTrigger'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("Texture2D'/Game/AmericasArmy/Textures/AGP/S_AA2_UseTrigger.S_AA2_UseTrigger'"), NULL, LOAD_None, NULL),
		LoadObject<USoundBase>(NULL, TEXT("Texture2D'/Game/AmericasArmy/Textures/AGP/S_AA2_UseTrigger.S_AA2_UseTrigger'"), NULL, LOAD_None, NULL)
	};
	//SwitchNoises(0) = Sound'S_AA2_Foley.radiostatic.AM_RadioTune1'
	//SwitchNoises(1) = Sound'S_AA2_Foley.radiostatic.AM_RadioTune2'
	//SwitchNoises(2) = Sound'S_AA2_Foley.radiostatic.AM_RadioTune3'
	bStartOn = true;
	//DrawType = 8;
	//StaticMesh = StaticMesh'M_AA2_Equipment.electronics.eqp_electronics_amradio';
	//bHidden = false;
	//DrawScale = 2;
}