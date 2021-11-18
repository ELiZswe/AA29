// All the original content belonged to the US Army


#include "AA29/NavigationPoint/PathNode/NPCPathNode/NPCWaypointPathNode/NPCCoverPositionPathNode/NPCFirePositionPathNode/NPCCamperFirePositionPathNode/NPCCamperFirePositionPathNode.h"

ANPCCamperFirePositionPathNode::ANPCCamperFirePositionPathNode()
{
	fpAmbushRange = 1250;
	fpMinRangeMeters = 1500;
	fpMaxRangeMeters = 100000;
	fpMinPlayersToSee = 1;
	fpVisionConeAngle = 9830;
	iNPCOrderTableWaypointIndex = 2;
	Texture = LoadObject<UTexture2D>(NULL, TEXT("Texture2D'/Game/AmericasArmy/Textures/AGP/S_PNodeCamper.S_PNodeCamper'"), NULL, LOAD_None, NULL);
	LoadEditorIcon();
}