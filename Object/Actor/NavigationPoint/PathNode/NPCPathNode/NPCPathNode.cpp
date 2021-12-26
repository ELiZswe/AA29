// All the original content belonged to the US Army

#include "AA29/Object/Actor/NavigationPoint/PathNode/NPCPathNode/NPCPathNode.h"

ANPCPathNode::ANPCPathNode()
{
	fpMentalStateChangeModifier = 1;
	fpVisionRangeModifier = 1;
	fpVisionConeAngle = 16384;
	fpHearingRangeModifier = 1;
	fpMentalStateRecoveryModifier = 1;
	bScoutExtentTrace = true;
	Texture = LoadObject<UTexture2D>(NULL, TEXT("Texture2D'/Game/AmericasArmy/Textures/AGP/S_PNodeRoute.S_PNodeRoute'"), NULL, LOAD_None, NULL);
	LoadEditorIcon();
	//DrawScale = 0.5;
}

void ANPCPathNode::BeginPlay()
{
	Super::BeginPlay();
	/*
	local NavigationPoint npIterator;
	npcbcUsingNode = nullptr;
	if (nameHallway != 'None')
	{
		Log(Name $ " trying to find hallway matching node " $ nameHallway);
		npIterator = Level.NavigationPointList;
		if (npIterator != None)
		{
			if (npIterator == Self)
			{
			}
			if (npIterator.Name == nameHallway)
			{
				Log(Name $ " found matching hallway node for name " $ nameHallway $ " of " $ npIterator);
				npcpnHallwayOtherEnd = NPCPathNode(npIterator);
			}
			else
			{
				npIterator = npIterator.nextNavigationPoint;
			}
		}
	}
	*/
}

bool ANPCPathNode::IsHallwayEntry()
{
	if (nameHallway == "None" || npcpnHallwayOtherEnd == nullptr)
	{
		return false;
	}
	else
	{
		return true;
	}
}

bool ANPCPathNode::RequestHallway(ANPCBaseController* npcbc)
{
	/*
	local int iRCEntry;
	local bool bNeedToOwnHallway;
	if (npcpnHallwayOtherEnd == nullptr)
	{
		return true;
	}
	if (npcbcUsingHallway == nullptr || npcbcUsingHallway == npcbc)
	{
		for (iRCEntry = 0; iRCEntry < 62; iRCEntry++)
		{
			if (npcbc.RouteCache[iRCEntry] == Self)
			{
				iRCEntry = iRCEntry + 1;
				if (iRCEntry < 62)
				{
					if (npcbc.RouteCache[iRCEntry] == npcpnHallwayOtherEnd)
					{
						bNeedToOwnHallway = true;
					}
					else
					{
						iRCEntry++;
					}
				}
			}
		}
		if (bNeedToOwnHallway)
		{
			Log(Self $ "." $ Name $ " Requesting hallway usage for NPC: " $ npcbc.Tag);
			npcpnHallwayOtherEnd.npcbcUsingHallway = npcbc;
		}
		return true;
	}
	else
	{
		Log(Self $ "." $ Name $ " Hallway busy - used by " $ npcbcUsingHallway.Tag);
	}
	*/
	return false;
}

void ANPCPathNode::ReleaseHallway(ANPCBaseController* npcbc)
{
	/*
	if (npcpnHallwayOtherEnd == nullptr)
	{
		Return;
	}
	if (npcbcUsingHallway == npcbc)
	{
		npcbcUsingHallway = nullptr;
	}
	*/
}
