// All the original content belonged to the US Army


#include "AA29/NavigationPoint/PathNode/NPCPathNode/NPCWaypointPathNode/NPCDoorEntryPathNode/NPCDoorEntryPathNode.h"

ANPCDoorEntryPathNode::ANPCDoorEntryPathNode()
{
	bNPCHasKey = true;
		//Texture = Texture'AGP.S_PNodeDoor';
	Texture = LoadObject<UTexture2D>(NULL, TEXT("Texture2D'/Game/AmericasArmy/Textures/AGP/S_PNodeWaypoint.S_PNodeWaypoint'"), NULL, LOAD_None, NULL);
	LoadEditorIcon();

}