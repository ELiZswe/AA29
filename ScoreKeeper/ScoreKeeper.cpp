// All the original content belonged to the US Army


#include "AA29/ScoreKeeper/ScoreKeeper.h"

// Sets default values
AScoreKeeper::AScoreKeeper()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AScoreKeeper::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AScoreKeeper::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


void AScoreKeeper::ResetScores()
{
	int32 i;
	for (i = 0; i < 8; i++)
	{
		TargetGroup[i].nShot = 0;
		TargetGroup[i].nMissed = 0;
		TargetGroup[i].nTotal = 0;
	}
	TotalScore.nShot = 0;
	TotalScore.nMissed = 0;
	TotalScore.nTotal = 0;
}
void AScoreKeeper::incrementTotal(int32 group_number)
{
	TargetGroup[group_number].nTotal++;
	TotalScore.nTotal++;
}
void AScoreKeeper::incrementMissed(int32 group_number)
{
	TargetGroup[group_number].nMissed++;
	TotalScore.nMissed++;
}
void AScoreKeeper::incrementShot(int32 group_number)
{
	TargetGroup[group_number].nShot++;
	TotalScore.nShot++;
}
void AScoreKeeper::SetLabel(FString group_label)
{
	TotalScore.Label = group_label;
}
void AScoreKeeper::setGroupLabel(int32 group_number, FString group_label)
{
	TargetGroup[group_number].Label = group_label;
}
FString AScoreKeeper::GetLabel()
{
	return TotalScore.Label;
}
FString AScoreKeeper::getGroupLabel(int32 group_number)
{
	return TargetGroup[group_number].Label;
}
void AScoreKeeper::printTargetGroups()
{
	int32 i;
	//Log("ScoreKeeper::printTargetGroups()	Groups");
	for (i = 0; i < 8; i++)
	{
		//Log("ScoreKeeper::printTargetGroups()		" $ TargetGroup[i].Label @ TargetGroup[i].nTotal @ TargetGroup[i].nShot @ TargetGroup[i].nMissed);
	}
	//Log("ScoreKeeper::printTargetGroups()		Total	" $ TotalScore.Label @ TotalScore.nTotal @ TotalScore.nShot @ TotalScore.nMissed);
}


