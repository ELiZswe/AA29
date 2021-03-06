// All the original content belonged to the US Army

#include "AA29/Object/Actor/SideEffect/SideEffectSlow/SideEffectSlow.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Pawn.h"
#include "AA29/Object/Actor/SideEffect/SideEffect.h"

ASideEffectSlow::ASideEffectSlow()
{
	SpeedPenalty        = 0.625;
	FadeTimeProportion  = 0.5;
	bServerEffect       = true;
}

bool ASideEffectSlow::OverrideEffects()
{
	ASideEffect* SE = nullptr;
	bool bCollisionFound = false;
	bCollisionFound = false;
	/*
	ForEach AllActors(ASideEffect::StaticClass(), SE)
	{
		if (((SE != Self) && SE->IsA(ASideEffectSlow::StaticClass())) && (SE.Owner == this.Owner))
		{
			bCollisionFound = true;
			if (bReplaceExtantEffects)
			{
				SE.End();
			}
		}
	}
	*/
	return bCollisionFound;
}

void ASideEffectSlow::ScaleByDamage(int32 Damage)
{
	EffectDuration = (EffectDuration + (float(Damage) / 100));
	SpeedPenalty = (SpeedPenalty - (float(Damage) / 400));
}

void ASideEffectSlow::Start()
{
	AController* AffectedController = nullptr;
	/*
	Super::Start();
	AffectedController = Cast<AController>(GetOwner());
	if (AffectedController != nullptr)
	{
		AffectedPawn = Cast<AAGP_Pawn>(AffectedController.Pawn);
		if (AffectedPawn != nullptr)
		{
			OldSpeedPenalty = AffectedPawn.fSpeedPenalty;
			AffectedPawn.fSpeedPenalty = SpeedPenalty;
		}
	}
	*/
}

void ASideEffectSlow::update(float DeltaTime)
{
	float Alpha = 0;
	float FadeTime = 0;
	ElapsedTime += DeltaTime;
	/*
	FadeTime = (EffectDuration * FadeTimeProportion);
	if ((AffectedPawn != nullptr) && (ElapsedTime > FadeTime))
	{
		Alpha = ((ElapsedTime - FadeTime) / (EffectDuration - FadeTime));
		AffectedPawn.fSpeedPenalty = ((SpeedPenalty * (1 - Alpha)) + (OldSpeedPenalty * Alpha));
	}
	*/
	//Super::update(DeltaTime);
}

void ASideEffectSlow::End()
{
	if (AffectedPawn != nullptr)
	{
		//AffectedPawn.fSpeedPenalty = OldSpeedPenalty;
	}
	//Super::End();
}
