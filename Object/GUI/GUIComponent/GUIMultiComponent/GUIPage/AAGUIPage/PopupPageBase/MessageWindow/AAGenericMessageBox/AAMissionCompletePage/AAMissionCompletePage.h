// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/AAGUIPage/PopupPageBase/MessageWindow/AAGenericMessageBox/AAGenericMessageBox.h"
#include "AAMissionCompletePage.generated.h"

class UGUIButton;
class UGUIImage;
class UGUILabel;

UCLASS()
class AA29_API UAAMissionCompletePage : public UAAGenericMessageBox
{
	GENERATED_BODY()
public:
	UAAMissionCompletePage();

	UPROPERTY(EditAnywhere)		UGUIButton*		b_Cancel;					//var() automated XInterface.GUIButton b_Cancel;
	UPROPERTY(EditAnywhere)		UGUIButton*		b_Retry;					//var() automated XInterface.GUIButton b_Retry;
	UPROPERTY(EditAnywhere)		UGUIImage*		i_Medal;					//var() automated XInterface.GUIImage i_Medal;
	UPROPERTY()					bool			bAuthContacted;				//var bool bAuthContacted;
	UPROPERTY()					bool			iAuthDelDotCounter;			//var int32 iAuthDelDotCounter;
	UPROPERTY(EditAnywhere)		UGUILabel*		b_CheatText;				//var() automated XInterface.GUILabel b_CheatText;

	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	bool InternalOnClick(UGUIComponent* Sender);
	bool InternalOnKeyEvent(uint8& Key, uint8& State, float Delta);
	void HandleObject(UObject* obj, UObject* OptionalObj_1, UObject* OptionalObj_2);
	FString GetDataString();
	void SetDataString(FString str);
	void OK();
	void Timer();
	void Cancel();
	void Retry();
};
