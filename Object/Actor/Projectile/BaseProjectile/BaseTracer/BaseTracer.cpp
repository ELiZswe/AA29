// All the original content belonged to the US Army

#include "AA29/Object/Actor/Projectile/BaseProjectile/BaseTracer/BaseTracer.h"
#include "AA29/Object/Actor/Emitter/BaseTracerEmitter/BaseTracerEmitter.h"
#include "AA29/Object/Actor/Emitter/BaseTracerEmitter/GreenTracerEmitter/GreenTracerEmitter.h"
#include "Particles/Emitter.h"

ABaseTracer::ABaseTracer(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	//cEmitterFXClass = ABaseTracerEmitter::StaticClass()
	//cEnemyEmitterFXClass = AGreenTracerEmitter::StaticClass()
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
	AEmitter* newEmitterClass = nullptr;
	Super::PostNetBeginPlay();
	if (GetNetMode() != ENetMode::NM_DedicatedServer)
	{
		if (EmitterFX == nullptr)
		{
			/*
			if ((Default.cEnemyEmitterFXClass != nullptr) && IsEnemyProjectile())
			{
				newEmitterClass = Default.cEnemyEmitterFXClass;
			}
			else
			{
				newEmitterClass = Default.cEmitterFXClass;
			}
			EmitterFX = Spawn(newEmitterClass, this, , Location, Rotation);
			*/
		}
	}
}

void ABaseTracer::Collision(AActor* Other, FVector HitLocation, FVector HitNormal, UMaterialInstance* HitMaterial, ECollisionType Type)
{
	Destroy();
}
