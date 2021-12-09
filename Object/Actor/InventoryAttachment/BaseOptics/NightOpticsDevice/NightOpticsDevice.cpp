// All the original content belonged to the US Army


#include "NightOpticsDevice.h"

// Sets default values
ANightOpticsDevice::ANightOpticsDevice()
{
	SwitchOnSound       = LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_Foley/Nightvision/NOD_on.NOD_on"), NULL, LOAD_None, NULL);
	SwitchOffSound      = LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_Foley/Nightvision/NOD_off.NOD_off"), NULL, LOAD_None, NULL);
	NightVisionTexture  = LoadObject<UTexture2D>(NULL, TEXT("/Game/AmericasArmy/Textures/T_AA2_FX/Optics/Nightvision1.Nightvision1"), NULL, LOAD_None, NULL);
	NightVisionOverlay  = LoadObject<UTexture2D>(NULL, TEXT("/Game/AmericasArmy/Textures/T_AA2_FX/Optics/Nightvision_overlay.Nightvision_overlay"), NULL, LOAD_None, NULL);
	NVG_Up              = LoadObject<UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AA2_Attachments/us-soldier/m-nvg_up.m-nvg_up"), NULL, LOAD_None, NULL);
	NVG_Down            = LoadObject<UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AA2_Attachments/us-soldier/m-nvg_dwn.m-nvg_dwn"), NULL, LOAD_None, NULL);
	DrawType            = EDrawType::DT_StaticMesh;
}