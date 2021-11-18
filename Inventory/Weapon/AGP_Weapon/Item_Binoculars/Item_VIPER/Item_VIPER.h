// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Inventory/Weapon/AGP_Weapon/Item_Binoculars/Item_Binoculars.h"
#include "Item_VIPER.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AItem_VIPER : public AItem_Binoculars
{
	GENERATED_BODY()
public:
	AItem_VIPER();
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		FString TAGAquiredForce;		//var() string TAGAquiredForce;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		FString TAGMarkForce;			//var() string TAGMarkForce;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		FString TAGFireForce;			//var() string TAGFireForce;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		USoundBase* AquiredSound;		//var() Sound AquiredSound;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		USoundBase* MarkSound;			//var() Sound MarkSound;
	UPROPERTY()										uint8 FirstStrike;				//var AGP.CallForSupport FirstStrike;
	UPROPERTY()										FVector EndEffect;				//var FVector EndEffect;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		float PaintDuration;			//var() float PaintDuration;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		float TraceRange;				//var() float TraceRange;
	UPROPERTY()										AActor* TraceTarget;			//var Actor TraceTarget;
	UPROPERTY()										FVector TargetNormal;			//var FVector TargetNormal;
	UPROPERTY()										FVector TargetLocation;			//var FVector TargetLocation;
	UPROPERTY()										FVector MarkLocation;			//var FVector MarkLocation;
	UPROPERTY()										float MarkTime;					//var float MarkTime;
	//UPROPERTY()									ACallForSupport* Support;		//var AGP.CallForSupport Support;
	//UPROPERTY()									ACallForSupport* SupportClass;	//var class<AGP.CallForSupport> SupportClass;
	UPROPERTY()										bool bMarkStarted;				//var bool bMarkStarted;
	UPROPERTY()										bool bAlreadyMarked;			//var bool bAlreadyMarked;
	UPROPERTY()										bool bInitialMark;				//var bool bInitialMark;
	UPROPERTY()										bool bValidMark;				//var bool bValidMark;
	UPROPERTY()										bool bDoHit;					//var bool bDoHit;
	UPROPERTY()										float UpTime;					//var float UpTime;
	UPROPERTY()										bool bIsFiring;					//var bool bIsFiring;
};
