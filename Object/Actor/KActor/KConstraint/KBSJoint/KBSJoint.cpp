// All the original content belonged to the US Army

#include "AA29/Object/Actor/KActor/KConstraint/KBSJoint/KBSJoint.h"

AKBSJoint::AKBSJoint()
{
	Texture = LoadObject<UTexture2D>(NULL, TEXT("Texture2D'/Game/AmericasArmy/Textures/Engine/S_KBSJoint.S_KBSJoint'"), NULL, LOAD_None, NULL);
}