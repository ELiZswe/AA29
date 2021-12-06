// All the original content belonged to the US Army

#include "AA29/Object/Actor/EventLab/EL_AVWID/EL_AVWID.h"

AEL_AVWID::AEL_AVWID()
{
	SodaGuySound = LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_CampMackall/SodaGuy/vendkicker1_Que.vendkicker1_Que'"), NULL, LOAD_None, NULL);
	/*
	LSAnims = {
		FLSAnim({ "Guy1", LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_CampMackall/Chopper/Guy1_Que.Guy1_Que'"), NULL, LOAD_None, NULL), {"None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "Guy1", LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_CampMackall/Chopper/Guy1_Que.Guy1_Que'"), NULL, LOAD_None, NULL), {"None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "Guy1", LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_CampMackall/Chopper/Guy1_Que.Guy1_Que'"), NULL, LOAD_None, NULL), {"None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "Guy1", LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_CampMackall/Chopper/Guy1_Que.Guy1_Que'"), NULL, LOAD_None, NULL), {"None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "Guy1", LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_CampMackall/Chopper/Guy1_Que.Guy1_Que'"), NULL, LOAD_None, NULL), {"None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "Guy1", LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_CampMackall/Chopper/Guy1_Que.Guy1_Que'"), NULL, LOAD_None, NULL), {"None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "Guy1", LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_CampMackall/Chopper/Guy1_Que.Guy1_Que'"), NULL, LOAD_None, NULL), {"None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "Guy1", LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_CampMackall/Chopper/Guy1_Que.Guy1_Que'"), NULL, LOAD_None, NULL), {"None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "Guy1", LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_CampMackall/Chopper/Guy1_Que.Guy1_Que'"), NULL, LOAD_None, NULL), {"None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "Guy1", LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_CampMackall/Chopper/Guy1_Que.Guy1_Que'"), NULL, LOAD_None, NULL), {"None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "Guy1", LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_CampMackall/Chopper/Guy1_Que.Guy1_Que'"), NULL, LOAD_None, NULL), {"None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "Guy1", LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_CampMackall/Chopper/Guy1_Que.Guy1_Que'"), NULL, LOAD_None, NULL), {"None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "Guy1", LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_CampMackall/Chopper/Guy1_Que.Guy1_Que'"), NULL, LOAD_None, NULL), {"None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "Guy1", LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_CampMackall/Chopper/Guy1_Que.Guy1_Que'"), NULL, LOAD_None, NULL), {"None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "Guy1", LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_CampMackall/Chopper/Guy1_Que.Guy1_Que'"), NULL, LOAD_None, NULL), {"None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "Guy1", LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_CampMackall/Chopper/Guy1_Que.Guy1_Que'"), NULL, LOAD_None, NULL), {"None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "Guy1", LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_CampMackall/Chopper/Guy1_Que.Guy1_Que'"), NULL, LOAD_None, NULL), {"None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "Guy1", LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_CampMackall/Chopper/Guy1_Que.Guy1_Que'"), NULL, LOAD_None, NULL), {"None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "Guy1", LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_CampMackall/Chopper/Guy1_Que.Guy1_Que'"), NULL, LOAD_None, NULL), {"None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "Guy1", LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_CampMackall/Chopper/Guy1_Que.Guy1_Que'"), NULL, LOAD_None, NULL), {"None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "Guy1", LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_CampMackall/Chopper/Guy1_Que.Guy1_Que'"), NULL, LOAD_None, NULL), {"None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "Guy1", LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_CampMackall/Chopper/Guy1_Que.Guy1_Que'"), NULL, LOAD_None, NULL), {"None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "Guy1", LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_CampMackall/Chopper/Guy1_Que.Guy1_Que'"), NULL, LOAD_None, NULL), {"None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "Guy1", LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_CampMackall/Chopper/Guy1_Que.Guy1_Que'"), NULL, LOAD_None, NULL), {"None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "Guy1", LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_CampMackall/Chopper/Guy1_Que.Guy1_Que'"), NULL, LOAD_None, NULL), {"None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "Guy1", LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_CampMackall/Chopper/Guy1_Que.Guy1_Que'"), NULL, LOAD_None, NULL), {"None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "Guy1", LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_CampMackall/Chopper/Guy1_Que.Guy1_Que'"), NULL, LOAD_None, NULL), {"None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "Guy1", LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_CampMackall/Chopper/Guy1_Que.Guy1_Que'"), NULL, LOAD_None, NULL), {"None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "Guy1", LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_CampMackall/Chopper/Guy1_Que.Guy1_Que'"), NULL, LOAD_None, NULL), {"None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "Guy1", LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_CampMackall/Chopper/Guy1_Que.Guy1_Que'"), NULL, LOAD_None, NULL), {"None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "Guy1", LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_CampMackall/Chopper/Guy1_Que.Guy1_Que'"), NULL, LOAD_None, NULL), {"None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "Guy1", LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_CampMackall/Chopper/Guy1_Que.Guy1_Que'"), NULL, LOAD_None, NULL), {"None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "Guy1", LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_CampMackall/Chopper/Guy1_Que.Guy1_Que'"), NULL, LOAD_None, NULL), {"None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "Guy1", LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_CampMackall/Chopper/Guy1_Que.Guy1_Que'"), NULL, LOAD_None, NULL), {"None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "Guy1", LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_CampMackall/Chopper/Guy1_Que.Guy1_Que'"), NULL, LOAD_None, NULL), {"None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "Guy1", LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_CampMackall/Chopper/Guy1_Que.Guy1_Que'"), NULL, LOAD_None, NULL), {"None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "Guy1", LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_CampMackall/Chopper/Guy1_Que.Guy1_Que'"), NULL, LOAD_None, NULL), {"None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "Guy1", LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_CampMackall/Chopper/Guy1_Que.Guy1_Que'"), NULL, LOAD_None, NULL), {"None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "Guy1", LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_CampMackall/Chopper/Guy1_Que.Guy1_Que'"), NULL, LOAD_None, NULL), {"None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "Guy1", LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_CampMackall/Chopper/Guy1_Que.Guy1_Que'"), NULL, LOAD_None, NULL), {"None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "Guy1", LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_CampMackall/Chopper/Guy1_Que.Guy1_Que'"), NULL, LOAD_None, NULL), {"None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "Guy1", LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_CampMackall/Chopper/Guy1_Que.Guy1_Que'"), NULL, LOAD_None, NULL), {"None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "Guy1", LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_CampMackall/Chopper/Guy1_Que.Guy1_Que'"), NULL, LOAD_None, NULL), {"None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "Guy1", LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_CampMackall/Chopper/Guy1_Que.Guy1_Que'"), NULL, LOAD_None, NULL), {"None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "Guy1", LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_CampMackall/Chopper/Guy1_Que.Guy1_Que'"), NULL, LOAD_None, NULL), {"None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "Guy1", LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_CampMackall/Chopper/Guy1_Que.Guy1_Que'"), NULL, LOAD_None, NULL), {"None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "Guy1", LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_CampMackall/Chopper/Guy1_Que.Guy1_Que'"), NULL, LOAD_None, NULL), {"None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "Guy1", LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_CampMackall/Chopper/Guy1_Que.Guy1_Que'"), NULL, LOAD_None, NULL), {"None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "Guy1", LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_CampMackall/Chopper/Guy1_Que.Guy1_Que'"), NULL, LOAD_None, NULL), {"None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "Guy1", LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_CampMackall/Chopper/Guy1_Que.Guy1_Que'"), NULL, LOAD_None, NULL), {"None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "Guy1", LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_CampMackall/Chopper/Guy1_Que.Guy1_Que'"), NULL, LOAD_None, NULL), {"None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "Guy1", LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_CampMackall/Chopper/Guy1_Que.Guy1_Que'"), NULL, LOAD_None, NULL), {"None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "Guy1", LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_CampMackall/Chopper/Guy1_Que.Guy1_Que'"), NULL, LOAD_None, NULL), {"None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "Guy1", LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_CampMackall/Chopper/Guy1_Que.Guy1_Que'"), NULL, LOAD_None, NULL), {"None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "Guy1", LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_CampMackall/Chopper/Guy1_Que.Guy1_Que'"), NULL, LOAD_None, NULL), {"None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "Guy1", LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_CampMackall/Chopper/Guy1_Que.Guy1_Que'"), NULL, LOAD_None, NULL), {"None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "Guy1", LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_CampMackall/Chopper/Guy1_Que.Guy1_Que'"), NULL, LOAD_None, NULL), {"None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "Guy1", LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_CampMackall/Chopper/Guy1_Que.Guy1_Que'"), NULL, LOAD_None, NULL), {"None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "Guy1", LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_CampMackall/Chopper/Guy1_Que.Guy1_Que'"), NULL, LOAD_None, NULL), {"None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "Guy1", LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_CampMackall/Chopper/Guy1_Que.Guy1_Que'"), NULL, LOAD_None, NULL), {"None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "Guy1", LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_CampMackall/Chopper/Guy1_Que.Guy1_Que'"), NULL, LOAD_None, NULL), {"None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "Guy1", LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_CampMackall/Chopper/Guy1_Que.Guy1_Que'"), NULL, LOAD_None, NULL), {"None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "Guy1", LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_CampMackall/Chopper/Guy1_Que.Guy1_Que'"), NULL, LOAD_None, NULL), {"None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "Guy1", LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_CampMackall/Chopper/Guy1_Que.Guy1_Que'"), NULL, LOAD_None, NULL), {"None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "Guy1", LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_CampMackall/Chopper/Guy1_Que.Guy1_Que'"), NULL, LOAD_None, NULL), {"None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "Guy1", LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_CampMackall/Chopper/Guy1_Que.Guy1_Que'"), NULL, LOAD_None, NULL), {"None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "Guy1", LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_CampMackall/Chopper/Guy1_Que.Guy1_Que'"), NULL, LOAD_None, NULL), {"None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "Guy1", LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_CampMackall/Chopper/Guy1_Que.Guy1_Que'"), NULL, LOAD_None, NULL), {"None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} }),
		FLSAnim({ "Guy1", LoadObject<USoundBase>(NULL, TEXT("SoundCue'/Game/AmericasArmy/Sounds/S_AAO_Lvl_CampMackall/Chopper/Guy1_Que.Guy1_Que'"), NULL, LOAD_None, NULL), {"None","None","None","None","None","None","None","None","None","None"},{0,0,0,0,0,0,0,0,0,0} })
	};
	*/
}

