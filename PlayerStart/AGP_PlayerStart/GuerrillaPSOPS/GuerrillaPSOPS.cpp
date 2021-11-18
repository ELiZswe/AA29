// All the original content belonged to the US Army


#include "GuerrillaPSOPS.h"
#include "AA29/AI_Primitive/SoldierClass/ClassGuerrillaBase/ClassGuerrillaAK74su/ClassGuerrillaPSO/ClassGuerrillaPSO.h"

AGuerrillaPSOPS::AGuerrillaPSOPS(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	SpawnClass  = AClassGuerrillaPSO::StaticClass();
	bGuerrilla  = true;
	Texture     = LoadObject<UTexture2D>(NULL, TEXT("/Game/AmericasArmy/Textures/T_AA2_Editor/PlayerStart/I_r.I_r"), NULL, LOAD_None, NULL);
	DrawScale   = 0.5;
	LoadEditorIcon();
}