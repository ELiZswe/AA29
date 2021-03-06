// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/AnimNotify/AA2_AnimNotify.h"
#include "AnimNotify_LIPSinc.generated.h"

UCLASS()
class UAnimNotify_LIPSinc : public UAA2_AnimNotify
{
	GENERATED_BODY()
public:
	UAnimNotify_LIPSinc();

	UPROPERTY(EditAnywhere)				float	Pitch;					//var() float Pitch;
	UPROPERTY(EditAnywhere)				int32	Radius;					//var() int Radius;
	UPROPERTY(EditAnywhere)				float	Volume;					//var() float Volume;
	UPROPERTY(EditAnywhere)				FName	LIPSincAnimName;		//var() name LIPSincAnimName;
};
