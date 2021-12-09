// All the original content belonged to the US Army


#include "AA29/Object/Actor/NavigationPoint/SmallNavigationPoint/PlayerStart/AGP_PlayerStart/ClassSFRiflemanPS/ClassSFRiflemanPS.h"
#include "AA29/Object/Actor/AI_Primitive/SoldierClass/ClassSFBase/ClassSFRifleman/ClassSFRifleman.h"

AClassSFRiflemanPS::AClassSFRiflemanPS(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	SpawnClass = AClassSFRifleman::StaticClass();
	bSpecialForces = true;
	Texture = LoadObject<UTexture2D>(NULL, TEXT("Texture2D'/Game/AmericasArmy/Textures/T_AA2_Editor/PlayerStart/18c.18c'"), NULL, LOAD_None, NULL);
	DrawScale = 0.5;
	LoadEditorIcon();
}