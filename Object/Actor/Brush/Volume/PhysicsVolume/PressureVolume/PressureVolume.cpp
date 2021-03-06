// All the original content belonged to the US Army

#include "AA29/Object/Actor/Brush/Volume/PhysicsVolume/PressureVolume/PressureVolume.h"
#include "AA29/Object/DamageType/Depressurized/Depressurized.h"
#include "AA29/Object/Actor/Controller/AIController/ScriptedController/Bot/Bot.h"

APressureVolume::APressureVolume()
{
	DieFOV = 150;
	//DamageType = ADepressurized::StaticClass();
}

void APressureVolume::Trigger(AActor* Other, APawn* EventInstigator)
{
	AController* p = nullptr;
	/*
	Instigator=EventInstigator;
	if ((Instigator.Controller != nullptr) && Instigator.Controller->IsA(ABot::StaticClass()))
	{
		for (p=Level.ControllerList; p!=nullptr; p=p.nextController)
		{
			if (((p.Pawn != nullptr) && (p.Pawn.PhysicsVolume == this)) && (p.Pawn.Health > 0))
			{
				Instigator.Controller.Target=p.Pawn;
				Instigator.Controller.GotoState("VictoryDance");
			}
		}
	}
	TimePassed=0;
	bTriggered=true;
	bScreamed=false;
	Disable("Trigger");
	Enable("Tick");
	*/
}

void APressureVolume::Tick(float DeltaTime)
{
	float ratio = 0;
	float curScale = 0;
	FVector curFog = FVector(0, 0, 0);
	APlayerController* PC = nullptr;
	AController* p = nullptr;
	AController* Killer = nullptr;
	bool bActive = false;
	/*
	if (!bTriggered)
	{
		Disable("Tick");
		return;
	}
	TimePassed += DeltaTime;
	ratio = (TimePassed / KillTime);
	if (ratio > 1)
	{
		ratio = 1;
	}
	for (p = Level.ControllerList; p != nullptr; p = p.nextController)
	{
		if (((p.Pawn.PhysicsVolume == this) && (p.Pawn.Health > 0)) && (!p.Pawn.IsA("Spectator")))
		{
			bActive = true;
			p.Pawn.SetDrawScale((1 + ((DieDrawScale - 1) * ratio)));
			if ((((!bScreamed) && p.bIsPlayer) && (ratio > 0.2)) && (FMath::FRand() < (2 * DeltaTime)))
			{
				bScreamed = true;
				p.Pawn.PlayDyingSound();
			}
			PC = Cast<APlayerController>(p);
			if (PC != nullptr)
			{
				curScale = (((EndFlashScale - StartFlashScale) * ratio) + StartFlashScale);
				curFog = (((EndFlashFog - StartFlashFog) * ratio) + StartFlashFog);
				PC.ClientFlash(curScale, (float(1000) * curFog));
				PC.SetFOVAngle((((DieFOV - PC.Default.FovAngle) * ratio) + PC.Default.FovAngle));
			}
			if (ratio == 1)
			{
				if (Instigator != nullptr)
				{
					Killer = Instigator.Controller;
				}
				p.Pawn.Died(Killer, ADepressurized::StaticClass(), p.Pawn.Location);
				MakeNormal(p.Pawn);
			}
		}
	}
	if ((!bActive) && (TimePassed >= KillTime))
	{
		Disable("Tick");
		Enable("Trigger");
		bTriggered = false;
	}
	*/
}

void APressureVolume::MakeNormal(APawn* p)
{
	/*
	APlayerController* PC = nullptr;
	p.SetDrawScale(p.Default.DrawScale);
	PC = Cast<APlayerController>(p.Controller);
	if (PC != nullptr)
	{
		PC.SetFOVAngle(PC.Default.FovAngle);
	}
	*/
}

void APressureVolume::PawnLeavingVolume(APawn* Other)
{
	/*
	MakeNormal(Other);
	Super::PawnLeavingVolume(Other);
	*/
}
