// All the original content belonged to the US Army

#include "BaseTracer.h"

ABaseTracer::ABaseTracer(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	//cEmitterFXClass = Class'AGP_Effects.BaseTracerEmitter'
	//cEnemyEmitterFXClass = Class'AGP_Effects.GreenTracerEmitter'
}

void ABaseTracer::Destroyed()
{
	Super::Destroyed();
	if (EmitterFX != nullptr)
	{
		//EmitterFX->Destroy();
		EmitterFX = nullptr;
	}
}

void ABaseTracer::PostNetBeginPlay()
{
	/*
	local class<Emitter>  newEmitterClass;
	Super::PostNetBeginPlay();
	if (Level.NetMode != NM_DedicatedServer)
	{
		if (EmitterFX == None)
		{
			if ((Default.cEnemyEmitterFXClass != None) && IsEnemyProjectile())
			{
				newEmitterClass = Default.cEnemyEmitterFXClass;
			}
			else
			{
				newEmitterClass = Default.cEmitterFXClass;
			}
			EmitterFX = Spawn(newEmitterClass, Self, , Location, Rotation);
		}
	}
	*/
}

void ABaseTracer::Collision(AActor* Other, FVector HitLocation, FVector HitNormal, UMaterialInstance* HitMaterial, ECollisionType Type)
{
	Destroy();
}
