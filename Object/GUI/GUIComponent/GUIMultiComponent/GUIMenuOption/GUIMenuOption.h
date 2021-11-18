// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIMultiComponent.h"
#include "GUIMenuOption.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UGUIMenuOption : public UGUIMultiComponent
{
	GENERATED_BODY()
public:
	UGUIMenuOption();


	UPROPERTY(EditAnywhere, Category = "Option")						bool				bIgnoreChange;					//var(Option) editconst bool bIgnoreChange;
	UPROPERTY(EditAnywhere, Category = "Option")						bool				bValueReadOnly;					//var(Option) bool bValueReadOnly;
	UPROPERTY(EditAnywhere, Category = "Option")						bool				bAutoSizeCaption;				//var(Option) bool bAutoSizeCaption;
	UPROPERTY(EditAnywhere, Category = "Option")						bool				bHeightFromComponent;			//var(Option) bool bHeightFromComponent;
	UPROPERTY(EditAnywhere, Category = "Option")						bool				bFlipped;						//var(Option) bool bFlipped;
	UPROPERTY(EditAnywhere, Category = "Option")						bool				bSquare;						//var(Option) bool bSquare;
	UPROPERTY(EditAnywhere, Category = "Option")						bool				bVerticalLayout;				//var(Option) bool bVerticalLayout;
	UPROPERTY(EditAnywhere, Category = "Option")						EeTextAlign			LabelJustification;				//var(Option) GUI.eTextAlign LabelJustification;
	UPROPERTY(EditAnywhere, Category = "Option")						EeTextAlign			ComponentJustification;			//var(Option) GUI.eTextAlign ComponentJustification;
	UPROPERTY(EditAnywhere, Category = "Option")						float				CaptionWidth;					//var(Option) float CaptionWidth;
	UPROPERTY(EditAnywhere, Category = "Option")						float				ComponentWidth;					//var(Option) float ComponentWidth;
	UPROPERTY(EditAnywhere, Category = "Option")						FString				Caption;						//var(Option) localized FString Caption;
	UPROPERTY(EditAnywhere, Category = "Option")						FString				ComponentClassName;				//var(Option) FString ComponentClassName;
	UPROPERTY(EditAnywhere, Category = "Option")						FString				LabelFont;						//var(Option) FString LabelFont;
	UPROPERTY(EditAnywhere, Category = "Option")						FString				LabelStyleName;					//var(Option) FString LabelStyleName;
	UPROPERTY(EditAnywhere, Category = "Option")						FColor				LabelColor;						//var(Option) Color LabelColor;
	UPROPERTY(EditAnywhere, Category = "Option")						UGUILabel*			MyLabel;						//var(Option) editconst noexport GUILabel MyLabel;
	UPROPERTY(EditAnywhere, Category = "Option")						UGUIComponent*		MyComponent;					//var(Option) editconst noexport GUIComponent MyComponent;

	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	void SetComponentValue(FString NewValue, bool bNoChange);
	FString GetComponentValue();
	void ResetComponent();
	void SetReadOnly(bool bValue);
	void SetHint(FString NewHint);
	void SetCaption(FString NewCaption);
	bool MenuOptionClicked(UGUIComponent* Sender);
	void InternalOnChange(UGUIComponent* Sender);
	void InternalOnCreateComponent(UGUIComponent* NewComp, UGUIComponent* Sender);
	void CenterMouse();
	void SetFriendlyLabel(UGUILabel* NewLabel);

};
