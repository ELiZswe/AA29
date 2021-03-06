// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Triggers/Triggers.h"
#include "SVehicleTrigger.generated.h"

class ANavigationPoint;

UCLASS()
class ASVehicleTrigger : public ATriggers
{
	GENERATED_BODY()
public:
	ASVehicleTrigger();
	
	UPROPERTY(EditAnywhere)		bool				bEnabled;				//var() bool bEnabled;
	UPROPERTY()					bool				BACKUP_bEnabled;		//var bool BACKUP_bEnabled;
	UPROPERTY()					bool				bMarkWithPath;			//var bool bMarkWithPath;
	UPROPERTY()					ANavigationPoint*	myMarker;				//var NavigationPoint myMarker;

	void PostBeginPlay();
	void Trigger(AActor* Other, APawn* EventInstigator);
	bool UsedBy(APawn* User);
	void Reset();
};
