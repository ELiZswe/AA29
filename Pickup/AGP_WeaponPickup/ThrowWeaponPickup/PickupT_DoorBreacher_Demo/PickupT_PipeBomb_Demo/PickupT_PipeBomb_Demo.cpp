// All the original content belonged to the US Army


#include "PickupT_PipeBomb_Demo.h"

APickupT_PipeBomb_Demo::APickupT_PipeBomb_Demo()
{
	liveStaticMesh		= LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AA2_Weapons/weapons_3p/wpn2_pipebomb_3p.wpn2_pipebomb_3p"), NULL, LOAD_None, NULL);
	EnemyPickupClass	= APickupT_DoorBreacher_Demo::StaticClass();
	//StaticMesh			= LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AA2_Weapons/weapons_3p/wpn2_pipebomb_3p.wpn2_pipebomb_3p"), NULL, LOAD_None, NULL);
	VisibleStaticMesh->SetStaticMesh(LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AA2_Weapons/weapons_3p/wpn2_pipebomb_3p.wpn2_pipebomb_3p"), NULL, LOAD_None, NULL));
	RelativeRotation	= FRotator(0, 89.989013671875, -175.78125);
}