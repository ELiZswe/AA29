// All the original content belonged to the US Army


#include "AA2_CommVolume.h"

//Sets the default values
AAA2_CommVolume::AAA2_CommVolume()
{
	Location = (TEXT("Location"));
	Priority = 1;

	//Register Events 2

//	OnActorBeginOverlap.AddDynamic(this, &AAA2_CommVolume::OnOverlapBegin);
//	OnActorEndOverlap.AddDynamic(this, &AAA2_CommVolume::OnOverlapEnd);
}
void AAA2_CommVolume::BeginPlay()
{
	Super::BeginPlay();
}
/*
void AAA2_CommVolume::OnOverlapBegin(class AActor* OverlappedActor, class AActor* OtherActor)
{
	APawn* Pawn = Cast<APawn>(OtherActor);
	if (Pawn)
	{
		APlayerController* PC = Cast<APlayerController>(Pawn->Controller);
		if (PC)
		{
			PlayerInside = true;
		}
	}
}

void AAA2_CommVolume::OnOverlapEnd(class AActor* OverlappedActor, class AActor* OtherActor)
{
	APawn* Pawn = Cast<APawn>(OtherActor);
	if (Pawn)
	{
		APlayerController* PC = Cast<APlayerController>(Pawn->Controller);
		if (PC)
		{
			PlayerInside = false;
		}
	}
}
*/