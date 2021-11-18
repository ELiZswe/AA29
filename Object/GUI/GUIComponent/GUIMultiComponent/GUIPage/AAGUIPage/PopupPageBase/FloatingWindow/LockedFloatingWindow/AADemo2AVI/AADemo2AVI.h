// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIPage/AAGUIPage/PopupPageBase/FloatingWindow/LockedFloatingWindow/LockedFloatingWindow.h"
#include "AADemo2AVI.generated.h"

class UGUILabel;
class UmoEditBox;
class UmoComboBox;
class UmoSlider;

UCLASS()
class AA29_API UAADemo2AVI : public ULockedFloatingWindow
{
	GENERATED_BODY()
public:
	UAADemo2AVI();

	UPROPERTY(EditAnywhere)		UGUILabel*		lb_SavePos;			//var() automated XInterface.GUILabel lb_SavePos;
	UPROPERTY(EditAnywhere)		UmoEditBox*		eb_Filename;		//var() automated XInterface.moEditBox eb_Filename;
	UPROPERTY(EditAnywhere)		UmoComboBox*	co_Resolution;		//var() automated XInterface.moComboBox co_Resolution;
	UPROPERTY(EditAnywhere)		UmoSlider*		so_Quality;			//var() automated XInterface.moSlider so_Quality;
	UPROPERTY()					FString			DemoName;			//var FString DemoName;

	void InitComponent(UGUIController* Controller, UGUIComponent* Owner);
	void HandleParameters(FString Param1, FString Param2);
	bool OkClick(UGUIComponent* Sender);
};
