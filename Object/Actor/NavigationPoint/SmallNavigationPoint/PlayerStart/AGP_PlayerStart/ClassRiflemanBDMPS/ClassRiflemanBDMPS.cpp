// All the original content belonged to the US Army


#include "AA29/Object/Actor/NavigationPoint/SmallNavigationPoint/PlayerStart/AGP_PlayerStart/ClassRiflemanBDMPS/ClassRiflemanBDMPS.h"
#include "AA29/Object/Actor/AI_Primitive/SoldierClass/ClassBDMRocket/ClassBDMRocket.h"

AClassRiflemanBDMPS::AClassRiflemanBDMPS(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	SpawnClass = AClassBDMRocket::StaticClass();
	Texture = LoadObject<UTexture2D>(NULL, TEXT("Texture2D'/Game/AmericasArmy/Textures/T_AA2_Editor/PlayerStart/bdm.bdm'"), NULL, LOAD_None, NULL);
	DrawScale = 0.5;
	LoadEditorIcon();
}