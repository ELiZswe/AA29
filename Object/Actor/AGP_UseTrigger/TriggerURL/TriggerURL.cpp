// All the original content belonged to the US Army


#include "AA29/Object/Actor/AGP_UseTrigger/TriggerURL/TriggerURL.h"

ATriggerURL::ATriggerURL()
{
	//StaticMesh = class'None';
	//bNoDelete = true;
	//bAcceptsProjectors = False;
	//bMovable = False;
	//CollisionRadius = 22;
	//CollisionHeight = 49;
	//bCollideActors = False;
	//bBlockZeroExtentTraces = False;
	//bUseCylinderCollision = False;
	//bEdShouldSnap = False;

	Texture = LoadObject<UTexture2D>(NULL, TEXT("Texture2D'/Game/AmericasArmy/Textures/Engine/S_Actor.S_Actor'"), NULL, LOAD_None, NULL);
	LoadEditorIcon();

}