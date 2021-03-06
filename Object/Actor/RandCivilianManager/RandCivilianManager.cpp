// All the original content belonged to the US Army

#include "AA29/Object/Actor/RandCivilianManager/RandCivilianManager.h"

// Sets default values
ARandCivilianManager::ARandCivilianManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	MinCivilians = 1;
	MaxCivilians = 30;
}


void ARandCivilianManager::BeginPlay()
{
	Super::BeginPlay();
	
}


void ARandCivilianManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ARandCivilianManager::PreBeginPlay()
{
	APawn* p = nullptr;
	/*
	ForEach AllActors(Class'Pawn', p)
	{
		if (IsLegalForThisManager(p))
		{
			CivilianList[CivilianList.Num()] = p;
		}
	}
	if (CivilianList.Num() > MaxCivilians)
	{
		MaxCivilians = CivilianList.Num();
	}
	if (MinCivilians > MaxCivilians)
	{
		MinCivilians = MaxCivilians;
	}
	HideOrShow();
	*/
}

void ARandCivilianManager::MatchStarting()
{
	HideOrShow();
}

bool ARandCivilianManager::IsLegalForThisManager(APawn* p)
{
	/*
	if (GroupTag == p.GroupTag)
	{
		return true;
	}
	else
	{
		return false;
	}
	*/
	return false;     //FAKE   /ELiZ
}

void ARandCivilianManager::HideOrShow()
{
	int32 i = 0;
	int32 RandNum = 0;
	int32 NextRandom = 0;
	TArray<APawn*> CopyList = {};
	/*
	for (i = 0; i < CivilianList.Num(); i++)
	{
		CopyList[i] = CivilianList[i];
	}
	RandNum = FindRand(MinCivilians, MaxCivilians);
	for (i = 0; i < RandNum; i++)
	{
		NextRandom = Rand(CopyList.Num());
		CopyList[NextRandom].TurnOnPawn(CopyList[NextRandom]);
		CopyList.RemoveAt(NextRandom, 1);
	}
	for (i = 0; i < CopyList.Num(); i++)
	{
		CopyList[i].TurnOffPawn(CopyList[i]);
	}
	*/
}

int32 ARandCivilianManager::FindRand(int32 Minimum, int32 Maximum)
{
	int32 Num = 0;
	/*
	Num = Rand(Maximum);
	if (Num < Minimum)
	{
		Num = Minimum;
	}
	*/
	return Num;
}
