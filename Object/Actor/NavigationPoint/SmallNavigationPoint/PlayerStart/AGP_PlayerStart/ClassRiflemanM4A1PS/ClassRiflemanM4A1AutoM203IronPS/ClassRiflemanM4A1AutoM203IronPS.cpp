// All the original content belonged to the US Army


#include "AA29/Object/Actor/NavigationPoint/SmallNavigationPoint/PlayerStart/AGP_PlayerStart/ClassRiflemanM4A1PS/ClassRiflemanM4A1AutoM203IronPS/ClassRiflemanM4A1AutoM203IronPS.h"
#include "AA29/Object/Actor/AI_Primitive/SoldierClass/ClassRifleman/ClassRiflemanM4A1AutoM203Iron/ClassRiflemanM4A1AutoM203Iron.h"

AClassRiflemanM4A1AutoM203IronPS::AClassRiflemanM4A1AutoM203IronPS(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	SpawnClass = AClassRiflemanM4A1AutoM203Iron::StaticClass();
}