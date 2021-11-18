// All the original content belonged to the US Army


#include "RiflemanM4A1AutoPS.h"
#include "AA29/AI_Primitive/SoldierClass/ClassRifleman/ClassRiflemanM4A1AutoIron/ClassRiflemanM4A1Auto/ClassRiflemanM4A1Auto.h"

ARiflemanM4A1AutoPS::ARiflemanM4A1AutoPS(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	SpawnClass = AClassRiflemanM4A1Auto::StaticClass();
}