// All the original content belonged to the US Army

/* =================================================================================== *
* AGP - AmmoRound_3P_RPG7_Rocket
* Author: Ramm
* =================================================================================== *
*	This third person ammo round for the RPG.
* =================================================================================== */


#include "AmmoRound_3P_RPG7_Rocket.h"

AAmmoRound_3P_RPG7_Rocket::AAmmoRound_3P_RPG7_Rocket()
{
	StaticMesh = LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AA2_Weapons/ammo3p/wpn2_ammo3p_rpg7round_unfired.wpn2_ammo3p_rpg7round_unfired"), NULL, LOAD_None, NULL);
}