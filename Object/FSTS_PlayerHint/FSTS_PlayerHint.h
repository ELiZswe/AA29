// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "FSTS_PlayerHint.generated.h"

class AEventLab;

UCLASS()
class UFSTS_PlayerHint : public UObject
{
	GENERATED_BODY()
public:
	UFSTS_PlayerHint();

	UPROPERTY()											AEventLab* MyEventlab;					//var AGP_Script.EventLab MyEventlab;
	UPROPERTY()											bool bRemoveWhenSatisfied;				//var bool bRemoveWhenSatisfied;
	UPROPERTY()											bool bDisplayOnlyOnce;					//var bool bDisplayOnlyOnce;
	UPROPERTY()											bool bIsDisplaying;						//var bool bIsDisplaying;
	UPROPERTY()											bool bHasDisplayed;						//var bool bHasDisplayed;
	UPROPERTY()											UFSTS_PlayerHint* NextHint;				//var FSTS_PlayerHint NextHint;
	UPROPERTY()											float TimeBeforeRedisplay;				//var float TimeBeforeRedisplay;
	UPROPERTY()											TArray<int32> SatisfiedLSMessage;		//var array<int> SatisfiedLSMessage;
	UPROPERTY()											TArray<int32> LSMessage;				//var array<int> LSMessage;
	UPROPERTY()											float TimeLastDisplayed;				//var float TimeLastDisplayed;
	UPROPERTY()											float TimeToDisplay;					//var float TimeToDisplay;
	UPROPERTY()											float TimeBeforeDisplay;				//var float TimeBeforeDisplay;
	UPROPERTY()											float TimeDelayStarted;					//var float TimeDelayStarted;
	UPROPERTY()											FString MsgTxt2;						//var string MsgTxt2;
	UPROPERTY()											FString MsgTxt1;						//var string MsgTxt1;

	bool IsAppropriate();
	bool IsSatisfied();
	bool StartDisplay();
	bool ContinueDisplay();
	void Reset();
	bool Always();
	bool Never();
};
