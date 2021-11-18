// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIComponent.h"
#include "AA29/AA29.h"

#include "GUIButton.generated.h"

class UGUIController;
class UGUIStyles;

UCLASS()
class AA29_API UGUIButton : public UGUIComponent
{
	GENERATED_BODY()
public:
	UGUIButton();

	UPROPERTY(EditAnywhere)											bool bUseCaptionHeight;							//var() bool bUseCaptionHeight;
	UPROPERTY(EditAnywhere)											bool bWrapCaption;								//var() bool bWrapCaption;
	UPROPERTY(EditAnywhere)											bool bAutoShrink;								//var() bool bAutoShrink;
	UPROPERTY(EditAnywhere)											bool bAutoSize;									//var() bool bAutoSize;
	UPROPERTY(EditAnywhere)											FString SizingCaption;							//var() string SizingCaption;
	UPROPERTY(EditAnywhere)											FPaddingPercent AutoSizePadding;				//var() PaddingPercent AutoSizePadding;
	UPROPERTY(EditAnywhere)											FString Caption;								//var() localized string Caption;
	UPROPERTY(EditAnywhere)											FString CaptionEffectStyleName;					//var() string CaptionEffectStyleName;
	UPROPERTY(EditAnywhere)											UGUIStyles* CaptionEffectStyle;					//var() editconst GUIStyles CaptionEffectStyle;
	UPROPERTY(EditAnywhere)											ETextAlign CaptionAlign;						//var() GUI.eTextAlign CaptionAlign;

	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	bool InternalOnKeyEvent(uint8& Key, uint8& State, float Delta);
};
