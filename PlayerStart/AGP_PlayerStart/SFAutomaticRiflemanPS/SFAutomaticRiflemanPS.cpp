// All the original content belonged to the US Army


#include "SFAutomaticRiflemanPS.h"
#include "AA29/AI_Primitive/SoldierClass/ClassSFBase/ClassSFAutomaticRifleman/ClassSFAutomaticRifleman.h"

ASFAutomaticRiflemanPS::ASFAutomaticRiflemanPS(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	SpawnClass      = AClassSFAutomaticRifleman::StaticClass();
	bSpecialForces  = true;
	Texture         = LoadObject<UTexture2D>(NULL, TEXT("/Game/AmericasArmy/Textures/T_AA2_Editor/PlayerStart/18z.18z"), NULL, LOAD_None, NULL);
	DrawScale       = 0.5;
	LoadEditorIcon();
}