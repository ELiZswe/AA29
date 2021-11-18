// All the original content belonged to the US Army



#include "AmmoRound_PG7VR_Rocket.h"

AAmmoRound_PG7VR_Rocket::AAmmoRound_PG7VR_Rocket()
{
	StaticMesh = LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AA2_Weapons/Ammo1P/rpg7_pg7vr.rpg7_pg7vr"), NULL, LOAD_None, NULL);
}