/*
State FindClass
{
	Function BeginState()
	{
		PlayTip("Locate the Class Room","T-3164 to take the test",15);
		StartTimer('FindClass_GlobalTimer',120,false);
		DoorTriggerOne.Open();
		DoorTriggerOne.SetLocked(false);
	}
	bool ClassVolumeOne_Enter(ATriggerVolume* Trigger, AActor* Instigator)
	{
		StopTimer('FindClass_GlobalTimer',0);
		UnCaptureEventGroup('ClassVolumeOne');
		DoorTriggerOne.Close();
		DoorTriggerOne.SetLocked(true);
		ChangeState('inClass');
		return true;
	}
	bool Timer_Timer(FName Name)
	{
		if (Name == 'FindClass_GlobalTimer')
		{
			GotoState(,'CantFindClass');
			return true;
		}
		return GlobalTimer(Name);
	}
	bool Timer_LSAnim(FName Name)
	{
		return false;
	}
Begin:
	JL'End'
;
	PlayerLock(true,false);
	FadeOutBlack(2);
	Sleep(2);
	Player.SetLocation(GoToClass.Location);
	Controller.SetRotation(RandLookRotation());
	PlayerLock(false,false);
	PlayTip("Enter the Class Room","T-3164 to take the test",10);
	StartTimer('FindClass_GlobalTimer',120,false);
	FadeInBlack(2);
}

State inClass
{
	Function BeginState()
	{
		CaptureController();
	}
	Function EndState()
	{
	}
	bool InstructorTriggerOne_UsedBy(AAGP_UseTrigger* Trigger, AActor* Instigator)
	{
		if (InstructorUseCount == 0)
		{
			PlayLSAnim('SFInstructor_Welcome2',InstructorOne,1,512);
			InstructorUseCount++;
			return true;
		}
		if (InstructorUseCount == 1)
		{
			PlayLSAnim('SFInstructor_Sit',InstructorOne,1,512);
			InstructorUseCount++;
			return true;
		}
		if (InstructorUseCount == 2)
		{
			PlayLSAnim('SFInstructor_Sit2',InstructorOne,1,512);
			InstructorUseCount++;
			return true;
		}
		return true;
	}
	bool SeatTriggerOne_UsedBy(AAGP_UseTrigger* Trigger, AActor* Instigator)
	{
		bInClass_DidSitDown = true;
		UnCaptureEvent(SeatTriggerOne);
		StartTimer('tmrSatDown',8,false);
		GotoState(,'End');
		PlayTip("To get out of the chair, press the <jump> key","",4);
		return true;
	}
	bool Timer_Timer(FName Name)
	{
		if ((Name == 'tmrBeginClass') || (Name == 'tmrSatDown'))
		{
			StopTimer('tmrBeginClass',0);
			StopTimer('tmrSatDown',0);
			ChangeState('LetsGetStarted');
			return true;
		}
		return GlobalTimer(Name);
	}
Begin:
	StartTimer('tmrBeginClass',60,false);
	PlayLSAnim('SFInstructor_Welcome1',InstructorOne,1,512);
	Sleep(2);
	PlayTip("Talk to people in your class by pressing","the <action> key while facing somebody",5);
	Sleep(15);
	PlayTip("When you are ready to begin the lecture,","take a seat and the class will start.",4);
	Sleep(6);
	if (!bInClass_DidSitDown)
	{
		PlayTip("To sit down, face your chair and press the <action> key","",5);
	}
}

State LetsGetStarted
{
	Function BeginState()
	{
	}
Begin:
	PlayLSAnim('SFInstructor_GetStarted',InstructorOne,1,512);
	Sleep(2);
	if (!bInClass_DidSitDown)
	{
		PlayTip("To sit down, face your chair and press the <action> key","",5);
		Sleep(5);
	}
	ChangeState('TimeToSit');
}

State TimeToSit
{
	Function BeginState()
	{
		ReCaptureEvent(SeatTriggerOne);
		StartTimer('tmrSitDown',5,false);
	}
	bool SeatTriggerOne_UsedBy(AAGP_UseTrigger* Trigger, AActor* Instigator)
	{
		ChangeState('BeginLecture');
		return true;
	}
	bool Timer_Timer(FName Name)
	{
		if (Name == 'tmrSitDown')
		{
			PlayTip("To sit down, face your chair and press the <action> key","",5);
			PlayLSAnim('SFInstructor_Sit2',InstructorOne,1,512);
			StartTimer('tmrSitDown2',5,false);
			return true;
		}
		if (Name == 'tmrSitDown2')
		{
			PlayLSAnim('SFInstructor_Sit',InstructorOne,1,512);
			StartTimer('tmrSitDown3',10,false);
			return true;
		}
		if (Name == 'tmrSitDown3')
		{
			PlayLSAnim('SFInstructor_Discipline1',InstructorOne,1,512);
			StartTimer('tmrSitDown4',5,false);
			return true;
		}
		if (Name == 'tmrSitDown4')
		{
			ChangeState('Busted');
			return true;
		}
		return GlobalTimer(Name);
	}
Begin:
	if (StudentController(Controller).IsSeated())
	{
		ChangeState('BeginLecture');
	}
}

State Lecture
{
	Function BeginState()
	{
		ReCaptureEvent(Controller);
		RememberState(GetCurrentState(),0);
		BeginSlide();
	}
	Function BeginSlide()
	{
	}
	bool SeatTriggerOne_UsedBy(AAGP_UseTrigger* Trigger, AActor* Instigator)
	{
		StopTimer('tmrOutOfChair',0);
		ReCaptureEvent(Controller);
		return true;
	}
	bool StudentController_Custom(StudentController SC, AActor* Instigator, FString Parms)
	{
		if (Parms == "EXITCHAIR")
		{
			UnCaptureEvent(Controller);
			StartTimer('tmrOutOfChair',1,false);
			return true;
		}
		if (Parms == "CHEATING")
		{
			return true;
		}
		return false;
	}
	bool Timer_Timer(FName Name)
	{
		if (Name == 'tmrOutOfChair')
		{
			ChangeState(RecallState(1));
			return true;
		}
		return GlobalTimer(Name);
	}
}

State BeginLecture extends Lecture
{
	Function BeginSlide()
	{
		StartTimer('tmrBeginLecture',1,false);
	}
	bool Timer_Timer(FName Name)
	{
		if (Name == 'tmrBeginLecture')
		{
			if (StudentController(Controller).SkipSlides())
			{
				ChangeState('Slide27');
				return true;
			}
			else
			{
				ChangeState('Slide01');
				return true;
			}
		}
		return Super::Timer_Timer(Name);
	}
}

State Slide01 extends Lecture
{
	Function BeginSlide()
	{
		SlideProjectorOne.SetCurrentMaterial(0);
		StartTimer('Slide01_Start',2,false);
	}
	bool Timer_Timer(FName Name)
	{
		if (Name == 'Slide01_Start')
		{
			ChangeState('Slide02');
			return true;
		}
		return Super::Timer_Timer(Name);
	}
Begin:
	if (bHack && bHackSkipSlides)
	{
		ChangeState('TestIntroduction');
	}
}

State Slide02 extends Lecture
{
	Function BeginSlide()
	{
		SlideProjectorOne.SetCurrentMaterial(1);
		StartTimer('Slide02_Start',2,false);
	}
	bool Timer_Timer(FName Name)
	{
		if (Name == 'Slide02_Start')
		{
			PlayLSAnim('SFInstructor_slide1',InstructorOne,1,512);
			return true;
		}
		return Super::Timer_Timer(Name);
	}
	bool Timer_LSAnim(FName Name)
	{
		if (Name == 'SFInstructor_slide1')
		{
			ChangeState('Slide03');
			return true;
		}
	}
}

State Slide03 extends Lecture
{
	Function BeginSlide()
	{
		SlideProjectorOne.SetCurrentMaterial(2);
		StartTimer('Slide03_Start',2,false);
		StartTimer('Slide02b',11,false);
	}
	bool Timer_Timer(FName Name)
	{
		if (Name == 'Slide03_Start')
		{
			PlayLSAnim('SFInstructor_slide2',InstructorOne,1,512);
			return true;
		}
		if (Name == 'Slide02b')
		{
			SlideProjectorOne.SetCurrentMaterial(3);
			return true;
		}
		return Super::Timer_Timer(Name);
	}
	bool Timer_LSAnim(FName Name)
	{
		if (Name == 'SFInstructor_slide2')
		{
			ChangeState('Slide04');
			return true;
		}
	}
}

State Slide04 extends Lecture
{
	Function BeginSlide()
	{
		SlideProjectorOne.SetCurrentMaterial(4);
		StartTimer('Slide04_Start',2,false);
		StartTimer('Slide03b',14,false);
		StartTimer('Slide03c',27,false);
	}
	bool Timer_Timer(FName Name)
	{
		if (Name == 'Slide04_Start')
		{
			PlayLSAnim('SFInstructor_slide3',InstructorOne,1,512);
			return true;
		}
		if (Name == 'Slide03b')
		{
			SlideProjectorOne.SetCurrentMaterial(5);
			return true;
		}
		if (Name == 'Slide03c')
		{
			SlideProjectorOne.SetCurrentMaterial(6);
			return true;
		}
		return Super::Timer_Timer(Name);
	}
	bool Timer_LSAnim(FName Name)
	{
		if (Name == 'SFInstructor_slide3')
		{
			ChangeState('Slide05');
			return true;
		}
	}
}

State Slide05 extends Lecture
{
	Function BeginSlide()
	{
		SlideProjectorOne.SetCurrentMaterial(7);
		StartTimer('Slide05_Start',2,false);
		StartTimer('Slide04b',15,false);
	}
	bool Timer_Timer(FName Name)
	{
		if (Name == 'Slide05_Start')
		{
			PlayLSAnim('SFInstructor_slide4',InstructorOne,1,512);
			return true;
		}
		if (Name == 'Slide04b')
		{
			SlideProjectorOne.SetCurrentMaterial(8);
			return true;
		}
		return Super::Timer_Timer(Name);
	}
	bool Timer_LSAnim(FName Name)
	{
		if (Name == 'SFInstructor_slide4')
		{
			ChangeState('Slide06');
			return true;
		}
	}
}

State Slide06 extends Lecture
{
	Function BeginSlide()
	{
		SlideProjectorOne.SetCurrentMaterial(9);
		StartTimer('Slide06_Start',2,false);
	}
	bool Timer_Timer(FName Name)
	{
		if (Name == 'Slide06_Start')
		{
			PlayLSAnim('SFInstructor_slide5',InstructorOne,1,512);
			return true;
		}
		return Super::Timer_Timer(Name);
	}
	bool Timer_LSAnim(FName Name)
	{
		if (Name == 'SFInstructor_slide5')
		{
			ChangeState('Slide07');
			return true;
		}
	}
}

State Slide07 extends Lecture
{
	Function BeginSlide()
	{
		SlideProjectorOne.SetCurrentMaterial(10);
		StartTimer('Slide07_Start',2,false);
		StartTimer('Slide06b',12,false);
		StartTimer('Slide06c',31,false);
	}
	bool Timer_Timer(FName Name)
	{
		if (Name == 'Slide07_Start')
		{
			PlayLSAnim('SFInstructor_slide6',InstructorOne,1,512);
			return true;
		}
		if (Name == 'Slide06b')
		{
			SlideProjectorOne.SetCurrentMaterial(11);
			return true;
		}
		if (Name == 'Slide06c')
		{
			SlideProjectorOne.SetCurrentMaterial(12);
			return true;
		}
		return Super::Timer_Timer(Name);
	}
	bool Timer_LSAnim(FName Name)
	{
		if (Name == 'SFInstructor_slide6')
		{
			ChangeState('Slide08');
			return true;
		}
	}
}

State Slide08 extends Lecture
{
	Function BeginSlide()
	{
		SlideProjectorOne.SetCurrentMaterial(13);
		StartTimer('Slide08_Start',2,false);
		StartTimer('Slide07b',9,false);
		StartTimer('Slide07c',22,false);
	}
	bool Timer_Timer(FName Name)
	{
		if (Name == 'Slide08_Start')
		{
			PlayLSAnim('SFInstructor_slide7',InstructorOne,1,512);
			return true;
		}
		if (Name == 'Slide07b')
		{
			SlideProjectorOne.SetCurrentMaterial(14);
			return true;
		}
		if (Name == 'Slide07c')
		{
			SlideProjectorOne.SetCurrentMaterial(15);
			return true;
		}
		return Super::Timer_Timer(Name);
	}
	bool Timer_LSAnim(FName Name)
	{
		if (Name == 'SFInstructor_slide7')
		{
			ChangeState('Slide09');
			return true;
		}
	}
}

State Slide09 extends Lecture
{
	Function BeginSlide()
	{
		SlideProjectorOne.SetCurrentMaterial(16);
		StartTimer('Slide09_Start',2,false);
		StartTimer('Slide08b',22,false);
	}
	bool Timer_Timer(FName Name)
	{
		if (Name == 'Slide09_Start')
		{
			PlayLSAnim('SFInstructor_slide8',InstructorOne,1,512);
			return true;
		}
		if (Name == 'Slide08b')
		{
			SlideProjectorOne.SetCurrentMaterial(17);
			return true;
		}
		return Super::Timer_Timer(Name);
	}
	bool Timer_LSAnim(FName Name)
	{
		if (Name == 'SFInstructor_slide8')
		{
			ChangeState('Slide10');
			return true;
		}
	}
}

State Slide10 extends Lecture
{
	Function BeginSlide()
	{
		SlideProjectorOne.SetCurrentMaterial(18);
		StartTimer('Slide10_Start',2,false);
	}
	bool Timer_Timer(FName Name)
	{
		if (Name == 'Slide10_Start')
		{
			PlayLSAnim('SFInstructor_slide9',InstructorOne,1,512);
			return true;
		}
		return Super::Timer_Timer(Name);
	}
	bool Timer_LSAnim(FName Name)
	{
		if (Name == 'SFInstructor_slide9')
		{
			ChangeState('Slide11');
			return true;
		}
	}
}

State Slide11 extends Lecture
{
	Function BeginSlide()
	{
		SlideProjectorOne.SetCurrentMaterial(19);
		StartTimer('Slide11_Start',2,false);
	}
	bool Timer_Timer(FName Name)
	{
		if (Name == 'Slide11_Start')
		{
			PlayLSAnim('SFInstructor_slide10',InstructorOne,1,512);
			return true;
		}
		return Super::Timer_Timer(Name);
	}
	bool Timer_LSAnim(FName Name)
	{
		if (Name == 'SFInstructor_slide10')
		{
			ChangeState('Slide12');
			return true;
		}
	}
}

State Slide12 extends Lecture
{
	Function BeginSlide()
	{
		SlideProjectorOne.SetCurrentMaterial(20);
		StartTimer('Slide12_Start',2,false);
	}
	bool Timer_Timer(FName Name)
	{
		if (Name == 'Slide12_Start')
		{
			PlayLSAnim('SFInstructor_slide11',InstructorOne,1,512);
			return true;
		}
		return Super::Timer_Timer(Name);
	}
	bool Timer_LSAnim(FName Name)
	{
		if (Name == 'SFInstructor_slide11')
		{
			ChangeState('Slide13');
			return true;
		}
	}
}

State Slide13 extends Lecture
{
	Function BeginSlide()
	{
		SlideProjectorOne.SetCurrentMaterial(21);
		StartTimer('Slide13_Start',2,false);
	}
	bool Timer_Timer(FName Name)
	{
		if (Name == 'Slide13_Start')
		{
			PlayLSAnim('SFInstructor_slide12',InstructorOne,1,512);
			return true;
		}
		return Super::Timer_Timer(Name);
	}
	bool Timer_LSAnim(FName Name)
	{
		if (Name == 'SFInstructor_slide12')
		{
			ChangeState('Slide14');
			return true;
		}
	}
}

State Slide14 extends Lecture
{
	Function BeginSlide()
	{
		SlideProjectorOne.SetCurrentMaterial(22);
		StartTimer('Slide14_Start',2,false);
	}
	bool Timer_Timer(FName Name)
	{
		if (Name == 'Slide14_Start')
		{
			PlayLSAnim('SFInstructor_slide13',InstructorOne,1,512);
			return true;
		}
		return Super::Timer_Timer(Name);
	}
	bool Timer_LSAnim(FName Name)
	{
		if (Name == 'SFInstructor_slide13')
		{
			ChangeState('Slide15');
			return true;
		}
	}
}

State Slide15 extends Lecture
{
	Function BeginSlide()
	{
		SlideProjectorOne.SetCurrentMaterial(23);
		StartTimer('Slide15_Start',2,false);
		StartTimer('Slide14b',17,false);
	}
	bool Timer_Timer(FName Name)
	{
		if (Name == 'Slide15_Start')
		{
			PlayLSAnim('SFInstructor_slide14',InstructorOne,1,512);
			return true;
		}
		if (Name == 'Slide14b')
		{
			SlideProjectorOne.SetCurrentMaterial(24);
			return true;
		}
		return Super::Timer_Timer(Name);
	}
	bool Timer_LSAnim(FName Name)
	{
		if (Name == 'SFInstructor_slide14')
		{
			ChangeState('Slide16');
			return true;
		}
	}
}

State Slide16 extends Lecture
{
	Function BeginSlide()
	{
		SlideProjectorOne.SetCurrentMaterial(25);
		StartTimer('Slide16_Start',2,false);
		StartTimer('Slide15b',19,false);
	}
	bool Timer_Timer(FName Name)
	{
		if (Name == 'Slide16_Start')
		{
			PlayLSAnim('SFInstructor_slide15',InstructorOne,1,512);
			return true;
		}
		if (Name == 'Slide15b')
		{
			SlideProjectorOne.SetCurrentMaterial(26);
			return true;
		}
		return Super::Timer_Timer(Name);
	}
	bool Timer_LSAnim(FName Name)
	{
		if (Name == 'SFInstructor_slide15')
		{
			ChangeState('Slide17');
			return true;
		}
	}
}

State Slide17 extends Lecture
{
	Function BeginSlide()
	{
		SlideProjectorOne.SetCurrentMaterial(27);
		StartTimer('Slide17_Start',2,false);
	}
	bool Timer_Timer(FName Name)
	{
		if (Name == 'Slide17_Start')
		{
			PlayLSAnim('SFInstructor_slide16',InstructorOne,1,512);
			return true;
		}
		return Super::Timer_Timer(Name);
	}
	bool Timer_LSAnim(FName Name)
	{
		if (Name == 'SFInstructor_slide16')
		{
			ChangeState('Slide18');
			return true;
		}
	}
}

State Slide18 extends Lecture
{
	Function BeginSlide()
	{
		SlideProjectorOne.SetCurrentMaterial(28);
		StartTimer('Slide18_Start',2,false);
	}
	bool Timer_Timer(FName Name)
	{
		if (Name == 'Slide18_Start')
		{
			PlayLSAnim('SFInstructor_slide17',InstructorOne,1,512);
			return true;
		}
		return Super::Timer_Timer(Name);
	}
	bool Timer_LSAnim(FName Name)
	{
		if (Name == 'SFInstructor_slide17')
		{
			ChangeState('Slide19');
			return true;
		}
	}
}

State Slide19 extends Lecture
{
	Function BeginSlide()
	{
		SlideProjectorOne.SetCurrentMaterial(29);
		StartTimer('Slide19_Start',2,false);
	}
	bool Timer_Timer(FName Name)
	{
		if (Name == 'Slide19_Start')
		{
			PlayLSAnim('SFInstructor_slide18',InstructorOne,1,512);
			return true;
		}
		return Super::Timer_Timer(Name);
	}
	bool Timer_LSAnim(FName Name)
	{
		if (Name == 'SFInstructor_slide18')
		{
			ChangeState('Slide20');
			return true;
		}
	}
}

State Slide20 extends Lecture
{
	Function BeginSlide()
	{
		SlideProjectorOne.SetCurrentMaterial(30);
		StartTimer('Slide20_Start',2,false);
	}
	bool Timer_Timer(FName Name)
	{
		if (Name == 'Slide20_Start')
		{
			PlayLSAnim('SFInstructor_slide19',InstructorOne,1,512);
			return true;
		}
		return Super::Timer_Timer(Name);
	}
	bool Timer_LSAnim(FName Name)
	{
		if (Name == 'SFInstructor_slide19')
		{
			ChangeState('Slide21');
			return true;
		}
	}
}

State Slide21 extends Lecture
{
	Function BeginSlide()
	{
		SlideProjectorOne.SetCurrentMaterial(31);
		StartTimer('Slide21_Start',2,false);
	}
	bool Timer_Timer(FName Name)
	{
		if (Name == 'Slide21_Start')
		{
			PlayLSAnim('SFInstructor_slide20',InstructorOne,1,512);
			return true;
		}
		return Super::Timer_Timer(Name);
	}
	bool Timer_LSAnim(FName Name)
	{
		if (Name == 'SFInstructor_slide20')
		{
			ChangeState('Slide22');
			return true;
		}
	}
}

State Slide22 extends Lecture
{
	Function BeginSlide()
	{
		SlideProjectorOne.SetCurrentMaterial(32);
		StartTimer('Slide22_Start',2,false);
	}
	bool Timer_Timer(FName Name)
	{
		if (Name == 'Slide22_Start')
		{
			PlayLSAnim('SFInstructor_slide21',InstructorOne,1,512);
			return true;
		}
		return Super::Timer_Timer(Name);
	}
	bool Timer_LSAnim(FName Name)
	{
		if (Name == 'SFInstructor_slide21')
		{
			ChangeState('Slide23');
			return true;
		}
	}
}

State Slide23 extends Lecture
{
	Function BeginSlide()
	{
		SlideProjectorOne.SetCurrentMaterial(33);
		StartTimer('Slide23_Start',2,false);
	}
	bool Timer_Timer(FName Name)
	{
		if (Name == 'Slide23_Start')
		{
			PlayLSAnim('SFInstructor_slide22',InstructorOne,1,512);
			return true;
		}
		return Super::Timer_Timer(Name);
	}
	bool Timer_LSAnim(FName Name)
	{
		if (Name == 'SFInstructor_slide22')
		{
			ChangeState('Slide24');
			return true;
		}
	}
}

State Slide24 extends Lecture
{
	Function BeginSlide()
	{
		SlideProjectorOne.SetCurrentMaterial(34);
		StartTimer('Slide24_Start',2,false);
	}
	bool Timer_Timer(FName Name)
	{
		if (Name == 'Slide24_Start')
		{
			PlayLSAnim('SFInstructor_slide23',InstructorOne,1,512);
			return true;
		}
		return Super::Timer_Timer(Name);
	}
	bool Timer_LSAnim(FName Name)
	{
		if (Name == 'SFInstructor_slide23')
		{
			ChangeState('Slide25');
			return true;
		}
	}
}

State Slide25 extends Lecture
{
	Function BeginSlide()
	{
		SlideProjectorOne.SetCurrentMaterial(35);
		StartTimer('Slide25_Start',2,false);
	}
	bool Timer_Timer(FName Name)
	{
		if (Name == 'Slide25_Start')
		{
			PlayLSAnim('SFInstructor_slide24',InstructorOne,1,512);
			return true;
		}
		return Super::Timer_Timer(Name);
	}
	bool Timer_LSAnim(FName Name)
	{
		if (Name == 'SFInstructor_slide24')
		{
			ChangeState('Slide26');
			return true;
		}
	}
}

State Slide26 extends Lecture
{
	Function BeginSlide()
	{
		SlideProjectorOne.SetCurrentMaterial(36);
		StartTimer('Slide26_Start',2,false);
	}
	bool Timer_Timer(FName Name)
	{
		if (Name == 'Slide26_Start')
		{
			PlayLSAnim('SFInstructor_slide25',InstructorOne,1,512);
			return true;
		}
		return Super::Timer_Timer(Name);
	}
	bool Timer_LSAnim(FName Name)
	{
		if (Name == 'SFInstructor_slide25')
		{
			ChangeState('Slide27');
			return true;
		}
	}
}

State Slide27 extends Lecture
{
	Function BeginSlide()
	{
		SlideProjectorOne.SetCurrentMaterial(0);
		StartTimer('Slide27_Start',2,false);
	}
	bool Timer_Timer(FName Name)
	{
		if (Name == 'Slide27_Start')
		{
			PlayLSAnim('SFInstructor_slide26',InstructorOne,1,512);
			return true;
		}
		return Super::Timer_Timer(Name);
	}
	bool Timer_LSAnim(FName Name)
	{
		if (Name == 'SFInstructor_slide26')
		{
			ChangeState('PosterTime');
			return true;
		}
		return false;
	}
}

State PosterTime
{
	bool StudentController_Custom(StudentController SC, AActor* Instigator, FString Parms)
	{
		if (Parms == "EXITCHAIR")
		{
			ChangeState('ExaminingPosters');
			return true;
		}
		if (Parms == "CHEATING")
		{
			return true;
		}
		return false;
	}
Begin:
	PlayTip("Go ahead and take a few minutes to","examine the posters on the wall",4);
	Sleep(6);
	PlayTip("Otherwise, remain seated and the","test will begin shortly.",4);
	Sleep(9);
	PlayTip("Time to begin the test","",3);
	ChangeState('TestIntroduction');
}

State ExaminingPosters
{
	bool SeatTriggerOne_UsedBy(AAGP_UseTrigger* Trigger, AActor* Instigator)
	{
		PlayTip("Time to begin the test","",3);
		ChangeState('TestIntroduction');
		return true;
	}
Begin:
	Sleep(60);
	PlayTip("Take your seat when you are","ready to begin the test",5);
}

State TestIntroduction extends Lecture
{
	Function BeginSlide()
	{
	}
Begin:
	SlideProjectorOne.SetCurrentMaterial(0);
	Sleep(2);
	PlayLSAnim('SFInstructor_Test1',InstructorOne,1,512);
	Sleep(24);
	FadeOutBlack(1);
	Sleep(1);
	SFExamOne.SetActive(true);
	ChangeState('TestSlide1');
}

State TestSlides
{
	Function BeginState()
	{
		ReCaptureEvent(Controller);
		RememberState(GetCurrentState(),0);
		BeginSlide();
	}
	Function BeginSlide()
	{
	}
	bool SeatTriggerOne_UsedBy(AAGP_UseTrigger* Trigger, AActor* Instigator)
	{
		StopTimer('tmrOutOfChair',0);
		ReCaptureEvent(Controller);
		return true;
	}
	bool StudentController_Custom(StudentController SC, AActor* Instigator, FString Parms)
	{
		if (Parms == "EXITCHAIR")
		{
			UnCaptureEvent(Controller);
			StartTimer('tmrOutOfChair',1,false);
			return true;
		}
		if (Parms == "CHEATING")
		{
			UnCaptureEvent(Controller);
			StartTimer('CheckCheating',1,false);
			return true;
		}
		return false;
	}
	bool Timer_Timer(FName Name)
	{
		if (Name == 'tmrOutOfChair')
		{
			ChangeState(RecallState(1));
			return true;
		}
		if (Name == 'CheckCheating')
		{
			if (StudentController(Controller).IsPossiblyCheating())
			{
				ChangeState('Cheating');
				return true;
			}
			else
			{
				ReCaptureEvent(Controller);
				return true;
			}
		}
		return GlobalTimer(Name);
	}
}

State TestSlide1 extends TestSlides
{
	Function BeginSlide()
	{
	}
Begin:
	ClearClock();
	SFExamOne.SetPage(0);
	Controller.GotoState('SFClassOneSitting');
	SlideProjectorOne.SetCurrentMaterial(37);
	FadeInBlack(1);
	Sleep(1);
	Sleep(15);
	FadeOutBlack(1);
	Sleep(1);
	SlideProjectorOne.SetCurrentMaterial(0);
	SFExamOne.SetPage(1);
	FadeInBlack(1);
	Controller.GotoState('SFClassOneTesting');
	StartClock(25,true);
	Sleep(25);
	FadeOutBlack(1);
	Sleep(1);
	ChangeState('TestSlide2');
}

State TestSlide2 extends TestSlides
{
	Function BeginSlide()
	{
	}
Begin:
	ClearClock();
	SFExamOne.SetPage(0);
	Controller.GotoState('SFClassOneSitting');
	SlideProjectorOne.SetCurrentMaterial(38);
	FadeInBlack(1);
	Sleep(1);
	Sleep(15);
	FadeOutBlack(1);
	Sleep(1);
	SlideProjectorOne.SetCurrentMaterial(0);
	SFExamOne.SetPage(2);
	FadeInBlack(1);
	Controller.GotoState('SFClassOneTesting');
	StartClock(25,true);
	Sleep(25);
	FadeOutBlack(1);
	Sleep(1);
	ChangeState('TestSlide3');
}

State TestSlide3 extends TestSlides
{
	Function BeginSlide()
	{
	}
Begin:
	ClearClock();
	SFExamOne.SetPage(0);
	Controller.GotoState('SFClassOneSitting');
	SlideProjectorOne.SetCurrentMaterial(39);
	FadeInBlack(1);
	Sleep(1);
	Sleep(15);
	FadeOutBlack(1);
	Sleep(1);
	SlideProjectorOne.SetCurrentMaterial(0);
	SFExamOne.SetPage(3);
	FadeInBlack(1);
	Controller.GotoState('SFClassOneTesting');
	StartClock(25,true);
	Sleep(25);
	FadeOutBlack(1);
	Sleep(1);
	ChangeState('TestSlide4');
}

State TestSlide4 extends TestSlides
{
	Function BeginSlide()
	{
	}
Begin:
	ClearClock();
	SFExamOne.SetPage(0);
	Controller.GotoState('SFClassOneSitting');
	SlideProjectorOne.SetCurrentMaterial(40);
	FadeInBlack(1);
	Sleep(1);
	Sleep(15);
	FadeOutBlack(1);
	Sleep(1);
	SlideProjectorOne.SetCurrentMaterial(0);
	SFExamOne.SetPage(4);
	FadeInBlack(1);
	Controller.GotoState('SFClassOneTesting');
	StartClock(25,true);
	Sleep(25);
	FadeOutBlack(1);
	Sleep(1);
	ChangeState('TestSlide5');
}

State TestSlide5 extends TestSlides
{
	Function BeginSlide()
	{
	}
Begin:
	ClearClock();
	SFExamOne.SetPage(0);
	Controller.GotoState('SFClassOneSitting');
	SlideProjectorOne.SetCurrentMaterial(41);
	FadeInBlack(1);
	Sleep(1);
	Sleep(15);
	FadeOutBlack(1);
	Sleep(1);
	SlideProjectorOne.SetCurrentMaterial(0);
	SFExamOne.SetPage(5);
	FadeInBlack(1);
	Controller.GotoState('SFClassOneTesting');
	StartClock(25,true);
	Sleep(25);
	FadeOutBlack(1);
	Sleep(1);
	ChangeState('TestingCompleted');
}

State TestingCompleted
{
	Function BeginState()
	{
		StartTimer('StudentStillSitting',5);
	}
	bool StudentController_Custom(StudentController SC, AActor* Instigator, FString Parms)
	{
		if (Parms == "EXITCHAIR")
		{
			StopTimer('StudentStillSitting',0);
			SFExamOne.HideExam();
			return true;
		}
		return false;
	}
	bool SeatTriggerOne_UsedBy(AAGP_UseTrigger* Trigger, AActor* Instigator)
	{
		SFExamOne.ShowExam();
		return true;
	}
	bool Timer_Timer(FName Name)
	{
		if (Name == 'StudentStillSitting')
		{
			PlayTip("To get out of your chair, press the <jump> key","",5);
			return true;
		}
		return GlobalTimer(Name);
	}
	bool InstructorTriggerOne_UsedBy(AAGP_UseTrigger* Trigger, AActor* Instigator)
	{
		Grade = int((SFExamOne.ScoreTest() * float(100)));
		if (Grade >= 80)
		{
			ChangeState('Eighty1Hundred');
			return true;
		}
		if (Grade >= 70)
		{
			ChangeState('SeventySeventyNine');
			return true;
		}
		if (Grade >= 60)
		{
			ChangeState('SixtySixtyNine');
			return true;
		}
		else
		{
			ChangeState('ZeroFiftyNine');
			return true;
		}
	}
Begin:
	SFExamOne.SetActive(false);
	SFExamOne.SetPage(0);
	ClearClock();
	Controller.GotoState('SFClassOneSitting');
	FadeInBlack(1);
	Sleep(1);
	PlayTip("Turn in your test in to the Instructor","",5);
}

State Eighty1Hundred
{
	Function BeginState()
	{
		PlayLSAnim('SFInstructor_TestPerfect',InstructorOne,1,512);
		if (StudentController(Controller).IsCheating())
		{
			PlayTip("Cheats Detected. Good job soldier,","you scored " $ string(Grade) $ "%",5);
		}
		else
		{
			PlayTip("Good job soldier,","you scored " $ string(Grade) $ "%",5);
		}
	}
	bool Timer_LSAnim(FName Name)
	{
		if (Name == 'SFInstructor_TestPerfect')
		{
			ChangeState('ChopperScene');
			return true;
		}
	}
}

State SeventySeventyNine
{
	Function BeginState()
	{
		PlayLSAnim('SFInstructor_TestGood',InstructorOne,1,512);
		if (StudentController(Controller).IsCheating())
		{
			PlayTip("Cheats Detected. You passed with","" $ string(Grade) $ "%",5);
		}
		else
		{
			PlayTip("You passed with","" $ string(Grade) $ "%",5);
		}
	}
	bool Timer_LSAnim(FName Name)
	{
		if (Name == 'SFInstructor_TestGood')
		{
			ChangeState('ChopperScene');
			return true;
		}
	}
}

State SixtySixtyNine
{
	Function BeginState()
	{
		PlayLSAnim('SFInstructor_TestFailure',InstructorOne,1,512);
		if (StudentController(Controller).IsCheating())
		{
			PlayTip("Cheats Detected. You Failed!","You scored" $ string(Grade) $ "%",5);
		}
		else
		{
			PlayTip("You Failed!","You scored" $ string(Grade) $ "%",5);
		}
	}
	bool Timer_LSAnim(FName Name)
	{
		if (Name == 'SFInstructor_TestFailure')
		{
			ChangeState('TestFailed');
			return true;
		}
	}
}

State ZeroFiftyNine
{
	Function BeginState()
	{
		PlayLSAnim('SFInstructor_TestPathetic',InstructorOne,1,512);
		if (StudentController(Controller).IsCheating())
		{
			PlayTip("Cheats Detected. Pathetic soldier!","You scored " $ string(Grade) $ "%",5);
		}
		else
		{
			PlayTip("Pathetic soldier!","You scored " $ string(Grade) $ "%",5);
		}
	}
	bool Timer_LSAnim(FName Name)
	{
		if (Name == 'SFInstructor_TestPathetic')
		{
			ChangeState('TestFailed');
			return true;
		}
	}
}

State TestPassed
{
	Function UpdateCompletionFields()
	{
		local Security secLocalSecurity;
		local class<Security>  scLocalSecurityClass;
		local TArray<FString> asMD5ForMap;
		local TArray<FString> asMD5ForScript;
		FString sMD5ForMap = "";
		FString sMD5ForScript = "";
		scLocalSecurityClass = class<Security>(DynamicLoadObject("Engine.Security",Class'Class'));
		if (scLocalSecurityClass != None)
		{
			secLocalSecurity = Spawn(scLocalSecurityClass,Controller);
			if (secLocalSecurity != None)
			{
				secLocalSecurity.LocalPerform(2,"../Maps/JavelinTraining.aao","",asMD5ForMap);
				secLocalSecurity.LocalPerform(2,"../System/AGP_Script.u","",asMD5ForScript);
				sMD5ForMap = asMD5ForMap[0];
				sMD5ForScript = asMD5ForScript[0];
			}
		}
		Controller.AddAuthExtraMissionData(sMD5ForMap);
		Controller.AddAuthExtraMissionData(sMD5ForScript);
	}
Begin:
	StudentController(Controller).ResetAuthExtraMissionData();
	StudentController(Controller).AddAuthExtraMissionData(string(Grade));
	UpdateCompletionFields();
	if (StudentController(Controller).IsCheating())
	{
		StudentController(Controller).SetAuthMissionPassFlag(false);
		DisplayMissionFailure("T_AA2_UI.tour_icons.hud_menu_touricon_sf","Congratulations!","Cheats detected, cannot complete.",128,128,7,'None');
	}
	else
	{
		StudentController(Controller).SetAuthMissionPassFlag(true);
		DisplayMissionSuccess("T_AA2_UI.tour_icons.hud_menu_touricon_sf","Congratulations! You qualify for ","Special Forces.",128,128,7,'None');
	}
}

State TestFailed
{
Begin:
	Sleep(2);
	PlayTip("Have a seat to take the test again.","",5);
	ChangeState('RepeatTest');
}

State RepeatTest
{
	bool SeatTriggerOne_UsedBy(AAGP_UseTrigger* Trigger, AActor* Instigator)
	{
		SFExamOne.SetActive(false);
		SFExamOne.ShowExam();
		SFExamOne.ResetTest();
		SFExamOne.SetPage(0);
		ChangeState('TestIntroduction');
		return true;
	}
Begin:
	Sleep(15);
	PlayTip("The class will begin when you take your seat.","",5);
}

State ChopperScene
{
	bool Timer_Timer(FName Name)
	{
		if (Name == 'ChopperStart')
		{
			TriggerEvent('rotorsnsound',Self,Player);
			return true;
		}
	}
Begin:
	StartTimer('ChopperStart',33);
	Guy1.LoopAnim('StdNo');
	Guy2.LoopAnim('CrhNo');
	SargChopper.LoopAnim('DrillIdle');
	PlayerLock(true,true);
	FadeOutBlack(2);
	Sleep(2);
	DisableHUD();
	CueCamera(ChopperCam01);
	FadeInBlack(2);
	Sleep(2);
	PlayLSAnim('Sgt1',SargChopper,1,512);
	Sleep(3);
	PlayLSAnim('Guy1',Guy1,1,512);
	Sleep(4);
	PlayLSAnim('Sgt2',SargChopper,1,512);
	Sleep(6);
	PlayLSAnim('Sgt3',SargChopper,1,512);
	Sleep(3);
	PlayLSAnim('Guy2',Guy2,1,512);
	Sleep(3);
	PlayLSAnim('Sgt4',SargChopper,1,512);
	Sleep(7);
	ChangeState('TestPassed');
}

State Trouble
{
	Function BeginState()
	{
		BeginTrouble();
	}
	Function EndState()
	{
		EndTrouble();
	}
	Function BeginTrouble()
	{
	}
	Function EndTrouble()
	{
	}
	bool SeatTriggerOne_UsedBy(AAGP_UseTrigger* Trigger, AActor* Instigator)
	{
		ChangeState(RecallState(0));
		return true;
	}
}

State OutOfChair1 extends Trouble
{
	Function BeginTrouble()
	{
		PlayLSAnim('SFInstructor_Sit',InstructorOne,1,512);
		RememberState('OutOfChair2',1);
		StartTimer('Escelate',10,false);
	}
	Function EndTrouble()
	{
		StopTimer('Escelate',0);
	}
	bool Timer_Timer(FName Name)
	{
		if (Name == 'Escelate')
		{
			ChangeState('OutOfChair2');
			return true;
		}
		return GlobalTimer(Name);
	}
}

State OutOfChair2 extends Trouble
{
	Function BeginTrouble()
	{
		PlayLSAnim('SFInstructor_Discipline2',InstructorOne,1,512);
		RememberState('Busted',1);
		StartTimer('Escelate',10,false);
	}
	Function EndTrouble()
	{
		StopTimer('Escelate',0);
	}
	bool Timer_Timer(FName Name)
	{
		if (Name == 'Escelate')
		{
			ChangeState('Busted');
			return true;
		}
		return GlobalTimer(Name);
	}
}

State Busted extends Trouble
{
	Function BeginTrouble()
	{
		PlayLSAnim('SFInstructor_Discipline3',InstructorOne,1,512);
		Controller.GotoState('MedicTraining_Frozen');
		FadeOutBlack(2);
		PlayerLock(true,true);
		StartTimer('tmrLoadEntry',4,false);
	}
	Function EndTrouble()
	{
	}
	bool Timer_Timer(FName Name)
	{
		if (Name == 'tmrLoadEntry')
		{
			StopLipSincAnims();
			RunConsoleCommand("open entry2");
			return true;
		}
		return GlobalTimer(Name);
	}
}

State Cheating
{
	Function EndState()
	{
		ReCaptureEvent(Controller);
	}
	bool Timer_LSAnim(FName Name)
	{
		if ((Name == 'SFInstructor_TestCheat') || (Name == 'SFInstructor_Discipline2'))
		{
			ChangeState(RecallState(0));
			return true;
		}
	}
Begin:
	LookCount++;
	if (LookCount == 1)
	{
		PlayLSAnim('SFInstructor_TestCheat',InstructorOne,1,512);
	}
	else
	{
		if (LookCount == 2)
		{
			PlayLSAnim('SFInstructor_Discipline2',InstructorOne,1,512);
		}
		else
		{
			ChangeState('Busted');
		}
	}
}
*/

