// All the original content belonged to the US Army


#include "Item_VIPER.h"
#include "AA29/InventoryAttachment/WeaponAttachment/BaseWeaponAttachment/Attch_VIPER/Attch_VIPER.h"
#include "AA29/BaseScope/Scope_VIPER.h"

AItem_VIPER::AItem_VIPER()
{
		//SupportClass = Class'AGP_Gameplay.F18AirStrike'
	TraceRange          = 18000;
	PaintDuration       = 1.2;
	TAGFireForce        = "TAGFireA";
	TAGMarkForce        = "TAGFireB";
	TAGAquiredForce     = "TAGAquire";
	InvBinocularsIndex  = 5;
	_cScopeClass        = AScope_VIPER::StaticClass();
	fWeight             = 0.85;
	AttachmentClass     = { AAttch_VIPER::StaticClass() };
	IconMaterial        = LoadObject<class UTexture2D>(NULL, TEXT("/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_binocs_VIPIR.hud_binocs_VIPIR"), NULL, LOAD_None, NULL);
	ItemName            = "Vector IV-Binocular Laser Range Finder";
}