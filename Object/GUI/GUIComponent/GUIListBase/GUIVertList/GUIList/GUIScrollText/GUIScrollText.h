// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIListBase/GUIVertList/GUIList/GUIList.h"
#include "GUIScrollText.generated.h"

class AGUIController;
class AGUIComponent;

/**
 * 
 */
UCLASS()
class AA29_API UGUIScrollText : public UGUIList
{
	GENERATED_BODY()
public:
	UGUIScrollText();

	UPROPERTY(EditAnywhere)						TArray<FString> StringElements;						//var() editconstarray editconst array<String> StringElements;
	UPROPERTY(EditAnywhere)						float RepeatDelay;									//var() float RepeatDelay;
	UPROPERTY(EditAnywhere)						float EOLDelay;										//var() float EOLDelay;
	UPROPERTY(EditAnywhere)						float CharDelay;									//var() float CharDelay;
	UPROPERTY(EditAnywhere)						float InitialDelay;									//var() float InitialDelay;
	UPROPERTY(EditAnywhere)						bool bClickText;									//var() bool bClickText;
	UPROPERTY(EditAnywhere)						bool bNoTeletype;									//var() bool bNoTeletype;
	UPROPERTY(EditAnywhere)						bool bRepeat;										//var() bool bRepeat;
	UPROPERTY(EditAnywhere)						bool bReceivedNewContent;							//var const editconst bool bReceivedNewContent;
	UPROPERTY(EditAnywhere)						bool bStopped;										//var() editconst bool bStopped;
	UPROPERTY(EditAnywhere)						bool bNewContent;									//var() editconst bool bNewContent;
	UPROPERTY(EditAnywhere)						EeScrollState ScrollState;							//var() editconst eScrollState ScrollState;
	UPROPERTY(EditAnywhere)						float oldWidth;										//var() editconst float oldWidth;
	UPROPERTY(EditAnywhere)						int32 VisibleChars;									//var() editconst int VisibleChars;
	UPROPERTY(EditAnywhere)						int32 VisibleLines;									//var() editconst int VisibleLines;
	UPROPERTY(EditAnywhere)						FString Separator;									//var() editconst string Separator;
	UPROPERTY(EditAnywhere)						FString Content;									//var() editconst string Content;
	UPROPERTY(EditAnywhere)						FString ClickedString;								//var() editconst string ClickedString;
	UPROPERTY(EditAnywhere)						FString NewText;									//var() editconst string NewText;
	UPROPERTY(EditAnywhere)						int32 BonusPackMaxHistoryColor;						//var() editconst int MaxHistory;

	void GetWordUnderCursor();
	void OnEndOfLine();
	void Dump();
	void InitComponent(AGUIController* MyController, AGUIComponent* MyOwner);
	void SetContent(FString NewContent, FString sep);
	void Stop();
	void Restart();
	bool SkipChar();
	void Timer();
	bool InternalOnClick(AGUIComponent* Sender);
	bool InternalOnKeyType(uint8& Key, FString Unicode);
	bool InternalOnKeyEvent(uint8& Key, uint8& State, float Delta);
	void EndScrolling();
	bool IsValid();

};
