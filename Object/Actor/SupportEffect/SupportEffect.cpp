// All the original content belonged to the US Army


#include "AA29/Object/Actor/SupportEffect/SupportEffect.h"

// Sets default values
ASupportEffect::ASupportEffect()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	DropTime = 0.5;
	//LightType = 1;
	//LightEffect = 21;
	//LightHue = 160;
	//LightSaturation = 140;
	//LightBrightness = 255;
	//LightRadius = 12;
	//DrawType = DT_None;
	//bDynamicLight = true;
	bNetTemporary = true;
	bAlwaysRelevant = true;
	//bReplicateMovement = false;
	//bSkipActorPropertyReplication = true;
	//RemoteRole = ROLE_SimulatedProxy;
	//LifeSpan = 2;
	//TransientSoundVolume = 1;
	//TransientSoundRadius = 5000;
}

// Called when the game starts or when spawned
void ASupportEffect::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASupportEffect::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
/*
State Drop
{
	simulated Function BeginState()
	{
		StartTime = Level.TimeSeconds;
		SetTimer(DropTime,false);
	}
	simulated Function Tick(float dt)
	{
		float Delta = 0;
		Delta = FMin(((Level.TimeSeconds - StartTime) / DropTime),1);
	}
	simulated Function Timer()
	{
		GotoState('None');
	}
}
*/

void ASupportEffect::AimAt(FVector hl, FVector hn)
{
	/*
	HitLocation = hl;
	HitNormal = hn;
	if (Level.NetMode != NM_DedicatedServer)
	{
		SpawnEffects();
	}
	*/
}

void ASupportEffect::PostNetBeginPlay()
{
	/*
	if (Role < 4)
	{
		SpawnEffects();
	}
	*/
}

void ASupportEffect::SpawnEffects()
{
	//GotoState('Drop');
}