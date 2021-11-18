// All the original content belonged to the US Army


#include "SF18FPS.h"
#include "AA29/AI_Primitive/SoldierClass/ClassSFBase/ClassSF18F/ClassSF18F.h"

ASF18FPS::ASF18FPS(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	SpawnClass                = AClassSF18F::StaticClass();
	bExtraSpecialForces       = true;
	ExtraSpecialForcesLetter  = "F";
	bSpecialForces            = true;
	Texture                   = LoadObject<UTexture2D>(NULL, TEXT("/Game/AmericasArmy/Textures/T_AA2_Editor/PlayerStart/18f.18f"), NULL, LOAD_None, NULL);
	DrawScale					= 0.5;
	LoadEditorIcon();
}