// All the original content belonged to the US Army


#include "Item_BinocM22_A.h"
#include "AA29/BaseScope/Scope_BinocM22_A.h"
#include "AA29/InventoryAttachment/WeaponAttachment/BaseWeaponAttachment/Attch_BinocM22_A/Attch_BinocM22_A.h"

AItem_BinocM22_A::AItem_BinocM22_A()
{
	InvBinocularsIndex  = 1;
	_cScopeClass        = AScope_BinocM22_A::StaticClass();
	fWeight             = 0.85;
	AttachmentClass     = { AAttch_BinocM22_A::StaticClass() };
	IconMaterial        = LoadObject<class UTexture2D>(NULL, TEXT("/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_binocs_m22.hud_binocs_m22"), NULL, LOAD_None, NULL);
	ItemName            = FString("M22 Binoculars");
	Mesh                = LoadObject<class USkeletalMesh>(NULL, TEXT("/Game/AmericasArmy/Animations/A_AA2_WeaponsUS/M22Binocs_1P.M22Binocs_1P"), NULL, LOAD_None, NULL);
}