// All the original content belonged to the US Army


#include "AA29/Object/Actor/NavigationPoint/SmallNavigationPoint/PlayerStart/AGP_PlayerStart/ClassSniperPS/ClassSniperPS.h"
#include "AA29/AI_Primitive/SoldierClass/ClassSniperBase/ClassSniper/ClassSniper.h"

AClassSniperPS::AClassSniperPS(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	SpawnClass = AClassSniper::StaticClass();
	Texture = LoadObject<UTexture2D>(NULL, TEXT("Texture2D'/Game/AmericasArmy/Textures/T_AA2_Editor/PlayerStart/S.S'"), NULL, LOAD_None, NULL);
	DrawScale = 0.5;
	//Style = STY_Modulated;
	LoadEditorIcon();
}