// All the original content belonged to the US Army


#include "AmmoRound_545x39_Bullet.h"

AAmmoRound_545x39_Bullet::AAmmoRound_545x39_Bullet()
{
	StaticMesh = LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AA2_Weapons/Ammo1P/ammo_545x39_bullet_1p.ammo_545x39_bullet_1p"), NULL, LOAD_None, NULL);
}