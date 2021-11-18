// All the original content belonged to the US Army


#include "AA29/AAGameplay/DebugSphere/DebugSphere.h"

ADebugSphere::ADebugSphere()
{
	DrawType = EDrawType::DT_StaticMesh;

	//StaticMesh = StaticMesh'Editor.TexPropSphere';
	StaticMesh->SetStaticMesh(LoadObject<UStaticMesh>(NULL, TEXT("StaticMesh'/Game/AmericasArmy/Meshes/Editor/TexPropSphere.TexPropSphere'"), NULL, LOAD_None, NULL));
	StaticMesh->SetCastShadow(false);
	//bAcceptsProjectors = false;
	//Physics = 5;
	//bUnlit = true;
	//bShouldBaseAtStartup = true;
	//bCanTeleport = true;
	//CollisionRadius = 1
	//CollisionHeight = 1
	//bCollideActors = false;
	//bCollideWorld = false;
	//bBlockActors = false;
	//bBlockPlayers = false;
	//bProjTarget = false;
	//bBlockZeroExtentTraces = false;
	//bBlockNonZeroExtentTraces = false;
	//bBlockBulletTraces = false;
	//bBlockCoronaTraces = false;
	//bFixedRotationDir = true;
	//bDirectional = false;
}
