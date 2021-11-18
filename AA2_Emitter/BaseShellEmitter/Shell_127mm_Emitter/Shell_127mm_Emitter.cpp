// All the original content belonged to the US Army


#include "Shell_127mm_Emitter.h"

AShell_127mm_Emitter::AShell_127mm_Emitter()
{
	ShellDrawScale	= FVector(115, 115, 115);
	ShellStaticMesh = LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AA2_FX/Bullets/fx_bullets_m82_shell.fx_bullets_m82_shell"), NULL, LOAD_None, NULL);
	fPitchModifier	= 0.85;
};