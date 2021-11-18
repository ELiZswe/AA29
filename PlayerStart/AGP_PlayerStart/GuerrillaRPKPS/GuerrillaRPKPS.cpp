// All the original content belonged to the US Army


#include "GuerrillaRPKPS.h"
#include "AA29/AI_Primitive/SoldierClass/ClassGuerrillaBase/ClassGuerrillaRPK/ClassGuerrillaRPK.h"

AGuerrillaRPKPS::AGuerrillaRPKPS(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	SpawnClass  = AClassGuerrillaRPK::StaticClass();
	bGuerrilla  = true;
	Texture     = LoadObject<UTexture2D>(NULL, TEXT("/Game/AmericasArmy/Textures/T_AA2_Editor/PlayerStart/I_rpk.I_rpk"), NULL, LOAD_None, NULL);
	DrawScale   = 0.5;
	LoadEditorIcon();
}