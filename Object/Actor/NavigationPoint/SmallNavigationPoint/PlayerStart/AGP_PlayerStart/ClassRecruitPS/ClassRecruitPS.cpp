// All the original content belonged to the US Army


#include "AA29/Object/Actor/NavigationPoint/SmallNavigationPoint/PlayerStart/AGP_PlayerStart/ClassRecruitPS/ClassRecruitPS.h"
#include "AA29/Object/Actor/AI_Primitive/SoldierClass/ClassRecruit/ClassRecruit.h"
	
AClassRecruitPS::AClassRecruitPS(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	SpawnClass = AClassRecruit::StaticClass();
	Texture = LoadObject<UTexture2D>(NULL, TEXT("Texture2D'/Game/AmericasArmy/Textures/T_AA2_Editor/PlayerStart/RCT.RCT'"), NULL, LOAD_None, NULL);
	DrawScale = 0.5;
	LoadEditorIcon();
}