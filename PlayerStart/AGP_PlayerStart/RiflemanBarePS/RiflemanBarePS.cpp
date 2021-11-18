// All the original content belonged to the US Army


#include "RiflemanBarePS.h"
#include "AA29/AI_Primitive/SoldierClass/ClassRiflemanBare/ClassRiflemanBare.h"

ARiflemanBarePS::ARiflemanBarePS(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	SpawnClass  = AClassRiflemanBare::StaticClass();
	Texture     = LoadObject<UTexture2D>(NULL, TEXT("/Game/AmericasArmy/Textures/T_AA2_Editor/PlayerStart/R.R"), NULL, LOAD_None, NULL);
	DrawScale   = 0.5;
	LoadEditorIcon();
}