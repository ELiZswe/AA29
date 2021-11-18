// All the original content belonged to the US Army


#include "PrisonerPS.h"
#include "AA29/AI_Primitive/SoldierClass/ClassPrisoner/ClassPrisoner.h"

APrisonerPS::APrisonerPS(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	SpawnClass   = AClassPrisoner::StaticClass();
	Texture      = LoadObject<UTexture2D>(NULL, TEXT("/Game/AmericasArmy/Textures/T_AA2_Editor/PlayerStart/p.p"), NULL, LOAD_None, NULL);
	DrawScale    = 0.5;
	LoadEditorIcon();
}