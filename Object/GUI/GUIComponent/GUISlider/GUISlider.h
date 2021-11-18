// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIComponent.h"
#include "GUISlider.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UGUISlider : public UGUIComponent
{
	GENERATED_BODY()
public:
	UGUISlider();
	
	UPROPERTY(EditAnywhere)							float				MinValue;				//var() float MinValue;
	UPROPERTY(EditAnywhere)							float				MaxValue;				//var() float MaxValue;
	UPROPERTY(EditAnywhere)							float				Value;					//var() float Value;
	UPROPERTY(EditAnywhere)							float				MarkerWidth;			//var() float MarkerWidth;
	UPROPERTY(EditAnywhere)							bool				bIntSlider;				//var() bool bIntSlider;
	UPROPERTY(EditAnywhere)							bool				bShowMarker;			//var() bool bShowMarker;
	UPROPERTY(EditAnywhere)							bool				bShowCaption;			//var() bool bShowCaption;
	UPROPERTY(EditAnywhere)							bool				bDrawPercentSign;		//var() bool bDrawPercentSign;
	UPROPERTY(EditAnywhere)							bool				bReadOnly;				//var() bool bReadOnly;
	UPROPERTY(EditAnywhere)							bool				bShowValueTooltip;		//var() bool bShowValueTooltip;
	UPROPERTY(EditAnywhere)							UMaterialInstance*	FillImage;				//var() Material FillImage;
	UPROPERTY(EditAnywhere)							FString				CaptionStyleName;		//var() FString CaptionStyleName;
	UPROPERTY(EditAnywhere)							FString				BarStyleName;			//var() FString BarStyleName;
	UPROPERTY()										UGUIStyles*			CaptionStyle;			//var GUIStyles CaptionStyle;
	UPROPERTY()										UGUIStyles*			BarStyle;				//var GUIStyles BarStyle;

	bool OnPreDrawCaption(float& X, float& Y, float& XL, float& YL, EeTextAlign& Justification);
	FString OnDrawCaption();
	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	bool InternalCapturedMouseMove(float deltaX, float deltaY);
	bool InternalOnKeyEvent(uint8& Key, uint8& State, float Delta);
	float SetValue(float NewValue);
	void Adjust(float Amount);
	bool InternalOnClick(UGUIComponent* Sender);
	void InternalOnMousePressed(UGUIComponent* Sender, bool RepeatClick);
	void InternalOnMouseRelease(UGUIComponent* Sender);
	void SetReadOnly(bool B);
	float GetMarkerPosition();
	void CenterMouse();
	FString GetValueString();
	void ModifyTooltipForDragging();
	void RevertTooltipToNormal();
	void ShowToolTip();
	void HideToolTip();
	bool ToolTipLeaveArea();

};
