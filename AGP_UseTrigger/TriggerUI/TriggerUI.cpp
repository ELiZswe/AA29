// All the original content belonged to the US Army


#include "AA29/AGP_UseTrigger/TriggerUI/TriggerUI.h"

ATriggerUI::ATriggerUI()
{
	bDebug = true;

	//StaticMesh = class'None';
	//bNoDelete = true;
	//bAcceptsProjectors = false;
	//bMovable = false;
	//CollisionRadius = 22;
	//CollisionHeight = 49;
	//bCollideActors = false;
	//bBlockZeroExtentTraces = false;
	//bUseCylinderCollision = false;
	//bEdShouldSnap = false;

	Texture = LoadObject<UTexture2D>(NULL, TEXT("Texture2D'/Game/AmericasArmy/Textures/Engine/S_Actor.S_Actor'"), NULL, LOAD_None, NULL);
	LoadEditorIcon();


}