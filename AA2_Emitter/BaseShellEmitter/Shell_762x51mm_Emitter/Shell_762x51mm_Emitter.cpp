// All the original content belonged to the US Army


#include "Shell_762x51mm_Emitter.h"

AShell_762x51mm_Emitter::AShell_762x51mm_Emitter()
{
	ShellDrawScale = FVector(14, 14, 14);
	ShellStaticMesh = LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AA2_FX/Bullets/fx_bullets_m16shell.fx_bullets_m16shell"), NULL, LOAD_None, NULL);
	bUseAnimNotifyEject = true;
};