// All the original content belonged to the US Army


#include "RiflemanM4A1AutoM203IronPS.h"
#include "AA29/AI_Primitive/SoldierClass/ClassRifleman/ClassRiflemanM4A1AutoM203Iron/ClassRiflemanM4A1AutoM203Iron.h"

ARiflemanM4A1AutoM203IronPS::ARiflemanM4A1AutoM203IronPS(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{
	SpawnClass = AClassRiflemanM4A1AutoM203Iron::StaticClass();
}