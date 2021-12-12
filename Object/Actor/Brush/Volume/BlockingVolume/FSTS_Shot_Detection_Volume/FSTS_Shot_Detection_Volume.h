// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Brush/Volume/AA2_Volume.h"
#include "FSTS_Shot_Detection_Volume.generated.h"

class AFA_EL_Ambush;

UCLASS()
class AA29_API AFSTS_Shot_Detection_Volume : public AAA2_Volume
{
	GENERATED_BODY()
public:
	AFSTS_Shot_Detection_Volume();

	UPROPERTY()											AFA_EL_Ambush* Ambush_Lab;				//var FA_EL_Ambush Ambush_Lab;


	//From BlockingVolume
	UPROPERTY(EditAnywhere)											TArray<AActor*> BlockedClasses;			//var() array<class<Actor> > BlockedClasses;
	UPROPERTY(EditAnywhere)											bool bClassBlocker;						//var() bool bClassBlocker;
	UPROPERTY(EditAnywhere)											bool bClampFluid;						//var() bool bClampFluid;
};
