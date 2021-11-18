// All the original content belonged to the US Army


#include "SF18DPS.h"
#include "AA29/AI_Primitive/SoldierClass/ClassSFBase/ClassSF18D/ClassSF18D.h"

ASF18DPS::ASF18DPS(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	SpawnClass                = AClassSF18D::StaticClass();
	bExtraSpecialForces       = true;
	ExtraSpecialForcesLetter  = "D";
	bSpecialForces            = true;
	Texture                   = LoadObject<UTexture2D>(NULL, TEXT("/Game/AmericasArmy/Textures/T_AA2_Editor/PlayerStart/18d.18d"), NULL, LOAD_None, NULL);
	DrawScale                 = 0.5;
	LoadEditorIcon();
}