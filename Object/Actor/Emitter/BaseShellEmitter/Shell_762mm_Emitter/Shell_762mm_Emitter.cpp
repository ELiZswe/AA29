// All the original content belonged to the US Army


#include "Shell_762mm_Emitter.h"

AShell_762mm_Emitter::AShell_762mm_Emitter()
{
	ShellDrawScale = FVector(0.14, 0.14, 0.14);
	ShellStaticMesh = LoadObject<UStaticMesh>(NULL, TEXT("StaticMesh'/Game/AmericasArmy/Meshes/M_AA2_FX/Bullets/fx_bullets_m16shell.fx_bullets_m16shell'"), NULL, LOAD_None, NULL);
};