// All the original content belonged to the US Army

/* =================================================================================== *
* AGP class AmmoRound_3P_RPG7_Rocket
* Author: Ramm
* =================================================================================== *
*	This third person ammo round for the RPG.
* =================================================================================== */

#include "AmmoRound_3P_PG7VR_Rocket.h"

AAmmoRound_3P_PG7VR_Rocket::AAmmoRound_3P_PG7VR_Rocket()
{
	StaticMesh = LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AA2_Weapons/ammo3p/wpn2_ammo3p_pg7vr_unfired.wpn2_ammo3p_pg7vr_unfired"), NULL, LOAD_None, NULL);
}