bool AEL_AVWID::AGP_UseTrigger_UsedBy(AAGP_UseTrigger* Trigger, AActor* aInstigator)
{
	/*
	switch (Trigger.Tag)
	{
	case 'SeatTriggerOne':
		return SeatTriggerOne_UsedBy(Trigger, aInstigator);
	case 'InstructorTriggerOne':
		return InstructorTriggerOne_UsedBy(Trigger, aInstigator);
	default:
		return false;
	}
	*/
	return false;    //FAKE   /ELiZ
}

bool AEL_AVWID::SeatTriggerOne_UsedBy(AAGP_UseTrigger* Trigger, AActor* aInstigator)
{
	return false;    //FAKE   /ELiZ
}

bool AEL_AVWID::InstructorTriggerOne_UsedBy(AAGP_UseTrigger* Trigger, AActor* aInstigator)
{
	return false;    //FAKE   /ELiZ
}

bool AEL_AVWID::AGP_Trigger_Trigger(AAGP_Trigger* Trigger, AActor* aInstigator)
{
	/*
	switch (Trigger.Tag)
	{
	case 'SeatVolumeOne':
		return SeatVolumeOne_Trigger(Trigger, aInstigator);
	default:
		return false;
	}
	*/
	return false;    //FAKE   /ELiZ
}

