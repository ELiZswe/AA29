// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Info/ZoneInfo/ZoneInfo.h"
#include "AA29/AA29.h"
#include "WarpZoneInfo.generated.h"

UCLASS()
class AWarpZoneInfo : public AZoneInfo
{
	GENERATED_BODY()
public:
	AWarpZoneInfo();

	UPROPERTY(EditAnywhere)			FString				OtherSideURL;			//var() FString OtherSideURL;
	UPROPERTY(EditAnywhere)			FString				ThisTag;				//var() FName ThisTag;
	UPROPERTY(EditAnywhere)			bool				bNoTeleFrag;			//var() bool bNoTeleFrag;
	UPROPERTY()						int32				iWarpZone;				//var const int32 iWarpZone;
	UPROPERTY()						FCoords				WarpCoords;				//var const Coords WarpCoords;
	UPROPERTY()						AWarpZoneInfo*		OtherSideActor;			//var transient WarpZoneInfo OtherSideActor;
	UPROPERTY()						UObject*			OtherSideLevel;			//var transient Object OtherSideLevel;
	UPROPERTY(EditAnywhere)			TArray<FString>		Destinations;			//var() FString Destinations[8];
	UPROPERTY()						int32				numDestinations;		//var int32 numDestinations;

	void Warp(FVector& loc, FVector& Vel, FRotator& R);
	void UnWarp(FVector& loc, FVector& Vel, FRotator& R);
	void PreBeginPlay();
	void Trigger(AActor* Other, APawn* EventInstigator);
	void Generate();
	void ForceGenerate();
	void ActorEntered(AActor* Other);
	void ActorLeaving(AActor* Other);
};
