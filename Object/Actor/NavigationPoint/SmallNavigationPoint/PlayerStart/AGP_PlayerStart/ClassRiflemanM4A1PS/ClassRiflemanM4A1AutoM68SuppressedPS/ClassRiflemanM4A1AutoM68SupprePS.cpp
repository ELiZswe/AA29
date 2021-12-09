// All the original content belonged to the US Army


#include "AA29/Object/Actor/NavigationPoint/SmallNavigationPoint/PlayerStart/AGP_PlayerStart/ClassRiflemanM4A1PS/ClassRiflemanM4A1AutoM68SuppressedPS/ClassRiflemanM4A1AutoM68SupprePS.h"
#include "AA29/Object/Actor/AI_Primitive/SoldierClass/ClassRifleman/ClassRiflemanM4A1AutoM68Suppress/ClassRiflemanM4A1AutoM68Suppress.h"

AClassRiflemanM4A1AutoM68SupprePS::AClassRiflemanM4A1AutoM68SupprePS(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	SpawnClass = AClassRiflemanM4A1AutoM68Suppress::StaticClass();
}