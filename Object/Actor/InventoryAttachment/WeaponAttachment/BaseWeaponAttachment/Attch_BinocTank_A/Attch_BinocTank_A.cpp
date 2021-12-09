// All the original content belonged to the US Army


#include "Attch_BinocTank_A.h"
#include "AA29/Object/Actor/InventoryAttachment/WeaponAttachment/BaseWeaponAttachment/Attch_BinocM22_A/Attch_BinocM22_A.h"

AAttch_BinocTank_A::AAttch_BinocTank_A()
{
	bAttachMILES          = false;
	EnemyAttachmentClass  = AAttch_BinocM22_A::StaticClass();
	StaticMesh            = LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AA2_Equipment/binoculars/eqp2_mil_bin_tank_3p.eqp2_mil_bin_tank_3p"), NULL, LOAD_None, NULL);
	RelativeRotation      = FRotator(0, -90, -90);
}

float AAttch_BinocTank_A::GetDrawScaleDecision(float PawnScale)
{
	//Log(Self @ "Attch_BinocTank_A::GetDrawScaleDecision Using value of 1.0 instead of PawnScale(" $ PawnScale $ ")");
	return 1;
}