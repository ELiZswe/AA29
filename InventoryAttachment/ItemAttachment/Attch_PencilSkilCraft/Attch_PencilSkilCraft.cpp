// All the original content belonged to the US Army


#include "Attch_PencilSkilCraft.h"

AAttch_PencilSkilCraft::AAttch_PencilSkilCraft()
{
	AttachBone = "LHandObject";
	StaticMesh = LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AA2_Weapons/weapons_3p/m2_wpn_skilcraft_pencil.m2_wpn_skilcraft_pencil"), NULL, LOAD_None, NULL);
}