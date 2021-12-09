// All the original content belonged to the US Army


#include "AA29/Object/Actor/NavigationPoint/SmallNavigationPoint/PlayerStart/AGP_PlayerStart/ClassRiflemanAT4PS/ClassRiflemanAT4PS.h"
#include "AA29/Object/Actor/AI_Primitive/SoldierClass/ClassAT4Rocket/ClassAT4Rocket.h"

AClassRiflemanAT4PS::AClassRiflemanAT4PS(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	SpawnClass = AClassAT4Rocket::StaticClass();
	Texture = LoadObject<UTexture2D>(NULL, TEXT("Texture2D'/Game/AmericasArmy/Textures/T_AA2_Editor/PlayerStart/AT4a.AT4a'"), NULL, LOAD_None, NULL);
	DrawScale = 0.5;
	LoadEditorIcon();
}