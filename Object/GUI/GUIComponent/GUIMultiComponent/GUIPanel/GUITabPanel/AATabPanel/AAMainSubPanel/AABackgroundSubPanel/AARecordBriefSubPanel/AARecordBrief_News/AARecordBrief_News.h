// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAMainSubPanel/AABackgroundSubPanel/AARecordBriefSubPanel/AARecordBriefSubPanel.h"
#include "AARecordBrief_News.generated.h"

class AHttpLink;
class UGUIContentBox;
class UGUIComponent;

UCLASS()
class AA29_API UAARecordBrief_News : public UAARecordBriefSubPanel
{
	GENERATED_BODY()
public:
	UAARecordBrief_News();

	UPROPERTY(EditAnywhere)			UGUIContentBox* guicbPanel;				//var() automated GUIContentBox guicbPanel;
	UPROPERTY()						UGUIComponent* selected;				//var UGUIComponent* selected;
	UPROPERTY()						AHttpLink* MyLink;						//var IpDrv.HttpLink MyLink;

	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	bool ButtonClick(UGUIComponent* Sender);
	
};