bool AEL_AVWID::AGP_Trigger_UnTrigger(AAGP_Trigger* Trigger, AActor* aInstigator)
{
	/*
	switch (Trigger.Tag)
	{
	case 'SeatVolumeOne':
		return SeatVolumeOne_UnTrigger(Trigger, aInstigator);
	default:
		return false;
	}
	*/
	return false;    //FAKE   /ELiZ
}

bool AEL_AVWID::SeatVolumeOne_Trigger(AAGP_Trigger* Trigger, AActor* aInstigator)
{
	return false;    //FAKE   /ELiZ
}

bool AEL_AVWID::SeatVolumeOne_UnTrigger(AAGP_Trigger* Trigger, AActor* aInstigator)
{
	return false;    //FAKE   /ELiZ
}

bool AEL_AVWID::DoorTrigger_UsedBy(ADoorTrigger* Trigger, AActor* aInstigator)
{
	/*
	switch (Trigger.Tag)
	{
	case 'DoorTriggerOne':
		return DoorTriggerOne_UsedBy(Trigger, aInstigator);
	default:
		return false;
	}
	*/
	return false;    //FAKE   /ELiZ

}

bool AEL_AVWID::DoorTriggerOne_UsedBy(ADoorTrigger* Trigger, AActor* aInstigator)
{
	return false;    //FAKE   /ELiZ
}

