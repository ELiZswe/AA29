// All the original content belonged to the US Army


#include "Attch_BinocM24_B.h"
#include "AA29/Object/Actor/InventoryAttachment/WeaponAttachment/BaseWeaponAttachment/Attch_BinocNewt_B/Attch_BinocNewt_B.h"

AAttch_BinocM24_B::AAttch_BinocM24_B()
{
	bAttachMILES          = false;
	EnemyAttachmentClass  = AAttch_BinocNewt_B::StaticClass();
	StaticMesh            = LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AA2_Equipment/binoculars/eqp2_mil_bin_m22_3p.eqp2_mil_bin_m22_3p"), NULL, LOAD_None, NULL);
	RelativeRotation      = FRotator(0, -90, -90);
}



float AAttch_BinocM24_B::GetDrawScaleDecision(float PawnScale)
{
	//Log(Self @ "Attch_BinocM24_B::GetDrawScaleDecision Using value of 1.0 instead of PawnScale(" $ PawnScale $ ")");
	return 1;
}