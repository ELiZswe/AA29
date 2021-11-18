// All the original content belonged to the US Army


#include "AA29/BodyPanel/CROWS_Main_BodyPanel/CROWS_Main_BodyPanel.h"

ACROWS_Main_BodyPanel::ACROWS_Main_BodyPanel()
{
	nmAttachBone = "B_Base";
	//StaticMesh = StaticMesh'M_AAO_Weapons.weapons_3p.m_weap_weapons3p_CROWS_main'
	//bCollideActors = False
	//bBlockActors = False
	//bBlockKarma = True
}
void ACROWS_Main_BodyPanel::PostNetBeginPlay()
{
	//Super::PostNetBeginPlay();
	//Owner.AttachToBone(Self, nmAttachBone);
	//RelRotation = rot(16384 0 32768);
	//SetRelativeRotation(RelRotation);
}