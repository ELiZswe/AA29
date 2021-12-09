// All the original content belonged to the US Army


#include "AA29/Object/Actor/BodyPanel/CROWS_Camera_BodyPanel/CROWS_Camera_BodyPanel.h"

ACROWS_Camera_BodyPanel::ACROWS_Camera_BodyPanel()
{
	nmAttachBone = "B_Camera";
	//StaticMesh = StaticMesh'M_AAO_Weapons.weapons_3p.m_weap_weapons3p_CROWS_camera'
	//bCollideActors = False
	//bBlockActors = False
	//bBlockKarma = True
}

void ACROWS_Camera_BodyPanel::PostNetBeginPlay()
{
	//Super::PostNetBeginPlay();
	//Owner.AttachToBone(Self, nmAttachBone);
	//RelRotation = rot(16384 0 32768);
	//SetRelativeRotation(RelRotation);
}