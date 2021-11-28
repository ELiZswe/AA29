// All the original content belonged to the US Army


#include "AA29/Object/Actor/NavigationPoint/PathNode/NPCPathNode/NPCWaypointPathNode/NPCWaypointPathNode.h"

ANPCWaypointPathNode::ANPCWaypointPathNode()
{
	iNPCOrderTableWaypointIndex = 1;
	Texture = LoadObject<UTexture2D>(NULL, TEXT("Texture2D'/Game/AmericasArmy/Textures/AGP/S_PNodeWaypoint.S_PNodeWaypoint'"), NULL, LOAD_None, NULL);
	LoadEditorIcon();

}
