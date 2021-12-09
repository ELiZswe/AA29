// All the original content belonged to the US Army


#include "AmmoRound_BS1_30mm_Gren.h"

AAmmoRound_BS1_30mm_Gren::AAmmoRound_BS1_30mm_Gren()
{
	ExpendedSM = LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AA2_Weapons/Ammo1P/wpn2_ammo1p_bs1_nade.wpn2_ammo1p_bs1_nade"), NULL, LOAD_None, NULL);
	StaticMesh = LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AA2_Weapons/Ammo1P/wpn2_ammo1p_bs1_nade.wpn2_ammo1p_bs1_nade"), NULL, LOAD_None, NULL);
}