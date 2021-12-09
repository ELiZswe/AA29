// All the original content belonged to the US Army


#include "WAttch_BlankPlug.h"

AWAttch_BlankPlug::AWAttch_BlankPlug()
{
	DrawType        = EDrawType::DT_StaticMesh;
	StaticMesh      = LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AA2_Weapons/weapons_3p/m-blank_plug_3p.m-blank_plug_3p"), NULL, LOAD_None, NULL);
	AttachmentBone  = "None";
}