// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Triggers/RandomDispatcher/RandomDispatcher.h"
#include "TargetManager.generated.h"

class AScoreKeeper;

UCLASS()
class ATargetManager : public ARandomDispatcher
{
	GENERATED_BODY()
public:
	ATargetManager();

	UPROPERTY()					bool				bActive;				//var bool bActive;
	UPROPERTY()					AScoreKeeper*		_ScoreKeeper;			//var AGP.ScoreKeeper _ScoreKeeper;
	UPROPERTY()					bool				bSkipTargets;			//var bool bSkipTargets;
	UPROPERTY()					bool				bTargetPractice;		//var bool bTargetPractice;
	UPROPERTY(EditAnywhere)		TArray<FString>		TargetGroupLabel;		//var() string TargetGroupLabel;
	UPROPERTY(EditAnywhere)		FString				TargetScoreLabel;		//var() string TargetScoreLabel;

	bool isActivelyTesting();
	void BeginPlay();
	void Trigger(AActor* Other, APawn* EventInstigator);
	void UnTrigger(AActor* Other, APawn* EventInstigator);
	void SetTargetPractice(bool new_practice);
	AScoreKeeper* getScoreKeeper();
	void DispatchComplete();
	void ResetScores();
	void StartDispatch();
	void EndDispatch();
	void StartPractice();
	void EndPractice();
	bool groupNotUsed(int32 group_number);
	void ReportTargetUp(int32 group_number);
	void ReportTargetDown(int32 group_number, bool bShot);
	void ReportTargetSkipped(int32 group_number);
};
