// All the original content belonged to the US Army


#include "AA29/Object/Actor/NavigationPoint/PathNode/NPCPathNode/NPCWaypointPathNode/NPCLadderPathNode/NPCLadderPathNode.h"

ANPCLadderPathNode::ANPCLadderPathNode()
{
	//Texture = Texture'AGP.S_PNodeLadder';
	Texture = LoadObject<UTexture2D>(NULL, TEXT("Texture2D'/Game/AmericasArmy/Textures/AGP/S_PNodeWaypoint.S_PNodeWaypoint'"), NULL, LOAD_None, NULL);
	LoadEditorIcon();

}