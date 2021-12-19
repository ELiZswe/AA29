// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Volume.h"
#include "CommVolume.generated.h"

UCLASS()
class ACommVolume : public AVolume
{
	GENERATED_BODY()
public:
	ACommVolume();

	void Touch(AActor* Other);
	void UnTouch(AActor* Other);

	UPROPERTY(EditAnywhere, BlueprintReadWrite)		FString Location;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		uint8 Priority;
	UPROPERTY()										bool PlayerInside;

	//From Volume
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CommLocation")		int32 LocationPriority;			//var(CommLocation) int32 LocationPriority;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CommLocation")		FString LocationName;			//var(CommLocation) localized FString LocationName;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CommLocation")		FName LocationObjective;		//var(CommLocation) FName LocationObjective;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CommLocation")		bool bScoreHelper;				//var(CommLocation) bool bScoreHelper;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CommLocation")		bool bScoreDefender;			//var(CommLocation) bool bScoreDefender;
	UPROPERTY()																	bool bIsCommVolume;				//var bool bIsCommVolume;
};


