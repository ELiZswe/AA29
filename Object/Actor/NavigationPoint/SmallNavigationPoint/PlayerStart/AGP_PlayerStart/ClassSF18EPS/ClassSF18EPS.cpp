// All the original content belonged to the US Army


#include "AA29/Object/Actor/NavigationPoint/SmallNavigationPoint/PlayerStart/AGP_PlayerStart/ClassSF18EPS/ClassSF18EPS.h"
#include "AA29/AI_Primitive/SoldierClass/ClassSFBase/ClassSF18E/ClassSF18E.h"

AClassSF18EPS::AClassSF18EPS(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	SpawnClass = AClassSF18E::StaticClass();
	bExtraSpecialForces = true;
	ExtraSpecialForcesLetter = "E";
	bSpecialForces = true;
	Texture = LoadObject<UTexture2D>(NULL, TEXT("Texture2D'/Game/AmericasArmy/Textures/T_AA2_Editor/PlayerStart/18e.18e'"), NULL, LOAD_None, NULL);
	DrawScale = 0.5;
	LoadEditorIcon();
}