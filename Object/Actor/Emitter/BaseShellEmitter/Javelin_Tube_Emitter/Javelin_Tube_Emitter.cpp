// All the original content belonged to the US Army


#include "Javelin_Tube_Emitter.h"

AJavelin_Tube_Emitter::AJavelin_Tube_Emitter()
{
	sWood = {
		LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AAO_Armory/Javelin/S_Armo_Javelin_Tube_Drop.S_Armo_Javelin_Tube_Drop"), NULL, LOAD_None, NULL),
		LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AAO_Armory/Javelin/S_Armo_Javelin_Tube_Drop.S_Armo_Javelin_Tube_Drop"), NULL, LOAD_None, NULL),
		LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AAO_Armory/Javelin/S_Armo_Javelin_Tube_Drop.S_Armo_Javelin_Tube_Drop"), NULL, LOAD_None, NULL)
	};
	sConcrete = {
		LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AAO_Armory/Javelin/S_Armo_Javelin_Tube_Drop.S_Armo_Javelin_Tube_Drop"), NULL, LOAD_None, NULL),
		LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AAO_Armory/Javelin/S_Armo_Javelin_Tube_Drop.S_Armo_Javelin_Tube_Drop"), NULL, LOAD_None, NULL),
		LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AAO_Armory/Javelin/S_Armo_Javelin_Tube_Drop.S_Armo_Javelin_Tube_Drop"), NULL, LOAD_None, NULL)
	};
	sMetal = {
		LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AAO_Armory/Javelin/S_Armo_Javelin_Tube_Drop.S_Armo_Javelin_Tube_Drop"), NULL, LOAD_None, NULL),
		LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AAO_Armory/Javelin/S_Armo_Javelin_Tube_Drop.S_Armo_Javelin_Tube_Drop"), NULL, LOAD_None, NULL),
		LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AAO_Armory/Javelin/S_Armo_Javelin_Tube_Drop.S_Armo_Javelin_Tube_Drop"), NULL, LOAD_None, NULL)
	};
	sWater = {
		LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AAO_Armory/Javelin/S_Armo_Javelin_Watersplash.S_Armo_Javelin_Watersplash"), NULL, LOAD_None, NULL),
		LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AAO_Armory/Javelin/S_Armo_Javelin_Watersplash.S_Armo_Javelin_Watersplash"), NULL, LOAD_None, NULL),
		LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AAO_Armory/Javelin/S_Armo_Javelin_Watersplash.S_Armo_Javelin_Watersplash"), NULL, LOAD_None, NULL)
	};
	sDirt = {
		LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AAO_Armory/Javelin/S_Armo_Javelin_Tube_Drop.S_Armo_Javelin_Tube_Drop"), NULL, LOAD_None, NULL),
		LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AAO_Armory/Javelin/S_Armo_Javelin_Tube_Drop.S_Armo_Javelin_Tube_Drop"), NULL, LOAD_None, NULL),
		LoadObject<class USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AAO_Armory/Javelin/S_Armo_Javelin_Tube_Drop.S_Armo_Javelin_Tube_Drop"), NULL, LOAD_None, NULL)
	};

	ShellDrawScale = FVector(113, 113, 113);
	ShellStaticMesh  = LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AAO_Armory/Javelin/Tube3PLoaded.Tube3PLoaded"), NULL, LOAD_None, NULL),
	bUseAnimNotifyEject = true;
		//Emitters(0) = MeshEmitter'AGP_Armory.Javelin_Tube_Emitter.MeshEmitter0'
};