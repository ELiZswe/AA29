// All the original content belonged to the US Army


#include "AA29/AAGameplay/BHM134A/BHM134A.h"

ABHM134A::ABHM134A()
{
	//bUseDynamicLights = false;
	//bAcceptsProjectors = false;
	//Mesh = SkeletalMesh'A_AA2_Weapons3P.m134_3P';
	SkeletalMesh->SetSkeletalMesh(LoadObject<USkeletalMesh>(NULL, TEXT("SkeletalMesh'/Game/AmericasArmy/Animations/A_AA2_Weapons3P/m134_3P.m134_3P'"), NULL, LOAD_None, NULL));
	//DrawScale = 1.13;
	//bShadowCast = false;
	//bCanTeleport = true;
	//CollisionRadius = 1;
	//CollisionHeight = 1;
	//bCollideActors = false;
	//bCollideWorld = false;
	//bBlockActors = false;
	//bBlockPlayers = false;
	//bProjTarget = false;
	//bBlockZeroExtentTraces = false;
	//bBlockNonZeroExtentTraces = false;
	//bUseCylinderCollision = false;
	//bBlockBulletTraces = false;
	//bBlockCoronaTraces = false;
}