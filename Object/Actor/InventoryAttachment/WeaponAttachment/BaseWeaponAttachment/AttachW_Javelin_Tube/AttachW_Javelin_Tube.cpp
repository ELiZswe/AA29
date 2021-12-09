// All the original content belonged to the US Army


#include "AttachW_Javelin_Tube.h"


AAttachW_Javelin_Tube::AAttachW_Javelin_Tube()
{
	TubeInHands                = LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AAO_Armory/Javelin/Tube3PIH.Tube3PIH"), NULL, LOAD_None, NULL);
	SlungWeaponLocationOffset  = FVector(2, 2, 0);
	_WeaponOffset3P            = FVector(0, 0, 0);
	EnemyAttachmentClass       = AAttachW_Javelin_Tube::StaticClass();
	StaticMesh                 = LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AAO_Armory/Javelin/Tube_OnBack.Tube_OnBack"), NULL, LOAD_None, NULL);
}