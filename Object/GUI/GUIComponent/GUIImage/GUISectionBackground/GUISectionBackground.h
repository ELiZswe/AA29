// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/GUI/GUIComponent/GUIImage/GUIImage.h"
#include "GUISectionBackground.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UGUISectionBackground : public UGUIImage
{
	GENERATED_BODY()
public:
	UGUISectionBackground();

	UPROPERTY()											int32 MaxPerColumn;						//var() int MaxPerColumn;
	UPROPERTY()											int32 NumColumns;						//var() int NumColumns;
	UPROPERTY()											TArray<float> ImageOffset;				//var() float ImageOffset;
	UPROPERTY()											float BottomPadding;					//var() float BottomPadding;
	UPROPERTY()											float TopPadding;						//var() float TopPadding;
	UPROPERTY()											float RightPadding;						//var() float RightPadding;
	UPROPERTY()											float LeftPadding;						//var() float LeftPadding;
	UPROPERTY()											float ColPadding;						//var() float ColPadding;
	UPROPERTY()											FString Caption;						//var() localized string Caption;
	UPROPERTY()											UMaterialInstance* HeaderBase;			//var() Material HeaderBase;
	UPROPERTY()											UMaterialInstance* HeaderBar;			//var() Material HeaderBar;
	UPROPERTY()											UMaterialInstance* HeaderTop;			//var() Material HeaderTop;
	UPROPERTY()											TArray<UGUIComponent*> AlignStack;		//var() array<GUIComponent> AlignStack;
	UPROPERTY()											int32 bFillClient;						//var() bool bFillClient;
	UPROPERTY()											int32 bRemapStack;						//var() bool bRemapStack;
	UPROPERTY(EditAnywhere, Category = "Style")			bool bAltCaption;						//var(Style) bool bAltCaption;
	UPROPERTY(EditAnywhere, Category = "Style")			ETextAlign AltCaptionAlign;				//var(Style) GUI.eTextAlign AltCaptionAlign;
	UPROPERTY(EditAnywhere, Category = "Style")			TArray<int32> AltCaptionOffset;			//var(Style) int AltCaptionOffset;
	UPROPERTY(EditAnywhere, Category = "Style")			FString CaptionStyleName;				//var(Style) string CaptionStyleName;
	//UPROPERTY(EditAnywhere, Category = "Style")		UGUIStyles* CaptionStyle;				//var(Style) editconst GUIStyles CaptionStyle;


	void InitComponent(UGUIController* MyController, UGUIComponent* MyOwner);
	void SetVisibility(bool bIsVisible);
	bool ManageComponent(UGUIComponent* Component);
	bool UnmanageComponent(UGUIComponent* Comp);
	int32 FindComponentIndex(UGUIComponent* Comp);
	void Reset();
	void InternalPreDraw(UCanvas* C);
	void ResolutionChanged(int32 ResX, int32 ResY);
	void SetPosition(float NewLeft, float NewTop, float NewWidth, float NewHeight, bool bRelative);

};
