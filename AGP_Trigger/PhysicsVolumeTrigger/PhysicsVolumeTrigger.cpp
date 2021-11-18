// All the original content belonged to the US Army


#include "AA29/AGP_Trigger/PhysicsVolumeTrigger/PhysicsVolumeTrigger.h"

APhysicsVolumeTrigger::APhysicsVolumeTrigger()
{
	//LightType = 1;
	//LightSaturation = 255;
	//LightRadius = 8;
	//LightPeriod = 32;
	//LightCone = 128;
	//bLightingVisibility = false;
	//bNoDelete = true;
	//bAcceptsProjectors = false;
	//bUnlit = true;
	//CollisionRadius = 32;
	//CollisionHeight = 32;
	//bCollideActors = false;
	//bBlockZeroExtentTraces = false;
	//bBlockNonZeroExtentTraces = false;
	//bBlockBulletTraces = false;
	//bBlockCoronaTraces = false;
	Texture = LoadObject<UTexture2D>(NULL, TEXT("Texture2D'/Game/AmericasArmy/Textures/Engine/S_Actor.S_Actor'"), NULL, LOAD_None, NULL);
	LoadEditorIcon();
}

void APhysicsVolumeTrigger::Trigger(AActor* Other, APawn* EventInstigator)
{
	/*
	local PhysicsVolume PV;
	ForEach AllActors(Class'PhysicsVolume', PV)
	{
		if (PV.Tag == Event)
		{
			PV.Trigger(Other, EventInstigator);
		}
	}
	*/
}