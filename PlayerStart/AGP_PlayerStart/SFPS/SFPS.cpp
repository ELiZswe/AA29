// All the original content belonged to the US Army


#include "SFPS.h"
#include "AA29/AI_Primitive/SoldierClass/ClassSF/ClassSF.h"

ASFPS::ASFPS(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	SpawnClass      = AClassSF::StaticClass();
	bSpecialForces  = true;
	Texture         = LoadObject<UTexture2D>(NULL, TEXT("/Game/AmericasArmy/Textures/T_AA2_Editor/PlayerStart/18a.18a"), NULL, LOAD_None, NULL);
	DrawScale       = 0.5;
	LoadEditorIcon();
}