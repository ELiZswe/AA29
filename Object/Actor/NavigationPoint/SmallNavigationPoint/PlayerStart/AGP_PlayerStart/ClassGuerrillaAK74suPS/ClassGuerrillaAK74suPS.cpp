// All the original content belonged to the US Army


#include "AA29/Object/Actor/NavigationPoint/SmallNavigationPoint/PlayerStart/AGP_PlayerStart/ClassGuerrillaAK74suPS/ClassGuerrillaAK74suPS.h"
#include "AA29/Object/Actor/AI_Primitive/SoldierClass/ClassGuerrillaBase/ClassGuerrillaAK74su/ClassGuerrillaAK74su.h"

AClassGuerrillaAK74suPS::AClassGuerrillaAK74suPS(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	SpawnClass = AClassGuerrillaAK74su::StaticClass();
	bGuerrilla = true;
	Texture = LoadObject<UTexture2D>(NULL, TEXT("Texture2D'/Game/AmericasArmy/Textures/T_AA2_Editor/PlayerStart/I_r.I_r'"), NULL, LOAD_None, NULL);
	DrawScale = 0.5;
	LoadEditorIcon();
}