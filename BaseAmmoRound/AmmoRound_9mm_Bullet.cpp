// All the original content belonged to the US Army


#include "AmmoRound_9mm_Bullet.h"

AAmmoRound_9mm_Bullet::AAmmoRound_9mm_Bullet()
{
	bHasBreechRound  = true;
	StaticMesh       = LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AA2_Weapons/Ammo1P/9mm_ammo_1p.9mm_ammo_1p"), NULL, LOAD_None, NULL);
}
