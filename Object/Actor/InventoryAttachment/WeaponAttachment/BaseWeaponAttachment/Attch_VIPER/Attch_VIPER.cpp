// All the original content belonged to the US Army


#include "Attch_VIPER.h"
#include "AA29/Object/Actor/InventoryAttachment/WeaponAttachment/BaseWeaponAttachment/Attch_BinocM24_B/Attch_BinocM24_B.h"

AAttch_VIPER::AAttch_VIPER()
{
	bAttachMILES          = false;
	EnemyAttachmentClass  = AAttch_BinocM24_B::StaticClass();
	RelativeRotation      = FRotator(0, -90, -90);
}


float AAttch_VIPER::GetDrawScaleDecision(float PawnScale)
{
	return 1;
}