// All the original content belonged to the US Army


#include "AttachW_PG7VR_Rocket.h"
#include "AA29/Object/Actor/Base3pAmmoRound/AmmoRound_3P_PG7VR_Rocket.h"
#include "AA29/Object/Actor/InventoryAttachment/WeaponAttachment/BaseWeaponAttachment/RocketWeaponAttachment/AttachW_BDM_Rocket/AttachW_BDM_Rocket.h"

AAttachW_PG7VR_Rocket::AAttachW_PG7VR_Rocket()
{
	ThirdPersonAmmoRoundClass  = AAmmoRound_3P_PG7VR_Rocket::StaticClass();
	EnemyAttachmentClass       = AAttachW_BDM_Rocket::StaticClass();
}