// All the original content belonged to the US Army


#include "RecruitPS.h"
#include "AA29/AI_Primitive/SoldierClass/ClassRecruit/ClassRecruit.h"

ARecruitPS::ARecruitPS(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	SpawnClass  = AClassRecruit::StaticClass();
	Texture     = LoadObject<UTexture2D>(NULL, TEXT("/Game/AmericasArmy/Textures/T_AA2_Editor/PlayerStart/RCT.RCT"), NULL, LOAD_None, NULL);
	DrawScale   = 0.5;
	LoadEditorIcon();
}