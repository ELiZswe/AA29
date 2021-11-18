// All the original content belonged to the US Army


#include "AmmoRound_556_LinkedBullet.h"

AAmmoRound_556_LinkedBullet::AAmmoRound_556_LinkedBullet()
{
	StaticMesh = LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AA2_Weapons/Ammo1P/ammo_556_linked.ammo_556_linked"), NULL, LOAD_None, NULL);
}