// All the original content belonged to the US Army

#include "AA29/Object/Actor/Emitter/EmitterSpawner/EmitterSpawner.h"
#include "AA29/Object/Actor/Pawn/Vehicle/Vehicle.h"
#include "Particles/Emitter.h"

AEmitterSpawner::AEmitterSpawner()
{
	ShakeRotMag = FVector(0, 0, 50);
	ShakeRotRate = FVector(0, 0, 500);
	ShakeRotTime = 10;
	ShakeOffsetMag = FVector(0, 0, 2);
	ShakeOffsetRate = FVector(0, 0, 50);
	ShakeOffsetTime = 8;
	//RemoteRole = ROLE_SimulatedProxy;
}

/*
replication
{
	reliable if ((Role == ROLE_Authority))
		bDoDestroy;
}
*/

void AEmitterSpawner::Trigger(AActor* Other, APawn* EventInstigator)
{
	int32 i = 0;
	AEmitter* E = nullptr;
	//Super::Trigger(Other, EventInstigator);
	/*
	for (i = 0; i < MyEmitterClasses.Num(); i++)
	{
		if (EmitterSound != nullptr)
		{
			PlayOwnedSound(EmitterSound, , (3 * TransientSoundVolume));
		}
		E = Spawn(MyEmitterClasses[i]);
		if (E != nullptr)
		{
			E.SetShowTeam(ShowTeam);
			MyEmitters.Num() = (MyEmitters.Num() + 1);
			MyEmitters[(MyEmitters.Num() - 1)] = E;
		}
		if (bShakeView)
		{
			ShakeView();
		}
		if (Damage > 0)
		{
			RadiusDamage(float(Damage), DamageRadius, DamageType, MomentumTransfer, Location);
		}
	}
	*/
}

void AEmitterSpawner::ShakeView()
{
	AController* C = nullptr;
	APlayerController* PC = nullptr;
	float dist = 0;
	float Scale = 0;
	/*
	for (C=Level.ControllerList; C!=nullptr; C=C.nextController)
	{
		PC=Cast<APlayerController>(C);
		if (((PC != nullptr) && (PC.ViewTarget != nullptr)) && (PC.ViewTarget.Base != nullptr))
		{
			dist=VSize((Location - PC.ViewTarget.Location));
			if (dist < (DamageRadius * 2))
			{
				if (dist < DamageRadius)
				{
					Scale=1;
				}
				else
				{
					Scale=(((DamageRadius * 2) - dist) / DamageRadius);
				}
				C.ShakeView((ShakeRotMag * Scale),ShakeRotRate,ShakeRotTime,(ShakeOffsetMag * Scale),ShakeOffsetRate,ShakeOffsetTime);
			}
		}
	}
	*/
}

void AEmitterSpawner::RadiusDamage(float DamageAmount, float aDamageRadius, UaDamageType* aDamageType, float Momentum, FVector HitLocation, float aKillRadius)
{
	AActor* Victim = nullptr;
	float damageScale = 0;
	float dist = 0;
	FVector Dir = FVector(0, 0, 0);
	float HitDamage = 0;
	/*
	ForEach RadiusActors(Class'Actor', Victim, aDamageRadius, HitLocation)
	{
		if ((Victim.Role == 4) && (!Victim.bHidden))
		{
			Dir = (Victim.Location - HitLocation);
			dist = FMax(1, VSize(Dir));
			Dir = (Dir / dist);
			damageScale = (1 - FMax(0, ((dist - Victim.CollisionRadius) / aDamageRadius)));
			HitDamage = (damageScale * DamageAmount);
			if (Victim->IsA(AVehicle::StaticClass()))
			{
				if (Cast<AVehicle>(Victim).TakeRadiusDamage(DamageAmount, Instigator, HitLocation, Momentum, aDamageType, aDamageRadius))
				{
					continue;
				}
			}
			if (((Cast<APawn>(Victim) != nullptr) && (Cast<APawn>(Victim).Controller == nullptr)) && (Cast<APawn>(Victim).DrivenVehicle != nullptr))
			{
				continue;
			}
			Victim.TakeDamage(int((damageScale * DamageAmount)), Instigator, (Victim.Location - ((0.5 * (Victim.CollisionHeight + Victim.CollisionRadius)) * Dir)), ((damageScale * Momentum) * Dir), aDamageType, , , this);
		}
	}
	*/
}

void AEmitterSpawner::MatchStarting()
{
	/*
	Super::MatchStarting();
	bDoDestroy = true;
	*/
}

void AEmitterSpawner::Destroyed()
{
	/*
	Super::Destroyed();
	DestroyMyEmitters();
	*/
}

void AEmitterSpawner::DestroyMyEmitters()
{
	/*
	int32 i = 0;
	for (i = 0; i < MyEmitters.Num(); i++)
	{
		MyEmitters[i].Destroy();
	}
	MyEmitters.RemoveAt(0, MyEmitters.Num());
	*/
}

void AEmitterSpawner::Tick(float DeltaTime)
{
	/*
	Super::Tick(DeltaTime);
	if (bDoDestroy)
	{
		bDoDestroy = false;
		DestroyMyEmitters();
	}
	*/
}
