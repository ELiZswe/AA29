// All the original content belonged to the US Army


#include "AmmoRound_556_Bullet.h"

AAmmoRound_556_Bullet::AAmmoRound_556_Bullet()
{
	StaticMesh = LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AA2_Weapons/Ammo1P/ammo_556.ammo_556"), NULL, LOAD_None, NULL);
}