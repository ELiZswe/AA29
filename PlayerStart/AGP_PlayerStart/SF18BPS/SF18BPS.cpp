// All the original content belonged to the US Army


#include "SF18BPS.h"
#include "AA29/AI_Primitive/SoldierClass/ClassSFBase/ClassSF18B/ClassSF18B.h"

ASF18BPS::ASF18BPS(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	SpawnClass					= AClassSF18B::StaticClass();
	bExtraSpecialForces			= true;
	ExtraSpecialForcesLetter	= "B";
	bSpecialForces				= true;
	Texture						= LoadObject<UTexture2D>(NULL, TEXT("/Game/AmericasArmy/Textures/T_AA2_Editor/PlayerStart/18b.18b"), NULL, LOAD_None, NULL);
	DrawScale					= 0.5;
	LoadEditorIcon();
}