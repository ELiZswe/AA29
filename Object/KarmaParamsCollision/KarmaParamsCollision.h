// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AA29/AA29.h"
#include "KarmaParamsCollision.generated.h"

UCLASS()
class AA29_API UKarmaParamsCollision : public UObject
{
	GENERATED_BODY()
public:
	UKarmaParamsCollision();

	UPROPERTY()										Fpointer KarmaData;								//var const transient Fpointer KarmaData;
	UPROPERTY()										float KScale;									//var const float KScale;
	UPROPERTY()										FVector KScale3D;								//var const Vector KScale3D;
	UPROPERTY()										FVector KAcceleration;							//var Vector KAcceleration;
	UPROPERTY()										float KFriction;								//var() float KFriction;
	UPROPERTY()										float KRestitution;								//var() float KRestitution;
	UPROPERTY()										float KImpactThreshold;							//var() float KImpactThreshold;
	UPROPERTY()										bool bContactingLevel;							//var const bool bContactingLevel;
	UPROPERTY()										FVector ContactRegionCenter;					//var const Vector ContactRegionCenter;
	UPROPERTY()										FVector ContactRegionNormal;					//var const Vector ContactRegionNormal;
	UPROPERTY()										float ContactRegionRadius;						//var const float ContactRegionRadius;
	UPROPERTY()										float ContactRegionNormalForce;					//var const float ContactRegionNormalForce;
	
	void CalcContactRegion();
};