bool AEL_AVWID::TriggerVolume_Enter(ATriggerVolume* Trigger, AActor* aInstigator)
{
	/*
	switch (Trigger.Tag)
	{
	case 'ClassVolumeOne':
		return ClassVolumeOne_Enter(Trigger, aInstigator);
	case 'LeavingVolumeOne':
		return LeavingVolumeOne_Enter(Trigger, aInstigator);
	case 'TestVolumeOne':
		return TestVolumeOne_Enter(Trigger, aInstigator);
	case 'SodaGuy_Trigger':
		return SodaGuy_Trigger_Enter(Trigger, aInstigator);
	case 'OutOfBounds':
		return OutOfBounds_Trigger_Enter(Trigger, aInstigator);
	default:
		return false;
	}
	*/
	return false;    //FAKE   /ELiZ
}

bool AEL_AVWID::ClassVolumeOne_Enter(ATriggerVolume* Trigger, AActor* aInstigator)
{
	return false;    //FAKE   /ELiZ
}

bool AEL_AVWID::LeavingVolumeOne_Enter(ATriggerVolume* Trigger, AActor* aInstigator)
{
	return false;    //FAKE   /ELiZ
}

bool AEL_AVWID::TestVolumeOne_Enter(ATriggerVolume* Trigger, AActor* aInstigator)
{
	return false;    //FAKE   /ELiZ
}

