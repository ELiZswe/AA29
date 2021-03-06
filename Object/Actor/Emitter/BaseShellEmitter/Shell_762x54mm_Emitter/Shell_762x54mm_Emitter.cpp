// All the original content belonged to the US Army

#include "AA29/Object/Actor/Emitter/BaseShellEmitter/Shell_762x54mm_Emitter/Shell_762x54mm_Emitter.h"

AShell_762x54mm_Emitter::AShell_762x54mm_Emitter()
{
	ShellDrawScale = FVector(0.14, 0.14, 0.14);
	ShellStaticMesh = LoadObject<UStaticMesh>(NULL, TEXT("StaticMesh'/Game/AmericasArmy/Meshes/M_AA2_FX/Bullets/fx_bullets_m16shell.fx_bullets_m16shell'"), NULL, LOAD_None, NULL);
	bUseAnimNotifyEject = true;
};
