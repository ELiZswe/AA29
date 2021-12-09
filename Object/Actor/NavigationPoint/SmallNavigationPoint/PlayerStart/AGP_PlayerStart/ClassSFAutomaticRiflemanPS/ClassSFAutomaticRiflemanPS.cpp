// All the original content belonged to the US Army


#include "AA29/Object/Actor/NavigationPoint/SmallNavigationPoint/PlayerStart/AGP_PlayerStart/ClassSFAutomaticRiflemanPS/ClassSFAutomaticRiflemanPS.h"
#include "AA29/Object/Actor/AI_Primitive/SoldierClass/ClassSFBase/ClassSFAutomaticRifleman/ClassSFAutomaticRifleman.h"

AClassSFAutomaticRiflemanPS::AClassSFAutomaticRiflemanPS(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	SpawnClass = AClassSFAutomaticRifleman::StaticClass();
	bSpecialForces = true;
	Texture = LoadObject<UTexture2D>(NULL, TEXT("Texture2D'/Game/AmericasArmy/Textures/T_AA2_Editor/PlayerStart/18z.18z'"), NULL, LOAD_None, NULL);
	DrawScale = 0.5;
	LoadEditorIcon();
}