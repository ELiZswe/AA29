// All the original content belonged to the US Army


#include "AA29/Object/KarmaParamsCollision/KarmaParamsCollision.h"

UKarmaParamsCollision::UKarmaParamsCollision()
{
	//PointerProperty* KarmaData = NewObject<PointerProperty>(PointerProperty::StaticClass());
	KScale = 1;
	KScale3D = FVector(1, 1, 1);
	KImpactThreshold = 1000000;
}

//native Function CalcContactRegion();
void UKarmaParamsCollision::CalcContactRegion()
{
}
