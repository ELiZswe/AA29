// All the original content belonged to the US Army


#include "WAttch_MILESBox.h"

AWAttch_MILESBox::AWAttch_MILESBox()
{
	DrawType        = EDrawType::DT_StaticMesh;
	StaticMesh      = LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AA2_Weapons/weapons_3p/m-miles_weapon_3p.m-miles_weapon_3p"), NULL, LOAD_None, NULL);
	AttachmentBone  = "None";
}