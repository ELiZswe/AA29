// All the original content belonged to the US Army


#include "AutomaticRiflemanPS.h"
#include "AA29/AI_Primitive/SoldierClass/ClassAutomaticRifleman/ClassAutomaticRifleman.h"

AAutomaticRiflemanPS::AAutomaticRiflemanPS(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	SpawnClass	= AClassAutomaticRifleman::StaticClass();
	Texture		= LoadObject<UTexture2D>(NULL, TEXT("/Game/AmericasArmy/Textures/T_AA2_Editor/PlayerStart/Ar.Ar"), NULL, LOAD_None, NULL);
	DrawScale	= 0.5;
	LoadEditorIcon();
}