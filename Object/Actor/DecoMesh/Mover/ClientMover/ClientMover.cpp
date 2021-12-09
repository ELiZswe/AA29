// All the original content belonged to the US Army


#include "AA29/Object/Actor/DecoMesh/Mover/ClientMover/ClientMover.h"

AClientMover::AClientMover()
{
	bAlwaysRelevant = false;
	//RemoteRole = 0;
	//bClientAuthoritative = true;
}

/*
State ServerIdle
{
}
*/
void AClientMover::PostBeginPlay()
{
	/*
	PostBeginPlay();
	if (Level.NetMode == 1)
	{
		GotoState('ServerIdle');
		SetTimer(0, False);
		SetPhysics(0);
	}
	*/
}