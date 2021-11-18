// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AA29/AA29.h"
#include "ScoreKeeper.generated.h"

UCLASS()
class AA29_API AScoreKeeper : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AScoreKeeper();

	UPROPERTY()										TArray<FTarGroup> TargetGroup;						//var ScoreKeeper.TarGroup TargetGroup;
	UPROPERTY()										FTarGroup TotalScore;								//var ScoreKeeper.TarGroup TotalScore;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void ResetScores();
	void incrementTotal(int32 group_number);
	void incrementMissed(int32 group_number);
	void incrementShot(int32 group_number);
	void SetLabel(FString group_label);
	void setGroupLabel(int32 group_number, FString group_label);
	FString GetLabel();
	FString getGroupLabel(int32 group_number);
	void printTargetGroups();



};
