// All the original content belonged to the US Army


#include "AA29/Object/Actor/KActor/KConstraint/KConeLimit/KConeLimit.h"

AKConeLimit::AKConeLimit()
{
	KHalfAngle = 8200;
	KStiffness = 50;
	Texture = LoadObject<UTexture2D>(NULL, TEXT("Texture2D'/Game/AmericasArmy/Textures/Engine/S_KConeLimit.S_KConeLimit'"), NULL, LOAD_None, NULL);
	//bDirectional = true;
}