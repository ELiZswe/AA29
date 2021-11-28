// All the original content belonged to the US Army


#include "Shell_556mm_Emitter.h"

AShell_556mm_Emitter::AShell_556mm_Emitter()
{
	ShellDrawScale = FVector(0.11, 0.11, 0.11);
	ShellStaticMesh = LoadObject<UStaticMesh>(NULL, TEXT("StaticMesh'/Game/AmericasArmy/Meshes/M_AA2_FX/Bullets/fx_bullets_m16shell.fx_bullets_m16shell'"), NULL, LOAD_None, NULL);
};