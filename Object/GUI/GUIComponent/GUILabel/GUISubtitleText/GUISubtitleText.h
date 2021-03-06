// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUILabel/GUILabel.h"
#include "GUISubtitleText.generated.h"

UCLASS()
class UGUISubtitleText : public UGUILabel
{
	GENERATED_BODY()
public:
	UGUISubtitleText();

	UPROPERTY()										EDisplayState DisplayState;					//var eDisplayState DisplayState;
	UPROPERTY()										int32 CurLine;								//var int CurLine;
	UPROPERTY()										FString Separator;							//var string Separator;
	UPROPERTY()										float GuessCharTime;						//var() float GuessCharTime;
	UPROPERTY()										float InitialDelay;							//var() float InitialDelay;
	UPROPERTY()										float DelayTime;							//var() float DelayTime;
	UPROPERTY()										float VisibleTime;							//var() float VisibleTime;
	UPROPERTY()										TArray<FVisibleDelay> SubTitleTiming;		//var() array<VisibleDelay> SubTitleTiming;
	UPROPERTY()										TArray<FString> SubTitles;					//var() TArray<FString> SubTitles;

	void OnStopped();
	void Restart();
	void Stop();
	int32 SetSubtitles(FString alldata, FString sep, bool bDontGuess, FString lengthdata);
	int32 AddSubtitle(FString NewTitle, float Delay, float Visible);
	int32 InsertSubtitle(int32 Position, FString NewTitle, float Delay, float Visible);
	void ClearSubtitles();
	void Timer();
};
