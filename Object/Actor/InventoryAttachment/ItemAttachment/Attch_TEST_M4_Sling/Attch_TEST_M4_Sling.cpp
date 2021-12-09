// All the original content belonged to the US Army


#include "Attch_TEST_M4_Sling.h"

AAttch_TEST_M4_Sling::AAttch_TEST_M4_Sling()
{
	AttachBone          = "ChestSlungWeapon";
	FriendlyStaticMesh  = LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AA2_Weapons/weapons_3p/m-m4a1_mod_3p.m-m4a1_mod_3p"), NULL, LOAD_None, NULL);
	StaticMesh          = LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AA2_Weapons/weapons_3p/m-m4a1_mod_3p.m-m4a1_mod_3p"), NULL, LOAD_None, NULL);
	RelativeRotation    = FRotator (-90, 0, 0);
}