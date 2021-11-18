// All the original content belonged to the US Army


#include "SFSniperPS.h"
#include "AA29/AI_Primitive/SoldierClass/ClassSFBase/ClassSFSniper/ClassSFSniper.h"

ASFSniperPS::ASFSniperPS(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	SpawnClass      = AClassSFSniper::StaticClass();
	bSpecialForces  = true;
	Texture         = LoadObject<UTexture2D>(NULL, TEXT("/Game/AmericasArmy/Textures/T_AA2_Editor/PlayerStart/18b.18b"), NULL, LOAD_None, NULL);
	DrawScale       = 0.5;
	LoadEditorIcon();
}