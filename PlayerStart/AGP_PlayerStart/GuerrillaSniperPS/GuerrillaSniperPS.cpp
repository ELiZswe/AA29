// All the original content belonged to the US Army


#include "GuerrillaSniperPS.h"
#include "AA29/AI_Primitive/SoldierClass/ClassGuerrillaBase/ClassGuerrillaSniper/ClassGuerrillaSniper.h"

AGuerrillaSniperPS::AGuerrillaSniperPS(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	SpawnClass  = AClassGuerrillaSniper::StaticClass();
	bGuerrilla  = true;
	Texture     = LoadObject<UTexture2D>(NULL, TEXT("/Game/AmericasArmy/Textures/T_AA2_Editor/PlayerStart/I_vss.I_vss"), NULL, LOAD_None, NULL);
	DrawScale   = 0.5;
	LoadEditorIcon();
}