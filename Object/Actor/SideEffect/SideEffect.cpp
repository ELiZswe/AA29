// All the original content belonged to the US Army


#include "SideEffect.h"

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

// Called when the game starts or when spawned
void ASideEffect::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASideEffect::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

