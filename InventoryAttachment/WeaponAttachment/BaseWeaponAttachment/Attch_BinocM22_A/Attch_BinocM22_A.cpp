// All the original content belonged to the US Army


#include "Attch_BinocM22_A.h"
#include "AA29/InventoryAttachment/WeaponAttachment/BaseWeaponAttachment/Attch_BinocTank_A/Attch_BinocTank_A.h"

AAttch_BinocM22_A::AAttch_BinocM22_A()
{
	bAttachMILES          = false;
	EnemyAttachmentClass  = AAttch_BinocTank_A::StaticClass();
	StaticMesh            = LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AA2_Equipment/binoculars/eqp2_mil_bin_m22_3p.eqp2_mil_bin_m22_3p"), NULL, LOAD_None, NULL);
	RelativeRotation      = FRotator(0, -90, -90);
}



float AAttch_BinocM22_A::GetDrawScaleDecision(float PawnScale)
{
	//Log(Self @ "Attch_BinocM22_A::GetDrawScaleDecision Using value of 1.0 instead of PawnScale(" $ PawnScale $ ")");
	return 1;
}