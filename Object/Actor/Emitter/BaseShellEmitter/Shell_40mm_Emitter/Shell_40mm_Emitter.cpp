// All the original content belonged to the US Army


#include "Shell_40mm_Emitter.h"

AShell_40mm_Emitter::AShell_40mm_Emitter()
{
	ShellDrawScale = FVector(0.45, 0.45, 0.45);
	ShellStaticMesh = LoadObject<UStaticMesh>(NULL, TEXT("StaticMesh'/Game/AmericasArmy/Meshes/M_AA2_Weapons/Projectiles/m-m203_shell.m-m203_shell'"), NULL, LOAD_None, NULL);
	fPitchModifier = 0.5;
	bUseAnimNotifyEject = true;

};