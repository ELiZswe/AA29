// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Patrol.generated.h"

class ANavigationPoint;
class APawn;

UCLASS()
class AA29_API APatrol : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APatrol();

	UPROPERTY(EditAnywhere)			float			NodePause;					//var() float NodePause;
	UPROPERTY(EditAnywhere)			bool			bDumbPatrol;				//var() bool bDumbPatrol;
	UPROPERTY(EditAnywhere)			bool			bDirectionalNodes;			//var() bool bDirectionalNodes;
	UPROPERTY(EditAnywhere)			TArray<APawn*>	StartPatrollers;			//var() edfindable TArray<Pawn> StartPatrollers;
	UPROPERTY(EditAnywhere)			FName			BeginPatrolState;			//var() FName BeginPatrolState;

	void PostBeginPlay();
	ANavigationPoint* GetNextNode(ANavigationPoint* CurrentNode, APawn* Bot);
	ANavigationPoint* GetNode(FVector Location, APawn* Bot);
	void Arrived(ANavigationPoint* Destination, APawn* Bot);


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