void AEL_AVWID::PreInit()
{
	/*
	DoorTriggerOne = DoorTrigger(CaptureEvent('DoorTriggerOne'));
	InstructorTriggerOne = AGP_UseTrigger(CaptureEvent('InstructorTriggerOne'));
	InstructorOne = NPC_MedInstructor(CaptureEvent('InstructorOne'));
	SlideProjectorOne = SlideProjector(CaptureEvent('SlideProjectorOne'));
	SeatTriggerOne = AGP_UseTrigger(CaptureEvent('SeatTriggerOne'));
	TestVolumeOne = TriggerVolume(CaptureEvent('TestVolumeOne'));
	LeavingVolumeOne = TriggerVolume(CaptureEvent('LeavingVolumeOne'));
	SeatVolumeOne = AGP_Trigger(CaptureEvent('SeatVolumeOne'));
	SFExamOne = MedExam(CaptureEvent('SFExamOne'));
	CaptureEventGroup('ClassVolumeOne');
	SodaGuy = NPC_Ambient(CaptureEvent('SodaGuy'));
	SodaMachine = NPC_Ambient(CaptureEvent('SodaMachine'));
	Guy1 = NPC_SpecialForces(CaptureEvent('Guy1'));
	Guy2 = NPC_SpecialForces(CaptureEvent('Guy2'));
	SargChopper = NPC_SpecialForces(CaptureEvent('SargChopper'));
	SodaGuy_Trigger = TriggerVolume(CaptureEvent('SodaGuy_Trigger'));
	TruckSplineTrigger = TriggerVolume(CaptureEvent('TruckSplineTrigger'));
	GoToClass = AGP_Location(CaptureEvent('GoToClass'));
	ClassRoom = AGP_Location(CaptureEvent('ClassRoom'));
	PlayerStartLocation = AGP_Location(CaptureEvent('PlayerStartLocation'));
	Chopper = AGP_Location(CaptureEvent('Chopper'));
	Truck1 = RelayTrigger(CaptureEvent('Truck1'));
	ChopperCam01 = CameraPoint(GetActorByTag('ChopperCam01'));
	CaptureEventGroup('OutOfBounds');
	*/
}

