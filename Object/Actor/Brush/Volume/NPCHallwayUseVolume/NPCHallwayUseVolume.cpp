// All the original content belonged to the US Army

#include "AA29/Object/Actor/Brush/Volume/NPCHallwayUseVolume/NPCHallwayUseVolume.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Pawn.h"
#include "AA29/Object/Actor/NavigationPoint/NavigationPoint.h"
#include "AA29/Object/Actor/Controller/AIController/NPCBaseController/NPCBaseController.h"

ANPCHallwayUseVolume::ANPCHallwayUseVolume()
{
	anameHallwayNodes.SetNum(2);
	anpcEntryNodes.SetNum(2);
	anpcEntryNodes.SetNum(3);
	anameHallwayNodes.SetNum(3);
}

void ANPCHallwayUseVolume::BeginPlay()
{
	ANavigationPoint* npIterator = nullptr;
	Super::BeginPlay();
	/*
	anpcEntryNodes[0] = nullptr;
	anpcEntryNodes[1] = nullptr;
	if ((anameHallwayNodes[0] != "None") && (anameHallwayNodes[1] != "None"))
	{
		Log(string(Name) + " trying to find hallway matching node " + FString::FromInt(anameHallwayNodes[0]) + " and " + FString::FromInt(anameHallwayNodes[1]));
		npIterator = Level.NavigationPointList;
		if (npIterator != nullptr)
		{
			if (npIterator.Name == anameHallwayNodes[0])
			{
				Log(string(Name) + " found matching hallway node for hallway volume name " + FString::FromInt(anameHallwayNodes[0]) + " of " + FString::FromInt(npIterator));
				anpcEntryNodes[0] = NPCPathNode(npIterator);
				if (anpcEntryNodes[1] != nullptr)
				{
				}
			}
			else
			{
		else
		{
			if (npIterator.Name == anameHallwayNodes[1])
			{
				Log(string(Name) + " found matching hallway node for hallway volume name " + FString::FromInt(anameHallwayNodes[1]) + " of " + FString::FromInt(npIterator));
				anpcEntryNodes[1] = NPCPathNode(npIterator);
				if (anpcEntryNodes[0] != nullptr)
				{
				}
			}
		}
	else
	{
		npIterator = npIterator.nextNavigationPoint;
	}
			}
		}
	}
	*/
}

void ANPCHallwayUseVolume::Touch(AActor* Other)
{
	/*
	if ((Other->IsA(AAGP_Pawn::StaticClass()) && (Cast<AAGP_Pawn>(Other).Controller != nullptr)) && Cast<AAGP_Pawn>(Other).Controller->IsA(ANPCBaseController::StaticClass()))
	{
		Super::Touch(Other);
	}
	*/
}

void ANPCHallwayUseVolume::UnTouch(AActor* Other)
{
	/*
	int32 iNode = 0;
	if ((Other->IsA(AAGP_Pawn::StaticClass()) && (Cast<AAGP_Pawn>(Other).Controller != nullptr)) && Cast<AAGP_Pawn>(Other).Controller->IsA(ANPCBaseController::StaticClass()))
	{
		for (iNode = 0; iNode < 2; iNode++)
		{
			if (anpcEntryNodes[iNode].npcbcUsingHallway == Other)
			{
				anpcEntryNodes[iNode].npcbcUsingHallway = nullptr;
			}
		}
		Super::UnTouch(Other);
	}
	*/
}
