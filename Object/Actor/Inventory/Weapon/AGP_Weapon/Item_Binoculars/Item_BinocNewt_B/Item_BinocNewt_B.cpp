// All the original content belonged to the US Army

#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/Item_Binoculars/Item_BinocNewt_B/Item_BinocNewt_B.h"

#include "AA29/Object/Actor/BaseScope/Scope_BinocNewt_B/Scope_BinocNewt_B.h"
#include "AA29/Object/Actor/InventoryAttachment/WeaponAttachment/BaseWeaponAttachment/Attch_BinocNewt_B/Attch_BinocNewt_B.h"

AItem_BinocNewt_B::AItem_BinocNewt_B()
{
	InvBinocularsIndex	= 4;
	_cScopeClass		= AScope_BinocNewt_B::StaticClass();
	fWeight				= 1.1;
	AttachmentClass		= { AAttch_BinocNewt_B::StaticClass() };
	IconMaterial		= LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_binocs_newt_Mat.hud_binocs_newt_Mat'"), NULL, LOAD_None, NULL);
	ItemName			= "Newtonian Binoculars";
	Mesh				= LoadObject<USkeletalMesh>(NULL, TEXT("SkeletalMesh'/Game/AmericasArmy/Animations/A_AA2_WeaponsUS/Binoculars_1P.Binoculars_1P'"), NULL, LOAD_None, NULL);
}
