// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIBorder/GUIFooter/GUIFooter.h"
#include "ButtonFooter.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UButtonFooter : public UGUIFooter
{
	GENERATED_BODY()
public:
	UButtonFooter();

	UPROPERTY(EditAnywhere, Category = "Footer")				EeTextAlign Alignment;			//var(Footer) GUI.eTextAlign Alignment;
	UPROPERTY(EditAnywhere, Category = "Footer")				bool bAutoSize;					//var(Footer) bool bAutoSize;
	UPROPERTY(EditAnywhere, Category = "Footer")				bool bFullHeight;				//var(Footer) bool bFullHeight;
	UPROPERTY(EditAnywhere, Category = "Footer")				bool bFixedWidth;				//var(Footer) bool bFixedWidth;
	UPROPERTY(EditAnywhere, Category = "Footer")				float Spacer;					//var(Footer) float Spacer;
	UPROPERTY(EditAnywhere, Category = "Footer")				float Margin;					//var(Footer) float Margin;
	UPROPERTY(EditAnywhere, Category = "Footer")				float Padding;					//var(Footer) float Padding;
	UPROPERTY(EditAnywhere, Category = "Footer")				float ButtonWidth;				//var(Footer) float ButtonWidth;
	UPROPERTY(EditAnywhere, Category = "Footer")				float ButtonHeight;				//var(Footer) float ButtonHeight;
	UPROPERTY(EditAnywhere, Category = "Footer")				float ButtonLeft;				//var(Footer) editconst float ButtonLeft;

	void InitComponent(UGUIController* InController, UGUIComponent* InOwner);
	bool InternalOnPreDraw(UCanvas* C);
	void ResolutionChanged(int32 ResX, int32 ResY);
	void SetupButtons(FString bPerButtonSizes);
	bool ButtonsSized(UCanvas* C);
	void PositionButtons(UCanvas* C);
	FString GetLongestCaption(UCanvas* C);
	void GetButtonLeft();
	void GetMargin();
	void GetPadding();
	void GetSpacer();
	void Timer();

};
