// All the original content belonged to the US Army


#include "AA29/Object/Actor/NavigationPoint/SmallNavigationPoint/PlayerStart/AGP_PlayerStart/ClassGuerrillaSniperPS/ClassGuerrillaSniperPS.h"
#include "AA29/Object/Actor/AI_Primitive/SoldierClass/ClassGuerrillaBase/ClassGuerrillaSniper/ClassGuerrillaSniper.h"

AClassGuerrillaSniperPS::AClassGuerrillaSniperPS(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	SpawnClass = AClassGuerrillaSniper::StaticClass();
	bGuerrilla = true;
	Texture = LoadObject<UTexture2D>(NULL, TEXT("Texture2D'/Game/AmericasArmy/Textures/T_AA2_Editor/PlayerStart/I_vss.I_vss'"), NULL, LOAD_None, NULL);
	DrawScale = 0.5;
	LoadEditorIcon();
}