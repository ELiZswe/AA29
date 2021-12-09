// All the original content belonged to the US Army


#include "Item_BinocM24_B.h"

#include "AA29/Object/Actor/BaseScope/Scope_BinocM24_B/Scope_BinocM24_B.h"
#include "AA29/Object/Actor/InventoryAttachment/WeaponAttachment/BaseWeaponAttachment/Attch_BinocM24_B/Attch_BinocM24_B.h"


AItem_BinocM24_B::AItem_BinocM24_B()
{
	InvBinocularsIndex  = 2;
	_cScopeClass        = AScope_BinocM24_B::StaticClass();
	fWeight             = 0.38;
	AttachmentClass     = { AAttch_BinocM24_B::StaticClass() };
	IconMaterial        = LoadObject<class UTexture2D>(NULL, TEXT("/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_wpn_ak47.hud_wpn_ak47"), NULL, LOAD_None, NULL);
	ItemName            = FString("SpecOp Binoculars");
	Mesh                = LoadObject<class USkeletalMesh>(NULL, TEXT("/Game/AmericasArmy/Animations/A_AA2_WeaponsUS/Binoculars_1P.Binoculars_1P"), NULL, LOAD_None, NULL);
}