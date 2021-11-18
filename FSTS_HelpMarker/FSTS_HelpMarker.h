// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FSTS_HelpMarker.generated.h"

UCLASS()
class AA29_API AFSTS_HelpMarker : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFSTS_HelpMarker();

	UPROPERTY()						AActor* CustomDisplayClass;									//var class<Actor> CustomDisplayClass;
	UPROPERTY()						AActor* CustomDisplay;										//var Actor CustomDisplay;
	UPROPERTY()						EBounceAxis BounceAxis;										//var EBounceAxis BounceAxis;
	UPROPERTY()						UStaticMesh* AltStaticMesh;									//var StaticMesh AltStaticMesh;
	UPROPERTY()						UStaticMesh* PrimaryStaticMesh;								//var StaticMesh PrimaryStaticMesh;
	UPROPERTY()						float AltDrawScale;											//var float AltDrawScale;
	UPROPERTY()						float PrimaryDrawScale;										//var float PrimaryDrawScale;
	UPROPERTY()						FVector OldLocation;										//var FVector OldLocation;
	UPROPERTY()						FVector OldMarkLocation;									//var FVector OldMarkLocation;
	UPROPERTY()						FVector MarkOffset;											//var FVector MarkOffset;
	UPROPERTY()						bool bNoFollowMarkingActor;									//var bool bNoFollowMarkingActor;
	UPROPERTY()						AActor* MarkActor;											//var Actor MarkActor;
	UPROPERTY()						float BounceTime;											//var float BounceTime;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
