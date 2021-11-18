// All the original content belonged to the US Army


#include "AA29/NavigationPoint/PathNode/NPCPathNode/NPCWaypointPathNode/NPCCoverPositionPathNode/NPCFirePositionPathNode/NPCFirePositionPathNode.h"

ANPCFirePositionPathNode::ANPCFirePositionPathNode()
{
	bIsCover = true;
	bUsePrimaryWeapon = true;
	fpWeaponAccuracyBonus = 15;
	iNPCOrderTableWaypointIndex = 1;
	//Texture = Texture'AGP.S_PNodeFiring'
	Texture = LoadObject<UTexture2D>(NULL, TEXT("Texture2D'/Game/AmericasArmy/Textures/AGP/S_PNodeCover.S_PNodeCover'"), NULL, LOAD_None, NULL);
	LoadEditorIcon();
}