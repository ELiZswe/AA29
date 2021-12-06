// All the original content belonged to the US Army


#include "AA29/Object/Actor/Volume/PhysicsVolume/PressureVolume/PressureVolume.h"

APressureVolume::APressureVolume()
{
	DieFOV = 150;
	//DamageType = class'GamePlay.Depressurized';
}

void APressureVolume::Trigger(AActor* Other, APawn* EventInstigator)
{
	/*
	local Controller p;
	Instigator = EventInstigator;
	if ((Instigator.Controller != None) && Instigator.Controller.IsA('Bot'))
	{
		p = Level.ControllerList;
		if (p != None)
		{
			if (((p.Pawn != None) && (p.Pawn.PhysicsVolume == Self)) && (p.Pawn.Health > 0))
			{
				Instigator.Controller.Target = p.Pawn;
				Instigator.Controller.GotoState('VictoryDance');
			}
			p = p.nextController;
		}
	}
	TimePassed = 0;
	bTriggered = true;
	bScreamed = false;
	Disable('Trigger');
	Enable('Tick');
	*/
}

void APressureVolume::Tick(float DeltaTime)
{
	/*
	float ratio = 0;
	float curScale = 0;
	FVector curFog = FVector(0, 0, 0);
	local PlayerController PC;
	local Controller p;
	local Controller Killer;
	bool bActive = false;
	if (!bTriggered)
	{
		Disable('Tick');
		return;
	}
	(TimePassed += DeltaTime);
	ratio = (TimePassed / KillTime);
	if (ratio > 1)
	{
		ratio = 1;
	}
	p = Level.ControllerList;
	if (p != None)
	{
		if (((p.Pawn.PhysicsVolume == Self) && (p.Pawn.Health > 0)) && (!p.Pawn.IsA('Spectator')))
		{
			bActive = true;
			p.Pawn.SetDrawScale((1 + ((DieDrawScale - 1) * ratio)));
			if ((((!bScreamed) && p.bIsPlayer) && (ratio > 0.2)) && (FRand() < (2 * DeltaTime)))
			{
				bScreamed = true;
				p.Pawn.PlayDyingSound();
			}
			PC = PlayerController(p);
			if (PC != None)
			{
				curScale = (((EndFlashScale - StartFlashScale) * ratio) + StartFlashScale);
				curFog = (((EndFlashFog - StartFlashFog) * ratio) + StartFlashFog);
				PC.ClientFlash(curScale, (float(1000) * curFog));
				PC.SetFOVAngle((((DieFOV - PC.Default.FovAngle) * ratio) + PC.Default.FovAngle));
			}
			if (ratio == 1)
			{
				if (Instigator != None)
				{
					Killer = Instigator.Controller;
				}
				p.Pawn.Died(Killer, class'GamePlay.Depressurized', p.Pawn.Location);
				MakeNormal(p.Pawn);
			}
		}
		p = p.nextController;
	}
	if ((!bActive) && (TimePassed >= KillTime))
	{
		Disable('Tick');
		Enable('Trigger');
		bTriggered = false;
	}
	*/
}

void APressureVolume::MakeNormal(APawn* p)
{
	/*
	local PlayerController PC;
	p.SetDrawScale(p.Default.DrawScale);
	PC = PlayerController(p.Controller);
	if (PC != None)
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