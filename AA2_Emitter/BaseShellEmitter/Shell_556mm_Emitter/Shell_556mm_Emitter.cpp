// All the original content belonged to the US Army


#include "Shell_556mm_Emitter.h"

AShell_556mm_Emitter::AShell_556mm_Emitter()
{
	ShellDrawScale = FVector(11, 11,  11);
	ShellStaticMesh = LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AA2_FX/Bullets/fx_bullets_m16shell.fx_bullets_m16shell"), NULL, LOAD_None, NULL);
};