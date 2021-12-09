// All the original content belonged to the US Army

/* =================================================================================== *
* AGP class AmmoRound_3P_RPG7_Rocket
* Author: Ramm
* =================================================================================== *
*	This third person ammo round for the RPG.
* =================================================================================== */	

#include "AmmoRound_RPG7_Rocket.h"

AAmmoRound_RPG7_Rocket::AAmmoRound_RPG7_Rocket()
{
	StaticMesh = LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AA2_Weapons/Ammo1P/rpg7_pg7v.rpg7_pg7v"), NULL, LOAD_None, NULL);
}