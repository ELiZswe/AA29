// All the original content belonged to the US Army


#include "SFRiflemanPS.h"
#include "AA29/AI_Primitive/SoldierClass/ClassSFBase/ClassSFRifleman/ClassSFRifleman.h"

ASFRiflemanPS::ASFRiflemanPS(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	SpawnClass      = AClassSFRifleman::StaticClass();
	bSpecialForces  = true;
	Texture         = LoadObject<UTexture2D>(NULL, TEXT("/Game/AmericasArmy/Textures/T_AA2_Editor/PlayerStart/18c.18c"), NULL, LOAD_None, NULL);
	DrawScale       = 0.5;
	LoadEditorIcon();
}