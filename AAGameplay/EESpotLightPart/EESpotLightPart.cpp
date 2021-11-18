// All the original content belonged to the US Army


#include "AA29/AAGameplay/EESpotLightPart/EESpotLightPart.h"

AEESpotLightPart::AEESpotLightPart()
{
	DrawType = EDrawType::DT_StaticMesh;

	//StaticMesh = StaticMesh'M_AA2_Lights.exterior.spot-light';
	
	StaticMesh->SetStaticMesh(LoadObject<UStaticMesh>(NULL, TEXT("StaticMesh'/Game/AmericasArmy/Meshes/M_AA2_Lights/exterior/spot-light.spot-light'"), NULL, LOAD_None, NULL));
	StaticMesh->SetCastShadow(false);
	// 
	//bUseDynamicLights = false;
	//bAcceptsProjectors = false;
	//Physics = 8;
	//bShadowCast = false;
	//CollisionRadius = 1;
	//CollisionHeight = 1;
	//bCollideWorld = false;
	//bBlockActors = false;
	//bBlockPlayers = false;
	//bProjTarget = false;
	//bBlockNonZeroExtentTraces = false;
	//bUseCylinderCollision = false;
	//bBlockBulletTraces = false;
	//bRotateToDesired = true;
}