// All the original content belonged to the US Army


#include "AA29/Object/Actor/NavigationPoint/PathNode/NPCPathNode/NPCWaypointPathNode/NPCCoverPositionPathNode/NPCCoverPositionPathNode.h"

ANPCCoverPositionPathNode::ANPCCoverPositionPathNode()
{
	fpMaxVerticalDeltaToFind = 100;
	fpMentalStateBonus = 15;
	fpMentalStateChangeModifier = 0.5;
	fpHearingRangeModifier = 1.15;
	fpMentalStateRecoveryModifier = 1.15;
	iNPCOrderTableWaypointIndex = 3;
	Texture = LoadObject<UTexture2D>(NULL, TEXT("Texture2D'/Game/AmericasArmy/Textures/AGP/S_PNodeCover.S_PNodeCover'"), NULL, LOAD_None, NULL);
	LoadEditorIcon();
}
