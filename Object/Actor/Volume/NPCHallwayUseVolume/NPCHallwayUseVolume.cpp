// All the original content belonged to the US Army


#include "AA29/Object/Actor/Volume/NPCHallwayUseVolume/NPCHallwayUseVolume.h"

ANPCHallwayUseVolume::ANPCHallwayUseVolume()
{
	anpcEntryNodes.SetNum(3);
	anameHallwayNodes.SetNum(3);
}

void ANPCHallwayUseVolume::BeginPlay()
{
	/*
	local NavigationPoint npIterator;
	Super::BeginPlay();
	anpcEntryNodes[0] = None;
	anpcEntryNodes[1] = None;
	if ((anameHallwayNodes[0] != 'None') && (anameHallwayNodes[1] != 'None'))
	{
		Log(string(Name) $ " trying to find hallway matching node " $ string(anameHallwayNodes[0]) $ " and " $ string(anameHallwayNodes[1]));
		npIterator = Level.NavigationPointList;
		if (npIterator != None)
		{
			if (npIterator.Name == anameHallwayNodes[0])
			{
				Log(string(Name) $ " found matching hallway node for hallway volume name " $ string(anameHallwayNodes[0]) $ " of " $ string(npIterator));
				anpcEntryNodes[0] = NPCPathNode(npIterator);
				if (anpcEntryNodes[1] != None)
				{
				}
			}
			else
			{
		else
		{
			if (npIterator.Name == anameHallwayNodes[1])
			{
				Log(string(Name) $ " found matching hallway node for hallway volume name " $ string(anameHallwayNodes[1]) $ " of " $ string(npIterator));
				anpcEntryNodes[1] = NPCPathNode(npIterator);
				if (anpcEntryNodes[0] != None)
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
	if ((Other.IsA('AGP_Pawn') && (AGP_Pawn(Other).Controller != None)) && AGP_Pawn(Other).Controller.IsA('NPCBaseController'))
	{
		Super::Touch(Other);
	}
	*/
}

void ANPCHallwayUseVolume::UnTouch(AActor* Other)
{
	/*
	int32 iNode = 0;
	if ((Other.IsA('AGP_Pawn') && (AGP_Pawn(Other).Controller != None)) && AGP_Pawn(Other).Controller.IsA('NPCBaseController'))
	{
		for (iNode = 0; iNode < 2; iNode++)
		{
			if (anpcEntryNodes[iNode].npcbcUsingHallway == Other)
			{
				anpcEntryNodes[iNode].npcbcUsingHallway = None;
			}
		}
		Super::UnTouch(Other);
	}
	*/
}