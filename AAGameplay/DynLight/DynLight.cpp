// All the original content belonged to the US Army


#include "AA29/AAGameplay/DynLight/DynLight.h"
#include "Engine/SpotLight.h"

ADynLight::ADynLight()
{
	//LightType = 1;
	//LightSaturation = 255;
	//LightBrightness = 128;
	//LightRadius = 8;
	//LightPeriod = 32;
	//LightCone = 128;
	DrawType = EDrawType::DT_Sprite;
	//bLightingVisibility = false;
	//bUseDynamicLights = false;
	//bHidden = true;
	//bDynamicLight = true;
	//bAcceptsProjectors = false;
	//Texture = Texture'Engine.S_Light';
	//bShadowCast = false;
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


void ADynLight::BeginPlay()
{
	UWorld* const World = GetWorld();
	if (World)
	{
		FVector Location = GetActorLocation();
		FRotator Rotation = GetActorRotation();
		FActorSpawnParameters SpawnParams;
		SpawnParams.Owner = this;
		ASpotLight* const SpawningObject = World->SpawnActor<ASpotLight>(ASpotLight::StaticClass(), Location, Rotation, SpawnParams);
		SpawningObject->SetBrightness(20000);
		SpawningObject->SpotLightComponent->SetInnerConeAngle(8);
		SpawningObject->SpotLightComponent->SetOuterConeAngle(25);
		SpawningObject->SpotLightComponent->SetAttenuationRadius(5000);
	}
}

