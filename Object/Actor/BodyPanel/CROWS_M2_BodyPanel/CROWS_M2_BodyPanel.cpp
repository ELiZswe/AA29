// All the original content belonged to the US Army

#include "AA29/Object/Actor/BodyPanel/CROWS_M2_BodyPanel/CROWS_M2_BodyPanel.h"

ACROWS_M2_BodyPanel::ACROWS_M2_BodyPanel()
{
	nmAttachBone = "B_Weapon";
	//StaticMesh = StaticMesh'M_AAO_Weapons.weapons_3p.m_weap_weapons3p_CROWS_m2'
	//bCollideActors = false
	//bBlockActors = false
	//bBlockKarma = true
}

void ACROWS_M2_BodyPanel::PostNetBeginPlay()
{
	Super::PostNetBeginPlay();
	//Owner.AttachToBone(this, nmAttachBone);
	//RelRotation = FRotator(16384 0 32768);
	//SetRelativeRotation(RelRotation);
}
