// All the original content belonged to the US Army


#include "Sniper24PS.h"
#include "AA29/AI_Primitive/SoldierClass\ClassSniperBase/ClassSniper24_US/ClassSniper24_US.h"

ASniper24PS::ASniper24PS(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	SpawnClass  = AClassSniper24_US::StaticClass();
	Texture     = LoadObject<UTexture2D>(NULL, TEXT("/Game/AmericasArmy/Textures/T_AA2_Editor/PlayerStart/S24.S24"), NULL, LOAD_None, NULL);
	DrawScale   = 0.5;
	LoadEditorIcon();
}