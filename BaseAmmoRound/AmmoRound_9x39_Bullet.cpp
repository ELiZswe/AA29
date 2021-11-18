// All the original content belonged to the US Army


#include "AmmoRound_9x39_Bullet.h"

AAmmoRound_9x39_Bullet::AAmmoRound_9x39_Bullet()
{
	StaticMesh = LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AA2_Weapons/Ammo1P/ammo_9x39_bullet_1p.ammo_9x39_bullet_1p"), NULL, LOAD_None, NULL);
}