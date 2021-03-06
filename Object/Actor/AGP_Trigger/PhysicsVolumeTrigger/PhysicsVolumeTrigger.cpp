// All the original content belonged to the US Army

#include "AA29/Object/Actor/AGP_Trigger/PhysicsVolumeTrigger/PhysicsVolumeTrigger.h"
#include "EngineUtils.h"
#include "GameFramework/PhysicsVolume.h"

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
	for (TActorIterator<APhysicsVolume> ActorIterator(GetWorld()); ActorIterator; ++ActorIterator)
	{
		APhysicsVolume* Actor = *ActorIterator;
		/*
		if (Actor->ActorHasTag(Event))
		{
			PV->Trigger(Other, EventInstigator);
		}
		*/
	}
}
