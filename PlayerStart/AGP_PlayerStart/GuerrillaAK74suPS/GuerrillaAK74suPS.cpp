// All the original content belonged to the US Army


#include "GuerrillaAK74suPS.h"
#include "AA29/AI_Primitive/SoldierClass/ClassGuerrillaBase/ClassGuerrillaAK74su/ClassGuerrillaAK74su.h"

AGuerrillaAK74suPS::AGuerrillaAK74suPS(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	SpawnClass  = AClassGuerrillaAK74su::StaticClass();
	bGuerrilla  = true;
	Texture     = LoadObject<UTexture2D>(NULL, TEXT("/Game/AmericasArmy/Textures/T_AA2_Editor/PlayerStart/I_r.I_r"), NULL, LOAD_None, NULL);
	DrawScale   = 0.5;
	LoadEditorIcon();
}