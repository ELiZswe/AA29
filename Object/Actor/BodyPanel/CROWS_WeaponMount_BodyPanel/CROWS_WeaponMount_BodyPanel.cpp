// All the original content belonged to the US Army

#include "AA29/Object/Actor/BodyPanel/CROWS_WeaponMount_BodyPanel/CROWS_WeaponMount_BodyPanel.h"

ACROWS_WeaponMount_BodyPanel::ACROWS_WeaponMount_BodyPanel()
{
	nmAttachBone = "B_Weapon";
	//StaticMesh = StaticMesh'M_AAO_Weapons.weapons_3p.m_weap_weapons3p_CROWS_weaponmount'
	//bCollideActors = false
	//bBlockActors = false
	//bBlockKarma = true
}
	
void ACROWS_WeaponMount_BodyPanel::PostNetBeginPlay()
{
	Super::PostNetBeginPlay();
	//if (Owner.AttachToBone(this, nmAttachBone))
	//{
	//	RelRotation = FRotator(16384 0 32768);
	//	SetRelativeRotation(RelRotation);
	//}
	//else
	//{
	//	Log("ATTACH FAILURE");
	//}
}
