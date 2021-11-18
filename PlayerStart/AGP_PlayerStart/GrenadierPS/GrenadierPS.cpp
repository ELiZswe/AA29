// All the original content belonged to the US Army


#include "GrenadierPS.h"
#include "AA29/AI_Primitive/SoldierClass/ClassGrenadier/ClassGrenadier.h"

AGrenadierPS::AGrenadierPS(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	SpawnClass = AClassGrenadier::StaticClass();
	Texture = LoadObject<UTexture2D>(NULL, TEXT("/Game/AmericasArmy/Textures/T_AA2_Editor/PlayerStart/G.G"), NULL, LOAD_None, NULL);
	DrawScale = 0.5;
	LoadEditorIcon();
}