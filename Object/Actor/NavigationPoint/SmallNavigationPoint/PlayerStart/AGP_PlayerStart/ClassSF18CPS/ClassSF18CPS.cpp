// All the original content belonged to the US Army


#include "AA29/Object/Actor/NavigationPoint/SmallNavigationPoint/PlayerStart/AGP_PlayerStart/ClassSF18CPS/ClassSF18CPS.h"
#include "AA29/Object/Actor/AI_Primitive/SoldierClass/ClassSFBase/ClassSF18C/ClassSF18C.h"

AClassSF18CPS::AClassSF18CPS(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	SpawnClass = AClassSF18C::StaticClass();
	bExtraSpecialForces = true;
	ExtraSpecialForcesLetter = "C";
	bSpecialForces = true;
	Texture = LoadObject<UTexture2D>(NULL, TEXT("Texture2D'/Game/AmericasArmy/Textures/T_AA2_Editor/PlayerStart/18c.18c'"), NULL, LOAD_None, NULL);
	DrawScale = 0.5;
	LoadEditorIcon();
}