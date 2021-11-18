// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAMainSubPanel/AABackgroundSubPanel/AABackgroundSubPanel.h"
#include "AARecordBriefSubPanel.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UAARecordBriefSubPanel : public UAABackgroundSubPanel
{
	GENERATED_BODY()
public:
	UAARecordBriefSubPanel();


	UPROPERTY()			FString				DefaultPanelText;				//var FString DefaultPanelText;
	UPROPERTY()			FString				LoggedInPanelText;				//var FString LoggedInPanelText;
	UPROPERTY()			int32				ResultCode;						//var int32 ResultCode;
	UPROPERTY()			int32				RecordBriefAttempts;			//var int32 RecordBriefAttempts;
	UPROPERTY()			FRecordBriefStruct	RecordBrief;					//var GetRecordBriefRequestAdapter.RecordBriefStruct RecordBrief;
	UPROPERTY()			int32				MAX_CONNECTION_ATTEMPTS;		//var const int32 MAX_CONNECTION_ATTEMPTS;

	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	void ShowPanel(bool bShow);
	void UpdateHeaderWithUserName();
	void InternalOnGetRecordBriefComplete(int32 Result, FRecordBriefStruct Brief);
	void RequestRecordBrief();
	void ProcessRecordBriefData();
	void ProcessRecordBriefError();
	int32 CalculateExperience(int32 CurrentHonor);
	int32 CalculateExperienceNeeded(int32 CurrentExperience, int32 CurrentHonor);
	AActor* FindActor();

};
