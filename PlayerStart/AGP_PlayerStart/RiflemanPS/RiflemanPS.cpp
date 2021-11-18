// All the original content belonged to the US Army


#include "RiflemanPS.h"
#include "AA29/AI_Primitive/SoldierClass/ClassRifleman/ClassRifleman.h"

ARiflemanPS::ARiflemanPS(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	SpawnClass		= AClassRifleman::StaticClass();
	Texture			= LoadObject<UTexture2D>(NULL, TEXT("/Game/AmericasArmy/Textures/T_AA2_Editor/PlayerStart/R.R"), NULL, LOAD_None, NULL);
	DrawScale		= 0.5;
	LoadEditorIcon();
}