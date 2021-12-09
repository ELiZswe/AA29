// All the original content belonged to the US Army


#include "AA29/Object/Actor/StaticMeshActor/FlagMeshActor/FlagMeshActor.h"

AFlagMeshActor::AFlagMeshActor()
{
	//StaticMesh = StaticMesh'M_AA2_ES2.ES2_Objects.ES2_FlagMarker'
	
	UStaticMesh* MyMesh = LoadObject<UStaticMesh>(NULL, TEXT("StaticMesh'/Game/AmericasArmy/Meshes/M_AA2_ES2/ES2_Objects/ES2_FlagMarker.ES2_FlagMarker'"), NULL, LOAD_None, NULL);
	//bStatic = false;
	//bHidden = true;
	//bAlwaysRelevant = true;
	//RemoteRole = 2;
	//bCollideActors = false;

	if(MyMesh)
	{
		GetStaticMeshComponent()->SetStaticMesh(MyMesh);
	}
	
}