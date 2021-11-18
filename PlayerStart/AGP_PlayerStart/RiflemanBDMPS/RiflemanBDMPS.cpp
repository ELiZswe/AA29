// All the original content belonged to the US Army


#include "RiflemanBDMPS.h"
#include "AA29/AI_Primitive/SoldierClass/ClassBDMRocket/ClassBDMRocket.h"

ARiflemanBDMPS::ARiflemanBDMPS(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	SpawnClass	= AClassBDMRocket::StaticClass();
	Texture		= LoadObject<UTexture2D>(NULL, TEXT("/Game/AmericasArmy/Textures/T_AA2_Editor/PlayerStart/bdm.bdm"), NULL, LOAD_None, NULL);
	DrawScale	= 0.5;
	LoadEditorIcon();
}