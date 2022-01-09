// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Volume.h"
#include "AA2_Volume.generated.h"

class ADecorationList;

UCLASS()
class AAA2_Volume : public AVolume
{
	GENERATED_BODY()
public:
	AAA2_Volume();

	UPROPERTY()												AActor*				AssociatedActor;			//var Actor AssociatedActor;
	UPROPERTY(EditAnywhere, Category = "PickupZone")		FName				AssociatedActorTag;			//var() FName AssociatedActorTag;
	UPROPERTY(EditAnywhere, Category = "PickupZone")		int32				LocationPriority;			//var(CommLocation) int32 LocationPriority;
	UPROPERTY(EditAnywhere, Category = "PickupZone")		FString				LocationName;				//var(CommLocation) localized FString LocationName;
	UPROPERTY(EditAnywhere, Category = "PickupZone")		FName				LocationObjective;			//var(CommLocation) FName LocationObjective;
	UPROPERTY(EditAnywhere, Category = "PickupZone")		bool				bScoreHelper;				//var(CommLocation) bool bScoreHelper;
	UPROPERTY(EditAnywhere, Category = "PickupZone")		bool				bScoreDefender;				//var(CommLocation) bool bScoreDefender;
	UPROPERTY(EditAnywhere, Category = "PickupZone")		ADecorationList*	DecoList;					//var() edfindable DecorationList DecoList;
	UPROPERTY()												bool				bIsCommVolume;				//var bool bIsCommVolume;
	UPROPERTY()												AActor*				Objective;					//var Actor Objective;
	UPROPERTY()												float				XY_Area;					//var float XY_Area;

	bool Encompasses(AActor* Other);
	bool EncompassesPoint(FVector Point);
	bool BetterThan(AActor* Other);
	AActor* GetNearbyObjective(bool bDefender);
	void BeginPlay();
	void SetAssociatedActor(AActor* Other);
	void PostBeginPlay();
	void DisplayDebug(class UCanvas* Canvas, const class FDebugDisplayInfo& DebugDisplay, float& YL, float& YPos);
};
