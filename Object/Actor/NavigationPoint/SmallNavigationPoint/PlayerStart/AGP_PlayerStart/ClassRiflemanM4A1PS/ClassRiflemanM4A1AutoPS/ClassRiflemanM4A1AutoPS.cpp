// All the original content belonged to the US Army


#include "AA29/Object/Actor/NavigationPoint/SmallNavigationPoint/PlayerStart/AGP_PlayerStart/ClassRiflemanM4A1PS/ClassRiflemanM4A1AutoPS/ClassRiflemanM4A1AutoPS.h"
#include "AA29/AI_Primitive/SoldierClass/ClassRifleman/ClassRiflemanM4A1AutoIron/ClassRiflemanM4A1Auto/ClassRiflemanM4A1Auto.h"

AClassRiflemanM4A1AutoPS::AClassRiflemanM4A1AutoPS(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	SpawnClass = AClassRiflemanM4A1Auto::StaticClass();
}