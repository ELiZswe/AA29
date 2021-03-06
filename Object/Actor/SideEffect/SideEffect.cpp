// All the original content belonged to the US Army

#include "AA29/Object/Actor/SideEffect/SideEffect.h"

// Sets default values
ASideEffect::ASideEffect()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	EffectDuration         = 1;
	bThereCanBeOnlyOne     = true;
	bReplaceExtantEffects  = true;
	DrawType               = EDrawType::DT_None;
}

/*
simulated State Affecting
{
	simulated Event Tick(float DeltaTime)
	{
		update(DeltaTime);
	}
Begin:
	Sleep(EffectDuration);
	End();
	GotoState("None");
}
*/


void ASideEffect::BeginPlay()
{
	Super::BeginPlay();
	
}


void ASideEffect::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ASideEffect::ScaleByDamage(int32 Damage)
{
}

bool ASideEffect::OverrideEffects()
{
	ASideEffect* SE = nullptr;
	bool bCollisionFound = false;
	bCollisionFound = false;
	/*
	ForEach AllActors(ASideEffect::StaticClass(), SE)
	{
		if (((SE != Self) && (SE.Class == this.Class)) && (SE.Owner == this.Owner))
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

void ASideEffect::Start()
{
	bool bCollisionFound = false;
	bCollisionFound = false;
	if (bThereCanBeOnlyOne)
	{
		bCollisionFound = OverrideEffects();
	}
	if ((bCollisionFound && bReplaceExtantEffects) || (!bCollisionFound))
	{
		//GotoState("Affecting");
	}
	else
	{
		Destroy();
	}
}

void ASideEffect::update(float DeltaTime)
{
}

void ASideEffect::End()
{
	Destroy();
}
