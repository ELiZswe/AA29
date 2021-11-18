// All the original content belonged to the US Army


#include "SF18ZPS.h"
#include "AA29/AI_Primitive/SoldierClass/ClassSFBase/ClassSF18Z/ClassSF18Z.h"

ASF18ZPS::ASF18ZPS(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	SpawnClass                = AClassSF18Z::StaticClass();
	bExtraSpecialForces       = true;
	ExtraSpecialForcesLetter  = "Z";
	bSpecialForces            = true;
	Texture                   = LoadObject<UTexture2D>(NULL, TEXT("/Game/AmericasArmy/Textures/T_AA2_Editor/PlayerStart/18z.18z"), NULL, LOAD_None, NULL);
	DrawScale                 = 0.5;
	LoadEditorIcon();
}