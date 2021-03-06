// All the original content belonged to the US Army

#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/Item_Binoculars/Item_BinocTank_A/Item_BinocTank_A.h"
#include "AA29/Object/Actor/BaseScope/Scope_BinocTank_A/Scope_BinocTank_A.h"
#include "AA29/Object/Actor/InventoryAttachment/WeaponAttachment/BaseWeaponAttachment/Attch_BinocTank_A/Attch_BinocTank_A.h"

AItem_BinocTank_A::AItem_BinocTank_A()
{
	InvBinocularsIndex  = 3;
	_cScopeClass        = AScope_BinocTank_A::StaticClass();
	fWeight             = 1.5;
	AttachmentClass     = { AAttch_BinocTank_A::StaticClass() };
	IconMaterial		= LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/HUD/hud_binocs_tank_Mat.hud_binocs_tank_Mat'"), NULL, LOAD_None, NULL);
	ItemName			= "Tank Binoculars";
	Mesh				= LoadObject<USkeletalMesh>(NULL, TEXT("SkeletalMesh'/Game/AmericasArmy/Animations/A_AA2_WeaponsUS/Binoculars_1P.Binoculars_1P'"), NULL, LOAD_None, NULL);
}
