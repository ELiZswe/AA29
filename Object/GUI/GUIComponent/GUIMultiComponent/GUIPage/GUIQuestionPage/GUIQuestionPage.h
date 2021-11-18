// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/GUIPage.h"
#include "GUIQuestionPage.generated.h"

class UGUILabel;
class UGUIButton;

UCLASS()
class AA29_API UGUIQuestionPage : public UGUIPage
{
	GENERATED_BODY()
public:
	UGUIQuestionPage();

	UPROPERTY()						UGUILabel*					lMessage;					//var GUILabel lMessage;
	UPROPERTY()						UMaterialInstance*			MessageIcon;				//var Material MessageIcon;
	UPROPERTY()						TArray<FString>				ButtonNames;				//var localized TArray<FString> ButtonNames;
	UPROPERTY()						TArray<UGUIButton*>			Buttons;					//var TArray<GUIButton> Buttons;
	UPROPERTY()						UGUIButton*					DefaultButton;				//var GUIButton DefaultButton;
	UPROPERTY()						UGUIButton*					CancelButton;				//var GUIButton CancelButton;

	void OnButtonClick(uint8 bButton);
	bool NewOnButtonClick(uint8 bButton);
	void InitComponent(UGUIController* pMyController, UGUIComponent* MyOwner);
	bool InternalOnPreDraw(UCanvas* C);
	void SetupQuestion(FString Question, uint8 bButtons, uint8 ActiveButton, bool bClearFirst);
	UGUIButton* AddButton(uint8 idesc);
	void LayoutButtons(uint8 ActiveButton);
	bool ButtonClick(UGUIComponent* Sender);
	FString Replace(FString Src, FString Tag, FString Value);
	void RemoveButtons();
};
