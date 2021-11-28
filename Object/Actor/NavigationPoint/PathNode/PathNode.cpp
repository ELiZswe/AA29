// All the original content belonged to the US Army


#include "PathNode.h"


APathNode::APathNode()
{

	Sprint = true;
	
	//SoundVolume = 128;

	Texture = LoadObject<UTexture2D>(NULL, TEXT("Texture2D'/Game/AmericasArmy/Textures/Engine/S_Pickup.S_Pickup'"), NULL, LOAD_None, NULL);
	LoadEditorIcon();
}

