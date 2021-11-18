// All the original content belonged to the US Army


#include "Item_BinocNewt_B.h"

#include "AA29/BaseScope/Scope_BinocNewt_B.h"
#include "AA29/InventoryAttachment/WeaponAttachment/BaseWeaponAttachment/Attch_BinocNewt_B/Attch_BinocNewt_B.h"

AItem_BinocNewt_B::AItem_BinocNewt_B()
{
	InvBinocularsIndex  = 4;
	_cScopeClass        = AScope_BinocNewt_B::StaticClass();
	fWeight             = 1.1;
	AttachmentClass     = { AAttch_BinocNewt_B::StaticClass() };
	IconMaterial        = LoadObject<class UTexture2D>(NULL, TEXT("/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_binocs_newt.hud_binocs_newt"), NULL, LOAD_None, NULL);
	ItemName            = FString("Newtonian Binoculars");
	Mesh                = LoadObject<class USkeletalMesh>(NULL, TEXT("/Game/AmericasArmy/Animations/A_AA2_WeaponsUS/Binoculars_1P.Binoculars_1P"), NULL, LOAD_None, NULL);
}