// All the original content belonged to the US Army


#include "Shell_9mm_BS1_Emitter.h"

AShell_9mm_BS1_Emitter::AShell_9mm_BS1_Emitter()
{
	ShellDrawScale = FVector(15, 15,  1);
	ShellStaticMesh = LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AA2_FX/ammo3p/fx2_ammo_9mm_shell_casing_3p.fx2_ammo_9mm_shell_casing_3p"), NULL, LOAD_None, NULL);
	bUseAnimNotifyEject = true;
};