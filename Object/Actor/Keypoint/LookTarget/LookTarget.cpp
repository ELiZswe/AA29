// All the original content belonged to the US Army


#include "AA29/Object/Actor/Keypoint/LookTarget/LookTarget.h"

ALookTarget::ALookTarget(const FObjectInitializer& objectInitializer)
	:Super(objectInitializer)
{
	//bStatic = false;
	//bNoDelete = true;
	//bStasis = true;

	Texture = LoadObject<UTexture2D>(NULL, TEXT("Texture2D'/Game/AmericasArmy/Textures/Engine/S_LookTarget.S_LookTarget'"), NULL, LOAD_None, NULL);
	LoadEditorIcon();
}