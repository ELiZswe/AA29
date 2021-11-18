// All the original content belonged to the US Army


#include "SniperPS.h"
#include "AA29/AI_Primitive/SoldierClass/ClassGuerrillaBase/ClassGuerrillaSniper/ClassGuerrillaSniper.h"

ASniperPS::ASniperPS(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	SpawnClass		= AClassGuerrillaSniper::StaticClass();
	bGuerrilla		= true;
	Texture = LoadObject<UTexture2D>(NULL, TEXT("/Game/AmericasArmy/Textures/T_AA2_Editor/PlayerStart/S.S"), NULL, LOAD_None, NULL);
	DrawScale		= 0.5;
	LoadEditorIcon();
}