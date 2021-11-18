// All the original content belonged to the US Army


#include "RiflemanAT4PS.h"
#include "AA29/AI_Primitive/SoldierClass/ClassAT4Rocket/ClassAT4Rocket.h"

ARiflemanAT4PS::ARiflemanAT4PS(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	SpawnClass  = AClassAT4Rocket::StaticClass();
	Texture     = LoadObject<UTexture2D>(NULL, TEXT("/Game/AmericasArmy/Textures/T_AA2_Editor/PlayerStart/AT4a.AT4a"), NULL, LOAD_None, NULL);
	DrawScale   = 0.5;
	LoadEditorIcon();
}