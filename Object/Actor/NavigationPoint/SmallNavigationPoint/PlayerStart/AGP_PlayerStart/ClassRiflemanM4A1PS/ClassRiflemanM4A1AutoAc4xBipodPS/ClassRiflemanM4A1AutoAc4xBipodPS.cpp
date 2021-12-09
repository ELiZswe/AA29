// All the original content belonged to the US Army


#include "AA29/Object/Actor/NavigationPoint/SmallNavigationPoint/PlayerStart/AGP_PlayerStart/ClassRiflemanM4A1PS/ClassRiflemanM4A1AutoAc4xBipodPS/ClassRiflemanM4A1AutoAc4xBipodPS.h"
#include "AA29/Object/Actor/AI_Primitive/SoldierClass/ClassRifleman/ClassRiflemanM4A1AutoAcog4xBipod/ClassRiflemanM4A1AutoAcog4xBipod.h"

AClassRiflemanM4A1AutoAc4xBipodPS::AClassRiflemanM4A1AutoAc4xBipodPS(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	SpawnClass = AClassRiflemanM4A1AutoAcog4xBipod::StaticClass();
}