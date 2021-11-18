// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/AAGUIPage/PopupPageBase/FloatingWindow/LargeWindow/LargeWindow.h"
#include "AAShowFiltersDialog.generated.h"

class UGUIButton;
class UGUIContentBox;

UCLASS()
class AA29_API UAAShowFiltersDialog : public ULargeWindow
{
	GENERATED_BODY()
public:
	UAAShowFiltersDialog();

	UPROPERTY(EditAnywhere)		UGUIButton*			b_OK;					//var() automated XInterface.GUIButton b_OK;
	UPROPERTY(EditAnywhere)		UGUIContentBox*		FilterSummary;			//var() automated GUIContentBox FilterSummary;
	UPROPERTY()					FString				NoFiltersMessage;		//var localized FString NoFiltersMessage;

	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	FString FilterDescriptionsToNML(TArray<FKeyValuePair> FilterDescriptions);
	void SetFilterDescriptions(TArray<FKeyValuePair> FilterDescriptions);
	bool InternalOnClick(UGUIComponent* Sender);
}; 