void AEL_AVWID::Init()
{
}

void AEL_AVWID::PostInit()
{
}

void AEL_AVWID::PostPostInit()
{
	/*
	local AGP_Characters.NPC_MedStudent MS;
	bHack = false;
	bHackChopper = false;
	bHackSkipSlides = false;
	RememberState('OutOfChair1', 1);
	SFExamOne.SetActive(false);
	SFExamOne.LockPageTurning();
	PlayerLock(false, false);
	DoorTriggerOne.SetLocked(true);
	ClearClock();
	SodaGuy.LoopAnim('vending_idle1');
	InstructorOne.GotoState('Professor', 'Begin');
	ForEach AllActors(Class'AGP_Characters.NPC_MedStudent', MS)
	{
		if (MS.EyesTrack == true)
		{
			MS.GotoState('StudentEyeTrackState', 'Begin');
		}
	}
	if (bHack && bHackChopper)
	{
		ChangeState('ChopperScene');
		return;
	}
	Player.SetLocation(GoToClass.Location);
	Controller.SetRotation(RandLookRotation());
	ChangeState('FindClass');
	*/
}

FRotator AEL_AVWID::RandLookRotation()
{
	//return MakeRot(0, (Rand(32768) * 2), 0);
	return FRotator(0, 0, 0);     //FAKE   /ELiZ
}

