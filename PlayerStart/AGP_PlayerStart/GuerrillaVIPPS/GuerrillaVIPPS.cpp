// All the original content belonged to the US Army


#include "GuerrillaVIPPS.h"
#include "AA29/AI_Primitive/SoldierClass/ClassGuerrillaBase/ClassGuerrillaVIP/ClassGuerrillaVIP.h"

AGuerrillaVIPPS::AGuerrillaVIPPS(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	SpawnClass  = AClassGuerrillaVIP::StaticClass();
	bGuerrilla  = true;
	bIFVIP      = true;
	Texture     = LoadObject<UTexture2D>(NULL, TEXT("/Game/AmericasArmy/Textures/T_AA2_Editor/PlayerStart/I_vip.I_vip"), NULL, LOAD_None, NULL);
	DrawScale   = 0.5;
	LoadEditorIcon();
}