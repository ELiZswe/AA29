// All the original content belonged to the US Army

#include "AA29/Object/Actor/NavigationPoint/SmallNavigationPoint/PlayerStart/AGP_PlayerStart/ClassSFSniperPS/ClassSFSniperPS.h"
#include "AA29/Object/Actor/AI_Primitive/SoldierClass/ClassSFBase/ClassSFSniper/ClassSFSniper.h"

AClassSFSniperPS::AClassSFSniperPS(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	SpawnClass = AClassSFSniper::StaticClass();
	bSpecialForces = true;
	Texture = LoadObject<UTexture2D>(NULL, TEXT("Texture2D'/Game/AmericasArmy/Textures/T_AA2_Editor/PlayerStart/18b.18b'"), NULL, LOAD_None, NULL);
	DrawScale = 0.5;
	LoadEditorIcon();
}
