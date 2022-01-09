// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Vignette/UT2LoadingPageBase/UT2LoadingPageBase.h"
#include "UT2SP_LadderLoading.generated.h"

class UMatchInfo;

UCLASS()
class AUT2SP_LadderLoading : public AUT2LoadingPageBase
{
	GENERATED_BODY()
public:
	AUT2SP_LadderLoading();

	UPROPERTY()		UMatchInfo*			myMatchInfo;				//var MatchInfo myMatchInfo;
	UPROPERTY()		FColor				White;						//var Color White;
	UPROPERTY()		FColor				Yellow;						//var Color Yellow;
	UPROPERTY()		FColor				Blue;						//var Color Blue;
	UPROPERTY()		FColor				Red;						//var Color Red;
	UPROPERTY()		UMaterialInstance*	Box;						//var Material Box;
	UPROPERTY()		UMaterialInstance*	CharFrame;					//var Material CharFrame;
	UPROPERTY()		TArray<FString>		StatNames;					//var localized FString StatNames[5];
	UPROPERTY()		FString				LoadingMessage;				//var localized FString LoadingMessage;

	void Init();
	void AddLoading();
	void AddBackground();
	void AddTitle();
	void AddPlayerRoster();
	void AddOpponentRoster();
	void AddTeamBar(int32 TeamID, FString TeamIconName, TArray<FString>& Crew, float Top, FColor TeamColor, bool bNameUp);
	void AddTeamCompare();

};
