// All the original content belonged to the US Army

#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/Item_Binoculars/Item_BinocM22_A/Item_BinocM22_A.h"
#include "AA29/Object/Actor/BaseScope/Scope_BinocM22_A/Scope_BinocM22_A.h"
#include "AA29/Object/Actor/InventoryAttachment/WeaponAttachment/BaseWeaponAttachment/Attch_BinocM22_A/Attch_BinocM22_A.h"

AItem_BinocM22_A::AItem_BinocM22_A()
{
	InvBinocularsIndex  = 1;
	_cScopeClass        = AScope_BinocM22_A::StaticClass();
	fWeight             = 0.85;
	AttachmentClass     = { AAttch_BinocM22_A::StaticClass() };
	IconMaterial = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_binocs_m22_Mat.hud_binocs_m22_Mat'"), NULL, LOAD_None, NULL);
	ItemName = "M22 Binoculars";
	Mesh = LoadObject<USkeletalMesh>(NULL, TEXT("SkeletalMesh'/Game/AmericasArmy/Animations/A_AA2_WeaponsUS/M22Binocs_1P.M22Binocs_1P'"), NULL, LOAD_None, NULL);
}
