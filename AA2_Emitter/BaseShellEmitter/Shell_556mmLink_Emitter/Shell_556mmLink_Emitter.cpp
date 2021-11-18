// All the original content belonged to the US Army


#include "Shell_556mmLink_Emitter.h"

AShell_556mmLink_Emitter::AShell_556mmLink_Emitter()
{
	ShellDrawScale = FVector( 1,  1, 1);
	ShellStaticMesh = LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AA2_Weapons/Ammo1P/ammo_556_link.ammo_556_link"), NULL, LOAD_None, NULL);
};