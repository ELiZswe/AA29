// All the original content belonged to the US Army


#include "AA29/NavigationPoint/PathNode/NPCPathNode/NPCDuckAndCoverPathNode/NPCDuckAndCoverPathNode.h"

ANPCDuckAndCoverPathNode::ANPCDuckAndCoverPathNode()
{
	iNPCOrderTableWaypointIndex = 3;
	Texture = LoadObject<UTexture2D>(NULL, TEXT("Texture2D'/Game/AmericasArmy/Textures/AGP/S_PNodeDuckAndCover.S_PNodeDuckAndCover'"), NULL, LOAD_None, NULL);
	LoadEditorIcon();

}
