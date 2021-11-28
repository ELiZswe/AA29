// All the original content belonged to the US Army


#include "Shell_9mm_Emitter.h"

AShell_9mm_Emitter::AShell_9mm_Emitter()
{
	ShellDrawScale = FVector(1, 1, 1);
	ShellStaticMesh = LoadObject<UStaticMesh>(NULL, TEXT("StaticMesh'/Game/AmericasArmy/Meshes/M_AA2_FX/ammo3p/fx2_ammo_9mm_shell_casing_3p.fx2_ammo_9mm_shell_casing_3p'"), NULL, LOAD_None, NULL);
};