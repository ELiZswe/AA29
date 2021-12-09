// All the original content belonged to the US Army


#include "AA29/Object/Actor/NavigationPoint/SmallNavigationPoint/PlayerStart/AGP_PlayerStart/ClassVIPPS/ClassVIPPS.h"
#include "AA29/Object/Actor/AI_Primitive/SoldierClass/ClassVIP/ClassVIP.h"

AClassVIPPS::AClassVIPPS(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	SpawnClass = AClassVIP::StaticClass();
	Texture = LoadObject<UTexture2D>(NULL, TEXT("Texture2D'/Game/AmericasArmy/Textures/T_AA2_Editor/PlayerStart/VIP.VIP'"), NULL, LOAD_None, NULL);
	DrawScale = 0.5;
	//Style = STY_Modulated;
	LoadEditorIcon();
}