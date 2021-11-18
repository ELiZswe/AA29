// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPanel/GUITabPanel/AATabPanel/AAMainSubPanel/AABackgroundSubPanel/AABackgroundSubPanel.h"
#include "AAMissionsContentSubPanel.generated.h"

class UGUIImage;
class UGUIContentBox;
class UGUIComponent;

UCLASS()
class AA29_API UAAMissionsContentSubPanel : public UAABackgroundSubPanel
{
	GENERATED_BODY()
public:
	UAAMissionsContentSubPanel();

	UPROPERTY(EditAnywhere)			UGUIImage* i_FieldBackground;		//var() automated XInterface.GUIImage i_FieldBackground;
	UPROPERTY(EditAnywhere)			UGUIContentBox* cob_Panel;			//var() automated GUIContentBox cob_Panel;
	UPROPERTY()						UGUIComponent* selected;			//var UGUIComponent* selected;
	UPROPERTY()						FString ToursFile;					//var FString ToursFile;
	UPROPERTY()						FString ContentPackage;				//var FString ContentPackage;
	UPROPERTY()						FString ContentPackageGroup;		//var FString ContentPackageGroup;
	UPROPERTY()						FString NotAvailableText;			//var localized FString NotAvailableText;
	UPROPERTY()						FString AvailableText;				//var localized FString AvailableText;
	UPROPERTY()						FString CompletedText;				//var localized FString CompletedText;
	UPROPERTY()						FColor NotAvailableColor;			//var Color NotAvailableColor;
	UPROPERTY()						FColor AvailableColor;				//var Color AvailableColor;
	UPROPERTY()						FColor CompletedColor;				//var Color CompletedColor;
	UPROPERTY()						int32 TourID;						//var int32 TourID;
	UPROPERTY()						int32 MissionID;					//var int32 MissionID;

	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	bool ButtonClick(UGUIComponent* Sender);
	void LoadContent();
	bool UseTraining(int32 Tour);
	void SetStatusCaption(int32 Status);

};
