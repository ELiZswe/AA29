// All the original content belonged to the US Army


#include "GuerrillaRPGPS.h"
#include "AA29/AI_Primitive/SoldierClass/ClassGuerrillaBase/ClassGuerrillaRPG/ClassGuerrillaRPG.h"

AGuerrillaRPGPS::AGuerrillaRPGPS(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	SpawnClass		= AClassGuerrillaRPG::StaticClass();
	bGuerrilla		= true;
	Texture			= LoadObject<UTexture2D>(NULL, TEXT("/Game/AmericasArmy/Textures/T_AA2_Editor/PlayerStart/I_rpg.I_rpg"), NULL, LOAD_None, NULL);
	DrawScale		= 0.5;
	LoadEditorIcon();
}