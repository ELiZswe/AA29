// All the original content belonged to the US Army


#include "AmmoRound_40mm_Gren.h"

AAmmoRound_40mm_Gren::AAmmoRound_40mm_Gren()
{
	ExpendedSM = LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AA2_Weapons/Ammo1P/wpn2_ammo1p_m203_40mmshell.wpn2_ammo1p_m203_40mmshell"), NULL, LOAD_None, NULL);
	StaticMesh = LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AA2_Weapons/Ammo1P/wpn2_ammo1p_m203_40mmround.wpn2_ammo1p_m203_40mmround"), NULL, LOAD_None, NULL);
}