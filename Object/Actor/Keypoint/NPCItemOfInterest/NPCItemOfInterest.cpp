// All the original content belonged to the US Army

#include "AA29/Object/Actor/Keypoint/NPCItemOfInterest/NPCItemOfInterest.h"

ANPCItemOfInterest::ANPCItemOfInterest(const FObjectInitializer& objectInitializer)
	:Super(objectInitializer)
{
	fpMaxDistanceToNotice = 100;
	fpTimeToWaitHere = 2;
	fpLikelihoodItemWillBeNoticed = 75;
	//bStatic = false;
}

void ANPCItemOfInterest::BeginPlay()
{
	Super::BeginPlay();
	/*
	Log(string(this) + ".BeginPlay() - targetpawn: " + FString::FromInt(nameTargetPawn));
	if ((nameTargetPawn != "None") && (nameTargetPawn != "None"))
	{
		SetTimer(3, false);
	}
	*/
}

void ANPCItemOfInterest::Timer()
{
	APawn* pawnIterator = nullptr;
	/*
	if ((nameTargetPawn != "None") && (nameTargetPawn != "None"))
	{
		Log(string(this) + " looking for pawn " + FString::FromInt(nameTargetPawn));
		ForEach AllActors(Class'Pawn', pawnIterator, nameTargetPawn)
		{
			Log(string(this) + " found pawn to shoot");
			pawnTargetToShoot = pawnIterator;
		}
	}
	*/
}
