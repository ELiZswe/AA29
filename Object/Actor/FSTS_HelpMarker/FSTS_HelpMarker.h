// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AA29/MyEnums.h"
#include "FSTS_HelpMarker.generated.h"

UCLASS()
class AFSTS_HelpMarker : public AActor
{
	GENERATED_BODY()
	
public:	
	
	AFSTS_HelpMarker();

	UPROPERTY()			EBounceAxis		BounceAxis;				//var Enum EBounceAxis  BounceAxis;
	UPROPERTY()			float			BounceTime;				//var float BounceTime;
	UPROPERTY()			AActor*			MarkActor;				//var Actor MarkActor;
	UPROPERTY()			bool			bNoFollowMarkingActor;	//var bool bNoFollowMarkingActor;
	UPROPERTY()			FVector			MarkOffset;				//var Vector MarkOffset;
	UPROPERTY()			FVector			OldMarkLocation;		//var Vector OldMarkLocation;
	UPROPERTY()			FVector			OldLocation;			//var Vector OldLocation;
	UPROPERTY()			float			PrimaryDrawScale;		//var float PrimaryDrawScale;
	UPROPERTY()			float			AltDrawScale;			//var float AltDrawScale;
	UPROPERTY()			UStaticMesh*	PrimaryStaticMesh;		//var StaticMesh PrimaryStaticMesh;
	UPROPERTY()			UStaticMesh*	AltStaticMesh;			//var StaticMesh AltStaticMesh;
	UPROPERTY()			AActor*			CustomDisplay;			//var Actor CustomDisplay;
	UPROPERTY()			AActor*			CustomDisplayClass;		//var class<Actor> CustomDisplayClass;

	void PostBeginPlay();
	void Tick(float dt);
	void ChangedMarker(FVector MarkingActorLocation, FVector MarkerOffset, bool bNoFollowTarget);
	bool SetMarkingActor(AActor* Target, FVector MarkerOffset, bool bNoFollowTarget);
	bool SetMarkingLocation(FVector NewLocation, FVector MarkerOffset);
	void ActivateMarker();
	void DeactivateMarker();
	bool IsActive();
	void SetDisplayMesh(bool bUsePrimaryMesh);

protected:
	
	virtual void BeginPlay() override;

public:	
};
