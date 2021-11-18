// All the original content belonged to the US Army


#include "NPCPathNode.h"

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
	npcbcUsingNode = None;
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
void ANPCPathNode::IsHallwayEntry()
{
	/*
	if (nameHallway == 'None' || npcpnHallwayOtherEnd == None)
	{
		Return False;
	}
	else
	{
		Return True;
	}
	*/
}
void ANPCPathNode::RequestHallway(ANPCBaseController* npcbc)
{
	/*
	local int iRCEntry;
	local bool bNeedToOwnHallway;
	if (npcpnHallwayOtherEnd == None)
	{
		Return True;
	}
	if (npcbcUsingHallway == None || npcbcUsingHallway == npcbc)
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
		Return True;
	}
	else
	{
		Log(Self $ "." $ Name $ " Hallway busy - used by " $ npcbcUsingHallway.Tag);
	}
	Return False;
	*/
}
void ANPCPathNode::ReleaseHallway(ANPCBaseController* npcbc)
{
	/*
	if (npcpnHallwayOtherEnd == None)
	{
		Return;
	}
	if (npcbcUsingHallway == npcbc)
	{
		npcbcUsingHallway = None;
	}
	*/
}
