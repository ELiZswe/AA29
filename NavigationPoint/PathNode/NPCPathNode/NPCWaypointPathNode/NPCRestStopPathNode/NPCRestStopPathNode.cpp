// All the original content belonged to the US Army


#include "AA29/NavigationPoint/PathNode/NPCPathNode/NPCWaypointPathNode/NPCRestStopPathNode/NPCRestStopPathNode.h"

ANPCRestStopPathNode::ANPCRestStopPathNode()
{
	fpTimeToRest = 2;
		iNPCOrderTableWaypointIndex = 5;
		//Texture = Texture'AGP.S_PNodeRest';
		Texture = LoadObject<UTexture2D>(NULL, TEXT("Texture2D'/Game/AmericasArmy/Textures/AGP/S_PNodeWaypoint.S_PNodeWaypoint'"), NULL, LOAD_None, NULL);
		LoadEditorIcon();

}
