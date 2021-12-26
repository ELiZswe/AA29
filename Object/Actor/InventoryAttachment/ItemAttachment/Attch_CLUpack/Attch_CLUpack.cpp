// All the original content belonged to the US Army

#include "AA29/Object/Actor/InventoryAttachment/ItemAttachment/Attch_CLUpack/Attch_CLUpack.h"

AAttch_CLUpack::AAttch_CLUpack()
{
	EnemyStaticMesh     = LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AAO_Armory/Javelin/CluPouch.CluPouch"), NULL, LOAD_None, NULL);
	FriendlyStaticMesh  = LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AAO_Armory/Javelin/CluPouch.CluPouch"), NULL, LOAD_None, NULL);
	RelativeRotation    = FRotator (175.78125, 0, 8.23974609375);
}
