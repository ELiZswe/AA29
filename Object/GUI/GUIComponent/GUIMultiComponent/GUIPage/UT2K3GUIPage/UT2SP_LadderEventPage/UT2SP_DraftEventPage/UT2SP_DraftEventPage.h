// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/UT2K3GUIPage/UT2SP_LadderEventPage/UT2SP_LadderEventPage.h"
#include "UT2SP_DraftEventPage.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UUT2SP_DraftEventPage : public UUT2SP_LadderEventPage
{
	GENERATED_BODY()
public:
	UUT2SP_DraftEventPage();

	UPROPERTY()			FString				MessageDraft;				//var localized FString MessageDraft;
	UPROPERTY()			FString				MessageDraftTitle;			//var localized FString MessageDraftTitle;

	void InitComponent(UGUIController* pMyController, UGUIComponent* MyOwner);
	bool InternalOnClick(UGUIComponent* Sender);
	void SetTutorialName(FString tutname);
};
