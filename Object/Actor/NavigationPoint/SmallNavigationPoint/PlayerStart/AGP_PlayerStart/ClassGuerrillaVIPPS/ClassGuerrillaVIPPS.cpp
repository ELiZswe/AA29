// All the original content belonged to the US Army


#include "AA29/Object/Actor/NavigationPoint/SmallNavigationPoint/PlayerStart/AGP_PlayerStart/ClassGuerrillaVIPPS/ClassGuerrillaVIPPS.h"
#include "AA29/Object/Actor/AI_Primitive/SoldierClass/ClassGuerrillaBase/ClassGuerrillaVIP/ClassGuerrillaVIP.h"

AClassGuerrillaVIPPS::AClassGuerrillaVIPPS(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	SpawnClass = AClassGuerrillaVIP::StaticClass();
	bGuerrilla = true;
	bIFVIP = true;
	Texture = LoadObject<UTexture2D>(NULL, TEXT("Texture2D'/Game/AmericasArmy/Textures/T_AA2_Editor/PlayerStart/I_vip.I_vip'"), NULL, LOAD_None, NULL);
	DrawScale = 0.5;
	LoadEditorIcon();
}