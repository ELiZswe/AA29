// All the original content belonged to the US Army

#include "AA29/Object/Actor/AAGameplay/EEBlackHawk_Collision/EEBlackHawk_Collision.h"

AEEBlackHawk_Collision::AEEBlackHawk_Collision()
{
	DrawType = EDrawType::DT_StaticMesh;
	
	if (StaticMesh)
	{
		StaticMesh->SetStaticMesh(LoadObject<UStaticMesh>(NULL, TEXT("StaticMesh'/Game/AmericasArmy/Meshes/M_AA2_Vehicles/blackhawk/veh_blackhawk_collision.veh_blackhawk_collision'"), NULL, LOAD_None, NULL));
		StaticMesh->SetReceivesDecals(false);
		StaticMesh->SetWorldScale3D(FVector(1.13, 1.13, 1.13));
	}

	//bUseDynamicLights = false;
	//bHidden = true:
	//bWorldGeometry = true;
	//DrawScale = 1.13;

	//Skins(0) = nullptr
	//Skins(1) = nullptr
	//Skins(2) = nullptr
	//Skins(3) = nullptr
	//Skins(4) = nullptr
	//bUnlit = true;
	//bCanTeleport = true;
	//bCollideWorld = false;

	//bUseCylinderCollision = false;
	//bBlockBulletTraces = false;
}
