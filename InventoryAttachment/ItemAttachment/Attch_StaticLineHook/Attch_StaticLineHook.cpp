// All the original content belonged to the US Army


#include "Attch_StaticLineHook.h"

AAttch_StaticLineHook::AAttch_StaticLineHook()
{
	AttachBone          = "RHand";
	FriendlyStaticMesh  = LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AA2_Vehicles/C17/c17_jump_cable_handle.c17_jump_cable_handle"), NULL, LOAD_None, NULL);
	StaticMesh          = LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AA2_Vehicles/C17/c17_jump_cable_handle.c17_jump_cable_handle"), NULL, LOAD_None, NULL);
}