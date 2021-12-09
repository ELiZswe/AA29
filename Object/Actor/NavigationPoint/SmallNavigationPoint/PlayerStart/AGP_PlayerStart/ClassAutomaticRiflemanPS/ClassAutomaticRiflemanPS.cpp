// All the original content belonged to the US Army


#include "AA29/Object/Actor/NavigationPoint/SmallNavigationPoint/PlayerStart/AGP_PlayerStart/ClassAutomaticRiflemanPS/ClassAutomaticRiflemanPS.h"
#include "AA29/Object/Actor/AI_Primitive/SoldierClass/ClassAutomaticRifleman/ClassAutomaticRifleman.h"

AClassAutomaticRiflemanPS::AClassAutomaticRiflemanPS(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	SpawnClass = AClassAutomaticRifleman::StaticClass();
	Texture = LoadObject<UTexture2D>(NULL, TEXT("Texture2D'/Game/AmericasArmy/Textures/T_AA2_Editor/PlayerStart/Ar.Ar'"), NULL, LOAD_None, NULL);
	DrawScale = 0.5;
	LoadEditorIcon();
}