// All the original content belonged to the US Army

#include "AA29/Object/Actor/Brush/Volume/CommVolume/CommVolume.h"

ACommVolume::ACommVolume()
{
	LocationPriority = 1;
	LocationName = "CHANGE THIS TEXT";
	bScoreHelper = true;
	bScoreDefender = true;
	bIsCommVolume = true;
}

void ACommVolume::Touch(AActor* Other)
{
	/*
	if ((Cast<APawn>(Other) != nullptr) && (Cast<APawn>(Other).PlayerReplicationInfo != nullptr))
	{
		Cast<APawn>(Other).PlayerReplicationInfo.UpdateCommVolume();
	}
	Super::Touch(Other);
	*/
}

void ACommVolume::UnTouch(AActor* Other)
{
	/*
	if ((Cast<APawn>(Other) != nullptr) && (Cast<APawn>(Other).PlayerReplicationInfo != nullptr))
	{
		Cast<APawn>(Other).PlayerReplicationInfo.UpdateCommVolume();
	}
	Super::UnTouch(Other);
	*/
}
