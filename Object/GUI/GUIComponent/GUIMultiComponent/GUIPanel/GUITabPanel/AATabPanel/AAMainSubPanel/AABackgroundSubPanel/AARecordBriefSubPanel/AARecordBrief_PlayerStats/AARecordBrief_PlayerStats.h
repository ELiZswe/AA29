// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAMainSubPanel/AABackgroundSubPanel/AARecordBriefSubPanel/AARecordBriefSubPanel.h"
#include "AARecordBrief_PlayerStats.generated.h"

class UNMLContent;
class UGUIContentBox;
class UGUIComponent;

UCLASS()
class AA29_API UAARecordBrief_PlayerStats : public UAARecordBriefSubPanel
{
	GENERATED_BODY()
public:
	UAARecordBrief_PlayerStats();

	UPROPERTY(EditAnywhere)			UGUIContentBox*	guicbPanel;					//var() automated GUIContentBox guicbPanel;
	UPROPERTY()						UGUIComponent*	selected;					//var UGUIComponent* selected;
	UPROPERTY()						UNMLContent*	MyNML;						//var NMLContent MyNML;
	UPROPERTY()						FString			DefaultRecordBriefText;		//var FString DefaultRecordBriefText;
	UPROPERTY()						FString			TemplateFile;				//var FString TemplateFile;

	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	void Opened(UGUIComponent* Sender);
	bool ButtonClick(UGUIComponent* Sender);
	void ProcessRecordBriefData();
	FString RankImageFromHonor();
	FString RankDescriptionFromHonor();
	void InsertDataIntoNML(FString& NML);
	FString ToHHMMSS(float Time);
	FString FixDate(FString Date);
	FString FixQualificationDate(FString Date);
	FString GetGroup(int32 Id);
	void ProcessRecordBriefError();
	void AddNMLTextBlock(FString TextToAdd, FString& NML);
	float GetWeaponShotPercentage(int32 WeaponClass);
	FString GetImageFrom28Mapname(FString MapName);

};
