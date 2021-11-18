// All the original content belonged to the US Army


#include "ScopeW_Javelin.h"

AScopeW_Javelin::AScopeW_Javelin()
{
	NightVisionTexture  = LoadObject<UTexture2D>(NULL, TEXT("/Game/AmericasArmy/Textures/T_AA2_FX/Optics/Nightvision1.Nightvision1"), NULL, LOAD_None, NULL);
	DayTex              = LoadObject<UTexture2D>(NULL, TEXT("/Game/AmericasArmy/Textures/T_AAO_Armory/Javelin/Day.Day"), NULL, LOAD_None, NULL);
	WFOVTex             = LoadObject<UTexture2D>(NULL, TEXT("/Game/AmericasArmy/Textures/T_AAO_Armory/Javelin/WFOV.WFOV"), NULL, LOAD_None, NULL);
	NFOVTex             = LoadObject<UTexture2D>(NULL, TEXT("/Game/AmericasArmy/Textures/T_AAO_Armory/Javelin/nfov.nfov"), NULL, LOAD_None, NULL);
	SEEKTex             = LoadObject<UTexture2D>(NULL, TEXT("/Game/AmericasArmy/Textures/T_AAO_Armory/Javelin/Seek.Seek"), NULL, LOAD_None, NULL);
	DIRTex              = LoadObject<UTexture2D>(NULL, TEXT("/Game/AmericasArmy/Textures/T_AAO_Armory/Javelin/Dir.Dir"), NULL, LOAD_None, NULL);
	TOPTex              = LoadObject<UTexture2D>(NULL, TEXT("/Game/AmericasArmy/Textures/T_AAO_Armory/Javelin/Top.Top"), NULL, LOAD_None, NULL);
	MBitFailTex         = LoadObject<UTexture2D>(NULL, TEXT("/Game/AmericasArmy/Textures/T_AAO_Armory/Javelin/MSBon.MSBon"), NULL, LOAD_None, NULL);
	WFOV_Overlay        = LoadObject<UTexture2D>(NULL, TEXT("/Game/AmericasArmy/Textures/T_AAO_Armory/Javelin/Javelin_overlay_WFOV.Javelin_overlay_WFOV"), NULL, LOAD_None, NULL);
	NFOV_Overlay        = LoadObject<UTexture2D>(NULL, TEXT("/Game/AmericasArmy/Textures/T_AAO_Armory/Javelin/Javelin_overlay_NFOV.Javelin_overlay_NFOV"), NULL, LOAD_None, NULL);
	Seek_Overlay        = LoadObject<UTexture2D>(NULL, TEXT("/Game/AmericasArmy/Textures/T_AAO_Armory/Javelin/Javelin_overlay_seek.Javelin_overlay_seek"), NULL, LOAD_None, NULL);
	CrossHair           = LoadObject<UTexture2D>(NULL, TEXT("/Game/AmericasArmy/Textures/T_AAO_Armory/Javelin/CrossHair.CrossHair"), NULL, LOAD_None, NULL);
	TrackGate           = LoadObject<UTexture2D>(NULL, TEXT("/Game/AmericasArmy/Textures/T_AAO_Armory/Javelin/track_gate.track_gate"), NULL, LOAD_None, NULL);
	TrackGateX          = 16;
	TrackGateY          = 16;
	VisualFadeInTime    = -1;
	aZoomFOV            = { 21.25f, 9.44f };
	tZoomOverlay        = LoadObject<UTexture2D>(NULL, TEXT("/Game/AmericasArmy/Textures/T_AAO_Armory/Javelin/Javelin_overlay_DAY.Javelin_overlay_DAY"), NULL, LOAD_None, NULL);
	fZoomMultiplier     = 4;
	bInstantZoom        = true;
	bHasNVMode          = true;
}