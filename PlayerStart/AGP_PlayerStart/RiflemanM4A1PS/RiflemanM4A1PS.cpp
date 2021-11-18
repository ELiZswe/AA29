// All the original content belonged to the US Army


#include "AA29/PlayerStart/AGP_PlayerStart/RiflemanM4A1PS/RiflemanM4A1PS.h"
#include "AA29/AI_Primitive/SoldierClass/ClassRifleman/ClassRiflemanM4A1AutoIron/ClassRiflemanM4A1AutoIron.h"

ARiflemanM4A1PS::ARiflemanM4A1PS(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	SpawnClass	= AClassRiflemanM4A1AutoIron::StaticClass();
	Texture		= LoadObject<UTexture2D>(NULL, TEXT("/Game/AmericasArmy/Textures/T_AA2_Editor/PlayerStart/R.R"), NULL, LOAD_None, NULL);
	DrawScale	= 0.5;
	LoadEditorIcon();
}