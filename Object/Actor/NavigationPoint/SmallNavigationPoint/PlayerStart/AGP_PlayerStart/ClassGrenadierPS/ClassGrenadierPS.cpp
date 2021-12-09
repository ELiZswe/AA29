// All the original content belonged to the US Army


#include "AA29/Object/Actor/NavigationPoint/SmallNavigationPoint/PlayerStart/AGP_PlayerStart/ClassGrenadierPS/ClassGrenadierPS.h"
#include "AA29/Object/Actor/AI_Primitive/SoldierClass/ClassGrenadier/ClassGrenadier.h"

AClassGrenadierPS::AClassGrenadierPS(const FObjectInitializer & ObjectInitializer) : Super(ObjectInitializer)
{
	SpawnClass = AClassGrenadier::StaticClass();
	Texture = LoadObject<UTexture2D>(NULL, TEXT("Texture2D'/Game/AmericasArmy/Textures/T_AA2_Editor/PlayerStart/G.G'"), NULL, LOAD_None, NULL);
	DrawScale = 0.5;
	LoadEditorIcon();
}