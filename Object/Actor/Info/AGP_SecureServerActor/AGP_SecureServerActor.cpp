// All the original content belonged to the US Army

#include "AA29/Object/Actor/Info/AGP_SecureServerActor/AGP_SecureServerActor.h"
#include "AA29/Object/Actor/Info/Mutator/AGP_Secure/AGP_Secure.h"

AAGP_SecureServerActor::AAGP_SecureServerActor()
{

}

void AAGP_SecureServerActor::BeginPlay()
{
	AAGP_Secure* mut = nullptr;
	/*
	PostBeginPlay();
	ForEach AllActors('AGP_Secure', mut)
	{
		return;
	}
	mut = Level.Spawn('AGP_Secure');
	mut.NextMutator = Level.Game.BaseMutator;
	Level.Game.BaseMutator = mut;
	*/
}