bool AEL_AVWID::SodaGuy_Trigger_Enter(ATriggerVolume* Trigger, AActor* aInstigator)
{
	
	AActor* SoundActor=nullptr;
	if (bSodaGuy_Trigger_Used)
	{
		return true;
	}
	bSodaGuy_Trigger_Used = true;
	//SodaGuy->PlayAnim("vending_attack");
	//SodaMachine->PlayAnim("vending_attack");
	StartTimer("SodaMachineEnd", 55.299999, false);
	if (SodaGuySound != nullptr)
	{
		//SoundActor = Spawn(Class'EffectLocation', , , SodaGuy.Location);
		//SoundActor.LifeSpan = GetSoundDuration(SodaGuySound);
		//SoundActor.PlaySound(SodaGuySound, 0, 1, , , , false);
	}
	return true;
}

bool AEL_AVWID::OutOfBounds_Trigger_Enter(ATriggerVolume* Trigger, AActor* aInstigator)
{
	FName CurrentState = "";
	FadeOutBlack(2);
	PlayerLock(true, false);
	CurrentState = GetCurrentState();
	if (CurrentState == "TalkToSFTeam")
	{
		StartTimer("OutOfBounds_Gabriel", 2,false);
		return true;
	}
	if (CurrentState == "FindClass")
	{
		StartTimer("FindClass_GlobalTimer", 120, false);
		StartTimer("OutOfBounds_GotoClass", 2, false);
		return true;
	}
	if (CurrentState == "inClass")
	{
		StartTimer("OutOfBounds_ClassRoom", 2, false);
		return true;
	}
	return false;
}

bool AEL_AVWID::GlobalTimer(FName Name)
{
	if (Name == "SodaMachineEnd")
	{
		//SodaGuy.LoopAnim('vending_idle2');
		return true;
	}
	if (Name == "OutOfBounds_GotoClass")
	{
		//Player.SetLocation(GoToClass.Location);
		//Controller.SetRotation(RandLookRotation());
		PlayTip("Locate the Class Room", "T-3164 to take the test", 10);
		PlayerLock(false, false);
		FadeInBlack(2);
		return true;
	}
	if (Name == "OutOfBounds_ClassRoom")
	{
		//Player.SetLocation(ClassRoom.Location);
		//Controller.SetRotation(ClassRoom.Rotation);
		PlayerLock(false, false);
		FadeInBlack(2);
		return true;
	}
	return false;
}

void AEL_AVWID::StopLipSincAnims()
{
	/*
	local Pawn p;
	ForEach AllActors(Class'Pawn', p)
	{
		p.StopLIPSincAnim();
	}
	*/
}