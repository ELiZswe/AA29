// All the original content belonged to the US Army


#include "AA29/Object/Actor/NavigationPoint/PathNode/RoadPathNode/RoadPathNode.h"

ARoadPathNode::ARoadPathNode()
{
	bNoAutoConnect = true;
	bFlyingPreferred = true;
	bVehicleDestination = true;
	Texture = LoadObject<UTexture2D>(NULL, TEXT("Texture2D'/Game/AmericasArmy/Textures/Engine/S_FlyingPath.S_FlyingPath'"), NULL, LOAD_None, NULL);
	LoadEditorIcon();

	//DrawScale = 0.4;
}