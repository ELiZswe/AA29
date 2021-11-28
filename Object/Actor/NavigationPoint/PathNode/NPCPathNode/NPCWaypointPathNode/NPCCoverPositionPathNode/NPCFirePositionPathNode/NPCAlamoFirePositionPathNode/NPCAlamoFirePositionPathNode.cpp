// All the original content belonged to the US Army


#include "AA29/Object/Actor/NavigationPoint/PathNode/NPCPathNode/NPCWaypointPathNode/NPCCoverPositionPathNode/NPCFirePositionPathNode/NPCAlamoFirePositionPathNode/NPCAlamoFirePositionPathNode.h"

ANPCAlamoFirePositionPathNode::ANPCAlamoFirePositionPathNode()
{
	iNPCOrderTableWaypointIndex = 4;
	Texture = LoadObject<UTexture2D>(NULL, TEXT("Texture2D'/Game/AmericasArmy/Textures/AGP/S_PNodeAlamo.S_PNodeAlamo'"), NULL, LOAD_None, NULL);
	LoadEditorIcon();

}
