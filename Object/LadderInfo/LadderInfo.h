// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "LadderInfo.generated.h"

class UMatchInfo;
class UGameProfile;

UCLASS()
class ULadderInfo : public UObject
{
	GENERATED_BODY()
public:
	ULadderInfo();

	UPROPERTY(EditAnywhere)			TArray<UMatchInfo*>		DMMatches;					//var() array<MatchInfo> DMMatches;
	UPROPERTY(EditAnywhere)			TArray<UMatchInfo*>		TDMMatches;					//var() array<MatchInfo> TDMMatches;
	UPROPERTY(EditAnywhere)			TArray<UMatchInfo*>		DOMMatches;					//var() array<MatchInfo> DOMMatches;
	UPROPERTY(EditAnywhere)			TArray<UMatchInfo*>		CTFMatches;					//var() array<MatchInfo> CTFMatches;
	UPROPERTY(EditAnywhere)			TArray<UMatchInfo*>		BRMatches;					//var() array<MatchInfo> BRMatches;
	UPROPERTY(EditAnywhere)			TArray<UMatchInfo*>		ChampionshipMatches;		//var() array<MatchInfo> ChampionshipMatches;
	UPROPERTY()						TArray<int32>			OpenNextLadderAtRung;		//var int OpenNextLadderAtRung;

	FString UpdateLadders(UGameProfile* G, int32 CurrentLadder);
	UMatchInfo* GetMatchInfo(int32 Ladder, int32 rung);
	UMatchInfo* GetCurrentMatchInfo(UGameProfile* G);
	FString MakeURLFor(UGameProfile* G);
	FString GetMatchDescription(UGameProfile* G);
	int32 LengthOfLadder(int32 Ladder);
};
