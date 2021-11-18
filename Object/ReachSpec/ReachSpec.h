// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ReachSpec.generated.h"

class ANavigationPoint;

UCLASS(Config = Game)
class AA29_API UReachSpec : public UObject
{
	GENERATED_BODY()
public:
	UReachSpec();


	UPROPERTY(config)								FVector PathColor_Narrow;				//var config Object.Vector PathColor_Narrow;
	UPROPERTY(config)								FVector PathColor_SuperWide;			//var config Object.Vector PathColor_SuperWide;
	UPROPERTY(config)								FVector PathColor_VeryWide;				//var config Object.Vector PathColor_VeryWide;
	UPROPERTY(config)								FVector PathColor_Wide;					//var config Object.Vector PathColor_Wide;
	UPROPERTY(config)								FVector PathColor_Ladder;				//var config Object.Vector PathColor_Ladder;
	UPROPERTY(config)								FVector PathColor_Proscribed;			//var config Object.Vector PathColor_Proscribed;
	UPROPERTY(config)								FVector PathColor_Special;				//var config Object.Vector PathColor_Special;
	UPROPERTY(config)								FVector PathColor_Forced;				//var config Object.Vector PathColor_Forced;
	UPROPERTY()										bool bForced;							//var bool bForced;
	UPROPERTY()										uint8 bPruned;							//var byte bPruned;
	UPROPERTY()										int32 MaxLandingVelocity;				//var int MaxLandingVelocity;
	UPROPERTY()										int32 reachFlags;						//var int reachFlags;
	UPROPERTY()										int32 CollisionHeight;					//var int CollisionHeight;
	UPROPERTY()										int32 CollisionRadius;					//var int CollisionRadius;
	UPROPERTY()										ANavigationPoint* End;					//var const NavigationPoint End;
	UPROPERTY()										ANavigationPoint* Start;				//var const NavigationPoint Start;
	UPROPERTY()										int32 Distance;							//var int Distance;
};
