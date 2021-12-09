// All the original content belonged to the US Army


#include "AA29/Object/Actor/NavigationPoint/SmallNavigationPoint/PlayerStart/AGP_PlayerStart/FSTS_PlayerStart/FA_RiflemanPS/FA_RiflemanPS.h"
#include "AA29/Object/Actor/AI_Primitive/SoldierClass/FA_ClassRifleman/FA_ClassRifleman.h"

AFA_RiflemanPS::AFA_RiflemanPS(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	SpawnClass = AFA_ClassRifleman::StaticClass();
	Texture = LoadObject<UTexture2D>(NULL, TEXT("Texture2D'/Game/AmericasArmy/Textures/T_AA2_Editor/PlayerStart/R.R'"), NULL, LOAD_None, NULL);
	DrawScale = 0.5;
	LoadEditorIcon();

}