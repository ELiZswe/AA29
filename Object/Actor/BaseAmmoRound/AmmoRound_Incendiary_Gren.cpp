// All the original content belonged to the US Army


#include "AmmoRound_Incendiary_Gren.h"

AAmmoRound_Incendiary_Gren::AAmmoRound_Incendiary_Gren()
{
	ExpendedSM = LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AA2_Weapons/Ammo1P/wpn2_ammo1p_m203_40mmshell.wpn2_ammo1p_m203_40mmshell"), NULL, LOAD_None, NULL);
	StaticMesh = LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AA2_Weapons/Ammo1P/wpn2_ammo1p_m203_40mmround.wpn2_ammo1p_m203_40mmround"), NULL, LOAD_None, NULL);
}