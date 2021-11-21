// All the original content belonged to the US Army


#include "Shell_9x39_Emitter.h"

AShell_9x39_Emitter::AShell_9x39_Emitter()
{
	ShellDrawScale	= FVector(175, 175, 225);
	ShellStaticMesh	= LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AA2_FX/ammo3p/fx2_ammo_9x39_shell_3p.fx2_ammo_9x39_shell_3p"), NULL, LOAD_None, NULL);
};