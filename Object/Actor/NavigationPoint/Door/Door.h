// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/NavigationPoint/NavigationPoint.h"
#include "Door.generated.h"

class AMover;

UCLASS()
class ADoor : public ANavigationPoint
{
	GENERATED_BODY()
public:
	ADoor();

	UPROPERTY()							bool		bTempNoCollide;			//var bool bTempNoCollide;
	UPROPERTY()							bool		bDoorOpen;				//var bool bDoorOpen;
	UPROPERTY(EditAnywhere)				bool		bBlockedWhenClosed;		//var() bool bBlockedWhenClosed;
	UPROPERTY(EditAnywhere)				bool		bInitiallyClosed;		//var() bool bInitiallyClosed;
	UPROPERTY()							AActor*		RecommendedTrigger;		//var Actor RecommendedTrigger;
	UPROPERTY(EditAnywhere)				FName		DoorTrigger;			//var() name DoorTrigger;
	UPROPERTY()							AMover*		MyDoor;					//var Mover MyDoor;
	UPROPERTY(EditAnywhere)				FName		DoorTag;				//var() name DoorTag;

	void PostBeginPlay();
	void MoverOpened();
	void MoverClosed();
	AActor* SpecialHandling(APawn* Other);
	bool ProceedWithMove(APawn* Other);
	bool SuggestMovePreparation(APawn* Other);
};
