// All the original content belonged to the US Army


#include "Item_BinocTank_A.h"
#include "AA29/BaseScope/Scope_BinocTank_A.h"
#include "AA29/InventoryAttachment/WeaponAttachment/BaseWeaponAttachment/Attch_BinocTank_A/Attch_BinocTank_A.h"

AItem_BinocTank_A::AItem_BinocTank_A()
{
	InvBinocularsIndex  = 3;
	_cScopeClass        = AScope_BinocTank_A::StaticClass();
	fWeight             = 1.5;
	AttachmentClass     = { AAttch_BinocTank_A::StaticClass() };
	IconMaterial        = LoadObject<class UTexture2D>(NULL, TEXT("/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_wpn_ak47.hud_wpn_ak47"), NULL, LOAD_None, NULL);
	ItemName            = FString("Tank Binoculars");
	Mesh                = LoadObject<class USkeletalMesh>(NULL, TEXT("/Game/AmericasArmy/Animations/A_AA2_WeaponsUS/Binoculars_1P.Binoculars_1P"), NULL, LOAD_None, NULL);
}