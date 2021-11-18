// All the original content belonged to the US Army


#include "AA29/NavigationPoint/SmallNavigationPoint/Teleporter/Teleporter.h"

ATeleporter::ATeleporter()
{
	bChangesYaw = true;
	bEnabled = true;
	bSpecialForced = true;
	//RemoteRole = 2;
	//SoundVolume = 128;
	//bCollideActors = true;

	Texture = LoadObject<UTexture2D>(NULL, TEXT("Texture2D'/Game/AmericasArmy/Textures/Engine/S_Teleport.S_Teleport'"), NULL, LOAD_None, NULL);
	LoadEditorIcon();
}